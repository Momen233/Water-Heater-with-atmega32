/*
 * ssd.h
 *
 * Created: 2/28/2024
 *  Author: Mo'men Mohamed
 */


#ifndef SSD_H_
#define SSD_H_


#define F_CPU 1000000UL
#include <util/delay.h>
#include "std_types.h"
#include "bit_math.h"

#define  DIO_PORTB   (*(volatile u8 *)0x38)
#define  DIO_PORTD   (*(volatile u8 *)0x32)

#define  DIO_DDRB    (*(volatile u8 *)0x37)
#define  DIO_DDRD    (*(volatile u8 *)0x31)

// SSD Display Macros
#define DISP1 1
#define DISP2 2

#define SSD_ENABLE_PORT_DIR DIO_DDRB
#define SSD_ENABLE_PORT DIO_PORTB
#define SSD1_ENABLE_PIN 6
#define SSD2_ENABLE_PIN 7
#define SSD_DATA DIO_PORTD
#define SSD_PORT_DIR DIO_DDRD

// SSD Control Functions
void SSD_init(void);
void SSD_send(u16 N);
void SSD_enable(u8 disp);
void SSD_disable(void);
void SSD_turn_off(void);
void SSD_write(u16 N);


#endif /* SSD_H_ */
