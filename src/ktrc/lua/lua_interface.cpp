#include "iostream"

#include "ktrc/lua/lua_interface.h"



// Вывод стека Lua
void dumpstack (lua_State *L);




// --------------------------------------------- Интерфейс генератора ТРЦ3 ---------------------------------------------

/**
 * @brief	Callback API функция запроса значения поля генератора ТРЦ3
 *
 * @param	[1] = <userdata> - Интерфейс пользовательских данных
 * @param	[2] = <string>   - Название поля
 *
 * @return	[1] = <number>   - Значение поля
 */
int interface_trc3Gen_api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto trc3Gen = *((InterfaceTrc3GenStruct **) luaL_checkudata(L, 1, INTERFACE_NAME(INTERFACE_TRC3_GEN_NAME)));
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
 * @brief	Callback API функция установки значения поля генератора ТРЦ3
 *
 * @param	[1] = <userdata> - Интерфейс пользовательских данных
 * @param	[2] = <string>   - Название поля
 * @param	[3] = <number>   - Значение поля
 *
 * @return	<nil>
 */
int interface_trc3Gen_api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto trc3Gen = *((InterfaceTrc3GenStruct **) luaL_checkudata(L, 1, INTERFACE_NAME(INTERFACE_TRC3_GEN_NAME)));
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
		{"__index", interface_trc3Gen_api_getField},			// Запрос значения поля
		{"__newindex", interface_trc3Gen_api_setField},		// Установка значения поля
		{NULL, NULL}
};

/**
 * @brief	Инициализация интерфейса генератора ТРЦ3
 * @note	На вершине стека должна быть таблица для записи в неё интерфейса (библиотека = таблица)
 */
void LuaLib_Interface::init_trc3Gen() {
	// Стек: [..., <table: library>]

	trc3Gen = {0, };

	// ======================== Метатаблицы ========================

	// Создание метатаблицы интерфейса генератора ТРЦ
	luaL_newmetatable(luaState, INTERFACE_NAME(INTERFACE_TRC3_GEN_NAME));
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_trc3Gen_functions, 0);
	// ~~ // Стек: [..., <table: library>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// =============================================================

	// Создание пользовательских данных
	auto map = (void **)lua_newuserdata(luaState, sizeof(size_t));
	*map = &trc3Gen;
	// +1 // Стек: [..., <table: library>, <userdata>]

	// Получение метатаблицы интерфейса генератора ТРЦ
	luaL_getmetatable(luaState, INTERFACE_NAME(INTERFACE_TRC3_GEN_NAME));
	// +1 // Стек: [..., <table: library>, <userdata>, <metatable>]

	// Установка метатаблицы в пользовательские данные
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <userdata>]

	// Установка пользовательских данных как поле библиотеки
	lua_setfield(luaState, -2, INTERFACE_TRC3_GEN_NAME);
	// -1 // Стек: [..., <table: library>]
}


// --------------------------------------------- Интерфейс приёмников ТРЦ3 ---------------------------------------------

/**
 * @brief	Callback API функция запроса значения поля приёмника ТРЦ3
 *
 * @param	[1] = <userdata> - Интерфейс пользовательских данных
 * @param	[2] = <string>   - Название поля
 *
 * @return	[1] = <number>   - Значение поля
 */
int interface_trc3Rec_api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto trc3Rec = *((InterfaceTrc3RecStruct::RecStruct **) luaL_checkudata(L, 1, INTERFACE_NAME(INTERFACE_TRC3_REC_NAME)));
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
 * @brief	Callback API функция установки значения поля приёмника ТРЦ3
 *
 * @param	[1] = <userdata> - Интерфейс пользовательских данных
 * @param	[2] = <string>   - Название поля
 * @param	[3] = <number>   - Значение поля
 *
 * @return	<nil>
 */
int interface_trc3Rec_api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto trc3Rec = *((InterfaceTrc3RecStruct::RecStruct **) luaL_checkudata(L, 1, INTERFACE_NAME(INTERFACE_TRC3_REC_NAME)));
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
		{"__index", interface_trc3Rec_api_getField},			// Запрос значения поля
		{"__newindex", interface_trc3Rec_api_setField},		// Установка значения поля
		{NULL, NULL}
};

/**
 * @brief	Инициализация интерфейса приёмников ТРЦ3
 * @note	На вершине стека должна быть таблица для записи в неё интерфейса (библиотека = таблица)
 */
