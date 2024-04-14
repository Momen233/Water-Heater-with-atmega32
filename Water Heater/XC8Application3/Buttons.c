/*
 * Buttons.c
 *
 * Created: 4/05/2024
 *  Author: Youssef Mohamed
 */ 

#include "Buttons.h"

/*----------------------------------------------------------------------------*-
Buttons_init() : to initialize Buttons by making their pins as INPUT pins,
enabling the internal pull-up resistor, and enabling the external interrupt
for the ON/OFF button.
-*----------------------------------------------------------------------------*/

void Buttons_init(void){
	// Setting the pins as INPUT pins
	CLEAR_BIT(B_PORT_DIR,ON_OFF_PIN);
	CLEAR_BIT(B_PORT_DIR,UP_PIN);
	CLEAR_BIT(B_PORT_DIR,DOWN_PIN);	
	
	// Enable internal Pull-Up Resistor
	
	SET_BIT(B_PORT,ON_OFF_PIN);
	SET_BIT(B_PORT,UP_PIN);
	SET_BIT(B_PORT,DOWN_PIN);
	
	
	// This Following Section is for the external interrupt
	// assigned to the ON/OFF Button.
	
	// Enable Global Interrupt bit
	SET_BIT(SREG,7);
	
	// Trigger with Rising Edge
	SET_BIT(MCUCSR,ISC2);
	
	// Enable INT2 (External Interrupt)
	SET_BIT(GICR,INT2);
}


/*----------------------------------------------------------------------------*-
UP_pressed() : Check if UP button is pressed or not and return the result.
-*----------------------------------------------------------------------------*/

u8 UP_pressed(void){
	// Check if pressed for the first time
	if(!(GET_BIT(DIO_PINB,UP_PIN))){
		// wait for 50 ms to make sure it's pressed (debouncing solution)
		_delay_ms(DEBOUNCE_INTERVAL);
		
		// check one more time
		if (!(GET_BIT(DIO_PINB,UP_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;	
}

/*----------------------------------------------------------------------------*-
DOWN_pressed() : Check if DOWN button is pressed or not and return the result.
-*----------------------------------------------------------------------------*/

u8 DOWN_pressed(void){
	// Check if pressed for the first time
	if(!(GET_BIT(DIO_PINB,DOWN_PIN))){
		// wait for 50 ms to make sure it's pressed (debouncing solution)
		_delay_ms(DEBOUNCE_INTERVAL);
	
		// check one more time
		if (!(GET_BIT(DIO_PINB,DOWN_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}
