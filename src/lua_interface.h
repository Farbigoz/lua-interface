#ifndef __LUA_INTERFACE_H__
#define __LUA_INTERFACE_H__

#include <stdint.h>
#include <map>
#include <list>

#include "defs/ars.h"
#include "defs/trc3.h"

#include "ktrcDefs.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <lua.h>

#ifdef __cplusplus
}
#endif


#define INTERFACE_STR				"interface"
#define INTERFACE_NAME(sname)		(INTERFACE_STR "." sname)


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
#define INTERFACE_ARS_GEN_GEN		"gen"			// arsGen.gen1
#define INTERFACE_ARS_GEN_GEN1		"gen1"			// arsGen.gen1
#define INTERFACE_ARS_GEN_GEN2		"gen2"			// arsGen.gen2

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




static const std::list<std::string> INTERFACE_ARS_CARRIER_NAMES = {
		INTERFACE_ARS_F75_NAME,
		INTERFACE_ARS_F125_NAME,
		INTERFACE_ARS_F175_NAME,
		INTERFACE_ARS_F225_NAME,
		INTERFACE_ARS_F275_NAME,
		INTERFACE_ARS_F325_NAME,
		INTERFACE_ARS_F275_AO_NAME,
};




/**
 * @brief	Структура интерфейса генератора ТРЦ3
 */
typedef struct {
	uint8_t			level;					///< Уровень генерации в вольтах
	TTrc3FreqNum	carrier;				///< Номер несущей частоты
	TTrc3ModFreqNum	mod;					///< Номер модуляции
} InterfaceTrc3GenStruct;


/**
 * @brief	Структура интерфейса приёмников ТРЦ3
 */
typedef struct {
	/**
	 * @brief	Структура интерфейса приёмника ТРЦ3
	 */
	struct RecStruct {
		uint8_t			level;				///< Уровень занятия РЦ в миливольтах
		TTrc3FreqNum	carrier;			///< Номер несущей частоты
		TTrc3ModFreqNum	mod;				///< Номер модуляции

		bool			tc;					///< Состояние свободности РЦ (true = свободна, false = занята)
	} rec[2];
} InterfaceTrc3RecStruct;


//typedef std::map	<TArsFreqNum, bool> InterfaceArsGenMapType;

typedef bool		InterfaceArsGenMapType[F_ARS_COUNT];

/**
 * @brief	Структура интерфейса генератора АРС
 */
typedef struct {
	/**
	 * @brief	Уровни каждой частоты
	 */
	struct LevelStruct{
		uint8_t		f75;					///< Уровень частоты 75Гц в вольтах
		uint8_t		f125;					///< Уровень частоты 125Гц в вольтах
		uint8_t		f175;					///< Уровень частоты 175Гц в вольтах
		uint8_t		f225;					///< Уровень частоты 225Гц в вольтах
		uint8_t		f275;					///< Уровень частоты 275Гц в вольтах
		uint8_t		f325;					///< Уровень частоты 325Гц в вольтах
	} level;

	InterfaceArsGenMapType		gen1;		///< Карта состояния генератора первой частоты
	InterfaceArsGenMapType		gen2;		///< Карта состояния генератора второй частоты
	//bool			gen1[F_ARS_COUNT];
	//bool			gen2[F_ARS_COUNT];
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
	uint8_t		pos;						///< Позиция начала считывания (С этого бита будет производиться считывание)
	uint8_t		len;						///< Количество бит для считывания
	uint8_t		input;						///< Номер входа для записи (в `InterfaceInputType`)
	uint8_t		d;							///< Значение по-умолчанию
	uint16_t	timeout;					///< Таймаут получения сообщения в милисекундах. При превышении: input = d
	uint32_t	lastReceiveTime;			///< Время последнего получения сообщения
} CanMapperNodeStruct;


/**
 * @brief	Тип данных интерфейса маппера CAN сообщений
 */
typedef std::map<uint32_t, std::list<CanMapperNodeStruct>>	InterfaceCanMapperType;


/**
 * @brief	Тип данных интерфейса входов, указанных в маппере CAN сообщений
 */
typedef std::map<uint8_t, uint8_t>							InterfaceCanInputType;




/**
 * @brief	Создание библиотеки - интерфейса
 */
int luaopen_interface(lua_State *L);



void interface_can_mapper_handle(CAN_Message *msg);



extern InterfaceTrc3GenStruct		INTERFACE_TRC3_GEN;
extern InterfaceTrc3RecStruct		INTERFACE_TRC3_REC;
extern InterfaceArsGenStruct		INTERFACE_ARS_GEN;
extern InterfaceCanMapperType		INTERFACE_CAN_MAPPER;
extern InterfaceCanInputType		INTERFACE_CAN_INPUT;












#endif /* __LUA_INTERFACE_H__ */