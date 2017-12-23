#include "timer.h"

#define COUNTER_ENABLE_bm  		(1<<0)
#define COUNTER_RESET_bm		 	(1<<1)
#define MR0_INTERRUPT_bm			(1<<0)

void InitTimer0(void){
	
	T0TCR |= COUNTER_ENABLE_bm;				
}

void WaitOnTimer0(unsigned int uiTime){
			
	for(uiTime*=15000;T0TC<uiTime;){
	}
	T0TCR |= COUNTER_RESET_bm;	
	T0TCR &= !COUNTER_RESET_bm;
}

void InitTimer0Match0(unsigned int iDelayTimer){
	
	T0MR0 = iDelayTimer*15000;
	T0TCR |= COUNTER_RESET_bm;
	T0TCR &= !COUNTER_RESET_bm;
	T0TCR |= COUNTER_ENABLE_bm;	
}

void WaitOnTimer0Match0(void){
	
	T0MCR |= MR0_INTERRUPT_bm;	
	for(;!(T0IR==0x1);){
	}
	T0IR  |= MR0_INTERRUPT_bm;
}
