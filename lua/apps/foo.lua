local thread = require("thread")
local socket = require("socket")
local mpeg2 = require("mpeg2")

local inputSocket = socket.udp()
inputSocket:setsockname("*", 1234) -- connect to a source
local packet = mpeg2.TSPacket()

-- thread
thread.newthread(function()
	while true do
		local data = inputSocket:receive()
--~ 		packet:setData(data, mpeg2.TSPacket.PACKET_SIZE)
--~ 		local pid = packet:getPid()
		print(data)
	end
end, {})

-- main
while true do end


-----------------------------------

local lastTime = 0
local lastPcr = 0
local total = 0
local limit = 0.5

local function pcrPacket(packet)
	if packet:hasPcr() then
		local pcr = packet:getPcrBase() + packet:getPcrExtension() / 300 -- 90 KHz
		local now = gettime()
		
		if now - lastTime < (pcr - lastPcr) / 90000 then -- too fast
			total = total + (((pcr - lastPcr) / 90000) - (now - lastTime))
			
			if total > limit then -- sleep when a certain limit is exceeded
				sleep(limit)
				total = total - limit
			end
		end
		
		lastPcr = pcr
		lastTime = gettime()
	end
end

local packet = mpeg2.TSPacket()

local function step(src, snk)
    local chunk, src_err = src()
	
	if chunk then
		for i = 1, string.len(chunk), 188 do
			packet:setData(string.sub(chunk, i, 188), 188)
			
			if packet:getPid() == 80 then
				pcrPacket(packet)
			end
		end
	end
	
	local ret, snk_err = snk(chunk, src_err)
	return chunk and ret and not src_err and not snk_err, src_err or snk_err
end

-------------------------------------------

local function replace(file)
	local packet = mpeg2.TSPacket()
	
	return function(data)
		if data ~= nil then
			if string.len(data) == mpeg2.TSPacket.PACKET_SIZE then
				packet:setData(data, mpeg2.TSPacket.PACKET_SIZE)
				
				if packet:getPid() == 8191 then
					data = file:read(mpeg2.TSPacket.PACKET_SIZE)
					
					if not data then -- eof
						file:seek("set") -- go to the beggining
						data = file:read(mpeg2.TSPacket.PACKET_SIZE)
					end
				end
				
				return data
			else
				return "" -- there is no extra output data
			end
		else
			return nil -- end of output
		end
	end
end