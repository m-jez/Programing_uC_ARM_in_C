#include "led.h"

unsigned int uiLedIndex; 

void DelayMS(unsigned int uiDelayMS){
	
	unsigned int uiIndex;
	
	for(uiIndex = 0; uiIndex < (5455 * uiDelayMS); uiIndex++){
	}
}

void SetLEDsAsOutput(void){
	
	OUTPUT_LED(0);
	OUTPUT_LED(1);
	OUTPUT_LED(2);
	OUTPUT_LED(3);
}

void TurnLEDsON(void){

	SetLEDsAsOutput();
	ON_LED(0);
	ON_LED(1);
	ON_LED(2);
	ON_LED(3);
}

void CycleLEDs(unsigned int uiDelayMS){
	
	char cLEDNumber;
	
	SetLEDsAsOutput();
	for(cLEDNumber = 0; cLEDNumber < 4; cLEDNumber++){
		ON_LED(cLEDNumber);
		DelayMS(uiDelayMS);
		OFF_LED(cLEDNumber);
	}
}

/*	ver 1
void LedInit(void){
	
	IO1DIR |= LED0 | LED1 | LED2 | LED3;
	IO1SET |= LED0;
}
*/

// ver 2
void LedInit(void){
	
	IO1DIR |= (LED0|LED1|LED2|LED3);
}

void LedOn(unsigned char ucLedIndeks){
	
	OUTPUT_LED(ucLedIndeks);
	IO1CLR |= (0xF<<16);
	ON_LED(ucLedIndeks);
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
