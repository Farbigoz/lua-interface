#ifndef __LUA_ULIB__
#define __LUA_ULIB__

#ifdef __cplusplus
extern "C" {
#endif


#include <lua.h>
#include <lauxlib.h>

#include <stdint.h>



#ifndef LUA_LIB_TIME_T
#define LUA_LIB_TIME_T		uint32_t
#endif /* LUA_LIB_TIME_T */

#define LUA_LIB_MAX_TIME		((LUA_LIB_TIME_T) - 1)


/**
 * @brief	Функция получения времени, используемая внутри Lua
 *
 * @note	Функцию нужно объявить
 *
 * @return	Время
 */
LUA_LIB_TIME_T LuaLib_GetTime();


/**
 * @brief	Создание библиотеки и добавление её в глобальное поле видимости
 *
 * @param	luaState - Экземпляр интерпретатора
 * @param	name - Название библиотеки (для её импорта)
 * @param	funcList - Список функций библиотеки. Может быть NULL, если нет функций
 *
 * @return	Стэк: [..., <table: library>]
 */
void LuaLib_CreateLib(lua_State *L, const char *name, const luaL_Reg *funcList);


#ifdef __cplusplus
}
#endif

#endif /* __LUA_ULIB__ */