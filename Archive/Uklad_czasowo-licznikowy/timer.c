#include "timer.h"
//====================================================================
void InitTimer0(void){
	
	T0TCR &= !0x1;			// Counter disable
	T0TCR |= 0x1;				// Counter enable
}
//====================================================================
void WaitOnTimer0(unsigned int uiTime){
	
	T0TCR |= 0x1;				// Counter enable
	for(uiTime*=15000;T0TC<uiTime;){
	}
	T0TCR |= 0x2;				// Counter reset enable 
	T0TCR &= !(0x2);		// Counter reset disable 
}
//====================================================================
void InitTimer0Match0(unsigned int iDelayTimer){
	
	T0MR0 = iDelayTimer*15000;
	T0TCR &= !0x0;			// Counter disable
	T0MCR |= 0x1;				// Counter enable
}
//====================================================================
void WaitOnTimer0Match0(void){
	
	T0TCR = 0x1;				// Counter enable
	for(;!(T0IR==0x1);){
	}
	T0IR  |= 0x1;				// Interrupt flag cleared 
	T0TCR |= 0x2;				// Counter reset enable
	T0TCR &= !(0x2);		// Counter reset disable 
}
//====================================================================
