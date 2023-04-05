/*
 * EXT_INT.c
 *
 * Created: 3/12/2023 7:58:24 PM
 *  Author: Shady Mahrous
 */ 

#include "EXT_INT.h"

#include "../../HAL/LED/LED.h"

static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;
static void (*INT2_Fptr) (void)=NULLPTR;

void EXT_INT_EnableGlobal()
{
	SET_BIT(SREG,7);
}

void EXT_INT_DisableGlobal()
{
	CLR_BIT(SREG,7);
}

void EXT_INT_ENABLE(EXT_INT_NO interrupt)
{
	switch(interrupt)
	{
		case EX_INT0 : SET_BIT(GICR,INT0);break;
		case EX_INT1 : SET_BIT(GICR,INT1);break;
		case EX_INT2 : SET_BIT(GICR,INT2);break;
	}
}

void EXT_INT_DISABLE(EXT_INT_NO interrupt)
{
	switch(interrupt)
	{
		case EX_INT0 : CLR_BIT(GICR,INT0);break;
		case EX_INT1 : CLR_BIT(GICR,INT1);break;
		case EX_INT2 : CLR_BIT(GICR,INT2);break;
	}
}

void EXT_INT_TriggerEdge(EXT_INT_NO interrupt,TriggerEdge_Type TriggerType)
{
	switch(interrupt)
	{
		case EX_INT0 :
		switch(TriggerType)
		{
			case LOW_LEVEL :
			CLR_BIT(MCUCR,0);	// ISC00
			CLR_BIT(MCUCR,1);	// ISC01
			break;
			case LOGIC_CHANGE :
			SET_BIT(MCUCR,0);	// ISC00
			CLR_BIT(MCUCR,1);	// ISC01
			break;
			case FALLING_EDGE :
			CLR_BIT(MCUCR,0);	// ISC00
			SET_BIT(MCUCR,1);	// ISC01
			break;
			case RISING_EDGE :
			SET_BIT(MCUCR,0);	// ISC00
			SET_BIT(MCUCR,1);	// ISC01
			break;
		}break;
		case EX_INT1 :
		switch(TriggerType)
		{
			case LOW_LEVEL :
			CLR_BIT(MCUCR,2);	// ISC10
			CLR_BIT(MCUCR,3);	// ISC11
			break;
			case LOGIC_CHANGE :
			SET_BIT(MCUCR,2);	//ISC10
			CLR_BIT(MCUCR,3);	//ISC11
			break;
			case FALLING_EDGE :
			CLR_BIT(MCUCR,2);	//ISC10
			SET_BIT(MCUCR,3);	//ISC11
			break;
			case RISING_EDGE :
			SET_BIT(MCUCR,2);	//ISC10
			SET_BIT(MCUCR,3);	//ISC11
			break;
		}break;
		case EX_INT2 :
		switch(TriggerType)
		{
			case FALLING_EDGE :
			CLR_BIT(MCUCR,6);	// ISC2
			break;
			case RISING_EDGE :
			SET_BIT(MCUCR,6);	// ISC2
			break;
			default : 
			SET_BIT(MCUCR,6);	// ISC2
			break;	
		}break;
	}
}


/*************Call Back function***************/

 void EXT_INT_SetCallBack(EXT_INT_NO Interrupt,void(*LocalPtr)(void))
 {
 	switch(Interrupt){
 		case EX_INT0: INT0_Fptr=LocalPtr; break;
 		case EX_INT1: INT1_Fptr=LocalPtr; break;
 		case EX_INT2: INT2_Fptr=LocalPtr; break;
 	}
 }
//
//void EXT_INT_SetCallBack0(void(*LocalPtr)(void))
//{
//	
//		 INT0_Fptr=LocalPtr; 
//	
//}

_ISR(INT0_VECT)
{
	INT0_Fptr();
}



/*
// 
// void ISR(INT0_vect)
// {
// 	if (BUTTON_read(BUTTON_PORT,BUTTON_PIN) == Pressed)
// 	{
// 		LED_on(LED_CAR_PORT,LED_CAR_GREEN_PIN);
// 		//INT0_Fptr();
// 	}
// }
*/
/*
ISR(INT1_vect)
{
	if (INT1_Fptr!=NULLPTR)
	{
		INT1_Fptr();
	}
}
ISR(INT2_vect)
{
	if (INT2_Fptr!=NULLPTR)
	{
		INT2_Fptr();
	}
}*/