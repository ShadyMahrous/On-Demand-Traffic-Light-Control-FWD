/*
 * Timer.c
 *
 * Created: 3/12/2023 7:58:45 PM
 *  Author: Shady Mahrous
 */ 
#include "Timer.h"
#define F_CPU 1000000				//at 1MHz
#define tickTime (1024/1000.0)		//Ttick = Presc/FCPU
//max delay 262.144 m.second

#include <math.h>


void TIMER_init()
{
	
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	
	/*Set timer 0 to normal mode
		TCCR0 = 0x00;
		
		// Enable timer 0 overflow interrupt
		
		SET_BIT(TIMSK,0);
		// Enable global interrupts
		
		SET_BIT(SREG,7);
		
		SET_BIT(MCUCR,1);	//setting interrupts to rising edge
		SET_BIT(MCUCR,0);*/
}

void TIMER_delay(uint32_t millisec)
{uint16_t numberOfOverflows, TimerInitial, overflow_Counter ;
	double maxDelay;
	overflow_Counter = 0;
	maxDelay = 262.144; //max delay in ms possible with this timer configuration

	if(millisec<maxDelay)
	{
		TimerInitial = (maxDelay-millisec)/tickTime;
		numberOfOverflows = 1;
	}
	else if (millisec == (uint16_t) maxDelay)
	{
		TimerInitial = 0;
		numberOfOverflows = 1;
	}
	else
	{
		numberOfOverflows = ceil((uint16_t) (millisec/maxDelay));
		TimerInitial = 256 - (maxDelay-millisec)/tickTime;
	}

	TCNT0 = TimerInitial;


	// Set prescaler to 1024 and start timer
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,2);

	while (overflow_Counter != numberOfOverflows)
	{
		while((TIFR & (1<<0)) == 0);
		//TIFR |= (1<<0);	//reset overflow flag
		
		SET_BIT(TIFR,0);
		overflow_Counter = overflow_Counter + 1 ;
		
	}
	TCCR0 = 0;			//stop timer
	return ;
	
}