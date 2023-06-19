#include "lua_interface.h"


#define LUA_METATABLE_ARS_GEN_LEVEL		(INTERFACE_KTRC_STR "." INTERFACE_ARS_GEN_NAME "." INTERFACE_ARS_GEN_LEVEL)
#define LUA_METATABLE_ARS_GEN_GENX		(INTERFACE_KTRC_STR "." INTERFACE_ARS_GEN_NAME "." INTERFACE_ARS_GEN_GEN)




int interface_ktrc_arsGen_level__api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto level = *((InterfaceArsGenStruct::LevelStruct **) luaL_checkudata(L, 1, LUA_METATABLE_ARS_GEN_LEVEL));
	std::string key = luaL_checkstring(L, 2);

	if (key == INTERFACE_ARS_F75_NAME)				// x = interface.level.f75
	{
		lua_pushinteger(L, level->f75);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F125_NAME)		// x = interface.level.f125
	{
		lua_pushinteger(L, level->f125);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F175_NAME)		// x = interface.level.f175
	{
		lua_pushinteger(L, level->f175);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F225_NAME)		// x = interface.level.f225
	{
		lua_pushinteger(L, level->f225);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_NAME)		// x = interface.level.f275
	{
		lua_pushinteger(L, level->f275);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F325_NAME)		// x = interface.level.f325
	{
		lua_pushinteger(L, level->f325);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_AO_NAME)
	{
		lua_pushinteger(L, level->f275_ao);			// x = interface.level.f275_ao
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else
	{
		lua_pushnil(L);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <nil(return)>]
	}

	return 1;	// Возвращаемых элементов - 1
}

int interface_ktrc_arsGen_level__api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto level = *((InterfaceArsGenStruct::LevelStruct **) luaL_checkudata(L, 1, LUA_METATABLE_ARS_GEN_LEVEL));
	std::string key = luaL_checkstring(L, 2);
	uint16_t value = luaL_checkinteger(L, 3);

	if (key == INTERFACE_ARS_F75_NAME)				// interface.level.f75 = x
	{
		level->f75 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F125_NAME)		// interface.level.f125 = x
	{
		level->f125 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F175_NAME)		// interface.level.f175 = x
	{
		level->f175 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F225_NAME)		// interface.level.f225 = x
	{
		level->f225 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_NAME)		// interface.level.f275 = x
	{
		level->f275 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F325_NAME)		// interface.level.f325 = x
	{
		level->f325 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_AO_NAME)
	{
		level->f275_ao = value;
	}

	return 0;	// Возвращаемых элементов - 0
}

// Функции взаимодействия с интерфейсом приёмника ТРЦ3
const struct luaL_Reg interface_arsGen_level_functions[] = {
		{"__index", interface_ktrc_arsGen_level__api_getField},			// Запрос значения поля
		{"__newindex", interface_ktrc_arsGen_level__api_setField},		// Установка значения поля
		{NULL, NULL}
};


int interface_ktrc_arsGen_gen__api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto gen = *((InterfaceArsGenMapType **) luaL_checkudata(L, 1, LUA_METATABLE_ARS_GEN_GENX));
	std::string key = luaL_checkstring(L, 2);

	if (key == INTERFACE_ARS_F75_NAME)				// x = interface.genX.f75
	{
		lua_pushinteger(L, (*gen)[F_075_HZ]);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F125_NAME)		// x = interface.genX.f125
	{
		lua_pushinteger(L, (*gen)[F_125_HZ]);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F175_NAME)		// x = interface.genX.f175
	{
		lua_pushinteger(L, (*gen)[F_175_HZ]);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F225_NAME)		// x = interface.genX.f225
	{
		lua_pushinteger(L, (*gen)[F_225_HZ]);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_NAME)		// x = interface.genX.f275
	{
		lua_pushinteger(L, (*gen)[F_275_HZ]);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F325_NAME)		// x = interface.genX.f325
	{
		lua_pushinteger(L, (*gen)[F_325_HZ]);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_AO_NAME)		// x = interface.genX.f275_ao
	{
		lua_pushinteger(L, (*gen)[F_275_HZ_AO]);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else
	{
		lua_pushnil(L);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <nil(return)>]
	}

	return 1;	// Возвращаемых элементов - 1
}

