/*
 * ADC.h
 *
 * Created: 3/27/2024
 *  Author: Youssef Mohamed
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "bit_math.h"

#define ADMUX           (*(volatile u8*)0x27)

#define REFS1	7
#define REFS0	6
#define ADLAR	5
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

#define ADCSRA          (*(volatile u8*)0x26)

#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

#define ADCH            (*(volatile u8*)0x25)

#define ADCL            (*(volatile u8*)0x24)

void ADC_init(void);
u16 ADC_read(void);


#endif /* ADC_H_ */