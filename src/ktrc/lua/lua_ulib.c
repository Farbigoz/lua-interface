#include "ktrc/lua/lua_ulib.h"



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