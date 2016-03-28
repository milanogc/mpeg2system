extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <stdio.h>

int tolua_mpeg2_open(lua_State* tolua_S);

extern "C" int luaopen_mpeg2(lua_State *L) {
    tolua_mpeg2_open(L);
    return 1;
}