void LuaLib_Interface::init_trc3Rec() {
	// Стек: [..., <table: library>]

	trc3Rec = {0, };

	// ======================== Метатаблицы ========================

	// Создание метатаблицы для приёмников
	luaL_newmetatable(luaState, INTERFACE_NAME(INTERFACE_TRC3_REC_NAME));
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_trc3Rec_functions, 0);
	// ~~ // Стек: [..., <table: library>, <userdata>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// =============================================================

	// Создание таблицы приёмников
	lua_createtable(luaState, INTERFACE_TRC3_REC_COUNT, 0);
	// +1 // Стек: [..., <table: library>, <table>]

	// Заполнение массива приёмников
	for (int i = 0; i < INTERFACE_TRC3_REC_COUNT; i++) {

		// Создание пользовательских данных
		auto map = (void **) lua_newuserdata(luaState, sizeof(size_t));
		*map = &trc3Rec.rec[i];
		// +1 // Стек: [..., <table: library>, <table>, <userdata>]

		// Получение метатаблицы
		luaL_getmetatable(luaState, INTERFACE_NAME(INTERFACE_TRC3_REC_NAME));
		// +1 // Стек: [..., <table: library>, <table>, <userdata>, <metatable>]

		// Установка метатаблицы в пользовательские данные
		lua_setmetatable(luaState, -2);
		// -1 // Стек: [..., <table: library>, <table>, <userdata>]

		// Добавление пользовательских данных в таблицу приёмников
		lua_rawseti(luaState, -2, i + 1);
		// -1 // Стек: [..., <table: library>,  <table>]
	}

	// Установка таблицы как поля библиотеки
	lua_setfield(luaState, -2, INTERFACE_TRC3_REC_NAME);
	// -1 // Стек: [..., <table: library>]
}


// --------------------------------------------- Интерфейс генератора АРС ----------------------------------------------


int interface_arsGen_level_api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto level = *((InterfaceArsGenStruct::LevelStruct **) luaL_checkudata(L, 1, INTERFACE_NAME(INTERFACE_ARS_GEN_LEVEL)));
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
	else
	{
		lua_pushnil(L);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <nil(return)>]
	}

	return 1;	// Возвращаемых элементов - 1
}

int interface_arsGen_level_api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto level = *((InterfaceArsGenStruct::LevelStruct **) luaL_checkudata(L, 1, INTERFACE_NAME(INTERFACE_ARS_GEN_LEVEL)));
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

	return 0;	// Возвращаемых элементов - 0
}

// Функции взаимодействия с интерфейсом приёмника ТРЦ3
const struct luaL_Reg interface_arsGen_level_functions[] = {
		{"__index", interface_arsGen_level_api_getField},			// Запрос значения поля
		{"__newindex", interface_arsGen_level_api_setField},		// Установка значения поля
		{NULL, NULL}
};


int interface_arsGen_gen_api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto gen = *((InterfaceArsGenMapType **) luaL_checkudata(L, 1, INTERFACE_NAME(INTERFACE_ARS_GEN_GEN)));
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

int interface_arsGen_gen_api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto gen = *((InterfaceArsGenMapType **) luaL_checkudata(L, 1, INTERFACE_NAME(INTERFACE_ARS_GEN_GEN)));
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
		{"__index", interface_arsGen_gen_api_getField},			// Запрос значения поля
		{"__newindex", interface_arsGen_gen_api_setField},		// Установка значения поля
		{NULL, NULL}
};


/**
 * @brief	Инициализация интерфейса генератора АРС
 * @note	На вершине стека должна быть таблица для записи в неё интерфейса (библиотека = таблица)
 */
