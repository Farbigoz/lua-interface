#ifndef __SYS_DEFS_H__
#define __SYS_DEFS_H__


#include <stdbool.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif


#define GENERATOR_SAMPLERATE			8000	// Частота дискретизации генератора
#define GENERATOR_HANDLER_FREQ			100		// Частота вызова обработчика генератора
#define GENERATOR_HANDLER_FRAME_SIZE	(GENERATOR_SAMPLERATE/GENERATOR_HANDLER_FREQ)	// Размер кадра обработчика генератора

#define RECEIVER_SAMPLERATE				2000	// Частота дискретизации приёмника
#define RECEIVER_HANDLER_FREQ			100		// Частота вызова обработчика приёмника
#define RECEIVER_HANDLER_FRAME_SIZE		(RECEIVER_SAMPLERATE/RECEIVER_HANDLER_FREQ)		// Размер кадра обработчика приёмника


#define CPU_COMM_MSG_BUFF_SIZE			20		// Размер буфера сообщений межпроцессорного обмена



typedef void (*SYS_Task)(void*);

typedef void (*SYS_SignalHandler)(int16_t *frame, uint16_t frameSize);

typedef void (*SYS_ErrorHandler)();



/**
 * @brief	Роль процессора
 */
typedef enum {
	CPU_ROLE_A,
	CPU_ROLE_B,
} SYS_TCpuRole;


/**
 * @brief	Режим работы модуля
 */
typedef enum {
	MODULE_MODE_NORMAL,			///< Нормальный режим	- работа с вольтами и милливольтами
	MODULE_MODE_CONFIGURE,		///< Режим конфигурации	- настройка параметров модуля, калибровка генераторов и приёмников, работа с У.Е.
	MODULE_MODE_PROTECTION,		///< Защитный режим		- отключение работы всех генераторов и приёмников
} SYS_TModuleMode;


/**
 * @brief	ID модулей
 */
typedef enum {
	MODULE_ARM_PROG		= 0x00,			///< Стенд проверки (АРМ настройщика, программатор)
	MODULE_MU			= 0x01,			///< Модуль управления МУ
	MODULE_MPP			= 0x02,			///< Модуль путевых приёмников МПП
	MODULE_GKS2_PWR		= 0x03,			///< Модуль путевых генераторов ГКС2 питающих концов РЦ
	MODULE_GKS2_REC		= 0x04,			///< Модуль путевых генераторов ГКС2 приёмных концов РЦ
	MODULE_GKS2_METRO	= 0x05,			///< Модуль путевых генераторов ГКС2 для метро (КРЛ + АРС)
	MODULE_MEC			= 0x07,			///< Модуль интерфейса с релейной электрической централизацией МЭЦ
	MODULE_MUS_LIGHT	= 0x08,			///< Модуль управления светофором МУС-ППМ-Ц (светофоры)
	MODULE_MSS			= 0x0B,			///< Модуль связи с соседней станцией МСС
	MODULE_KRC			= 0x0E,
	MODULE_KRC_METRO	= 0x0F
} SYS_TModuleType;


/**
 * @brief	Тип CAN интерфейса
 */
typedef enum {
	CAN_INTERFACE_SYS_A		= 0x00,
	CAN_INTERFACE_SYS_B		= 0x01,
	CAN_INTERFACE_DIAG_A	= 0x02,
	CAN_INTERFACE_DIAG_B	= 0x03,
} SYS_TCanInterfaceType;



/**
 * @brief	Структура сообщения межпроцессорного обмена
 */
#pragma pack(1)
typedef struct {
	uint16_t		: 6;
	uint16_t	ID	: 10;		///< Идентификатор
	uint8_t		data[32];		///< Данные сообщения
	uint8_t		length;			///< Длина сообщения
} CC_Message;
#pragma pack()


/**
 * @brief	Структура CAN сообщения
 */
typedef struct {
	uint32_t	ID;				///< Идентификатор
	uint8_t		data[8];		///< Данные сообщения
	uint8_t		length;			///< Длина сообщения
} CAN_Message;


#pragma pack(1)
/**
 * @brief	Структура айди CAN сообщения
 */
typedef struct {
	uint32_t	interface	:3;				///< Интерфейс: Системный А, Системный Б, Диагностический А...
	uint32_t	moduleId	:8;				///< Айди оборудования
	uint32_t	command		:9;				///< Номер команды
	uint32_t	moduleType	:9;				///< Тип оборудования
	uint32_t				:3;				///< Не используется (ID сообщения = 29 бит)
} CAN_MessageId;
#pragma pack()


#ifdef __cplusplus
}
#endif


#endif /* __SYS_DEFS_H__ */