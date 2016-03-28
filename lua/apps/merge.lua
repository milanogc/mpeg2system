local mpeg2 = require("mpeg2")
local pipe  = require("ltn12")

local function getPes(file, pes)
	local data
	data = file:read(4) -- discard
	if not data then return false end
	data = file:read(2)
	if not data then return false end
	local pesPacketLength = string.byte(data, 1) * (2^8) + string.byte(data, 2)
	file:seek("cur", -6)
	data = file:read(6 + pesPacketLength)
	if not data then return false end
	pes:setData(data, 6 + pesPacketLength)
	return true
end

local function source(...)
	local h = arg
	local n = table.getn(h)
	local pes = {}
	local timePes = {}
	local index
	
	for i = 1, n do
		pes[i] = mpeg2.PesPacket()
		getPes(h[i], pes[i])
		timePes[i] = 2^33 - 1
	end
	
	return function()
		if n == 0 then
			return nil
		end
		
		local index = 1
		
		for i = 1, n do
			if pes[i]:hasPts() then
				if pes[i]:hasDts() then
					timePes[i] = pes[i]:getDts()
				else
					timePes[i] = pes[i]:getPts()
				end
			end
			
			if timePes[i] < timePes[index] then
				index = i
			end
		end
		
		local pesData = pes[index]:getData()
		local r = getPes(h[index], pes[index])
		
		if not r then
			table.remove(h, index)
			table.remove(pes, index)
			table.remove(timePes, index)
			n = n - 1
		end
		
		return pesData
	end
end

pipe.pump.all(
	-- source
	source(io.open(arg[1], "rb"), io.open(arg[2], "rb")),
	-- sink
	pipe.sink.file(io.open(arg[3], "wb"), "Unable to create output file!")
)