void LuaLib_Interface::init_arsGen() {
	// Стек: [..., <table: library>]

	arsGen = {0, };

	// ======================== Метатаблицы ========================

	// Создание метатаблицы уровней частот АРС
	luaL_newmetatable(luaState, INTERFACE_NAME(INTERFACE_ARS_GEN_LEVEL));
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_arsGen_level_functions, 0);
	// ~~ // Стек: [..., <table: library>, <userdata>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// Создание метатаблицы управления генераторами АРС
	luaL_newmetatable(luaState, INTERFACE_NAME(INTERFACE_ARS_GEN_GEN));
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_arsGen_gen_functions, 0);
	// ~~ // Стек: [..., <table: library>, <userdata>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// =============================================================


	// Создание таблицы полей генератора АРС
	lua_createtable(luaState, 0, 3);
	// +1 // Стек: [..., <table: library>, <table>]



	// Добавление в стек названия таблицы уровней частот АРС
	lua_pushstring(luaState, INTERFACE_ARS_GEN_LEVEL);
	// +1 // Стек: [..., <table: library>, <table>, <string>]

	// Создание таблицы уровней частот АРС
	auto map = (void **) lua_newuserdata(luaState, sizeof(size_t));
	*map = &arsGen.level;
	// +1 // Стек: [..., <table: library>, <table>, <string>, <userdata>]

	// Получение метатаблицы
	luaL_getmetatable(luaState, INTERFACE_NAME(INTERFACE_ARS_GEN_LEVEL));
	// +1 // Стек: [..., <table: library>, <table>, <string>, <userdata>, <metatable>]

	// Установка метатаблицы в пользовательские данные
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table>, <string>, <userdata>]

	// Добавление в таблицу полей генератора АРС - таблицы уровней частот АРС
	lua_settable(luaState, -3);
	// -2 // Стек: [..., <table: library>, <table>]


	// Добавление в стек названия таблицы состояния первого генератора
	lua_pushstring(luaState, INTERFACE_ARS_GEN_GEN1);
	// +1 // Стек: [..., <table: library>, <table>, <string>]

	// Создание таблицы уровней частот АРС
	auto gen1 = (void **) lua_newuserdata(luaState, sizeof(size_t));
	*gen1 = &arsGen.gen1;
	// +1 // Стек: [..., <table: library>, <table>, <string>, <userdata>]

	// Получение метатаблицы
	luaL_getmetatable(luaState, INTERFACE_NAME(INTERFACE_ARS_GEN_GEN));
	// +1 // Стек: [..., <table: library>, <table>, <string>, <userdata>, <metatable>]

	// Установка метатаблицы в пользовательские данные
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table>, <string>, <userdata>]

	// Добавление в таблицу полей генератора АРС - таблицы уровней частот АРС
	lua_settable(luaState, -3);
	// -2 // Стек: [..., <table: library>, <table>]


	// Добавление в стек названия таблицы состояния первого генератора
	lua_pushstring(luaState, INTERFACE_ARS_GEN_GEN2);
	// +1 // Стек: [..., <table: library>, <table>, <string>]

	// Создание таблицы уровней частот АРС
	auto gen2 = (void **) lua_newuserdata(luaState, sizeof(size_t));
	*gen2 = &arsGen.gen2;
	// +1 // Стек: [..., <table: library>, <table>, <string>, <userdata>]

	// Получение метатаблицы
	luaL_getmetatable(luaState, INTERFACE_NAME(INTERFACE_ARS_GEN_GEN));
	// +1 // Стек: [..., <table: library>, <table>, <string>, <userdata>, <metatable>]

	// Установка метатаблицы в пользовательские данные
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table>, <string>, <userdata>]

	// Добавление в таблицу полей генератора АРС - таблицы уровней частот АРС
	lua_settable(luaState, -3);
	// -2 // Стек: [..., <table: library>, <table>]



	// Установка таблицы уровней частот АРС как поля библиотеки
	lua_setfield(luaState, -2, INTERFACE_ARS_GEN_NAME);
	// -1 // Стек: [..., <table: library>]
}


// ------------------------------------------ Интерфейс настройки маппера CAN ------------------------------------------


int interface_can_map_api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto canUData = (InterfaceCanUData *)luaL_checkudata(L, 1, INTERFACE_NAME(INTERFACE_CAN_MAPPER_NAME));
	uint32_t msgId = luaL_checkinteger(L, 2);
	luaL_checktype(L, 3, LUA_TTABLE);

	if (lua_getfield(L, 3, INTERFACE_CAN_MAPPER_POSITION) != LUA_TNUMBER)
		luaL_typeerror(L, 3, "mapper map field \"" INTERFACE_CAN_MAPPER_POSITION "\" is not a INTEGER.");
	// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>, <int:pos>]

	if (lua_getfield(L, 3, INTERFACE_CAN_MAPPER_LENGTH) != LUA_TNUMBER)
		luaL_typeerror(L, 3, "mapper map field \"" INTERFACE_CAN_MAPPER_LENGTH "\" is not a INTEGER.");
	// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>, <int:pos>, <int:len>]

	if (lua_getfield(L, 3, INTERFACE_CAN_MAPPER_INPUT) != LUA_TNUMBER)
		luaL_typeerror(L, 3, "mapper map field \"" INTERFACE_CAN_MAPPER_INPUT "\" is not a INTEGER.");
	// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>, <int:pos>, <int:len>, <int:input>]

	if (lua_getfield(L, 3, INTERFACE_CAN_MAPPER_DEFAULT) != LUA_TNUMBER)
		luaL_typeerror(L, 3, "mapper map field \"" INTERFACE_CAN_MAPPER_DEFAULT "\" is not a INTEGER.");
	// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>, <int:pos>, <int:len>, <int:input>, <int:d>]

	if (lua_getfield(L, 3, INTERFACE_CAN_MAPPER_TIMEOUT) != LUA_TNUMBER)
		luaL_typeerror(L, 3, "mapper map field \"" INTERFACE_CAN_MAPPER_POSITION "\" is not a INTEGER.");
	// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>, <int:pos>, <int:len>, <int:input>, <int:d>, <int:timeout>]

	if (canUData->canMapper->count(msgId) == 0) {
		std::list<CanMapperNodeStruct> idMap;
		(*canUData->canMapper)[msgId] = idMap;
	}

	CanMapperNodeStruct map = {
			.pos = (uint8_t)lua_tointeger(L, 4),
			.len = (uint8_t)lua_tointeger(L, 5),
			.input = (uint8_t)lua_tointeger(L, 6),
			.d = (uint8_t)lua_tointeger(L, 7),
			.timeout = (uint16_t)lua_tointeger(L, 8),
			.lastRxTime = 0
	};

	(*canUData->canMapper)[msgId].push_back(map);
	(*canUData->canInput)[map.input] = map.d;

	return 0;
}

