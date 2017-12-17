#include <LPC21xx.H>

#define ClocksToMilliSecRatio 5455

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

#define BUTTON1_bm	(1<<4)
#define BUTTON2_bm	(1<<6)
#define BUTTON3_bm	(1<<5)
#define BUTTON4_bm	(1<<7)

enum StepDirection{LEFT, RIGHT};
enum KeyboardState {RELASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4};

void Delay(unsigned int uiDelayMS){
	
	unsigned int uiIndex;
	
	for(uiIndex=0; uiIndex<(ClocksToMilliSecRatio*uiDelayMS); uiIndex++){}
}

void LedInit(void){
	
	IO1DIR|=(LED0_bm|LED1_bm|LED2_bm|LED3_bm);
	IO1SET=LED1_bm;
}

void LedOn(unsigned char ucLedIndeks){
	
	IO1CLR|=(LED0_bm|LED1_bm|LED2_bm|LED3_bm);
	
	switch(ucLedIndeks){
		case 0:
			IO1SET|=LED0_bm;
			break;
		case 1:
			IO1SET|=LED1_bm;
			break;
		case 2:
			IO1SET|=LED2_bm;
			break;
		case 3:
			IO1SET|=LED3_bm;
			break;
	}
}

void KeyboardInit(){
	
	IO0DIR &= !(BUTTON1_bm|BUTTON2_bm|BUTTON3_bm|BUTTON4_bm);
}

enum KeyboardState eKeyboarRead(){

	if(0 == (IO0PIN & BUTTON1_bm)){				//		PRESSED: 0x00000000		RELASED: 0x00000010
		return BUTTON_1;
	}
	else if(0 == (IO0PIN & BUTTON2_bm)){	//		PRESSED  0x00000000		RELASED: 0x00000040
		return BUTTON_2;
	}
	else if(0 == (IO0PIN & BUTTON3_bm)){
		return BUTTON_3;
	}
	else if(0 == (IO0PIN & BUTTON4_bm)){
		return BUTTON_4;
	}
	else{
		return RELASED;
	}
}

void LedStep(enum StepDirection eStepDirection){
	
	static unsigned char sucLedIndex=0;
	
	if(eStepDirection==LEFT){
		sucLedIndex++;
		sucLedIndex=sucLedIndex%4;
		LedOn(sucLedIndex);
	}
	else if(eStepDirection==RIGHT){
		sucLedIndex--;
		sucLedIndex=sucLedIndex%4;
		LedOn(sucLedIndex);
	}
}

void LedStepLeft(void){
	
	LedStep(LEFT);
}

void LedStepRight(void){
	
	LedStep(RIGHT);
}

int main(){
	
	enum KeyboardState eKeyboardState;
	
	for(;;){
		eKeyboardState = eKeyboarRead();
	
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
		Delay(500);
	}
	/*for(;;){
		LedStepLeft();
		Delay(50);
		LedStepRight();
		Delay(250);
	}*/
}
