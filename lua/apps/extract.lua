local mpeg2  = require("mpeg2")
local pipe   = require("ltn12")

local function extractPes()
	local pesPacket = mpeg2.PesPacket()
	local buffer = {}
	local pos = 1
	
	return function(packet)
		local pesData = ""
		
		if packet:getPayloadUnitStartIndicator() and pos ~= 1 then -- start of a new pes packet
			buffer[pos], pos = nil, 1
			pesData = table.concat(buffer) -- concat the payloads
			
			if pesData ~= "" then
				local length = string.len(pesData)
				
				if length <= 65541 then
					pesPacket:setData(pesData, length)
					pesPacket:setPesPacketLength(length - 6)
					pesPacket:finalize()
					pesData = pesPacket:getData()
				end
			end
		end
		
		local payload = packet:getPayload()
		
		if payload then
			buffer[pos], pos = payload, pos + 1 -- add the payload to the buffer
		end
		
		return pesData
	end
end

local map = {}

for i = 3, table.getn(arg) do
	map[tonumber(arg[i])] = extractPes()
end

pipe.pump.chain(
	pipe.source.file(io.open(arg[1], "rb"), nil, mpeg2.TSPacket.PACKET_SIZE),
	mpeg2.filter.processor(map),
	pipe.sink.file(io.open(arg[2], "wb"))
)
