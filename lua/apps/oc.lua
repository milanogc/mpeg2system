#!/usr/local/bin/lua

------------------
-- BEGIN CONFIG --
------------------

-- PIDS
local pmtPid = 32
local dataPid = 336
local aitPid = 337

----------------
-- END CONFIG --
----------------

local socket = require("socket")
local pipe = require("ltn12")
local mpeg2 = require("mpeg2")

local function newContinuityCounter()
	local cc = {}
	for i = 0, 8191 do cc[i] = 0 end
	
	return function(pid)
		local v = cc[pid]
		cc[pid] = math.mod(cc[pid] + 1, 16) -- increment continuity counter
		return v
	end
end

local function buildMap(ifile, pmtPid, dataPid, aitPid)
	-- DATA STREAM DESCRIPTORS
	
	local atd = mpeg2.AssociationTagDescriptor()
	atd:setAssociationTag(11) -- 0xB
	atd:setUse(0)
	atd:setTransactionId(2147483648) -- 0x80000000
	atd:setTimeout(4294967295) -- 0xFFFFFFFF
	atd:finalize()
	
	local sid = mpeg2.StreamIdentifierDescriptor()
	sid:setComponentTag(11) -- 0xB
	sid:finalize()
	
	local cid = mpeg2.CarouselIdentifierDescriptor()
	cid:setCarouselId(1)
	cid:setFormatId(0)
	cid:finalize()
	
	local dbid = mpeg2.DataBroadcastIdDescriptor()
	dbid:setDataBroadcastId(240) -- MHP Object Carousel
	dbid:finalize()
	
	-- DATA STREAM
	
	local dataStream = mpeg2.PmtSection.Stream()
	dataStream:setStreamType(11) -- 0xB
	dataStream:setElementaryPid(dataPid)
	dataStream:appendDescriptor(atd)
	dataStream:appendDescriptor(sid)
	dataStream:appendDescriptor(cid)
	dataStream:appendDescriptor(dbid)
	dataStream:finalize()
	
	-- AIT STREAM DESCRIPTORS
	
	local asd = mpeg2.ApplicationSignallingDescriptor()
	asd:appendAppTypeAndAitVersion(1, 1) -- app type, ait version
	asd:finalize()
	
	-- AIT STREAM
	
	local aitStream = mpeg2.PmtSection.Stream()
	aitStream:setStreamType(5) -- ETSI TS 102 812 V1.2.1 - 10.7.1 Application Signalling Descriptor - pg. 223
	aitStream:setElementaryPid(aitPid)
	aitStream:appendDescriptor(asd)
	aitStream:finalize()
	
	-- PMT and DATA
	
	local getContinuityCounter = newContinuityCounter()
	local pmtSection = mpeg2.PmtSection()
	local replace = false
	
	return {
		[pmtPid] = function(packet)
			assert(packet:getPayloadUnitStartIndicator())
			pmtSection:setData(mpeg2.skipPointerField(packet:getPayload()))
			assert(pmtSection:verify())
			-- packet
			packet:setTransportErrorIndicator(false)
			packet:setPayloadUnitStartIndicator(true)
			packet:setTransportPriority(false)
			packet:setPid(pmtPid)
			packet:setTransportScramblingControl(mpeg2.NOT_SCRAMBLED)
			packet:setAdaptationFieldControl(mpeg2.ONLY_PAYLOAD)
			packet:setContinuityCounter(getContinuityCounter(pmtPid))
			-- append streams to pmt
			pmtSection:appendStream(dataStream)
			pmtSection:appendStream(aitStream)
			pmtSection:finalize()
			assert(pmtSection:getDataLength() <= 183)
			-- now null packets can be replaced
			replace = true
			-- pointer field and data
			packet:setPayload(string.char(0) .. pmtSection:getData(), pmtSection:getDataLength() + 1)
			
			return packet:getData()
		end,
		
		[8191] = function(packet)
			if replace then
	 			local data = ifile:read(mpeg2.TSPacket.PACKET_SIZE)
				
				if not data then -- end of file reached
	 				ifile:seek("set")
					replace = false -- do not replace until we receive a PMT packet
				else
					assert(string.len(data) == mpeg2.TSPacket.PACKET_SIZE)
					packet:setData(data, mpeg2.TSPacket.PACKET_SIZE)
				end
			end
			
			packet:setContinuityCounter(getContinuityCounter(packet:getPid()))
			
			return packet:getData()
		end,
	}
end

-- PIPE

local source = socket.udp()
source:setpeername(arg[1], tonumber(arg[2]))

local target = socket.udp()
target:setpeername(arg[3], tonumber(arg[4]))

pipe.pump.chain(
 	socket.source("until-closed", source),
	mpeg2.filter.processor(buildMap(io.open(arg[5], "rb"), pmtPid, dataPid, aitPid)),
	socket.sink("unreliable", target)
)
