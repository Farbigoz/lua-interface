#include "lua_interface.h"


#define LUA_METATABLE_ARS_GEN_LEVEL		(INTERFACE_MU_NAME "." INTERFACE_ARS_GEN_NAME "." INTERFACE_ARS_GEN_LEVEL)
#define LUA_METATABLE_ARS_GEN_GENX		(INTERFACE_MU_NAME "." INTERFACE_ARS_GEN_NAME "." INTERFACE_ARS_GEN_GEN)



typedef struct {
	void		*data;
	uint8_t		*moduleNum;
	uint8_t		genNum;
} InterfaceMuKtrcArsUData;



/**
 * @brief	Lua API функция запроса напряжения частоты генератора АРС
 *
 * @code	x = interface.mu.ktrc[NUM].arsGen.level.FREQ
 *
 * @param	L - Экземпляр Lua
 *
 * @param	Lua_Стек[1] - Userdata "InterfaceMuKtrcArsUData"
 * @param	Lua_Стек[2] - Название частоты
 *
 * @return	Lua_Стек[-1] - Напряжение
 */
int interface_mu_ktrc_arsGen_level__api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto udata = (InterfaceMuKtrcArsUData *) luaL_checkudata(L, 1, LUA_METATABLE_ARS_GEN_LEVEL);
	std::string key = luaL_checkstring(L, 2);

	auto controller = (InterfaceArsGenController *)(udata->data);
	auto level = &(*controller)[*udata->moduleNum].level;


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

/**
 * @brief	Lua API функция установки напряжения частоты генератора АРС
 *
 * @code	interface.mu.ktrc[NUM].arsGen.level.FREQ = x
 *
 * @param	L - Экземпляр Lua
 *
 * @param	Lua_Стек[1] - Userdata "InterfaceMuKtrcArsUData"
 * @param	Lua_Стек[2] - Название частоты
 * @param	Lua_Стек[3] - Напряжение
 *
 * @return	nil
 */
int interface_mu_ktrc_arsGen_level__api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto udata = (InterfaceMuKtrcArsUData *) luaL_checkudata(L, 1, LUA_METATABLE_ARS_GEN_LEVEL);
	std::string key = luaL_checkstring(L, 2);
	uint16_t value = luaL_checkinteger(L, 3);

	auto controller = (InterfaceArsGenController *)(udata->data);
	auto level = &(*controller)[*udata->moduleNum].level;

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
const struct luaL_Reg interface_mu_arsGen_level_functions[] = {
		{"__index", interface_mu_ktrc_arsGen_level__api_getField},			// Запрос значения поля
		{"__newindex", interface_mu_ktrc_arsGen_level__api_setField},		// Установка значения поля
		{NULL, NULL}
};



/**
 * @brief	Lua API функция запроса состояния генератора частоты АРС
 *
 * @code	x = interface.mu.ktrc[NUM].arsGen[n].FREQ
 *
 * @param	L - Экземпляр Lua
 *
 * @param	Lua_Стек[1] - Userdata "InterfaceMuKtrcArsUData"
 * @param	Lua_Стек[2] - Название частоты
 *
 * @return	Lua_Стек[-1] - Состояние
 */
