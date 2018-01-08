#include "servo.h"
#include <LPC21xx.H>
#include "led.h"
#include "timer_interrupts.h"

#define PIN10_bm (1<<10)
#define PIN16_bm (1<<16)
#define PIN17_bm (1<<17)
#define PIN18_bm (1<<18)
#define PIN19_bm (1<<19)

unsigned int uiDelay;

void DetectorInit(void){
	
	IO0DIR &= !PIN10_bm;
}

enum DecetorState eReadDetector(){
	
	if(0 == (IO0PIN & PIN10_bm)){
		return ACTIVE;
	}
	else{
		return INACTIVE;
	}		
}

void IncrementDetector(void){
	LedStepLeft();
	eServo.uiCurrentPosition++;
}

void DecrementDetector(void){
	LedStepRight();
	eServo.uiCurrentPosition--;
}

void ServoCallib(void){
	for(;;){
		if(eReadDetector()==ACTIVE){	
			eServo.uiCurrentPosition=0;
			eServo.uiDesirePosition	=0;
			Timer0Interrupts_End();	
			break;
		}
		else{
			Timer0Interrupts_Init(uiDelay, &LedStepLeft);
		}		
	}
}

void ServoInit(unsigned int uiServoFrequency){
	uiDelay=1000/uiServoFrequency;
	LedInit();
	ServoCallib();
}

void ServoGoTo(unsigned int uiPosition){
	
	eServo.uiDesirePosition=uiPosition;
	for(;;){
		if(eServo.uiCurrentPosition==eServo.uiDesirePosition){
			Timer0Interrupts_End();
			break;
		}
		else if(eServo.uiCurrentPosition<eServo.uiDesirePosition){
			Timer0Interrupts_Init(uiDelay, &IncrementDetector);
		}
		else{
			Timer0Interrupts_Init(uiDelay, &DecrementDetector);
		}
	}
}
