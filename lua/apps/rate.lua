local inputFile = assert(io.open(arg[1], "rb"))
local mpeg2 = require("mpeg2")
local packet = mpeg2.TSPacket()
local patSection = mpeg2.PatSection()
local pmtSection = mpeg2.PmtSection()
local pmtPid = -1
local pcrPid = -1

local function patPacket(packet)
	local payloadData, length = packet:getPayload(0)
	-- skip pointer field
	payloadData, length = string.sub(payloadData, string.byte(payloadData, 1) + 2), length - 1
	patSection:setData(payloadData, length)
	
	if patSection:verify() then
		local iterator = patSection:getProgramsIterator()
		
		if iterator:hasNext() then -- get the first program
			local program = mpeg2.PatSection.Program((iterator:getNext(0)))
			pmtPid = program:getPid()
			break
		end
	end
end

local function pmtPacket(packet)
	local payloadData, length = packet:getPayload(0)
	-- skip pointer field
	payloadData, length = string.sub(payloadData, string.byte(payloadData, 1) + 2), length - 1
	pmtSection:setData(payloadData, length)
	
	if pmtSection:verify() then
		pcrPid = pmtSection:getPcrPid()
	end
end

local lastPcr = -1
local diffs = {}
local packets = {}
local nPackets = 0

local function pcrPacket(packet)
	if packet:hasPcr() then
		local pcr = packet:getPcrBase() + packet:getPcrExtension() / 300 -- 90 KHz
		
		if lastPcr ~= -1 then
			table.insert(diffs, pcr - lastPcr)
			table.insert(packets, nPackets)
		end
		
		nPackets = 0
		lastPcr = pcr
	end
end

local function bitRate()
	local allDiffs = 0
	local allPackets = 0
	
	for i = 1, table.getn(diffs) do
		allDiffs = allDiffs + diffs[i]
		allPackets = allPackets + packets[i]
	end
	
	return (allPackets * 188 * 8) / (allDiffs / 90000)
end

while true do
	local data = inputFile:read(188)
	
	if not data then
		inputFile:close()
		break
	end
	
	packet:setData(data, 188)
	nPackets = nPackets + 1
	local pid = packet:getPid()
	
	if     pid == 0      then patPacket(packet)
	elseif pid == pmtPid then pmtPacket(packet)
	elseif pid == pcrPid then pcrPacket(packet)
	end
end

print("Bit rate is: ", bitRate())
