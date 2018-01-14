#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

enum LedStatus {LED_LEFT, LED_STOP, LED_RIGHT};

void Automat(void){
	
	static enum LedStatus eLedStatus = LED_STOP;

	switch (eLedStatus){
		case LED_LEFT:
			if(eKeyboardRead() == BUTTON_2){
				eLedStatus = LED_STOP;
			}
			else{
				LedStep(LEFT);
			}
			break;
		case LED_STOP:
			if(eKeyboardRead() == BUTTON_1){
				eLedStatus = LED_LEFT;
			}
			else if(eKeyboardRead() == BUTTON_3){
				eLedStatus = LED_RIGHT;
			}
			break;
		case LED_RIGHT:
			if(eKeyboardRead() == BUTTON_2){
				eLedStatus = LED_STOP;
			}
			else{
				LedStep(RIGHT);
			}
			break;
	};
}


int main (){
	
	unsigned int uiDelayMS = 100;		
	
	LedInit();
	Timer0Interrupts_Init(uiDelayMS, &Automat);
	for(;;){
	}
}
