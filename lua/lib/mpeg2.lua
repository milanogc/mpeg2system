-- Author: Milano Gadelha Carvalho

local base   = require("base")
local string = require("string")
local socket = require("socket")
local mpeg2  = require("lmpeg2")

module("mpeg2")

local PACKET_SIZE = mpeg2.TSPacket.PACKET_SIZE

function mpeg2.skipPointerField(payloadData, length)
	local pointerField = string.byte(payloadData, 1)
	return string.sub(payloadData, pointerField + 2), length - (1 + pointerField)
end

function mpeg2.isPid(pid)
	return base.type(pid) == "number" and pid >= 0 and pid <= 8191
end

--
-- MPEG-2 sources and sinks, conforming to LTN12
--

mpeg2.filter = {}

-- processor({[n] = function(...) ... end}, ( true | false ))
function mpeg2.filter.processor(map, pass)
	local packet = mpeg2.TSPacket()
	
	return function(data)
		if not data then return nil end
		
		if data and string.len(data) == PACKET_SIZE then
			packet:setData(data, PACKET_SIZE)
			local pid = packet:getPid()
			if map[pid] then return map[pid](packet) end
		end
		
		return pass and data or ""
	end
end

local function discarder()
	return ""
end

-- discarder(8191, 33, ...)
function mpeg2.filter.packetDiscarder(...)
	local t = {}
	
	for i = 1, table.getn(arg) do
		base.assert(isPid(arg[i]))
		t[arg[i]] = discarder
	end
	
	return mpeg2.filter.processor(t, true)
end

local function pidChanger(newPid)
	return function(packet)
		packet:setPid(newPid)
		return packet:getData() -- output data
	end
end

-- pidChanger{[a] = b, [c] = d}
function mpeg2.filter.pidChanger(pids)
	local t = {}
	
	for k, v in pairs(pids) do
		base.assert(isPid(k))
		base.assert(isPid(v))
		t[k] = pidChanger(v)
	end
	
	return mpeg2.filter.processor(t, true)
end

function mpeg2.filter.bitRateKeeper(bitRate, limit)
	local count = 0
	local lastTime = socket.gettime()
	bitRate = bitRate * limit
	
	return function(data)
		if data then
			count = count + string.len(data) * 8
			
			if count >= bitRate then
				local now = socket.gettime()
				
				if now - lastTime < limit then
					socket.sleep(limit - (now - lastTime))
				end
				
				count = count - bitRate
				lastTime = socket.gettime()
			end
		end
		
		return data
	end
end

function mpeg2.filter.dataSplitter(length)
	local chunk = nil
	
	local co = coroutine.create(function()
		while true do
			if not chunk then return nil end
			
			for i = 1, string.len(chunk), length do
				coroutine.yield(string.sub(chunk, i, i + length - 1))
			end
			
			chunk = nil
			coroutine.yield("")
		end
	end)
	
	return function(data)
		if not chunk then
			chunk = data
		end
		
		local _, r = coroutine.resume(co)
		return r
	end
end

function mpeg2.filter.dataAccumulator(times)
	local buffer = {}
	local i = 1
	
	return function(data)
		if not data then
			buffer[i] = nil
			i = 1
			local r = table.concat(buffer)
			return r ~= "" and r or nil
		elseif data == "" then
			return ""
		else
			buffer[i] = data
			
			if i == times then
				i = 1
				return table.concat(buffer)
			else
				i = i + 1
				return ""
			end
		end
	end
end
