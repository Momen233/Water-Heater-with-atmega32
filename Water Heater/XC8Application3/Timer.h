/*
 * Timer.h
 *
 * Created: 2/15/2024
 *  Author: Youssef Mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "std_types.h"
#include "bit_math.h"


#define SREG            *((volatile u8 *)0x5F)
#define TCCR1B			*((volatile u8 *)0x4E)

#define ICNC1	7
#define ICES1	6
#define WGM13	4
#define WGM12	3
#define CS12	2
#define CS11	1
#define CS10	0

#define OCR1AH			*((volatile u8 *)0x4B)
#define OCR1AL			*((volatile u8 *)0x4A)

#define TCCR0			*((volatile u8 *)0x53)

#define	FOC0	7
#define WGM00	6
#define COM01	5
#define COM00	4
#define WGM01	3
#define CS02	2
#define CS01	1
#define CS00	0

#define TIMSK			*((volatile u8 *)0x59)

#define OCIE2	7
#define TOIE2	6
#define TICIE1	5
#define OCIE1A	4
#define OCIE1B	3
#define TOIE1	2
#define OCIE0	1
#define TOIE0	0

#define OCR0			*((volatile u8 *)0x5C)



void timer1_init();
void timer0_init();
void timer1_INT_disable();
void timer1_INT_enable();

#endif /* TIMER_H_ */