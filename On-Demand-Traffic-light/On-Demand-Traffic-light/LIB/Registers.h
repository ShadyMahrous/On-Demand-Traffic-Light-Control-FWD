/*
 * Registers.h
 *
 * Created: 2/22/2023 9:54:56 AM
 *  Author: Shady Mahrous
 */ 
#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "STD_Types.h"

//Pin numbers
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//PORTA registers
#define PORTA (*(volatile uint8_t*)(0x3B))
#define DDRA (*(volatile uint8_t*)(0x3A))
#define PINA (*(volatile uint8_t*)(0x39))

//PORTB registers
#define PORTB (*(volatile uint8_t*)(0x38))
#define DDRB (*(volatile uint8_t*)(0x37))
#define PINB (*(volatile uint8_t*)(0x36))

//PORTC registers
#define PORTC (*(volatile uint8_t*)(0x35))
#define DDRC (*(volatile uint8_t*)(0x34))
#define PINC (*(volatile uint8_t*)(0x33))


//PortD registers
#define PORTD (*(volatile uint8_t*)(0x32))
#define DDRD (*(volatile uint8_t*)(0x31))
#define PIND (*(volatile uint8_t*)(0x30))


//****************************
//* Timer0 REGISTERS
//****************************
#define TCCR0 (*(volatile uint8_t*)(0x53))
#define TCNT0 (*(volatile uint8_t*)(0x52))
#define TIFR (*(volatile uint8_t*)(0x58))
#define TIMSK (*(volatile uint8_t*)(0x59))


//****************************
//  Interrupt REGISTERS
//****************************
#define SREG  (*(volatile uint8_t*)(0x5F))
#define GICR  (*(volatile uint8_t*)(0x5B))
#define MCUCR (*(volatile uint8_t*)(0x55))
#define GIFR  (*(volatile uint8_t*)0x5A)


#endif /* REGISTERS_H_ */