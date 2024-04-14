/*
 * EEPROM.h
 *
 * Created: 2/28/2024
 *  Author: Mo'men Mohamed
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "std_types.h"
#include "bit_math.h"

#define SREG            *((volatile u8 *)0x5F)

#define EEARH			*((volatile u8 *)0x3F)

#define EEAR9	1
#define EEAR8	0

#define EEARL           *((volatile u8 *)0x3E)

#define EEDR            *((volatile u8 *)0x3D)

#define EECR			*((volatile u8 *)0x3C)

#define EERIE	3
#define EEMWE	2
#define EEWE	1
#define EERE	0

void EEPROM_write(const u16 addr, u16 data);
u16 EEPROM_read(const u16 addr);

#endif /* EEPROM_H_ */