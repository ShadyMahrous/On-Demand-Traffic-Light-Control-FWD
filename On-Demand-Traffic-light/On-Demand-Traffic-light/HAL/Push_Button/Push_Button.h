/*
 * Push_Button.h
 *
 * Created: 3/12/2023 8:06:43 PM
 *  Author: Shady Mahrous
 */ 
#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_

#include "../../MCAL/DIO/DIO.h"
 #include "../../MCAL/EX_INT/EXT_INT.h"
 #include "../../MCAL/Timer0/Timer.h"

#define BUTTON_PORT PORT_D
#define BUTTON_PIN	PIN2
#define Pressed 1
#define Not_Pressed 0

void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);
int BUTTON_read(uint8_t buttonPort,uint8_t buttonPin);


#endif /* PUSH_BUTTON_H_ */