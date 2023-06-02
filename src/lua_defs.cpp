#include "lua_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

#ifdef __cplusplus
}
#endif


// Функции библиотеки
static const struct luaL_Reg defsLib_func[] = {
		{NULL, NULL}
};



int luaopen_defs(lua_State *L) {
	// Стек: [<string(arg1): lib name>]

	// Создание библиотеки
	luaL_newlib(L, defsLib_func);
	// +1 // Стек: [..., <table: library>]


	auto it = DEFS_LIB_FIELDS.begin();
	for (; it != DEFS_LIB_FIELDS.end(); it++) {
		// Добавление значения в стек
		lua_pushinteger(L, it->second);
		// +1 // Стек: [..., <table: library>, <int:val>]

		// Установка значения как поля библиотеки
		lua_setfield(L, -2, it->first.c_str());
		// -1 // Стек: [..., <table: library>]
	}


	return 1;
}