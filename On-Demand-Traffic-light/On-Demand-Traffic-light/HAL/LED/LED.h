/*
 * LED.h
 *
 * Created: 3/12/2023 8:05:49 PM
 *  Author: Shady Mahrous
 */ 
#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"

//LED set 1 for car
#define LED_CAR_PORT		PORT_A

#define LED_CAR_RED_PIN		PIN0
#define LED_CAR_YELLOW_PIN	PIN1
#define LED_CAR_GREEN_PIN	PIN2

//LED set 2 for pedestrians
#define LED_PED_PORT		PORT_B

#define LED_PED_RED_PIN		PIN0
#define LED_PED_YELLOW_PIN	PIN1
#define LED_PED_GREEN_PIN	PIN2

void LED_Init(uint8_t ledPort,uint8_t ledPin);
void LED_On(uint8_t ledPort,uint8_t ledPin);
void LED_Off(uint8_t ledPort,uint8_t ledPin);
void LED_Toggle(uint8_t ledPort,uint8_t ledPin);



#endif /* LED_H_ */