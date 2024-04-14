/*
 * ADC.c
 *
 * Created: 3/27/2024
 *  Author: Youssef mohamed
 */ 

#include "ADC.h"

/*----------------------------------------------------------------------------*-
ADC_init() : to initialize the ADC to sense temperature from the sensor connected.
-*----------------------------------------------------------------------------*/

void ADC_init(){
	
	// Choosing reference voltage option.
	// the AVCC pin with a capacitor at the AREF pin.
	SET_BIT(ADMUX,REFS0);
	
	// Choosing Channel One (Single Ended In.) at A0 pin.
	CLEAR_BIT(ADMUX,MUX0);
	CLEAR_BIT(ADMUX,MUX1);
	CLEAR_BIT(ADMUX,MUX2);
	CLEAR_BIT(ADMUX,MUX3);
	CLEAR_BIT(ADMUX,MUX4);
	
	// Choosing the Data to be Right Adjusted in the Data Reg.
	CLEAR_BIT(ADMUX,ADLAR);
	
	// Choosing Prescaler for the ADC clock.
	// the following is choosing (2) as a Prescaler.
	SET_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
	
	// Enable the ADC
	SET_BIT(ADCSRA,ADEN);
	
}

/*----------------------------------------------------------------------------*-
ADC_read() : to read data from the temperature sensor whenever it's called.
-*----------------------------------------------------------------------------*/

u16 ADC_read(){
	
	u16 data;
	
	// Start Conversion
	SET_BIT(ADCSRA,ADSC);
	
	// Wait for flag to be set.
	// Indication of finished conversion
	while(GET_BIT(ADCSRA,ADIF)==0);
	
	// Read Data from the ADC Data Register
	// Read the Low register first!
	data = ADCL;
	data |= (ADCH<<8);
	
	// Clear Flag (As we are not using the interrupt)
	// It won't be cleared automatically!
	SET_BIT(ADCSRA,ADIF);
	
	return data;	
}