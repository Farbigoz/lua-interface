#include "lua_ulib.h"



// Заглушка функций библиотеки
const struct luaL_Reg luaULib_emptyFuncList[] = {
		{NULL, NULL}
};



void LuaLib_CreateLib(lua_State *L, const char *name, const luaL_Reg *funcList) {
	if (funcList == NULL)
		funcList = luaULib_emptyFuncList;

	// Получение таблицы загруженных библиотек
	luaL_getsubtable(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
	// +1 // Стек: [..., <table: LOADED>]

	// Создание библиотеки
	luaL_newlib(L, funcList);
	// +1 // Стек: [..., <table: LOADED>, <table: library>]

	// Клонирование экземпляра библиотеки
	lua_pushvalue(L, -1);
	// +1 // Стек: [..., <table: LOADED>, <table: library>, <table: library>]

	// Запись библиотеки в таблицу загруженных библиотек
	lua_setfield(L, -3, name);  /* LOADED["interface"] = library */
	// -1 // Стек: [..., <table: LOADED>, <table: library>]

	// Клонирование экземпляра библиотеки
	lua_pushvalue(L, -1);
	// +1 // Стек: [..., <table: LOADED>, <table: library>, <table: library>]

	// Объявление модуля глобальным
	lua_setglobal(L, name);  /* _G["interface"] = library */
	// -1 // Стек: [..., <table: LOADED>, <table: library>]

	// Удаление из стека таблицы загруженных библиотек
	lua_remove(L, -2);
	// -1 // Стек: [..., <table: library>]
}


void LuaLib_GetLib(lua_State *L, const char *name) {
	lua_getglobal(L, name);
}



void LuaLib_GetCreateTable(lua_State *L, const char *name) {
	// Запрос таблицы "name" у объекта
	lua_getfield(L, -1, name);
	// +1 // Стек: [..., <object>, <table: name>]

	// Если таблицы "name" у объекта нет - создание таблицы
	if (lua_isnil(L, -1)) {
		lua_pop(L, 1);
		// -1 // Стек: [..., <object>,]

		lua_createtable(L, 0, 0);
		// +1 // Стек: [..., <object>, <table: name>]

		lua_pushvalue(L, -1);
		// +1 // Стек: [..., <object>, <table: name>, <table: name>]

		lua_setfield(L, -3, name);
		// -1 // Стек: [..., <object>, <table: name>]
	}
}
