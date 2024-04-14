/*
 * Button.h
 *
 * Created: 4/05/2024
 *  Author: Youssef Mohamed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU 1000000UL
#include <util/delay.h>
#include "bit_math.h"
#include "std_types.h"

#define DIO_PORTB		*((volatile u8 *)0x38)
#define DIO_DDRB		*((volatile u8 *)0x37)
#define  DIO_PINB		*((volatile u8 *)0x36)

#define SREG            *((volatile u8 *)0x5F)
#define MCUCR           *((volatile u8 *)0x55)

#define SE		7
#define SM2		6
#define SM1		5
#define SM0		4
#define ISC11	3
#define ISC10	2
#define ISC01	1
#define ISC00	0

#define MCUCSR          *((volatile u8 *)0x54)

#define JTD		7
#define ISC2	6

#define JTRF	4
#define WDRF	3
#define BORF	2
#define EXTRF	1
#define PORF	0

#define GICR            *((volatile u8 *)0x5B)

#define INT1	7
#define INT0	6
#define INT2	5
#define IVSEL	1
#define IVCE	0

#define GIFR            *((volatile u8 *)0x5A)

#define INTF1	7
#define INTF0	6
#define INTF2	5

#define PRESSED 1
#define NOT_PRESSED 0

#define DEBOUNCE_INTERVAL 100
#define B_PORT DIO_PORTB
#define B_PORT_DIR DIO_DDRB

#define ON_OFF_PIN 2
#define UP_PIN 1
#define DOWN_PIN 3

// Buttons Reading Functions
void Buttons_init(void);
void ON_OFF_EXTI(void);

unsigned char UP_pressed(void);
unsigned char DOWN_pressed(void);


#endif /* BUTTON_H_ */