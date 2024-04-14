/*
 * led.h
 *
 * Created: 3/30/2024
 *  Author: Mo'men Mohamed
 */


#ifndef LED_H_
#define LED_H_


#include "std_types.h"
#include "bit_math.h"

#define  DIO_PORTB   (*(volatile u8 *)0x38)

#define  DIO_DDRB    (*(volatile u8 *)0x37)


#define LED_PORT_DIR DIO_DDRB
#define LED_PORT DIO_PORTB
#define LED_PIN 0

void led_init(void);
void led_on(void);
void led_off(void);


#endif /* LED_H_ */
