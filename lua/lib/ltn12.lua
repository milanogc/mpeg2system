-----------------------------------------------------------------------------
-- LTN12 - Filters, sources, sinks and pumps.
-- LuaSocket toolkit.
-- Author: Diego Nehab
-- RCS ID: $Id: ltn12.lua,v 1.24 2005/01/02 22:44:00 diego Exp $
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
-- Declare module
-----------------------------------------------------------------------------
local string = require("string")
local table = require("table")
local base = require("base")
module("ltn12")

filter = {}
source = {}
sink = {}
pump = {}

-- 2048 seems to be better in windows...
BLOCKSIZE = 2048

-----------------------------------------------------------------------------
-- Filter stuff
-----------------------------------------------------------------------------
-- returns a high level filter that cycles a low-level filter
function filter.cycle(low, ctx, extra)
	base.assert(low)
	return function(chunk)
		local ret
		ret, ctx = low(ctx, chunk, extra)
		return ret
	end
end

-- chains a bunch of filters together
-- (thanks to Wim Couwenberg)
function filter.chain(...) 
	local n = table.getn(arg)
	local top, index = 1, 1
	local retry = ""
	return function(chunk)
		retry = chunk and retry
		while true do 
			if index == top then
				chunk = arg[index](chunk)
				if chunk == "" or top == n then return chunk
				elseif chunk then index = index + 1
				else 
					top = top+1 
					index = top
				end
			else
				chunk = arg[index](chunk or "")
				if chunk == "" then
					index = index - 1
					chunk = retry
				elseif chunk then
					if index == n then return chunk
					else index = index + 1 end
				else base.error("filter returned inappropriate nil") end
			end
		end
	end
end

-----------------------------------------------------------------------------
-- Source stuff
-----------------------------------------------------------------------------
-- create an empty source
local function empty()
	return nil
end

function source.empty()
	return empty
end

-- returns a source that just outputs an error
function source.error(err)
	return function()
		return nil, err
	end
end

-- creates a file source
function source.file(handle, io_err, blocksize) -- milano: added blocksize
	blocksize = blocksize or BLOCKSIZE
	if handle then
		return function()
			local chunk = handle:read(blocksize)
			if not chunk then handle:close() end
			return chunk
		end
	else return source.error(io_err or "unable to open file") end
end

-- turns a fancy source into a simple source
function source.simplify(src)
	base.assert(src)
	return function()
		local chunk, err_or_new = src()
		src = err_or_new or src
		if not chunk then return nil, err_or_new
		else return chunk end
	end
end

-- creates string source
function source.string(s)
	if s then
		local i = 1
		return function()
			local chunk = string.sub(s, i, i+BLOCKSIZE-1)
			i = i + BLOCKSIZE
			if chunk ~= "" then return chunk
			else return nil end
		end
	else return source.empty() end
end

-- creates rewindable source
function source.rewind(src)
	base.assert(src)
	local t = {}
	return function(chunk)
		if not chunk then
			chunk = table.remove(t)
			if not chunk then return src()
			else return chunk end
		else
			table.insert(t, chunk)
		end
	end
end

-- chains a source with a filter
function source.chain(src, f)
	base.assert(src and f)
	local last_in, last_out = "", ""
	return function()
		if last_out == "" then
			while true do
				local err
				last_in, err = src()
				if err then return nil, err end
				last_out = f(last_in)
				if last_out ~= "" then return last_out end
				if not last_in then 
					base.error('filter returned inappropriate ""') 
				end
			end
		elseif last_out then
			last_out = f(last_in and "")
			if last_in and not last_out then
				base.error('filter returned inappropriate nil') 
			end
			if last_out == "" and not last_in then
				base.error(base.tostring(f) .. ' returned inappropriate ""') 
			end
			return last_out
		else
			base.error("source is empty", 2)
		end
	end
end

-- creates a source that produces contents of several sources, one after the
-- other, as if they were concatenated
-- (thanks to Wim Couwenberg)
function source.cat(...)
	local src = table.remove(arg, 1)
	return function()
		while src do
			local chunk, err = src()
			if chunk then return chunk end
			if err then return nil, err end
			src = table.remove(arg, 1)
		end
	end
end

-----------------------------------------------------------------------------
-- Sink stuff
-----------------------------------------------------------------------------
-- creates a sink that stores into a table
function sink.table(t)
	t = t or {}
	local f = function(chunk, err)
		if chunk then table.insert(t, chunk) end
		return 1
	end
	return f, t
end

-- turns a fancy sink into a simple sink
function sink.simplify(snk)
	base.assert(snk)
	return function(chunk, err)
		local ret, err_or_new = snk(chunk, err)
		if not ret then return nil, err_or_new end
		snk = err_or_new or snk
		return 1
	end
end

-- creates a file sink
function sink.file(handle, io_err)
	if handle then
		return function(chunk, err)
			if not chunk then
				handle:close()
				return 1
			else return handle:write(chunk) end
		end
	else return sink.error(io_err or "unable to open file") end
end

-- creates a sink that discards data
local function null()
	return 1
end

function sink.null()
	return null
end

-- creates a sink that just returns an error
function sink.error(err)
	return function()
		return nil, err
	end
end

-- chains a sink with a filter 
function sink.chain(f, snk)
	base.assert(f and snk)
	return function(chunk, err)
		if chunk ~= "" then
			local filtered = f(chunk)
			local done = chunk and ""
			while true do
				local ret, snkerr = snk(filtered, err)
				if not ret then return nil, snkerr end
				if filtered == done then return 1 end
				filtered = f(done)
			end
		else return 1 end
	end
end

-----------------------------------------------------------------------------
-- Pump stuff
-----------------------------------------------------------------------------
-- pumps one chunk from the source to the sink
function pump.step(src, snk)
	local chunk, src_err = src()
	local ret, snk_err = snk(chunk, src_err)
	return chunk and ret and not src_err and not snk_err, src_err or snk_err
end

-- pumps all data from a source to a sink, using a step function
function pump.all(src, snk, step)
	base.assert(src and snk)
	step = step or pump.step
	while true do
		local ret, err = step(src, snk)
		if not ret then return not err, err end
	end
end

-- pumps all data from a source to a sink through the filters (milano)
function pump.chain(...)
	local n = table.getn(arg)
	local src = arg[1]
	local snk = arg[n]
	if n > 2 then
		local t = {}
		for i = 2, table.getn(arg) - 1 do t[i - 1] = arg[i] end
		snk = sink.chain(filter.chain(unpack(t)), snk)
	end
	return pump.all(src, snk)
end

--getmetatable(_M).__index = nil
