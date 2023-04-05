/*
 * Timer.h
 *
 * Created: 3/12/2023 7:59:03 PM
 *  Author: Shady Mahrous
 */ 
#ifndef TIMER_H_
#define TIMER_H_

#include "../../LIB/Registers.h"
#include "../../LIB/Bit_Math.h"

void TIMER_init();				//initialize Timer0
void TIMER_delay(uint32_t millisec);	//delay of specific amount default uses 256 prescaler


// select crystal oscillator frequency in MHz
#define CRYSTAL_FREQ       16
// select PRESCALER_D_F options --> [ 256 , 1024 ]
#define PRESCALER_D_F      1024


#endif /* TIMER_H_ */