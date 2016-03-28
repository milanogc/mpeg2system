-- filter selected pids from an input file and save it on an output file
-- filter *input file* *output file*

local mpeg2 = require("mpeg2")
local pipe = require("ltn12")
local socket = require("socket")

-- input file -> filter -> output file

local ret, msg = pipe.pump.chain(
	-- source
	pipe.source.file(io.open(arg[1], "rb"), nil, mpeg2.TSPacket.PACKET_SIZE),
	
	-- filter
	mpeg2.filter.discarder(8191), -- it accepts multiple args
	
	-- sink
	pipe.sink.file(io.open(arg[2], "wb"))
)

if not ret then print(msg) end
