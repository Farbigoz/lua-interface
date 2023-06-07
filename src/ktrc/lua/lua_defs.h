#ifndef __LUA_DEFS_H__
#define __LUA_DEFS_H__

#include <string>
#include <map>

#include "ktrc/defs/trc3.h"
#include "ktrc/defs/ars.h"

#include "lua_ulib.h"



#define DEFS_STR	"defs"



static const std::map	<std::string, int> DEFS_LIB_FIELDS = {
		{"F_420_HZ",		F_420_HZ},
		{"F_480_HZ",		F_480_HZ},
		{"F_565_HZ",		F_565_HZ},
		{"F_720_HZ",		F_720_HZ},
		{"F_780_HZ",		F_780_HZ},

		{"F_8_HZ",			F_8_HZ},
		{"F_12_HZ",			F_12_HZ},

		{"MAX_TIME",		LUA_LIB_MAX_TIME}
};



class LuaLib_Defs {
private:
	lua_State *luaState;

public:
	void InitLib(lua_State *L);
};



#endif /* __LUA_DEFS_H__ */