// Функции взаимодействия с интерфейсом маппера CAN сообщений
const struct luaL_Reg interface_can_map_functions[] = {
		{"__newindex", interface_can_map_api_setField},			// Установка значения поля
		{NULL, NULL}
};


int interface_can_input_api_getField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>]

	auto canUData = (InterfaceCanUData *)luaL_checkudata(L, 1, INTERFACE_NAME(INTERFACE_CAN_INPUT_NAME));
	uint8_t key = luaL_checkinteger(L, 2);

	auto it = canUData->canInput->find(key);

	if (it != canUData->canInput->end())
	{

		// TODO: Проверка таймаута ожидания CAN сообщения

		lua_pushinteger(L, it->second);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <number(return)>]
	}
	else
	{
		lua_pushnil(L);
		// +1 // Стек: [<userdata(arg1)>, <key(arg2)>, <nil(return)>]
	}

	return 1;	// Возвращаемых элементов - 1
}

// Функции взаимодействия с интерфейсом входов данных CAN
const struct luaL_Reg interface_can_input_functions[] = {
		{"__index", interface_can_input_api_getField},			// Запрос значения поля
		{NULL, NULL}
};


void LuaLib_Interface::init_canMapper() {
	// Стек: [..., <table: library>]

	canMapper.clear();
	canInput.clear();

	// ======================== Метатаблицы ========================

	// Создание метатаблицы маппера CAN сообщений
	luaL_newmetatable(luaState, INTERFACE_NAME(INTERFACE_CAN_MAPPER_NAME));
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_can_map_functions, 0);
	// ~~ // Стек: [..., <table: library>, <userdata>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// Создание метатаблицы входов данных CAN
	luaL_newmetatable(luaState, INTERFACE_NAME(INTERFACE_CAN_INPUT_NAME));
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_can_input_functions, 0);
	// ~~ // Стек: [..., <table: library>, <userdata>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// =============================================================

	// Создание таблицы полей контроллера CAN
	lua_createtable(luaState, 0, 3);
	// +1 // Стек: [..., <table: library>, <table>]


	// Создание интерфейса маппера
	auto canUData = (InterfaceCanUData *) lua_newuserdata(luaState, sizeof(InterfaceCanUData));
	canUData->canMapper = &canMapper;
	canUData->canInput = &canInput;
	// +1 // Стек: [..., <table: library>, <table>, <userdata>]

	// Получение метатаблицы
	luaL_getmetatable(luaState, INTERFACE_NAME(INTERFACE_CAN_MAPPER_NAME));
	// +1 // Стек: [..., <table: library>, <table>, <userdata>, <metatable>]

	// Установка метатаблицы в маппер
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table>, <userdata>]

	// Установка маппера как поля контроллера CAN
	lua_setfield(luaState, -2, INTERFACE_CAN_MAPPER_NAME);
	// -1 // Стек: [..., <table: library>, <table>]


	// Создание интерфейса CAN входов
	canUData = (InterfaceCanUData *) lua_newuserdata(luaState, sizeof(InterfaceCanUData));
	canUData->canMapper = &canMapper;
	canUData->canInput = &canInput;
	// +1 // Стек: [..., <table: library>, <table>, <userdata>]

	// Получение метатаблицы
	luaL_getmetatable(luaState, INTERFACE_NAME(INTERFACE_CAN_INPUT_NAME));
	// +1 // Стек: [..., <table: library>, <table>, <userdata>, <metatable>]

	// Установка метатаблицы в маппер
	lua_setmetatable(luaState, -2);
	// -1 // Стек: [..., <table: library>, <table>, <userdata>]

	// Установка интерфейса CAN входов как поля контроллера CAN
	lua_setfield(luaState, -2, INTERFACE_CAN_INPUT_NAME);
	// -1 // Стек: [..., <table: library>, <table>]


	// Установка контроллера CAN как поля библиотеки
	lua_setfield(luaState, -2, INTERFACE_CAN_NAME);
	// -1 // Стек: [..., <table: library>]
}


