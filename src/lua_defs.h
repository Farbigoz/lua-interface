#ifndef __LUA_DEFS_H__
#define __LUA_DEFS_H__

#include <string>
#include <map>

#include "defs/trc3.h"
#include "defs/ars.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <lua.h>

#ifdef __cplusplus
}
#endif




static const std::map	<std::string, int>DEFS_LIB_FIELDS = {
		{"F_420_HZ",		F_420_HZ},
		{"F_480_HZ",		F_480_HZ},
		{"F_565_HZ",		F_565_HZ},
		{"F_720_HZ",		F_720_HZ},
		{"F_780_HZ",		F_780_HZ},

		{"F_8_HZ",			F_8_HZ},
		{"F_12_HZ",			F_12_HZ},
};




/**
 * @brief	Создание библиотеки
 */
int luaopen_defs(lua_State *L);




#endif /* __LUA_DEFS_H__ */