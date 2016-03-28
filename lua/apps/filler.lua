local socket = require("socket")
local pipe   = require("ltn12")
local mpeg2  = require("mpeg2")

local target = socket.udp()
target:setpeername(socket.dns.toip(arg[2]), arg[3])

pipe.pump.chain(
	-- source
	pipe.source.file(io.open(arg[1], "rb"), nil, mpeg2.TSPacket.PACKET_SIZE),
	
	-- filter
	mpeg2.filter.bitRateKeeper(arg[4], 0.25),
	
	-- filter
	mpeg2.filter.packetDiscarder(8191),
	
	-- filter
	mpeg2.filter.dataAccumulator(7),
	
	-- sink
	socket.sink("close-when-done", target)
)
