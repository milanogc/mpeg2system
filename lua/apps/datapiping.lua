local mpeg2 = require("mpeg2")

local function dataPiping(file, pid)
	local packet = mpeg2.TSPacket()
	local fileData = nil
	local nullContinuityCounter = 0
	
	-- packet initialization
	packet:setTransportErrorIndicator(false)
	packet:setTransportPriority(false)
	packet:setPid(pid)
	packet:setTransportScramblingControl(mpeg2.SC_NOT_SCRAMBLED)
	packet:setAdaptationFieldControl(mpeg2.AFC_ONLY_PAYLOAD)
	packet:setContinuityCounter(0)
	
	return function(nullPacket)
		if replace then
			if fileData then
				fileData = file:read(mpeg2.TSPacket.MAX_PAYLOAD_SIZE)
				packet:setPayloadUnitStartIndicator(false)
			end
			
			if not fileData then
				file:seek("set")
				fileData = file:read(mpeg2.TSPacket.MAX_PAYLOAD_SIZE) -- read the first amount of data from file
				packet:setPayloadUnitStartIndicator(true)
				replace = false -- do something better
			end
			
			packet:setPayload(fileData, string.len(fileData))
			packet:finalize()
			packetData = packet:getData()
			packet:incContinuityCounter() -- increment continuity counter
		else
			nullPacket:setContinuityCounter(nullContinuityCounter)
			nullPacket:finalize()
			packetData = nullPacket:getData()
			nullContinuityCounter = math.mod(nullContinuityCounter + 1, 16)
			replace = true -- do something better
		end
		
		return packetData
	end
end

local map = {
	[8191] = dataPiping(io.open(arg[1], "rb"), 2600)
}

mpeg2.filter.nullReplacer(source, replacer)
mpeg2.filter.processor(map, true)
