/*
 * Push_Button.c
 *
 * Created: 3/12/2023 8:06:28 PM
 *  Author: Shady Mahrous
 */ 

#include "Push_Button.h"


void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin)
{
	PIN_Init(BUTTON_PORT,BUTTON_PIN,INPUNT);
	//SET_BIT (GICR,6);	//enabling external interrupt 0
	 
}
int BUTTON_read(uint8_t buttonPort,uint8_t buttonPin)
{
	uint8_t reading = Not_Pressed;
	reading = PIN_Read(BUTTON_PORT,BUTTON_PIN);
	return reading;
}
