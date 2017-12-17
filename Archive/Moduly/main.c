#include "led.h"
#include "keyboard.h"

#define ClocksToMiliSecRatio 5455

void Delay(unsigned int uiDelayMS){
	
	unsigned int uiIndex;
	
	for(uiIndex=0; uiIndex<(ClocksToMiliSecRatio*uiDelayMS); uiIndex++){}
}

int main(){
	enum KeyboardState eKeyboardState;
	
	LedInit();
	KeyboardInit();
	for(;;){
		eKeyboardState = eKeyboardRead();
	
		switch(eKeyboardState){
			case BUTTON_1:
				LedOn(0);
				break;
			case BUTTON_2:
				LedOn(1);
				break;
			case BUTTON_3:
				LedOn(2);
				break;
			case BUTTON_4:
				LedOn(3);
				break;
			case RELASED:		
				LedOn(4);
				break;
		}
		Delay(50);
	}
}
