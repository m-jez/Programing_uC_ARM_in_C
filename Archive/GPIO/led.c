#include "led.h"

unsigned int uiLedIndex; 



void SetLEDsAsOutput(void){
	
	IO1DIR|=(LED0_bm|LED1_bm|LED2_bm|LED3_bm);
}

void TurnLEDsON(void){

	SetLEDsAsOutput();
	IO1SET|=(LED0_bm|LED1_bm|LED2_bm|LED3_bm);
}

void CycleLEDs(unsigned int uiDelayMS){
	
	char cLEDNumber;
	
	SetLEDsAsOutput();
	for(cLEDNumber = 0; cLEDNumber < 4; cLEDNumber++){
		LedOn(cLEDNumber);
	}
}

void LedInit(void){
	
	IO1DIR |= (LED0_bm|LED1_bm|LED2_bm|LED3_bm);
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

void StepLeft(){
	
	++uiLedIndex;
	LedOn(uiLedIndex%4);
}

void StepRight(){
	
	++uiLedIndex;
	LedOn(3-(uiLedIndex%4));
}


void LedStep(enum eStepDirection dir){
	
	static unsigned char sucLedIndex = 0;
	
	if(dir == Left){
		++sucLedIndex;
		sucLedIndex %= 4;
		LedOn(sucLedIndex);
	}
	else{
		--sucLedIndex;
		sucLedIndex %= 4;
		LedOn(sucLedIndex);
	}
}

void LedStepLeft(void){
	
	LedStep(Left);
}

void LedStepRight(void){
	
	LedStep(Right);
}
