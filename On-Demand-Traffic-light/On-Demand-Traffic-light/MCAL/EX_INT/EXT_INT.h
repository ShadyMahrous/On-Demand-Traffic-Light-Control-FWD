/*
 * EXT_INT.h
 *
 * Created: 3/12/2023 7:58:13 PM
 *  Author: Shady Mahrous
 */ 
#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "../../LIB/STD_Types.h"
#include "../../LIB/Registers.h"
#include "../../LIB/Bit_Math.h"


#define NULLPTR ((void*)0)

#define INT0    6
#define INT1    7
#define INT2    5

#define INT0_VECT __vector_1
#define INT1_VECT __vector_2
#define INT2_VECT __vector_3

#define _ISR(Source) void Source(void) __attribute__ ((signal,used)) ; \
void Source(void)


typedef enum
{
	EX_INT0,
	EX_INT1,
	EX_INT2
}EXT_INT_NO;

typedef enum
{
	LOW_LEVEL,
	LOGIC_CHANGE,
	RISING_EDGE,
	FALLING_EDGE
}TriggerEdge_Type;


void EXT_INT_EnableGlobal();
void EXT_INT_DisableGlobal();

void EXT_INT_ENABLE(EXT_INT_NO interrupt);
void EXT_INT_DISABLE(EXT_INT_NO interrupt);

void EXT_INT_TriggerEdge(EXT_INT_NO interrupt,TriggerEdge_Type TriggerType);

void EXT_INT_SetCallBack(EXT_INT_NO interrupt,void(*FunctionPtr)(void));

//void EXT_INT_SetCallBack0(void(*LocalPtr)(void));

#endif /* EXT_INT_H_ */