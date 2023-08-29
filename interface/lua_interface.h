#ifndef __LUA_INTERFACE_H__
#define __LUA_INTERFACE_H__

#include <stdint.h>
#include <map>
#include <list>
#include <string>

#include "ars.h"
#include "trc3.h"
#include "hardware_interface.h"

#include "lua_ulib.h"


#define INTERFACE_LIB_NAME			"interface"

#define INTERFACE_KTRC_NAME			"ktrc"

#define INTERFACE_MU_NAME			"mu"


#define INTERFACE_TRC3_GEN_NAME		"trc3Gen"
#define INTERFACE_TRC3_GEN_LEVEL	"level"			// trc3Gen.level
#define INTERFACE_TRC3_GEN_CARRIER	"carrier"		// trc3Gen.carrier
#define INTERFACE_TRC3_GEN_MOD		"mod"			// trc3Gen.mod


#define INTERFACE_TRC3_REC_NAME		"trc3Rec"
#define INTERFACE_TRC3_REC_LEVEL	"level"			// trc3Rec[i].level
#define INTERFACE_TRC3_REC_CARRIER	"carrier"		// trc3Rec[i].carrier
#define INTERFACE_TRC3_REC_MOD		"mod"			// trc3Rec[i].mod
#define INTERFACE_TRC3_REC_TC		"tc"			// trc3Rec[i].tc

#define INTERFACE_TRC3_REC_COUNT	2


#define INTERFACE_ARS_GEN_NAME		"arsGen"
#define INTERFACE_ARS_GEN_LEVEL		"level"			// arsGen.level
#define INTERFACE_ARS_GEN_GEN		"gen"			// arsGen.gen

#define INTERFACE_ARS_F75_NAME		"f75"
#define INTERFACE_ARS_F125_NAME		"f125"
#define INTERFACE_ARS_F175_NAME		"f175"
#define INTERFACE_ARS_F225_NAME		"f225"
#define INTERFACE_ARS_F275_NAME		"f275"
#define INTERFACE_ARS_F325_NAME		"f325"
#define INTERFACE_ARS_F275_AO_NAME	"f275_ao"


#define INTERFACE_CAN_NAME				"can"
#define INTERFACE_CAN_INPUT_NAME		"input"
#define INTERFACE_CAN_MAPPER_NAME		"mapper"
#define INTERFACE_CAN_MAPPER_POSITION	"pos"
#define INTERFACE_CAN_MAPPER_LENGTH		"len"
#define INTERFACE_CAN_MAPPER_INPUT		"inp"
#define INTERFACE_CAN_MAPPER_DEFAULT	"d"
#define INTERFACE_CAN_MAPPER_TIMEOUT	"timeout"

#pragma pack(1)

/**
 * @brief	Структура интерфейса генератора ТРЦ3
 */
typedef struct {
#if defined(LUA_INTERFACE_OPTIMIZE_STRUCTS)
	uint8_t			level;				///< Уровень занятия РЦ в миливольтах
	uint8_t			carrier		:3;		///< Номер несущей частоты
	uint8_t			mod			:2;		///< Номер модуляции
	uint8_t						:3;
#else
	uint8_t			level;					///< Уровень генерации в вольтах
	TTrc3Carrier	carrier;				///< Номер несущей частоты
	TTrc3Mod	mod;					///< Номер модуляции
#endif
} InterfaceTrc3GenStruct;


/**
 * @brief	Структура интерфейса приёмников ТРЦ3
 */
typedef struct {
	/**
	 * @brief	Структура интерфейса приёмника ТРЦ3
	 */
	struct RecStruct {
#if defined(LUA_INTERFACE_OPTIMIZE_STRUCTS)
		uint8_t			level;				///< Уровень занятия РЦ в миливольтах
		uint8_t			carrier		:3;		///< Номер несущей частоты
		uint8_t			mod			:2;		///< Номер модуляции
		uint8_t			tc			:1;		///< Состояние свободности РЦ (true = свободна, false = занята)
		uint8_t						:2;
#else
		uint8_t			level;				///< Уровень занятия РЦ в миливольтах
		TTrc3Carrier	carrier;			///< Номер несущей частоты
		TTrc3Mod	mod;				///< Номер модуляции

		bool			tc;					///< Состояние свободности РЦ (true = свободна, false = занята)
#endif
	} rec[TRC3_REC_COUNT];
} InterfaceTrc3RecStruct;


