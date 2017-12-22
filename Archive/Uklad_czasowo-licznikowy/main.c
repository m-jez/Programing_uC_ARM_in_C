#include <LPC21xx.H>
#include "timer.h"
#include "led.h"


 int main(void){
	
// #1	 
	 /*
	LedInit();
	for(;;){
		InitTimer0();
		WaitOnTimer0(250);
		LedStep(LEFT);
	}
	*/
	 
// #2	 
	LedInit();
		for(;;){
			InitTimer0Match0(150);
			WaitOnTimer0Match0();
			LedStep(LEFT);	
		}
}
