local wx = require("wx")
local socket = require("socket")
local mpeg2 = require("mpeg2")

local function expandAll(tree, root)
	tree:Expand(root)
	local child, cookie = tree:GetFirstChild(root)
	
	while cookie ~= 0 do
		expandAll(tree, child)
		child, cookie = tree:GetNextChild(root, cookie)
	end
end

function createMenu()
	-- file
	local fileMenu = wx.wxCreateMenu{
		{wx.wxID_OPEN,   "&Open...\tCtrl-O", "Open"},
		{},
		{wx.wxID_EXIT,   "E&xit\tAlt-X", "Exit Application"},
	}
	
	-- help
	local helpMenu = wx.wxCreateMenu{
		{wx.wxID_ABOUT, "&About", "About"},
	}
	
	-- menu
	local menuBar = wx.wxMenuBar()
	menuBar:Append(fileMenu, "&File")
	menuBar:Append(helpMenu, "&Help")
	
	return menuBar
end

local function createToolBar(frame)
	local toolBar = wx.ToolBar(frame, -1, wx.DefaultPosition, wx.DefaultSize, wx.TB_FLAT + wx.TB_DOCKABLE)
	local bitmapPath = wx.GetCwd() .. "\\bitmaps\\"
	local openBitmap = wx.BitmapFromFile(bitmapPath .. "open.bmp",    wx.BITMAP_TYPE_BMP)
	toolBar:AddTool(wx.ID_OPEN,  openBitmap, wx.NullBitmap, wx.FALSE, wx.Null, "Open")
	toolBar:Realize()
	return toolBar
end

local function openDialog(frame)
	local dialog = wx.Dialog(frame, -1, "Open")
	local sizer = wx.BoxSizer(wx.VERTICAL)
	
	--
	
	local box = wx.BoxSizer(wx.HORIZONTAL)
	local label = wx.StaticText(dialog, -1, "Address", wx.DefaultPosition)
	box:AddWindow(label, 0, wx.ALIGN_CENTRE + wx.ALL, 5)
	local text = wx.TextCtrl(dialog, -1, "")
	box:AddWindow(text, 1, wx.ALIGN_CENTRE + wx.ALL, 5)
	local label = wx.StaticText(dialog, -1, "Port", wx.DefaultPosition)
	box:AddWindow(label, 0, wx.ALIGN_CENTRE + wx.ALL, 5)
	local spin = wx.SpinCtrl(dialog, -1, "")
	spin:SetRange(0, 276447232)
	box:AddWindow(spin, 1, wx.ALIGN_CENTRE + wx.ALL, 5)
	sizer:AddSizer(box, 0, wx.GROW + wx.ALIGN_CENTER_VERTICAL + wx.ALL, 5)
	
	--
	
	local line = wx.StaticLine(dialog, -1)
	sizer:AddWindow(line, 0, wx.GROW + wx.ALIGN_CENTER_VERTICAL + wx.RIGHT + wx.TOP)
	
	--
	
	local box = wx.BoxSizer(wx.HORIZONTAL)
	local btn = wx.Button(dialog, wx.ID_OK, "OK")
	btn:SetDefault()
	box:AddWindow(btn, 0, wx.ALIGN_CENTRE + wx.ALL, 5)
	local btn = wx.Button(dialog, wx.ID_CANCEL, "Cancel")
	box:AddWindow(btn, 0, wx.ALIGN_CENTRE + wx.ALL, 5)
	sizer:AddSizer(box, 0, wx.ALIGN_CENTRE + wx.ALIGN_CENTER_VERTICAL + wx.ALL, 5)
	
	--
	
	dialog:SetSizer(sizer)
	dialog:SetAutoLayout(wx.TRUE)
	sizer:Fit(dialog)
	dialog:Centre()
	local result = dialog:ShowModal()
	
	if result == wx.ID_OK then
		local address = text:GetValue()
		local port = spin:GetValue()
		dialog:Destroy()
		
		if address == "" then
			address = "*"
		end
		
		if port < 0 then
			return nil
		end
		
		return address, port
	else
		dialog:Destroy()
		return nil
	end
end

local count = {}
local listPos = {}
local description = {
	[0] = "PAT",
	[8191] = "Null"
}

local function main()
	local run = true
	
	-- create the frame window
	local frame = wx.Frame(
		wx.Null,
		-1,
		"GUI",
		wx.Point(-1, -1),
		wx.Size(450, 450)
	)
	
	frame:SetMenuBar(createMenu())
	frame:SetToolBar(createToolBar(frame))
	frame:CreateStatusBar(1)
	
	frame:ConnectEvent(wx.ID_OPEN, wx.EVT_COMMAND_MENU_SELECTED, function(event)
		local address, port = openDialog(frame)
		
		if address then
			-- input
			if address ~= "*" then address = socket.dns.toip(address) end
			local inputSocket = socket.udp()
			inputSocket:setsockname(address, port) -- connect to a source
			local packet = mpeg2.TSPacket()
			
			thread.newthread(function()
				while true do
					local data = inputSocket:receive()
					
					if data then
						local dataLength = string.len(data)
						
						for i = 1, dataLength, mpeg2.TSPacket.PACKET_SIZE do
							packet:setData(string.sub(data, i, i + mpeg2.TSPacket.PACKET_SIZE), mpeg2.TSPacket.PACKET_SIZE)
							local pid = packet:getPid()
							
							if not count[pid] then
								-- increment the pos of the existing items
								for k, v in pairs(listPos) do
									listPos[k] = v + 1
								end
								
								count[pid] = 1
								listPos[pid] = list:InsertItem(wx.ListItem())
								list:SetStringItem(listPos[pid], 0, tostring(pid))
								
								if description[pid] then -- add description
									list:SetStringItem(listPos[pid], 1, description[pid])
								else
									list:SetStringItem(listPos[pid], 1, "Unknown")
								end
								
								list:SetStringItem(listPos[pid], 2, "1")
							else
								count[pid] = count[pid] + 1
								list:SetStringItem(listPos[pid], 2, tostring(count[pid]))
							end
						end
					else
						break
					end
				end
			end, {})
		end
	end)
	
	frame:ConnectEvent(wx.ID_EXIT, wx.EVT_COMMAND_MENU_SELECTED, function(event)
		frame:Close()
		run = false
	end)
	
	local splitter = wx.SplitterWindow(frame, -1)
	
    local tree = wx.TreeCtrl(
		splitter,
		-1,
		wx.DefaultPosition,
		wx.DefaultSize,
		wx.TR_LINES_AT_ROOT
	)
	
	local root = tree:AddRoot("TS")
	local pat = tree:AppendItem(root, "PAT")
	tree:AppendItem(pat, "PMT")
	tree:AppendItem(pat, "PMT")
	local pmt = tree:AppendItem(pat, "PMT")
	tree:AppendItem(pmt, "Stream")
	
	expandAll(tree, root)
	
	list = wx.ListCtrl(splitter, -1, wx.DefaultPosition, wx.DefaultSize, wx.LC_REPORT)
	
	-- header
	list:InsertColumnInfo(0, "PID")
	list:InsertColumnInfo(1, "Type")
	list:InsertColumnInfo(2, "Number")
	
	splitter:SplitHorizontally(tree, list)
	
	-- show the frame window
	frame:Centre()
	frame:Show(wx.TRUE)
end

main()
wx.wxGetBaseApp():MainLoop()
