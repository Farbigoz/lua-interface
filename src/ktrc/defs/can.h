#ifndef __DEFS_CAN__
#define __DEFS_CAN__

#include "stdint.h"


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
} CAN_ModuleType;


/**
 * @brief	Тип CAN интерфейса
 */
typedef enum {
	CAN_INTERFACE_SYS_A		= 0x00,
	CAN_INTERFACE_SYS_B		= 0x01,
	CAN_INTERFACE_DIAG_A	= 0x02,
	CAN_INTERFACE_DIAG_B	= 0x03,
} CAN_InterfaceType;


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



#endif /* __DEFS_CAN__ */