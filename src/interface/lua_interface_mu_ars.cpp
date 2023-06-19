#include "lua_interface.h"



/*
 * Интерфейсы
 *
 * - Интерфейс CAN маппера
 *
 *   interface.can       - Интерфейс CAN
 *
 *     .mapper[canId]      - Конфигурирование CAN маппера
 *
 *     .input[in]          - Входы, настроенные CAN маппером. Устанавливаются так же CAN маппером
 *
 * - Интерфейс КТРЦ
 *
 *   interface.ktrc      - Интерфейс КТРЦ
 *
 *     .trc3Gen            - Генератор ТРЦ3
 *       .level              - Напряжение
 *       .carrier            - Несущая
 *       .mod                - Модуляция
 *
 *     .trc3Rec[n]         - Приёмник ТРЦ3 под номером "n"
 *       .level              - Напряжение
 *       .carrier            - Несущая
 *       .mod                - Модуляция
 *       .tc                 - Состояние РЦ
 *
 *     .arsGen             - Генератор АРС
 *
 *       .level              - Напряжения частот генератора АРС
 *         .f75                - Напряжение генератора на частоте 75Гц
 *         .f125               - Напряжение генератора на частоте 125Гц
 *         ...
 *         .f325               - Напряжение генератора на частоте 325Гц
 *         .f275_ao            - Напряжение генератора на частоте 275Гц с АО
 *
 *       .gen1               - Первый генератор АРС
 *         .f75                - Флаг генерации частоты 75Гц (1 - генерировать, 0 - не генерировать)
 *         .f125               - Флаг генерации частоты 125Гц
 *         ...
 *         .f325               - Флаг генерации частоты 325Гц
 *         .f275_ao            - Флаг генерации частоты 275Гц с АО
 *
 *       .gen2               - Второй генератор АРС
 *         .f75                - Флаг генерации частоты 75Гц (1 - генерировать, 0 - не генерировать)
 *         ...
 *
 *     .krlGen             - Генератор КРЛ
 *
 *     .krlRec             - Приёмник КРЛ
 *
 *     .alsnGen            - Генератор АЛСН
 *
 *     .alsenGen           - Генератор АЛС-ЕН
 *
 *
 * - Интерфейс МУ
 *
 *   interface.mu        - Интерфейс модуля управления
 *     .ktrc[n]            - Интерфейс управления КТРЦ под номером "n"
 *       .arsGen             - Генератор АРС
 *         .level              - Напряжения частот генератора АРС
 *           .f75                - Напряжение генератора на частоте 75Гц
 *           ...
 *
 *         .gen1             - Первый генератор АРС
 *           .f75              - Флаг генерации частоты 75Гц (1 - генерировать, 0 - не генерировать)
 *           ...
 *
 *         .gen2             - Второй генератор АРС
 *           .f75              - Флаг генерации частоты 75Гц (1 - генерировать, 0 - не генерировать)
 *           ...
 *
 *       .alsnGen
 *
 *       .alsenGen
 *
 *     .mec[n]                       - Интерфейс управление МЭЦ-ем под номером "n"
 *
 */


/*
 * Lua userdata интерфейсов
 *
 * interface.mu.ktrc[n].arsGen.level.X     - [указатель на список настроек АРС КТРЦ, указатель на "selectedKtrc"]
 * interface.mu.ktrc[n].arsGen.gen1.X      - [указатель на список настроек АРС КТРЦ, указатель на "selectedKtrc", номер генератора = 1]
 * interface.mu.ktrc[n].arsGen.gen2.X      - [указатель на список настроек АРС КТРЦ, указатель на "selectedKtrc", номер генератора = 2]
 *
 */



/*
 * Принцип обращения к модулю под номером "n"
 *
 * Пример:
 *   print(interface.mu.ktrc[n].arsGen.gen1.f125)
 *
 * Алгоритм обработки:
 *   1. [Lua] У объекта "interface.mu.ktrc" запрашивается элемент под номером "n"
 *   2. [C]   Обработчик записывает номер КТРЦ "n" в переменную "selectedKtrc" обработчика и возвращает объект
 *            "interface.mu.ktrc"
 *   3. [Lua] У объекта "interface.mu.ktrc" запрашивается поле ".arsGen"
 *   4. [Lua] У объекта "interface.mu.ktrc.arsGen" запрашивается поле ".gen1"
 *   5. [Lua] У объекта "interface.mu.ktrc.arsGen.gen1" запрашивается поле ".f125"
 *   6. [C]   Обработчик возвращает значение "arsGen.gen1.f125" КТРЦ под номером "selectedKtrc"
 *
 * Сам объект "interface.mu.ktrc" содержит в себе объекты управления КТРЦ, такие как:
 *     interface.mu.ktrc.arsGen...
 *     interface.mu.ktrc.aslnGen...
 *     interface.mu.ktrc.alsenGen...
 * Взаимодействие точно такое же, как и в интерфейсе "interface.ktrc", единственное чем отличается интерфейс МУ -
 * предварительным выбором номера КТРЦ.
 *
 * Данное решение позволяет переписать конструкцию
 *   interface.mu.ktrc[n].level.f75 = x
 *   interface.mu.ktrc[n].level.f125 = x
 *   interface.mu.ktrc[n].level.f175 = x
 * в конструкцию
 *   interface.mu.ktrc[n]
 *   interface.mu.ktrc.level.f75 = x
 *   interface.mu.ktrc.level.f125 = x
 *   interface.mu.ktrc.level.f175 = x
 * где сначала выбирается КТРЦ, с которым будет производится работа, а дальше сама работа
 *
 *
 *
 *
 */






















/*
int interface_mu_api_timeFunc(lua_State *L) {
	lua_pushinteger(L, LuaLib_GetTime());
	return 1;
}


// Функции библиотеки
const struct luaL_Reg interface_mu_funcs[] = {
		{"time", interface_mu_api_timeFunc},
		{NULL, NULL}
};


void LuaLib_MuInterface::LibInitAll() {

}


const struct luaL_Reg * LuaLib_MuInterface::LibFuncs() {
	return interface_mu_funcs;
}


const char * LuaLib_MuInterface::LibName() {
	return INTERFACE_MU_NAME;
}
 */