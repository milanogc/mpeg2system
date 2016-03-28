local socket = require("socket")
local pipe   = require("ltn12")
local mpeg2  = require("mpeg2")

local target = socket.udp()
target:setpeername(socket.dns.toip(arg[2]), arg[3])

pipe.pump.chain(
	pipe.source.file(io.open(arg[1], "rb"), nil, 188 * 7),
	socket.sink("close-when-done", target)
)
