--
-- load libraries
--

local socket = require("socket")
local mpeg2 = require("mpeg2")
local gettime = socket.gettime
local sleep = socket.sleep

--~ local verbose = print
local verbose = function() end

--
-- file
--

local inputFile = assert(io.open(arg[1], "rb"))
--~ local outputFile = assert(io.open(arg[2], "wb"))

-- socket
local host, port = "127.0.0.1", 1234
local ip = socket.try(socket.dns.toip(host))
local udp = socket.try(socket.udp())
udp:setpeername(ip, port)

-- mpeg2
local packet = mpeg2.TSPacket()
local pes = mpeg2.PesPacket("@", 1)
local patSection = mpeg2.PatSection()
local pmtSection = mpeg2.PmtSection()

-- pts
local firstPts = 0
local lastPts = 0

-- pcr
local firstPcr = 0
local lastPcr = 0

-- time
local startTime = gettime()
local lastTime = 0

local function unknownPacketProcessor(packet)
	verbose("Unknown", packet:getPid())
end

local function emptyPacketProcessor(packet)
end

local packetProcessor
local patPacketProcessor
local pmtPacketProcessor
local pcrPacketProcessor
local videoPacketProcessor
local audioPacketProcessor

--
-- PAT
--

patPacketProcessor = function(packet)
	local payloadData, length = packet:getPayload(0)
	-- skip pointer field
	payloadData, length = string.sub(payloadData, string.byte(payloadData, 1) + 2), length - 1
	patSection:setData(payloadData, length)
	
	if patSection:verify() then
		local iterator = patSection:getProgramsIterator()
		
		while iterator:hasNext() do
			local program = mpeg2.PatSection.Program((iterator:getNext(0)))
			local pPid = program:getPid()
			packetProcessor[pPid] = pmtPacketProcessor
			verbose("PAT->PMT", program:getProgramNumber(), pPid)
		end
	end
end

--
-- PMT
--

pmtPacketProcessor = function(packet)
	local payloadData, length = packet:getPayload(0)
	-- skip pointer field
	payloadData, length = string.sub(payloadData, string.byte(payloadData, 1) + 2), length - 1
	pmtSection:setData(payloadData, length)
	
	if pmtSection:verify() then
		packetProcessor[pmtSection:getPcrPid()] = pcrPacketProcessor
		local iterator = pmtSection:getStreamsIterator()
		
		verbose("PMT->PCR", pmtSection:getProgramNumber(), pmtSection:getPcrPid())
		
		while iterator:hasNext() do
			local stream = mpeg2.PmtSection.Stream((iterator:getNext(0)))
			local streamType = stream:getStreamType()
			local ePid = stream:getElementaryPid()
			
			verbose("PMT->Stream", stream:getStreamType(), stream:getElementaryPid())
			
			if streamType == 1 or streamType == 2 then -- video
				packetProcessor[ePid] = videoPacketProcessor
			elseif streamType == 3 or streamType == 4 then -- audio
				packetProcessor[ePid] = audioPacketProcessor
			else
				packetProcessor[ePid] = emptyPacketProcessor
			end
			
			if pmtSection:getPcrPid() == ePid then
				local oldProcessor = packetProcessor[ePid]
				
				packetProcessor[ePid] = function(packet)
					pcrPacketProcessor(packet)
					oldProcessor(packet)
				end
			end
		end
	end
end

--
-- PCR
--

local total = 0
local delta = 0.2

pcrPacketProcessor = function(packet)
	if packet:hasPcr() then -- pcr
		local pcr = packet:getPcrBase() + packet:getPcrExtension() / 300 -- 90 KHz
		
		if firstPcr == 0 then
			firstPcr = pcr
		else
			local now = gettime()
			
			if now - lastTime < (pcr - lastPcr) / 90000 then -- too fast
				total = total + (((pcr - lastPcr) / 90000) - (now - lastTime))
				
				if total > delta then
--~ 					sleep(total)
					total = 0
				end
			end
		end
		
		lastPcr = pcr
		lastTime = gettime()
	end
end

--
-- VIDEO
--

videoPacketProcessor = function(packet)
	local payload, length = packet:getPayload(0)
	
	if length ~= 0 then
		if packet:getPayloadUnitStartIndicator() then
			pes:setData(payload, length)
--~ 			outputFile:write(string.sub(payload, 10 + pes:getPesHeaderDataLength()))
			
			if pes:hasPts() then
				local pts = pes:getPts() -- 90 Khz
				
				if firstPts == 0 then
					firstPts = pts
				end
				
				lastPts = pts
			end
		else
--~ 			outputFile:write(payload)
		end
	end
end

--
-- AUDIO
--

audioPacketProcessor = function(packet)
--~ 	local payload, length = packet:getPayload(0)
	
--~ 	if length ~= 0 then
--~ 		if packet:getPayloadUnitStartIndicator() then
--~ 			pes:setData(payload, length)
--~ 			outputFile:write(string.sub(payload, 10 + pes:getPesHeaderDataLength()))
--~ 		else
--~ 			outputFile:write(payload)
--~ 		end
--~ 	end
end

--
-- GENERAL
--

packetProcessor = {
	[0] = patPacketProcessor,
	[8191] = emptyPacketProcessor,
	
	__index = function(t, i)
		t[i] = unknownPacketProcessor -- to improve performance, but i'm not sure about this improvement
		return unknownPacketProcessor
	end,
}

setmetatable(packetProcessor, packetProcessor)

local t = {}

while true do
	local data = inputFile:read(188) -- read a MPEG-2 packet from file
	
	if not data then
		inputFile:close()
--~ 		outputFile:close()
		break
	end
	
	packet:setData(data, 188)
	packetProcessor[packet:getPid()](packet)
	table.insert(t, (packet:getData()))
	
	if table.getn(t) == 7 then -- send seven packets each time
		udp:send(table.concat(t))
		t = {}
	end
end

if table.getn(t) > 0 then
	udp:send(table.concat(t))
end

print("Statistics")
print("PCR", (lastPcr - firstPcr) / 90000) -- 90 KHz to seconds
print("Execution time:", gettime() - startTime)
