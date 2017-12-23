#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

int main (){
	
	enum LedStatus {LED_LEFT, LED_STOP, LED_RIGHT};
	enum LedStatus eLedStatus = LED_STOP;
	unsigned int uiDelay = 20;			// 50 Hz

	LedInit();
	for(;;){
		switch (eLedStatus){
			case LED_LEFT:
				if(eKeyboardRead() == BUTTON_2){
					eLedStatus = LED_STOP;
					Timer0Interrupts_End();
				}
				else{
					Timer0Interrupts_Init(uiDelay, &LedStepLeft);
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
					Timer0Interrupts_End();
				}
				else{
					Timer0Interrupts_Init(uiDelay, &LedStepRight);
				}
				break;
		};
	}
}
