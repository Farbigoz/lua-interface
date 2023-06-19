#ifndef __SIGNAL_ARS_H__
#define __SIGNAL_ARS_H__


#include <stdint.h>


#ifndef ARS_CARRIERS_DEF
#define ARS_CARRIERS_DEF

/// Число несущих частот АРС
#define CARRIER_FREQ_NUM_ARS	7

/// Частоты несущей АРС
typedef enum
{
	F_075_HZ,
	F_125_HZ,
	F_175_HZ,
	F_225_HZ,
	F_275_HZ,
	F_325_HZ,
	F_275_HZ_AO,

	F_ARS_COUNT,

	F_WRONG = 0x7
} TArsFreqNum;

const uint16_t ArsFreq[CARRIER_FREQ_NUM_ARS] = {75, 125, 175, 225, 275, 325, 275};


#define ARS_275_AO_PERIOD			1.65		// 1.5 - 1.8
//#define ARS_275_AO_PERIOD(_samplerate)		(uint16_t)((float)_samplerate * 1.65) // 1.5 - 1.8


#endif /* ARS_CARRIERS_DEF */


#endif /* __SIGNAL_ARS_H__ */