//typedef std::map	<TArsFreqNum, bool> InterfaceArsGenMapType;

typedef struct ArsGenStruct {
#if defined(LUA_INTERFACE_OPTIMIZE_STRUCTS)
	uint8_t		f75		: 1;			///< Уровень частоты 75Гц в вольтах
	uint8_t		f125	: 1;			///< Уровень частоты 125Гц в вольтах
	uint8_t		f175	: 1;			///< Уровень частоты 175Гц в вольтах
	uint8_t		f225	: 1;			///< Уровень частоты 225Гц в вольтах
	uint8_t		f275	: 1;			///< Уровень частоты 275Гц в вольтах
	uint8_t		f325	: 1;			///< Уровень частоты 325Гц в вольтах
	uint8_t		f275_ao	: 1;			///< Уровень частоты 275Гц с АО в вольтах
	uint8_t				: 1;
#else
	uint8_t		f75;					///< Уровень частоты 75Гц в вольтах
	uint8_t		f125;					///< Уровень частоты 125Гц в вольтах
	uint8_t		f175;					///< Уровень частоты 175Гц в вольтах
	uint8_t		f225;					///< Уровень частоты 225Гц в вольтах
	uint8_t		f275;					///< Уровень частоты 275Гц в вольтах
	uint8_t		f325;					///< Уровень частоты 325Гц в вольтах
	uint8_t		f275_ao;				///< Уровень частоты 275Гц с АО в вольтах
#endif
} InterfaceArsGenMapType;

/**
 * @brief	Структура интерфейса генератора АРС
 */
typedef struct {
	/**
	 * @brief	Уровни каждой частоты
	 */
	struct ArsLevelStruct {
		uint8_t		f75;					///< Уровень частоты 75Гц в вольтах
		uint8_t		f125;					///< Уровень частоты 125Гц в вольтах
		uint8_t		f175;					///< Уровень частоты 175Гц в вольтах
		uint8_t		f225;					///< Уровень частоты 225Гц в вольтах
		uint8_t		f275;					///< Уровень частоты 275Гц в вольтах
		uint8_t		f325;					///< Уровень частоты 325Гц в вольтах
		uint8_t		f275_ao;				///< Уровень частоты 275Гц с АО в вольтах
	} level;

	InterfaceArsGenMapType gen[ARS_GEN_NUM];
} InterfaceArsGenStruct;


/**
 * @brief	Структура элемента маппера CAN сообщения
 *
 * @note	Если новое сообщение не было получено в течении timeout,
 *			значение входа будет сброшено до значения по-умолчанию.
 *
 * @note	Данные CAN сообщения преобразуются в uint64_t (LITTLE ENDIAN!)
 * 			uint8_t data[8] = {0x7f, 0x58, ...};
 * 			uint64_t DATA_UINT64 = *(uint64_t*)(data);   // = 0x...587f
 *
 * @note	Схема считывания битов из данных CAN сообщения
 * 			     CAN data | ... |        data[1]        |     data[0]     |
 * 			          pos | ... | 15 14 13 12 11 10 9 8 | 7 6 5 4 3 2 1 0 |
 * 			    bit value | ... |  0  1  0  1  1  0 0 0 | 0 1 1 1 1 1 1 1 |
 * 			                                |- pos = 12                 |- pos = 0
 * 			                          |<--->|- len = 3                  |- len = 1
 * 			                                value = 5                   value = 1
 *
 * @note	Формула извлечения значения:
 * 			  value = (DATA_UINT64 >> pos) & ((1 << len) - 1);
 * 			Пример:
 * 			  value = (0x587f >> 12) & ((1 << 3) - 1);       // = 5
 * 			  value = (0x587f >> 0) & ((1 << 1) - 1);        // = 1
 */