// ----------------------------------------------- Библиотека интерфейса -----------------------------------------------


int interface_api_timeFunc(lua_State *L) {
	lua_pushinteger(L, LuaLib_GetTime());
	return 1;
}


// Функции библиотеки
const struct luaL_Reg interfaceLib_func[] = {
		{"time", interface_api_timeFunc},
		{NULL, NULL}
};


void LuaLib_Interface::InitLib(lua_State *L) {
	// Стек: [...]

	luaState = L;

	LuaLib_CreateLib(luaState, INTERFACE_STR, interfaceLib_func);
	// +1 // Стек: [..., <table: library>]

	// Инициализация интерфейса генератора ТРЦ3
	init_trc3Gen();

	// Инициализация интерфейса приёмников ТРЦ3
	init_trc3Rec();

	// Инициализация интерфейса генератора АРС
	init_arsGen();

	// Инициализация интерфейса маппера CAN сообщений
	init_canMapper();

	lua_pop(L, 1);
	// -1 // Стек: [...]
}


void LuaLib_Interface::CanHandler(CAN_Message *msg) {
	uint64_t data = *((uint64_t *)msg->data);

	auto mapIt = canMapper.find(msg->ID);

	if (mapIt == canMapper.end())
		return;

	for (auto mapNodeIt = mapIt->second.begin(); mapNodeIt != mapIt->second.end(); mapNodeIt++) {

		canInput[mapNodeIt->input] = (data >> mapNodeIt->pos) & ((1 << mapNodeIt->len) - 1);
		mapNodeIt->lastRxTime = 0;

		/*
		printf("ID: %#010x\t"
			   "pos: %d\t"
			   "len: %d\t"
			   "input: %d\t"
			   "d: %d\t"
			   "timeout: %d\t"
			   "lastReceivedTime: %d\n", mapperIt->first, it->pos, it->len, it->input, it->d, it->timeout, it->lastRxTime);
		*/
	}
}


void LuaLib_Interface::CanUpdateTimeouts() {
	LUA_LIB_TIME_T _time = LuaLib_GetTime();

	for (auto mapIt = canMapper.begin(); mapIt != canMapper.end(); mapIt++) {
		auto mapNodeList = mapIt->second;

		for (auto mapNodeIt = mapNodeList.begin(); mapNodeIt != mapNodeList.end(); mapNodeIt++) {

			// Произошло переполнение переменной времени
			if (mapNodeIt->lastRxTime > _time)
				// Проверка таймаута ожидания CAN сообщения (с учётом переполнения переменной времени)
				if (((LUA_LIB_MAX_TIME - mapNodeIt->lastRxTime) + _time) > mapNodeIt->timeout)
					// Сброс входа к значению по-умолчанию
					canInput[mapNodeIt->input] = mapNodeIt->d;

			// Проверка таймаута ожидания CAN сообщения
			else if ((_time - mapNodeIt->lastRxTime) > mapNodeIt->timeout)
				// Сброс входа к значению по-умолчанию
				canInput[mapNodeIt->input] = mapNodeIt->d;
		}
	}
}




void dumpstack (lua_State *L) {
	int top=lua_gettop(L);

	printf("\nLua stack:\n");

	for (int i=1; i <= top; i++) {
		printf("%d\t%s\t", i, luaL_typename(L,i));
		switch (lua_type(L, i)) {
			case LUA_TNUMBER:
				printf("%g\n",lua_tonumber(L,i));
				break;
			case LUA_TSTRING:
				printf("%s\n",lua_tostring(L,i));
				break;
			case LUA_TBOOLEAN:
				printf("%s\n", (lua_toboolean(L, i) ? "true" : "false"));
				break;
			case LUA_TNIL:
				printf("%s\n", "nil");
				break;
			default:
				printf("%p\n",lua_topointer(L,i));
				break;
		}
	}

	printf("\n");
}


