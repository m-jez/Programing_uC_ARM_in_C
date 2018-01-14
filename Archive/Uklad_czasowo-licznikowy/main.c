#include <LPC21xx.H>
#include "timer.h"
#include "led.h"


 int main(void){
	
// #1	 
	/*
	LedInit();
	 InitTimer0();
	for(;;){
		WaitOnTimer0(250);
		LedStep(LEFT);
	}*/
	
	 
	 
// #2	 
	LedInit();
	InitTimer0Match0(150);
		for(;;){		
			WaitOnTimer0Match0();
			LedStep(LEFT);	
		}
		
//
}
