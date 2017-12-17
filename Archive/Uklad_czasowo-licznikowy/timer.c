#include "timer.h"
//====================================================================
void InitTimer0(void){
	
	DISABLE_TIMER_0;
	ENABLE_TIMER_0;
}
//====================================================================
void WaitOnTimer0(unsigned int uiTime){
	
	InitTimer0();
	uiTime *= 15000;
	while(TIMER_0 < uiTime){
	}
	RESET_TIMER_0;
}
//====================================================================
void InitTimer0Match0(unsigned int iDelayTimer){
	
	DISABLE_TIMER_0;
	iDelayTimer = iDelayTimer * 15000;
	SET_TIMEOUT_TIMER_0(iDelayTimer);
	ENABLE_INTERRUPT_MR0_0;
	ENABLE_TIMER_0;
}
//====================================================================
void WaitOnTimer0Match0(void){
	
	InitTimer0Match0(100);
	for(;!(T0CCR&0x1);){
	}	
}
//====================================================================

