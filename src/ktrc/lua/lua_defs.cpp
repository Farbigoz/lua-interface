#include "ktrc/lua/lua_defs.h"


// Функции библиотеки
static const struct luaL_Reg defsLib_func[] = {
		{NULL, NULL}
};



void LuaLib_Defs::InitLib(lua_State *L) {
	// Стек: [...]

	luaState = L;

	LuaLib_CreateLib(luaState, DEFS_STR, defsLib_func);
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

	lua_pop(L, 1);
	// -1 // Стек: [...]
}
