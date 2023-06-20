#include "lua_interface.h"


#define LUA_METATABLE_TRC3_GEN		(INTERFACE_KTRC_NAME "." INTERFACE_TRC3_GEN_NAME)
#define LUA_METATABLE_TRC3_REC		(INTERFACE_KTRC_NAME "." INTERFACE_TRC3_REC_NAME)


/**
 * @brief	Lua API функция запроса значения поля генератора ТРЦ3
 *
 * @code	x = interface.ktrc.trc3Gen.FIELD
 *
 * @param	L - Экземпляр Lua
 *
 * @param	Lua_Стек[1] - Userdata "InterfaceTrc3GenStruct"
 * @param	Lua_Стек[2] - Название поля
 *
 * @return	Lua_Стек[-1] - Значение поля
 */
int interface_ktrc_trc3Gen__api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto trc3Gen = *((InterfaceTrc3GenStruct **) luaL_checkudata(L, 1, LUA_METATABLE_TRC3_GEN));
	std::string key = luaL_checkstring(L, 2);

	if (key == INTERFACE_TRC3_GEN_LEVEL)			// x = interface.level
	{
		lua_pushinteger(L, trc3Gen->level);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_TRC3_GEN_CARRIER)		// x = interface.carrier
	{
		lua_pushinteger(L, trc3Gen->carrier);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_TRC3_GEN_MOD)			// x = interface.mod
	{
		lua_pushinteger(L, trc3Gen->mod);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else
	{
		lua_pushnil(L);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <nil(return)>]
	}

	return 1;	// Возвращаемых элементов - 1
}

/**
 * @brief	Lua API функция установки значения поля генератора ТРЦ3
 *
 * @code	interface.ktrc.trc3Gen.FIELD = x
 *
 * @param	L - Экземпляр Lua
 *
 * @param	Lua_Стек[1] - Userdata "InterfaceTrc3GenStruct"
 * @param	Lua_Стек[2] - Название поля
 * @param	Lua_Стек[3] - Значение поля
 *
 * @return	nil
 */
int interface_ktrc_trc3Gen__api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto trc3Gen = *((InterfaceTrc3GenStruct **) luaL_checkudata(L, 1, LUA_METATABLE_TRC3_GEN));
	std::string key = luaL_checkstring(L, 2);

	if (key == INTERFACE_TRC3_GEN_LEVEL)			// interface.level = x
	{
		uint8_t value = luaL_checkinteger(L, 3);
		trc3Gen->level = value;
	}
	else if (key == INTERFACE_TRC3_GEN_CARRIER)		// interface.carrier = x
	{
		uint8_t value = luaL_checkinteger(L, 3);
		trc3Gen->carrier = (TTrc3FreqNum)value;
	}
	else if (key == INTERFACE_TRC3_GEN_MOD)			// interface.mod = x
	{
		uint8_t value = luaL_checkinteger(L, 3);
		trc3Gen->mod = (TTrc3ModFreqNum)value;

	}

	return 0;	// Возвращаемых элементов - 0
}

// Функции взаимодействия с интерфейсом генератора ТРЦ3
const struct luaL_Reg interface_trc3Gen_functions[] = {
		{"__index", interface_ktrc_trc3Gen__api_getField},			// Запрос значения поля
		{"__newindex", interface_ktrc_trc3Gen__api_setField},		// Установка значения поля
		{NULL, NULL}
};

/**
 * @brief	Инициализация интерфейса генератора ТРЦ3
 * @note	На вершине стека должна быть таблица для записи в неё интерфейса (библиотека = таблица)
 */
void LuaInterface_Ktrc_Trc3::connect_trc3Gen() {
	// Стек: [..., <table: library>]

	trc3Gen = {0, };

	// ======================== Метатаблицы ========================

	// Создание метатаблицы интерфейса генератора ТРЦ
	luaL_newmetatable(luaState, LUA_METATABLE_TRC3_GEN);
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_trc3Gen_functions, 0);
	// ~~ // Стек: [..., <table: library>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// =============================================================


	// Запрос таблицы "ktrc" у библиотеки
	LuaLib_GetCreateTable(luaState, INTERFACE_KTRC_NAME);
	// +1 // Стек: [..., <table: library>, <table: ktrc>]


	// Создание пользовательских данных
	auto map = (void **)lua_newuserdata(luaState, sizeof(size_t));
	*map = &trc3Gen;
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <userdata: trc3Gen>]

	// Получение метатаблицы интерфейса генератора ТРЦ
	luaL_getmetatable(luaState, LUA_METATABLE_TRC3_GEN);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <userdata: trc3Gen>, <metatable>]

	// Установка метатаблицы в пользовательские данные
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table: ktrc>, <userdata: trc3Gen>]

	// Установка пользовательских данных как поле библиотеки
	lua_setfield(luaState, -2, INTERFACE_TRC3_GEN_NAME);
	// -1 // Стек: [..., <table: library>, <table: ktrc>]

	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]
}







/**
 * @brief	Lua API функция запроса значения поля приёмника ТРЦ3
 *
 * @code	x = interface.ktrc.trc3Rec.FIELD
 *
 * @param	L - Экземпляр Lua
 *
 * @param	Lua_Стек[1] - Userdata "InterfaceTrc3GenStruct"
 * @param	Lua_Стек[2] - Название поля
 *
 * @return	Lua_Стек[-1] - Значение поля
 */
