/*
 * LED.c
 *
 * Created: 3/12/2023 8:06:00 PM
 *  Author: Shady Mahrous
 */ 

#include "LED.h"


void LED_Init(uint8_t ledPort,uint8_t ledPin)
{
	PIN_Init(ledPort,ledPin,OUTPUT);
}
void LED_On(uint8_t ledPort,uint8_t ledPin)
{
	PIN_Write(ledPort,ledPin,HIGH);
}
void LED_Off(uint8_t ledPort,uint8_t ledPin)
{
	PIN_Write(ledPort,ledPin,LOW);
}
void LED_Toggle(uint8_t ledPort,uint8_t ledPin)
{
	PIN_Toggle(ledPort,ledPin);
}