typedef struct {
	uint8_t				pos;				///< Позиция начала считывания (С этого бита будет производиться считывание)
	uint8_t				len;				///< Количество бит для считывания
	uint8_t				input;				///< Номер входа для записи (в `InterfaceInputType`)
	uint8_t				d;					///< Значение по-умолчанию
	uint16_t			timeout;			///< Таймаут получения сообщения в милисекундах. При превышении: input = d
	LUA_LIB_TIME_T		lastRxTime;			///< Время последнего получения сообщения
} CanMapperNodeStruct;

#pragma pack()

/**
 * @brief	Тип данных интерфейса маппера CAN сообщений
 */
typedef std::map<uint32_t, std::list<CanMapperNodeStruct>>	InterfaceCanMapperType;


/**
 * @brief	Тип данных интерфейса входов, указанных в маппере CAN сообщений
 */
typedef std::map<uint8_t, uint8_t>							InterfaceCanInputType;



typedef std::map<uint8_t, InterfaceArsGenStruct>	InterfaceArsGenController;




/**
 * @brief	Родительский класс Lua интерфейсов
 */
class _LuaInterface {
protected:
	lua_State	*luaState;

public:
	/**
	 * @brief	Подключение интерфейса к таблице находящейся на вершине стека
	 *
	 * @param	L - Экземпляр интерпретатора Lua
	 */
	virtual void Connect(lua_State *L) { luaState = L; }
};


/**
 * @brief	Lua библиотека-интерфейс
 */
class LuaInterfaceLib {
private:
	lua_State	*luaState;

public:
	/**
	 * @brief	Подключение библиотеки к рабочей среде
	 *
	 * @param	L - Экземпляр интерпретатора Lua
	 */
	void InitLib(lua_State *L);

	/**
	 * @brief	Добавление интерфейса в библиотеку
	 *
	 * @note	Автоматически вызывает метод "Connect" класса "_LuaInterface"
	 *
	 * @param	interfaceInst - Экземпляр интерфейса
	 */
	void AddInterface(_LuaInterface *interfaceInst);
};


/**
 * @brief	Интерфейс CAN маппера
 */
class LuaInterface_Can : public _LuaInterface {
protected:
	void connect_can();

public:
	InterfaceCanMapperType		canMapper;
	InterfaceCanInputType		canInput;

public:
	void Connect(lua_State *L) {
		_LuaInterface::Connect(L);

		connect_can();
	}

	/**
	 * @brief	Обработчик CAN сообщений
	 * @param	msg - Указатель на сообщение
	 */
	void CanHandler(CAN_Message *msg);

	/**
	 * @brief	Обновление таймаутов, сброс значений к значениям по-умолчанию
	 */
	void CanUpdateTimeouts();
};


/**
 * @brief	Интерфейс ТРЦ3 в КТРЦ
 */
class LuaInterface_Ktrc_Trc3 : public _LuaInterface {
protected:
	void connect_trc3Gen();

	void connect_trc3Rec();

public:
	InterfaceTrc3GenStruct		trc3Gen;
	InterfaceTrc3RecStruct		trc3Rec;

public:
	void Connect(lua_State *L) {
		_LuaInterface::Connect(L);

		connect_trc3Gen();
		connect_trc3Rec();
	}
};


/**
 * @brief	Интерфейс АРС в КТРЦ
 */
class LuaInterface_Ktrc_Ars : public _LuaInterface {
private:
	void connect_arsGen();

public:
	InterfaceArsGenStruct		arsGen;

public:
	void Connect(lua_State *L) {
		_LuaInterface::Connect(L);

		connect_arsGen();
	}
};


class LuaInterface_Mu_Ktrc : public _LuaInterface {
protected:
	uint8_t		*selectedKtrc;

private:
	void connect_ktrc();

public:
	void Connect(lua_State *L) {
		_LuaInterface::Connect(L);

		connect_ktrc();
	}
};


/**
 * @brief	Интерфейс АРС в МУ
 */
class LuaInterface_Mu_Ktrc_Ars : public LuaInterface_Mu_Ktrc {
private:
	void connect_arsGen();

public:
	InterfaceArsGenController	arsGen;

public:
	void Connect(lua_State *L) {
		LuaInterface_Mu_Ktrc::Connect(L);

		connect_arsGen();
	}
};




void dumpstack (lua_State *L);



#endif /* __LUA_INTERFACE_H__ */