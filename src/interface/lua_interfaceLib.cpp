#include "lua_interface.h"


int interface_lib_func_time(lua_State *L) {
	lua_pushinteger(L, LuaLib_GetTime());
	return 1;
}


const struct luaL_Reg interface_lib_func[] = {
		{"time", interface_lib_func_time},
		{NULL, NULL}
};


void LuaInterfaceLib::InitLib(lua_State *L) {
	// Стек: [...]

	luaState = L;

	LuaLib_CreateLib(luaState, INTERFACE_LIB_NAME, interface_lib_func);
	// +1 // Стек: [..., <table: library>]

	lua_pop(L, 1);
	// -1 // Стек: [...]
}


void LuaInterfaceLib::AddInterface(_LuaInterface *interfaceInst) {
	// Стек: [...]

	LuaLib_GetLib(luaState, INTERFACE_LIB_NAME);
	// +1 // Стек: [..., <table: library>]

	interfaceInst->Connect(luaState);
	// ~~ // Стек: [..., <table: library>]

	lua_pop(luaState, 1);
	// -1 // Стек: [...]
}