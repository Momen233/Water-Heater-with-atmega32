/*
 * cool_heat_elements.h
 *
 * Created: 3/25/2024
 *  Author: Youssef Mohamed
 */ 

#include "bit_math.h"
#include "std_types.h"

#ifndef COOL_HEAT_ELEMENTS_H_
#define COOL_HEAT_ELEMENTS_H_

#define  DIO_PORTB   (*(volatile u8 *)0x38)

#define  DIO_DDRB    (*(volatile u8 *)0x37)


#define HEAT_PORT_DIR DIO_DDRB
#define HEAT_PORT DIO_PORTB
#define HEAT_PIN 4

#define COOL_PORT_DIR DIO_DDRB
#define COOL_PORT DIO_PORTB
#define COOL_PIN 5

void heat_init(void);
void heat_start(void);
void heat_stop(void);

void cool_init(void);
void cool_start(void);
void cool_stop(void);


#endif /* COOL_HEAT_ELEMENTS_H_ */