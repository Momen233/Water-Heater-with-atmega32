/*
 * led.c
 *
 * Created: 3/30/2024
 *  Author: Mo'men Mohamed
 */


#include "LED.h"

/*----------------------------------------------------------------------------*-
led_init() : to init. heating element indication led by making it an output pin.
-*----------------------------------------------------------------------------*/

void led_init(void){

	// PIN 0 in the port is an output pin
	// the LED pin is initially off

	SET_BIT(LED_PORT_DIR,LED_PIN);
	CLEAR_BIT(LED_PORT,LED_PIN);

}

/*----------------------------------------------------------------------------*-
LED control : to turn on/off or toggle the LED.
-*----------------------------------------------------------------------------*/

void led_on(void){
	SET_BIT(LED_PORT,LED_PIN);
}

void led_off(void){
	CLEAR_BIT(LED_PORT,LED_PIN);
}
