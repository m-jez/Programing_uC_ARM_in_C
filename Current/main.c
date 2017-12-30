#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"

int main (){

	unsigned int uiDestinationPosition;

	ServoInit(50);
	for(;;){
		switch(eServo.eState){
			case CALLIB:
				ServoCallib();
				eServo.eState=IDLE;
				break;
			case IDLE:
				if(eKeyboardRead()==BUTTON_1){
					eServo.eState=CALLIB;
				}
				else if(eKeyboardRead()==BUTTON_2){
					uiDestinationPosition=50;
					eServo.eState=IN_PROGRESS;
				}
				else if(eKeyboardRead()==BUTTON_3){
					uiDestinationPosition=100;
					eServo.eState=IN_PROGRESS;
				}
				else if(eKeyboardRead()==BUTTON_4){
					uiDestinationPosition=150;
					eServo.eState=IN_PROGRESS;
				}
				break;
			case IN_PROGRESS:
				ServoGoTo(uiDestinationPosition);
				eServo.eState=IDLE;
				break;
		}
	}
}
