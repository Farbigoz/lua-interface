#ifndef __SIGNAL_TRC3_H__
#define __SIGNAL_TRC3_H__


#include <stdint.h>


#ifndef TRC3_CARRIERS_DEF
#define TRC3_CARRIERS_DEF

/// Количество несущих частот ТРЦ3
#define CARRIER_FREQ_NUM_TRC3	5

/// Частоты ТРЦ 3
typedef enum
{
	F_420_HZ,
	F_480_HZ,
	F_565_HZ,
	F_720_HZ,
	F_780_HZ,
} TTrc3FreqNum;

const uint16_t Trc3Freq[CARRIER_FREQ_NUM_TRC3] = {420, 480, 565, 720, 780};

/// Количество частот модуляции
#define MODULATION_FREQ_NUM_TRC3 2

/// Частоты модуляции ТРЦ 3
typedef enum
{
	F_8_HZ,
	F_12_HZ
} TTrc3ModFreqNum;

const uint16_t Trc3ModFreq[MODULATION_FREQ_NUM_TRC3] = {8, 12};

#endif /* TRC3_CARRIERS_DEF */


#endif /* __SIGNAL_TRC3_H__ */