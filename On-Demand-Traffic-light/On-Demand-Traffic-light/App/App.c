/*
 * App.c
 *
 * Created: 2/22/2023 9:23:03 AM
 *  Author: Shady Mahrous
 */ 
#include "App.h"
EN_carColor_t CarLedColor = GREEN;
void App_init(void)
{
	/********** LEDS INIT ************/
	LED_Init(LED_CAR_PORT,LED_CAR_GREEN_PIN);
	LED_Init(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
	LED_Init(LED_CAR_PORT,LED_CAR_RED_PIN);
	
	LED_Init(LED_PED_PORT,LED_PED_GREEN_PIN);
	LED_Init(LED_PED_PORT,LED_PED_YELLOW_PIN);
	LED_Init(LED_PED_PORT,LED_PED_RED_PIN);
	
	//LED_Init(PORT_C,PIN0);
	/********* PUSH_BUTTON INIT *******/
	BUTTON_init(BUTTON_PORT,BUTTON_PIN);
	
	/*********** TIMER INIT ***********/
	TIMER_init();
	
	
	/*********** EXT_INT INIT ***********/
	EXT_INT_TriggerEdge(EX_INT0,RISING_EDGE);
	EXT_INT_ENABLE(EX_INT0);
	EXT_INT_EnableGlobal();
	
	EXT_INT_SetCallBack(EX_INT0,EXT_INT0_Exe);
}

void blinkYellow(void)
{
	
	for (uint8_t i = 0; i < 5;i++)
	{
		LED_On(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
		LED_On(LED_PED_PORT,LED_PED_YELLOW_PIN);
		TIMER_delay(1000);
		LED_Off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
		LED_Off(LED_PED_PORT,LED_PED_YELLOW_PIN);
		TIMER_delay(1000);
	}

}


void NormalMode(void)
{	
	 
	//turn all LEDs off to clear whatever was done in pedestrian mode (if coming from there)
	LED_Off(LED_CAR_PORT,LED_CAR_GREEN_PIN);
	LED_Off(LED_CAR_PORT,LED_CAR_RED_PIN);
	LED_Off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
	
	LED_Off(LED_PED_PORT,LED_PED_GREEN_PIN);
	LED_Off(LED_PED_PORT,LED_PED_YELLOW_PIN);
	LED_Off(LED_PED_PORT,LED_PED_RED_PIN);
	
	
	/*******  1.car green on & pedestrian red on for 5 seconds *********/ 
	LED_On(LED_CAR_PORT,LED_CAR_GREEN_PIN);
	LED_On(LED_PED_PORT,LED_PED_RED_PIN);
	CarLedColor = GREEN;
	TIMER_delay(5000); //delay 5 seconds
	
	
	//car yellow light to blink for 5 seconds	
	CarLedColor = YELLOW;
	blinkYellow();
	LED_Off(LED_PED_PORT,LED_PED_RED_PIN);
	LED_Off(LED_CAR_PORT,LED_CAR_GREEN_PIN); //turn green led off 
	LED_Off(LED_CAR_PORT,LED_PED_RED_PIN); //turning off the pedestrian red 
	
	/*******  2.car RED on & pedestrian GREEN on for 5 seconds *********/ 
	CarLedColor = RED;
	
	LED_On(LED_CAR_PORT,LED_CAR_RED_PIN);
	LED_On(LED_PED_PORT,LED_PED_GREEN_PIN);
	
	TIMER_delay(5000);
	//start blinking car yellow light
	CarLedColor = YELLOW;
	blinkYellow();
	LED_Off(LED_CAR_PORT,LED_CAR_RED_PIN); //turn car red off
	LED_On(LED_PED_PORT,LED_PED_RED_PIN); //turn ped red on
	LED_Off(LED_PED_PORT,LED_PED_GREEN_PIN); //turn ped green off

}


void pedestrianMode()
{
	switch(CarLedColor)
	{		
		
		
		case RED :
			//car red on and ped green on for 5 seconds
			LED_On(LED_CAR_PORT,LED_CAR_RED_PIN);
			LED_On(LED_PED_PORT,LED_CAR_GREEN_PIN);		
			TIMER_delay(5000);	
			
			/*
				continue as if in normal mode to complete the cycle since the ISR returns to the
				place it came from.
			*/
			
			
			LED_Off(LED_CAR_PORT,LED_CAR_RED_PIN);
			//while green still on for pedestrians
			for (uint8_t i = 0; i < 5;i++)
			{
				LED_On(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
				TIMER_delay(500);
				LED_Off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
				TIMER_delay(500);
			} 
			
			//turn off ped green and turn on ped red and car green
			LED_Off(LED_PED_PORT,LED_CAR_GREEN_PIN);
			LED_On(LED_PED_PORT,LED_CAR_RED_PIN);//ped red on
			LED_On(LED_CAR_PORT,LED_CAR_GREEN_PIN); //car green	
			TIMER_delay(5000);
			
			LED_Off(LED_CAR_PORT,LED_CAR_GREEN_PIN); //turn off car green 
			blinkYellow(); //blink both yellow
			LED_On(LED_CAR_PORT,LED_CAR_RED_PIN);//turn on car red and back to normal mode
			//LED_off(LED_PED_PORT,LED_CAR_PORT_R_PIN);
			
			
			break;
		
		case YELLOW:
			//1.both yellow blink for 5 seconds
			blinkYellow();
		
			LED_Off(LED_CAR_PORT,LED_CAR_GREEN_PIN);	// CAR GREEN OFF
			LED_On(LED_CAR_PORT,LED_CAR_RED_PIN);	//car red on
			
			LED_Off(LED_PED_PORT,LED_PED_RED_PIN);	// PED RED OFF
			LED_On(LED_PED_PORT,LED_PED_GREEN_PIN); //ped green on	
			
			
			TIMER_delay(5000);
			
			
			blinkYellow();
			LED_Off(LED_CAR_PORT,LED_CAR_RED_PIN);	//car RED OFF
			LED_Off(LED_PED_PORT,LED_CAR_GREEN_PIN); //ped green off
			
			LED_On(LED_CAR_PORT,LED_CAR_GREEN_PIN); //car green on
			LED_On(LED_PED_PORT,LED_CAR_RED_PIN); //ped red on
			TIMER_delay(5000);
			 			
 			break;
			
		case GREEN:
			blinkYellow();
			
			LED_Off(LED_CAR_PORT,LED_CAR_GREEN_PIN); //car green off
			LED_On(LED_CAR_PORT,LED_CAR_RED_PIN); //car red on

			LED_Off(LED_PED_PORT,LED_CAR_RED_PIN); //ped red off
			LED_On(LED_PED_PORT,LED_CAR_GREEN_PIN); //ped green on
			
			TIMER_delay(5000);
	
			blinkYellow();
					
			LED_Off(LED_PED_PORT,LED_CAR_GREEN_PIN); //ped green off
			LED_On(LED_PED_PORT,LED_CAR_RED_PIN); //ped red on
			
			LED_Off(LED_CAR_PORT,LED_CAR_RED_PIN);
			LED_On(LED_CAR_PORT,LED_CAR_GREEN_PIN); //car green on
			
			TIMER_delay(5000);
			
			break;
	}
	
}

void App_Start(void)
{
	while(1)
	{
		NormalMode();
	}
}

void EXT_INT0_Exe(void)
{
	while(BUTTON_read(BUTTON_PORT,BUTTON_PIN) == Pressed);  
	//LED_Toggle(PORT_C,PIN0);
	pedestrianMode();
}