int interface_ktrc_arsGen_gen__api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto gen = *((InterfaceArsGenMapType **) luaL_checkudata(L, 1, LUA_METATABLE_ARS_GEN_GENX));
	std::string key = luaL_checkstring(L, 2);
	uint8_t value;
	if (lua_isinteger(L, 3))
		value = lua_tointeger(L, 3) != 0;
	else
		value = lua_toboolean(L, 3);

	if (key == INTERFACE_ARS_F75_NAME)				// x = interface.genX.f75
	{
		(*gen)[F_075_HZ] = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F125_NAME)		// x = interface.genX.f125
	{
		(*gen)[F_125_HZ] = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F175_NAME)		// x = interface.genX.f175
	{
		(*gen)[F_175_HZ] = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F225_NAME)		// x = interface.genX.f225
	{
		(*gen)[F_225_HZ] = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_NAME)		// x = interface.genX.f275
	{
		(*gen)[F_275_HZ] = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F325_NAME)		// x = interface.genX.f325
	{
		(*gen)[F_325_HZ] = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_AO_NAME)		// x = interface.genX.f275_ao
	{
		(*gen)[F_275_HZ_AO] = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}

	return 0;
}

// Функции взаимодействия с интерфейсом приёмника ТРЦ3
const struct luaL_Reg interface_arsGen_gen_functions[] = {
		{"__index", interface_ktrc_arsGen_gen__api_getField},			// Запрос значения поля
		{"__newindex", interface_ktrc_arsGen_gen__api_setField},		// Установка значения поля
		{NULL, NULL}
};


/**
 * @brief	Инициализация интерфейса генератора АРС
 * @note	На вершине стека должна быть таблица для записи в неё интерфейса (библиотека = таблица)
 */
void LuaInterface_Ktrc_Ars::connect_arsGen() {
	// Стек: [..., <table: library>]

	arsGen = {0, };

	// ======================== Метатаблицы ========================

	// Создание метатаблицы уровней частот АРС
	luaL_newmetatable(luaState, LUA_METATABLE_ARS_GEN_LEVEL);
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_arsGen_level_functions, 0);
	// ~~ // Стек: [..., <table: library>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// Создание метатаблицы управления генераторами АРС
	luaL_newmetatable(luaState, LUA_METATABLE_ARS_GEN_GENX);
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_arsGen_gen_functions, 0);
	// ~~ // Стек: [..., <table: library>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// =============================================================


	// Запрос поля "ktrc" у библиотеки
	LuaLib_GetCreateTable(luaState, INTERFACE_KTRC_STR);
	// +1 // Стек: [..., <table: library>, <table: ktrc>]



	// Создание таблицы полей генератора АРС
	lua_createtable(luaState, 0, 3);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>]



	// Добавление в стек названия таблицы уровней частот АРС
	lua_pushstring(luaState, INTERFACE_ARS_GEN_LEVEL);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: level>]

	// Создание таблицы уровней частот АРС
	auto map = (void **) lua_newuserdata(luaState, sizeof(size_t));
	*map = &arsGen.level;
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: level>, <userdata: level>]

	// Получение метатаблицы
	luaL_getmetatable(luaState, LUA_METATABLE_ARS_GEN_LEVEL);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: level>, <userdata: level>, <metatable>]

	// Установка метатаблицы в пользовательские данные
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: level>, <userdata: level>]

	// Добавление в таблицу полей генератора АРС - таблицы уровней частот АРС
	lua_settable(luaState, -3);
	// -2 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>]


	// Добавление в стек названия таблицы состояния первого генератора
	lua_pushstring(luaState, INTERFACE_ARS_GEN_GEN1);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: gen1>]

	// Создание таблицы уровней частот АРС
	auto gen1 = (void **) lua_newuserdata(luaState, sizeof(size_t));
	*gen1 = &arsGen.gen1;
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: gen1>, <userdata: gen1>]

	// Получение метатаблицы
	luaL_getmetatable(luaState, LUA_METATABLE_ARS_GEN_GENX);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: gen1>, <userdata: gen1>, <metatable>]

	// Установка метатаблицы в пользовательские данные
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: gen1>, <userdata: gen1>]

	// Добавление в таблицу полей генератора АРС - таблицы уровней частот АРС
	lua_settable(luaState, -3);
	// -2 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>]


	// Добавление в стек названия таблицы состояния первого генератора
	lua_pushstring(luaState, INTERFACE_ARS_GEN_GEN2);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: gen2>]

	// Создание таблицы уровней частот АРС
	auto gen2 = (void **) lua_newuserdata(luaState, sizeof(size_t));
	*gen2 = &arsGen.gen2;
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: gen2>, <userdata: gen2>]

	// Получение метатаблицы
	luaL_getmetatable(luaState, LUA_METATABLE_ARS_GEN_GENX);
	// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: gen2>, <userdata: gen2>, <metatable>]

	// Установка метатаблицы в пользовательские данные
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <string: gen2>, <userdata: gen2>]

	// Добавление в таблицу полей генератора АРС - таблицы уровней частот АРС
	lua_settable(luaState, -3);
	// -2 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>]




	// Установка таблицы уровней частот АРС как поля библиотеки
	lua_setfield(luaState, -2, INTERFACE_ARS_GEN_NAME);
	// -1 // Стек: [..., <table: library>, <table: ktrc>]

	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]
}