int interface_ktrc_trc3Rec__api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto trc3Rec = *((InterfaceTrc3RecStruct::RecStruct **) luaL_checkudata(L, 1, LUA_METATABLE_TRC3_REC));
	std::string key = luaL_checkstring(L, 2);

	if (key == INTERFACE_TRC3_REC_LEVEL)			// x = interface[i].level
	{
		lua_pushinteger(L, trc3Rec->level);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_TRC3_REC_CARRIER)		// x = interface[i].carrier
	{
		lua_pushinteger(L, trc3Rec->carrier);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_TRC3_REC_MOD)			// x = interface[i].mod
	{
		lua_pushinteger(L, trc3Rec->mod);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_TRC3_REC_TC)			// interface[i].mod = x
	{
		lua_pushinteger(L, trc3Rec->tc);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else
	{
		lua_pushnil(L);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <nil(return)>]
	}

	return 1;	// Возвращаемых элементов - 1
}

/**
 * @brief	Lua API функция установки значения поля приёмника ТРЦ3
 *
 * @code	interface.ktrc.trc3Rec.FIELD = x
 *
 * @param	L - Экземпляр Lua
 *
 * @param	Lua_Стек[1] - Userdata "InterfaceTrc3GenStruct"
 * @param	Lua_Стек[2] - Название поля
 * @param	Lua_Стек[3] - Значение поля
 *
 * @return	nil
 */
int interface_ktrc_trc3Rec__api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto trc3Rec = *((InterfaceTrc3RecStruct::RecStruct **) luaL_checkudata(L, 1, LUA_METATABLE_TRC3_REC));
	std::string key = luaL_checkstring(L, 2);

	if (key == INTERFACE_TRC3_REC_LEVEL)			// interface[i].level = x
	{
		uint8_t value = luaL_checkinteger(L, 3);
		trc3Rec->level = value;
	}
	else if (key == INTERFACE_TRC3_REC_CARRIER)		// interface[i].carrier = x
	{
		uint8_t value = luaL_checkinteger(L, 3);
		trc3Rec->carrier = (TTrc3FreqNum)value;
	}
	else if (key == INTERFACE_TRC3_REC_MOD)			// interface[i].mod = x
	{
		uint8_t value = luaL_checkinteger(L, 3);
		trc3Rec->mod = (TTrc3ModFreqNum)value;
	}

	return 0;	// Возвращаемых элементов - 0
}

// Функции взаимодействия с интерфейсом приёмника ТРЦ3
const struct luaL_Reg interface_trc3Rec_functions[] = {
		{"__index", interface_ktrc_trc3Rec__api_getField},			// Запрос значения поля
		{"__newindex", interface_ktrc_trc3Rec__api_setField},		// Установка значения поля
		{NULL, NULL}
};

/**
 * @brief	Инициализация интерфейса приёмников ТРЦ3
 * @note	На вершине стека должна быть таблица для записи в неё интерфейса (библиотека = таблица)
 */
void LuaInterface_Ktrc_Trc3::connect_trc3Rec() {
	// Стек: [..., <table: library>]

	trc3Rec = {0, };

	// ======================== Метатаблицы ========================

	// Создание метатаблицы для приёмников
	luaL_newmetatable(luaState, LUA_METATABLE_TRC3_REC);
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_trc3Rec_functions, 0);
	// ~~ // Стек: [..., <table: library>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// =============================================================


	// Запрос таблицы "ktrc" у библиотеки
	LuaLib_GetCreateTable(luaState, INTERFACE_KTRC_NAME);
	// +1 // Стек: [..., <table: library>, <table: ktrc>]


	// Создание таблицы приёмников
	lua_createtable(luaState, INTERFACE_TRC3_REC_COUNT, 0);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: trc3Rec>]

	// Заполнение массива приёмников
	for (int i = 0; i < INTERFACE_TRC3_REC_COUNT; i++) {

		// Создание пользовательских данных
		auto map = (void **) lua_newuserdata(luaState, sizeof(size_t));
		*map = &trc3Rec.rec[i];
		// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: trc3Rec>, <userdata: trc3Rec[i]>]

		// Получение метатаблицы
		luaL_getmetatable(luaState, LUA_METATABLE_TRC3_REC);
		// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: trc3Rec>, <userdata: trc3Rec[i]>, <metatable>]

		// Установка метатаблицы в пользовательские данные
		lua_setmetatable(luaState, -2);
		// -1 // Стек: [..., <table: library>, <table: ktrc>, <table: trc3Rec>, <userdata: trc3Rec[i]>]

		// Добавление пользовательских данных в таблицу приёмников
		lua_rawseti(luaState, -2, i + 1);
		// -1 // Стек: [..., <table: library>, <table: ktrc>,  <table: trc3Rec>]
	}

	// Установка таблицы как поля библиотеки
	lua_setfield(luaState, -2, INTERFACE_TRC3_REC_NAME);
	// -1 // Стек: [..., <table: library>, <table: ktrc>]

	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]
}