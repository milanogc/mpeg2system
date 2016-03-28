local socket = require("socket")
local pipe   = require("ltn12")
local mpeg2  = require("mpeg2")

local source = socket.udp()
source:setpeername(socket.dns.toip(arg[1]), tonumber(arg[2]))

local target = socket.udp()
target:setpeername(socket.dns.toip(arg[3]), tonumber(arg[4]))

pipe.pump.chain(
	socket.source("keep-open", source),
	mpeg2.filter.mpe("eth0"),
	socket.sink("close-when-done", target)
)

mpeg2.ts.multiplexer(manager, src1, src2, ..., srcN)

