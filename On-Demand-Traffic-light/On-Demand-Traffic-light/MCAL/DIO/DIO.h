/*
 * DIO.h
 *
 * Created: 3/12/2023 7:57:51 PM
 *  Author: Shady Mahrous
 */ 
#ifndef DIO_H_
#define DIO_H_

#include "../../LIB/Registers.h"
#include "../../LIB/Bit_Math.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define INPUNT	0
#define OUTPUT	1

#define HIGH	1
#define LOW		0


void PIN_Init(uint8_t portName, uint8_t pinNumber,uint8_t direction);
void PIN_Write(uint8_t portName, uint8_t pinNumber,uint8_t value);
uint8_t PIN_Read(uint8_t portName, uint8_t pinNumber);
void PIN_Toggle(uint8_t portName, uint8_t pinNumber);



#endif /* DIO_H_ */