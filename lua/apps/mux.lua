local socket = require("socket")
local mpeg2 = require("mpeg2")

local patSection = mpeg2.PatSection()
local pmtSection = mpeg2.PmtSection()
local videoPes = mpeg2.PesPacket()
local audioPes = mpeg2.PesPacket()
local pcrPacket = mpeg2.TSPacket()

local function isTimeToSendPcr()
	-- todo implement
	return false
end

local function isTimeToSendPat()
	-- todo implement
	return false
end

local function isTimeToSendPmt()
	-- todo implement
	return false
end

local function getPesFromFile(file, pes)
	local data
	data = file:read(4) -- discard
	if not data then return false end
	data = file:read(2)
	if not data then return false end
	local pesPacketLength = string.byte(data, 1) * (2^8) + string.byte(data, 2)
	file:seek("cur", -6)
	data = file:read(6 + pesPacketLength)
	if not data then return false end
	pes:setData(data)
	return true
end

local function buildPesToTsConverter(pid)
	local packet = mpeg2.TSPacket()
	packet:setTransportErrorIndicator(false)
	packet:setTransportPriority(false)
	packet:setPid(pid)
	packet:setTransportScramblingControl(mpeg2.NOT_SCRAMBLED)
	packet:setAdaptationFieldControl(mpeg2.ONLY_PAYLOAD)
	packet:setContinuityCounter(0)
	
	return function(pes)
		local data, length = pes:getData()
		local result = {}
		packet:setPayloadUnitStartIndicator(true)
		
		for i = 1, length - 184, 184 do
			packet:setPayload(string.sub(data, i, i + 184))
			local packetData = packet:getData()
			table.insert(result, packetData)
			packet:setPayloadUnitStartIndicator(false)
			packet:incContinuityCounter()
		end
		
		-- TODO stuffing bytes
		
		return table.concat(result)
	end
end

while true do
	if isTimeToSendPcr() then
		-- send pcr
	end
	
	if isTimeToSendPat() then
		-- send pat section
	end
	
	if isTimeToSendPmt() then
		-- send pmt section
	end
	
	-- VIDEO
	
	if videoPes and (
		(audioPes and (videoPes:getPts() < audioPes:getPts()))
		or
		(not audioPes)
	) then
		-- update pts with the new clock
		-- convert to ts packets
		-- send video
		-- go to the next video pes packet
		if not getPesFromFile(videoFile, videoPes) then
			videoPes = nil
		end
	
	-- AUDIO
	
	else if audioPes and (
		(videoPes and (audioPes:getPts() <= videoPes:getPts()))
		or
		(not videoPes)
	) then
		-- update pts with the new clock
		-- convert to ts packets
		-- send audio
		-- go to the next audio pes packet
		if not getPesFromFile(audioFile, audioPes) then
			audioPes = nil
		end
	end
end
