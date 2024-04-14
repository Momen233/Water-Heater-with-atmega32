/*
 * EEPROM.c
 *
 * Created: 2/28/2024
 *  Author: Mo'men Mohamed
 */ 

#include "EEPROM.h"

/*----------------------------------------------------------------------------*-
EEPROM_read() : To read the data from the EEPROM given the Address.
-*----------------------------------------------------------------------------*/

u16 EEPROM_read(const u16 addr){
	// Setup Address Register
	EEARL = (char)addr;
	EEARH = (char)(addr>>8);
	
	// Start Reading
	SET_BIT(EECR,EERE);
	
	// Return Data
	return EEDR;
}

/*----------------------------------------------------------------------------*-
EEPROM_write() : to write data in the EEPROM given the address and the data.
-*----------------------------------------------------------------------------*/

void EEPROM_write(const u16 addr, u16 data){
	u16 INT_EN=0;
		
	// Setup Address Register
	EEARL = (char)addr;
	EEARH = (char)(addr>>8);
	
	// Put Data in Data Register
	EEDR = data;
	
	// Disable Interrupts to work fine
	if(((SREG&(1<<7))>>7)==1){
		INT_EN = 1;
		CLEAR_BIT(SREG,7);
	}
	
	// Start Writing
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(((EECR&(1<<EEWE))>>EEWE)==1);
	
	// Back
	if (INT_EN==1)
	{
		SET_BIT(SREG,7);
	}
	
}