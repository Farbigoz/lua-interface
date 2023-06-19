#include "lua_interface.h"


#define LUA_METATABLE_CAN_MAPPER	(INTERFACE_CAN_NAME "." INTERFACE_CAN_MAPPER_NAME)
#define LUA_METATABLE_CAN_INPUT		(INTERFACE_CAN_NAME "." INTERFACE_CAN_INPUT_NAME)


typedef struct {
	InterfaceCanMapperType		*canMapper;
	InterfaceCanInputType		*canInput;
} InterfaceCanUData;



int interface_can_map_api_setField(lua_State *L) {
	// Стек: [<userdata(arg1)>, <key(arg2)>, <value(arg3)>]

	auto canUData = (InterfaceCanUData *)luaL_checkudata(L, 1, LUA_METATABLE_CAN_MAPPER);
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

	auto canUData = (InterfaceCanUData *)luaL_checkudata(L, 1, LUA_METATABLE_CAN_INPUT);
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


void LuaInterface_Can::connect_can() {
	// Стек: [..., <table: library>]

	canMapper.clear();
	canInput.clear();

	// ======================== Метатаблицы ========================

	// Создание метатаблицы маппера CAN сообщений
	luaL_newmetatable(luaState, LUA_METATABLE_CAN_MAPPER);
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_can_map_functions, 0);
	// ~~ // Стек: [..., <table: library>, <metatable>]

	// Удаление метатаблицы из стека
	lua_pop(luaState, 1);
	// -1 // Стек: [..., <table: library>]

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// Создание метатаблицы входов данных CAN
	luaL_newmetatable(luaState, LUA_METATABLE_CAN_INPUT);
	// +1 // Стек: [..., <table: library>, <metatable>]

	// Установка функций метатаблицы
	luaL_setfuncs(luaState, interface_can_input_functions, 0);
	// ~~ // Стек: [..., <table: library>, <metatable>]

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
	luaL_getmetatable(luaState, LUA_METATABLE_CAN_MAPPER);
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
	luaL_getmetatable(luaState, LUA_METATABLE_CAN_INPUT);
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




void LuaInterface_Can::CanHandler(CAN_Message *msg) {
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


void LuaInterface_Can::CanUpdateTimeouts() {
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