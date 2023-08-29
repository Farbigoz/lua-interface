#include "lua_interface.h"


#define LUA_METATABLE_MU_KTRC		(INTERFACE_MU_NAME "." INTERFACE_KTRC_NAME)



/**
 * @brief	Lua API функция запроса КТРЦ под определённым номером
 *
 * @code	interface.mu.ktrc[NUM]...
 *
 * @param	L - Экземпляр Lua
 *
 * @param	Lua_Стек[1] - Table "ktrc"
 * @param	Lua_Стек[2] - Номер КТРЦ
 *
 * @return	Lua_Стек[-1] - Table "ktrc"
 */
int interface_ktrc__api_getField(lua_State *L) {
	// Стек: [<table(arg1): ktrc>, <key(arg2)>]

	if (lua_isnumber(L, 2))
	{
		lua_getmetatable(L, -2);
		// +1 // Стек: [<table(arg1): ktrc>, <key(arg2)>, <metatable>]

		lua_getfield(L, -1, INTERFACE_KTRC_NAME);
		// +1 // Стек: [<table(arg1): ktrc>, <key(arg2)>, <metatable>, <userdata: ktrc>]

		auto selectedKtrcNum = (uint8_t *) lua_touserdata(L, -1);
		uint8_t ktrcNumber = luaL_checkinteger(L, 2);

		*selectedKtrcNum = ktrcNumber;

		// Возвращение пользовательских данных
		lua_pushvalue(L, 1);
		// +1 // Стек: [<table(arg1): ktrc>, <key(arg2)>, <metatable>, <userdata: ktrc>, <table(ret1): ktrc>]
	}
	else
	{
		lua_pushnil(L);
		// +1 // Стек: [<table(arg1): ktrc>, <key(arg2)>, <nil>]
	}

	return 1;	// Возвращаемых элементов - 1
}





// Функции запроса КТРЦ по индексу
const struct luaL_Reg interface_mu_ktrc_functions[] = {
		{"__index", interface_ktrc__api_getField},			// Запрос значения поля
		//{"__newindex", interface_ktrc_arsGen_level__api_setField},		// Установка значения поля
		{NULL, NULL}
};







void LuaInterface_Mu_Ktrc::connect_ktrc() {
	// Стек: [..., <table: library>]



	// ======================== Метатаблицы ========================

	// Создание метатаблицы КТРЦ
	luaL_newmetatable(luaState, LUA_METATABLE_MU_KTRC);
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_mu_ktrc_functions, 0);
	// ~~ // Стек: [..., <table: library>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]




	// Запрос таблицы "mu" у библиотеки
	LuaLib_GetCreateTable(luaState, INTERFACE_MU_NAME);
	// +1 // Стек: [..., <table: library>, <table: mu>]


	// Запрос таблицы "ktrc" у МУ
	lua_getfield(luaState, -1, INTERFACE_KTRC_NAME);
	// +1 // Стек: [..., <table: library>, <table: mu>, <table: ktrc>]

	// Если польз. данных "ktrc" у МУ нет - создание
	if (!lua_istable(luaState, -1)) {
		lua_pop(luaState, 1);
		// -1 // Стек: [..., <table: library>, <table: mu>]

		// Создание таблицы "ktrc"
		lua_createtable(luaState, 0, 0);
		// +1 // Стек: [..., <table: library>, <table: mu>, <table: ktrc>]

		// Получение метатаблицы
		luaL_getmetatable(luaState, LUA_METATABLE_MU_KTRC);
		// +1 // Стек: [..., <table: library>, <table: mu>, <table: ktrc>, <metatable>]

		// Создание пользовательских данных с номером выбранного КТРЦ
		auto map = (uint8_t *) lua_newuserdata(luaState, sizeof(uint8_t));
		*map = 0;
		// +1 // Стек: [..., <table: library>, <table: mu>, <table: ktrc>, <metatable>, <userdata: ktrc>]

		// Запись пользовательских данных в метатаблицу
		lua_setfield(luaState, -2, INTERFACE_KTRC_NAME);
		// +1 // Стек: [..., <table: library>, <table: mu>, <table: ktrc>, <metatable>]

		// Установка метатаблицы в таблицу "ktrc"
		lua_setmetatable(luaState, -2);
		// -1 // Стек: [..., <table: library>, <table: mu>, <table: ktrc>]

		// Клонирование таблицы "ktrc"
		lua_pushvalue(luaState, -1);
		// +1 // Стек: [..., <table: library>, <table: mu>, <table: ktrc>, <table: ktrc>]

		// Добавление таблицы "ktrc" в МУ
		lua_setfield(luaState, -3, INTERFACE_KTRC_NAME);
		// -1 // Стек: [..., <table: library>, <table: mu>, <table: ktrc>]
	}

	// Удаление таблицы МУ из стека
	lua_remove(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table: ktrc>]

	// Запрос метатаблицы у таблицы КТРЦ
	lua_getmetatable(luaState, -1);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <metatable>]

	// Запрос поля (пользовательских данных) у метатаблицы
	lua_getfield(luaState, -1, INTERFACE_KTRC_NAME);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <metatable>, <userdata: ktrc>]

	// Установка указателя на указатель номера выбранного КТРЦ
	selectedKtrc = (uint8_t *)lua_touserdata(luaState, -1);

	// Удаление из стека лишнего
	lua_pop(luaState, 3);
	// -1 // Стек: [..., <table: library>]
}