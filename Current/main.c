#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

#define ClocksToMilliSecRatio 5455

#define PIN10_bm (1<<10)
#define PIN16_bm (1<<16)
#define PIN17_bm (1<<17)
#define PIN18_bm (1<<18)
#define PIN19_bm (1<<19)


unsigned int Delay_ON = 5, Delay_OFF = 5;
unsigned int ucCoil;

enum DecetorState {ACTIVE, INACTIVE, CALIB};
enum MotorRotationDirectory {COUNTERCLOCKWISE, CLOCKWISE};
	
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

void Delay(unsigned int uiDelayMS){
	
	unsigned int uiIndex;
	
	for(uiIndex=0; uiIndex<(ClocksToMilliSecRatio*uiDelayMS); uiIndex++){}
}

void Move(enum MotorRotationDirectory eRotation){
	
	unsigned char ucDir;
	if(eRotation == COUNTERCLOCKWISE){
		ucDir = 3 - (ucCoil%4); // 3 - 2 - 1 - 0 - 3
	}
	else{							// RIGHT
		ucDir = (ucCoil%4);			// 0 - 1 - 2 - 3 - 0
	}
	
	switch((ucDir)){
		case 0:
			IO1SET |= PIN19_bm;
			Delay(Delay_ON);
			IO1CLR |= PIN19_bm;
			Delay(Delay_OFF);
			break;
		case 1:
			IO1SET |= PIN18_bm;
			Delay(Delay_ON);
			IO1CLR |= PIN18_bm;
			Delay(Delay_OFF);
			break;
		case 2:
			IO1SET |= PIN17_bm;
			Delay(Delay_ON);
			IO1CLR |= PIN17_bm;
			Delay(Delay_OFF);
			break;
		case 3:
			IO1SET |= PIN16_bm;
			Delay(Delay_ON);
			IO1CLR |= PIN16_bm;
			Delay(Delay_OFF);
			break;
	}
	ucCoil++;
}

void CalibMotor(void){
		for(;;){
		if((IO0PIN & PIN10_bm)==0){
			break;
		}
		Move(COUNTERCLOCKWISE);
	}
}

int main (){
	
	enum LedStatus {LED_LEFT, LED_STOP, LED_RIGHT};         
	unsigned int uiDelay = 20;			// 50 Hz
	enum DecetorState eDetectorState = CALIB;

	LedInit();	
	DetectorInit();
	for(;;){
		switch (eDetectorState){
			case ACTIVE:
				if(eKeyboardRead() == BUTTON_2){
					eDetectorState = INACTIVE;
					Timer0Interrupts_End();
				}
				else{
					Timer0Interrupts_Init(uiDelay, &LedStepLeft);
				}
				break;
			case INACTIVE:
				if(eKeyboardRead() == BUTTON_1){
					eDetectorState = ACTIVE;
				}
				else if(eKeyboardRead() == BUTTON_3){
					eDetectorState = CALIB;
				}
				break;
			case CALIB:
				CalibMotor();
				eDetectorState = INACTIVE;
				break;
		};
	}
}
