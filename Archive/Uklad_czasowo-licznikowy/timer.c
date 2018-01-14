#include "timer.h"

#define COUNTER_ENABLE_bm  		(1<<0)
#define COUNTER_RESET_bm		 	(1<<1)
#define MR0_INTERRUPT_bm			(1<<0)
#define MR0_RESET_bm					(1<<1)	

void InitTimer0(void){
	
	T0TCR |= COUNTER_ENABLE_bm;				// wlaczenie timera T0 
}

void WaitOnTimer0(unsigned int uiTime){
		
	T0TCR |= COUNTER_RESET_bm;				// resetowanie timera T0
	T0TCR &= ~COUNTER_RESET_bm;				// wylaczenie resetu
	for(uiTime*=15000;T0TC<uiTime;){	// oczekiwanie na zrownanie sie wartosci timera oraz wartosci uiTime
	}
}

void InitTimer0Match0(unsigned int iDelayTimer){
	
	T0MR0 = iDelayTimer*15000;				// ustawienie wartosci do ktorej ma zliczac timer
	T0MCR |= MR0_INTERRUPT_bm | MR0_RESET_bm;	//wlaczenie przerwania i resetowanie timera0 podczas zrowniania z wartoscia zadana
	T0TCR |= COUNTER_ENABLE_bm;				// wlaczenie timera T0
}

void WaitOnTimer0Match0(void){
	
	for(;!(T0IR==0x1);){											// oczekiwanie na ustawienie flagi przerwania 
	}
	T0IR  = MR0_INTERRUPT_bm;									// usuniecie flagi przerwania
}
