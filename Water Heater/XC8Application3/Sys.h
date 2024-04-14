/*
 * Sys.h
 *
 * Created: 4/10/2024
 *  Author: Omar Azab
 */ 


#ifndef SYS_H_
#define SYS_H_


// Description
/*
The system is using a modified cooperative scheduler. it has
only one task (ON_TASK) which executes the functionality of
the normally working WATER HEATER. the ON_TASK is also checking
if buttons are pressed so it can switch to the SETTING_MODE, 
which is another function (state) to allow the user to change
the set point - or the desired temperature.
*/

// when Reading the ADC, the value is halved due to some issues
// to the Temperature sensor in Proteus LM35. So, please, configure
// it depending on your sensor.

// Including All Peripherals
#define F_CPU 1000000UL
#include <util/delay.h>
#include "Sys_Config.h"
#include "bit_math.h"
#include "std_types.h"
#include "ADC.h"
#include "Buttons.h"
#include "Cool_Heat_Elements.h"
#include "LED.h"
#include "SSD_disp.h"
#include "Timer.h"
#include "EEPROM.h"

#define OFF 0
#define ON 1
#define SETTING 2

/****************************************
*                Vectors	            *
****************************************/

#define RESET       __vector_0		// External Pin, Power-on Reset, Brown-out Reset, Watchdog Reset, and JTAG AVR Reset
#define EX_INT0     __vector_1		// External Interrupt Request 0
#define EX_INT1     __vector_2		// External Interrupt Request 1
#define EX_INT2     __vector_3		// External Interrupt Request 2
#define TM2CM       __vector_4		// Timer/Counter2 Compare Match
#define TM2OV       __vector_5		// Timer/Counter2 Overflow
#define TM1CE       __vector_6		// Timer/Counter1 Capture Event
#define TM1CMA      __vector_7		// Timer/Counter1 Compare Match A
#define TM1CMB      __vector_8		// Timer/Counter1 Compare Match B
#define TM1OV       __vector_9		// Timer/Counter1 Overflow
#define TM0CM       __vector_10		// Timer/Counter0 Compare Match
#define TM0OV       __vector_11		// Timer/Counter0 Overflow
#define SPI_STC     __vector_12		// Serial Transfer Complete
#define USART_RXC   __vector_13		// USART, Rx Complete
#define USART_UDRE  __vector_14		// USART Data Register Empty
#define USART_TXC   __vector_15		// USART, Tx Complete
#define ADC         __vector_16		// ADC Conversion Complete
#define EE_RDY      __vector_17		// EEPROM Ready
#define ANA_CM      __vector_18		// Analog Comparator
#define I2C         __vector_19		// Two-wire Serial Interface
#define SPM_RDY     __vector_20		// Store Program Memory Ready

void RESET(void) __attribute__((signal));
void EX_INT0(void) __attribute__((signal));
void EX_INT1(void) __attribute__((signal));
void EX_INT2(void) __attribute__((signal));
void TM2CM(void) __attribute__((signal));
void TM2OV(void) __attribute__((signal));
void TM1CE(void) __attribute__((signal));
void TM1CMA(void) __attribute__((signal));
void TM1CMB(void) __attribute__((signal));
void TM1OV(void) __attribute__((signal));
void TM0CM(void) __attribute__((signal));
void TM0OV(void) __attribute__((signal));
void SPI_STC(void) __attribute__((signal));
void USART_RXC(void) __attribute__((signal));
void USART_UDRE(void) __attribute__((signal));
void USART_TXC(void) __attribute__((signal));
void ADC(void) __attribute__((signal));
void EE_RDY(void) __attribute__((signal));
void ANA_CM(void) __attribute__((signal));
void I2C(void) __attribute__((signal));
void SPM_RDY(void) __attribute__((signal));

/**************************************** 
*               Functions               *
****************************************/

void sys_init(void);
void ON_state(void);
void OFF_state(void);
void SET_state(void);

void change_temp(void);
void add_new_temp(uint16_t * arr , uint16_t new_val);
uint16_t calc_avg_temp(uint16_t * arr);
void temp_arr_init(void);
void go_to_sleep(void);

/****************************************
*               Variables               *
****************************************/

// will add as needed

uint8_t Curr_state;

uint16_t temp_arr[NUM_OF_TEMP_MEASURES];
uint16_t desired_temp;
uint16_t actual_temp;
uint16_t avg_temp;

uint8_t temp_measure_f;
uint8_t temp_measure_counter;
uint8_t setting_counter;

uint16_t toggle_f;
uint8_t arr_counter;

#endif /* SYS_H_ */