int interface_mu_ktrc_arsGen_gen__api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto udata = (InterfaceMuKtrcArsUData *) luaL_checkudata(L, 1, LUA_METATABLE_ARS_GEN_GENX);
	std::string key = luaL_checkstring(L, 2);

	auto controller = (InterfaceArsGenController *)(udata->data);
	auto gen = &(*controller)[*udata->moduleNum].gen[udata->genNum];

	if (key == INTERFACE_ARS_F75_NAME)				// x = interface.genX.f75
	{
		lua_pushinteger(L, gen->f75);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F125_NAME)		// x = interface.genX.f125
	{
		lua_pushinteger(L, gen->f125);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F175_NAME)		// x = interface.genX.f175
	{
		lua_pushinteger(L, gen->f175);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F225_NAME)		// x = interface.genX.f225
	{
		lua_pushinteger(L, gen->f225);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_NAME)		// x = interface.genX.f275
	{
		lua_pushinteger(L, gen->f275);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F325_NAME)		// x = interface.genX.f325
	{
		lua_pushinteger(L, gen->f325);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_AO_NAME)		// x = interface.genX.f275_ao
	{
		lua_pushinteger(L, gen->f275_ao);
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
 * @brief	Lua API функция установки состояния генератора частоты АРС
 *
 * @code	interface.mu.ktrc[NUM].arsGen[n].FREQ = x
 *
 * @param	L - Экземпляр Lua
 *
 * @param	Lua_Стек[1] - Userdata "InterfaceMuKtrcArsUData"
 * @param	Lua_Стек[2] - Название частоты
 * @param	Lua_Стек[3] - Состояние
 *
 * @return	nil
 */
int interface_mu_ktrc_arsGen_gen__api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto udata = (InterfaceMuKtrcArsUData *) luaL_checkudata(L, 1, LUA_METATABLE_ARS_GEN_GENX);
	std::string key = luaL_checkstring(L, 2);
	uint8_t value;
	if (lua_isinteger(L, 3))
		value = lua_tointeger(L, 3) != 0;
	else
		value = lua_toboolean(L, 3);

	auto controller = (InterfaceArsGenController *)(udata->data);
	auto gen = &(*controller)[*udata->moduleNum].gen[udata->genNum];

	if (key == INTERFACE_ARS_F75_NAME)				// x = interface.genX.f75
	{
		gen->f75 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F125_NAME)		// x = interface.genX.f125
	{
		gen->f125 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F175_NAME)		// x = interface.genX.f175
	{
		gen->f175 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F225_NAME)		// x = interface.genX.f225
	{
		gen->f225 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_NAME)		// x = interface.genX.f275
	{
		gen->f275 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F325_NAME)		// x = interface.genX.f325
	{
		gen->f325 = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else if (key == INTERFACE_ARS_F275_AO_NAME)		// x = interface.genX.f275_ao
	{
		gen->f275_ao = value;
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}

	return 0;
}

// Функции взаимодействия с интерфейсом приёмника ТРЦ3
const struct luaL_Reg interface_arsGen_gen_functions[] = {
		{"__index", interface_mu_ktrc_arsGen_gen__api_getField},			// Запрос значения поля
		{"__newindex", interface_mu_ktrc_arsGen_gen__api_setField},			// Установка значения поля
		{NULL, NULL}
};




void LuaInterface_Mu_Ktrc_Ars::connect_arsGen() {


	// ======================== Метатаблицы ========================

	// Создание метатаблицы КТРЦ
	luaL_newmetatable(luaState, LUA_METATABLE_ARS_GEN_LEVEL);
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_mu_arsGen_level_functions, 0);
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
	





	// Запрос таблицы "mu" у библиотеки
	LuaLib_GetCreateTable(luaState, INTERFACE_MU_NAME);
	// +1 // Стек: [..., <table: library>, <table: mu>]

	// Запрос таблицы "ktrc" у МУ
	LuaLib_GetCreateTable(luaState, INTERFACE_KTRC_NAME);
	// +1 // Стек: [..., <table: library>, <table: mu>, <table: ktrc>]

	// Запрос таблицы "arsGen" у КТРЦ
	LuaLib_GetCreateTable(luaState, INTERFACE_ARS_GEN_NAME);
	// +1 // Стек: [..., <table: library>, <table: mu>, <table: ktrc>, <table: arsGen>]

	// Удаление лишнего из стека
	lua_remove(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table: mu>, <table: arsGen>]
	lua_remove(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table: arsGen>]




	// Создание таблицы уровней частот АРС
	auto map = (InterfaceMuKtrcArsUData *) lua_newuserdata(luaState, sizeof(InterfaceMuKtrcArsUData));
	map->data = &arsGen;
	map->moduleNum = selectedKtrc;
	// +1 // Стек: [..., <table: library>, <table: arsGen>, <userdata: level>]

	// Получение метатаблицы
	luaL_getmetatable(luaState, LUA_METATABLE_ARS_GEN_LEVEL);
	// +1 // Стек: [..., <table: library>, <table: arsGen>, <userdata: level>, <metatable>]

	// Установка метатаблицы в пользовательские данные
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table: arsGen>, <userdata: level>]

	// Добавление в таблицу полей генератора АРС - таблицы уровней частот АРС
	lua_setfield(luaState, -2, INTERFACE_ARS_GEN_LEVEL);
	// -2 // Стек: [..., <table: library>, <table: arsGen>]



	// Добавление генераторов АРС
	for (int i = 0; i < ARS_GEN_NUM; i++) {
		// Создание таблицы уровней частот АРС
		auto gen = (InterfaceMuKtrcArsUData *) lua_newuserdata(luaState, sizeof(InterfaceMuKtrcArsUData));
		gen->data = &arsGen;
		gen->moduleNum = selectedKtrc;
		gen->genNum = i;
		// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <userdata: gen[i]>]

		// Получение метатаблицы
		luaL_getmetatable(luaState, LUA_METATABLE_ARS_GEN_GENX);
		// +1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <userdata: gen[i]>, <metatable>]

		// Установка метатаблицы в пользовательские данные
		lua_setmetatable(luaState, -2);
		// -1 // Стек: [..., <table: library>, <table: ktrc>, <table: arsGen>, <userdata: gen[i]>]

		// Добавление пользовательских данных в таблицу генераторов
		lua_rawseti(luaState, -2, i + 1);
		// -1 // Стек: [..., <table: library>, <table: ktrc>,  <table: arsGen>]
	}

	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

}


