/*
 * Timer.c
 *
 * Created: 2/15/2024
 *  Author: Youssef Mohamed
 */ 


#include "Timer.h"


/*----------------------------------------------------------------------------*-
timer1_init() : to initialize timer(1) to measure time between tasks every 1ms.
-*----------------------------------------------------------------------------*/

void timer1_init(){
	
	// we are working with AVR ATmega32 chip with a frequency of 1 MHz
	// It triggers an interrupt every One millisecond
	
	
	// Select CTC Mode
	SET_BIT(TCCR1B,WGM12);
	
	
	// Load Value in OCR1A
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;
	/*
	// Load Value in OCR1B
	OCR1BH = 0b00000011;
	OCR1BL = 0b11010001;
	*/
	// Select Clock Prescaler (F_CPU / 1024)
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	
	// Enable Global Interrupt bit
	SET_BIT(SREG,7);

}

/*----------------------------------------------------------------------------*-
timer0_init() : to initialize timer(0) to trigger INT every 100ms to get Temp.
-*----------------------------------------------------------------------------*/

void timer0_init(){
	
	// choose mode
	SET_BIT(TCCR0,WGM01);
	
	// Load Value in OCR0
	OCR0 = 250;
	
	// Choose Prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// Enable Timer INT
	SET_BIT(SREG,7);		//Global Interrupt Enable	sei()
	SET_BIT(TIMSK,OCIE0);
	
}

/*----------------------------------------------------------------------------*-
timer1_INT_disable() : to stop timer(1) from triggering INTERRUPTS.
-*----------------------------------------------------------------------------*/

void timer1_INT_disable(){
	
	// Disable Interrupts when Comparing with values A and B
	SET_BIT(TIMSK,OCIE1A);
	//clr_bit(TIMSK,OCIE1B);
}

/*----------------------------------------------------------------------------*-
timer1_INT_enable() : to make timer(1) start.
-*----------------------------------------------------------------------------*/

void timer1_INT_enable(){
	
	// Enable Interrupts when Comparing with values A and B
	SET_BIT(TIMSK,OCIE1A);
	//set_bit(TIMSK,OCIE1B);
}