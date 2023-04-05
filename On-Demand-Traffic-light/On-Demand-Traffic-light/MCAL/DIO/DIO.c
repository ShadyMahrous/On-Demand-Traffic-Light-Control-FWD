/*
 * DIO.c
 *
 * Created: 3/12/2023 7:57:37 PM
 *  Author: Shady Mahrous
 */ 

#include "DIO.h"

void PIN_Init(uint8_t portName, uint8_t pinNumber,uint8_t direction)
{
	switch (portName){
		case PORT_A:
		if (direction == INPUNT)
		{
			CLR_BIT(DDRA, pinNumber);
		}
		else if (direction == OUTPUT)
		{		
			SET_BIT(DDRA, pinNumber);
		}
		else
		{
		}
		break;
		case PORT_B:
		if (direction == INPUNT)
		{
			CLR_BIT(DDRB, pinNumber);
		}
		else if (direction == OUTPUT)
		{
			SET_BIT(DDRB, pinNumber);
		}
		else
		{
		}
		break;
		case PORT_C:
		if (direction == INPUNT)
		{
			CLR_BIT(DDRB, pinNumber);
		}
		else if (direction == OUTPUT)
		{	
			SET_BIT(DDRC, pinNumber);
		}
		else
		{
		}
		break;
		
		case PORT_D:
		if (direction == INPUNT)
		{
			CLR_BIT(DDRD, pinNumber);
		}
		else if (direction == OUTPUT)
		{
			SET_BIT(DDRD, pinNumber);
		}
		else
		{
		}
		break;
	}
}
void PIN_Write(uint8_t portName, uint8_t pinNumber,uint8_t value)
{
	switch (portName)
	{
		case PORT_A:
		if (value == LOW)
		{
			CLR_BIT(PORTA,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTA,pinNumber);
		}
		else
		{
		}
		break;
		case PORT_B:
		if (value == LOW)
		{
			CLR_BIT(PORTB,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTB,pinNumber);
		}
		else
		{
		}
		break;
		case PORT_C:
		if (value == LOW)
		{
			CLR_BIT(PORTC,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTC,pinNumber);
		}
		else
		{
		}
		break;
		case PORT_D:
		if (value == LOW)
		{
			CLR_BIT(PORTD,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTD,pinNumber);
		}
		else
		{
		}
		break;
	}
}
uint8_t PIN_Read(uint8_t portName, uint8_t pinNumber)
{
	uint8_t reading=0;
	switch(portName){
		case PORT_A:
		//*reading = (PINA&(1<<pinNumber))>>pinNumber;
		reading =	GET_BIT(PINA,pinNumber); 
		break;
		
		case PORT_B:
		reading =	GET_BIT(PINB,pinNumber);
		break;
		
		case PORT_C:
		reading = GET_BIT(PINC,pinNumber);
		break;
		
		case PORT_D:
		reading = GET_BIT(PIND,pinNumber);
		break;
	}
	return reading;
}
void PIN_Toggle(uint8_t portName, uint8_t pinNumber)
{
	switch (portName)
	{
		case PORT_A:
		TOG_BIT(PORTA,pinNumber);
		break;
		
		case PORT_B:
		TOG_BIT(PORTB,pinNumber);
		break;
		
		case PORT_C:
		TOG_BIT(PORTC,pinNumber);
		break;
		
		case PORT_D:
		TOG_BIT(PORTD,pinNumber);
		break;
	}
}