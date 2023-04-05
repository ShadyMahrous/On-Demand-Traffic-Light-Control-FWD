/*
 * App.h
 *
 * Created: 2/22/2023 9:23:19 AM
 *  Author: Shady Mahrous
 */ 
#ifndef APP_H_
#define APP_H_

#include "../LIB/Registers.h"
#include "../LIB/STD_Types.h"
#include "../HAL/LED/LED.h"
#include "../HAL/Push_Button/Push_Button.h"


void App_init(void);            // Initialize the application
void App_Start(void);           // Starts the application

void EXT_INT0_Exe(void);		// external interrupt execution function

#endif /* APP_H_ */