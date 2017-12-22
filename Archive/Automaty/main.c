#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

#define ClocksToMiliSecRatio 5455

void Delay(unsigned int uiDelayMS){
	
	unsigned int uiIndex;
	
	for(uiIndex=0; uiIndex<(ClocksToMiliSecRatio*uiDelayMS); uiIndex++){}
}

// zad3
/*
enum LedState{LED_LEWO, LED_PRAWO};

int main(void){
	
	enum LedState eLedState=LED_LEWO;
	unsigned char ucLicznikPrzesuniec=0;
	
	LedInit();
	Delay(500);
	for(;;){
		switch(eLedState){
			case LED_LEWO:
				LedStep(LEFT);
				if((ucLicznikPrzesuniec++)==2){
					eLedState=LED_PRAWO;
				}
				break;
			case LED_PRAWO:
				LedStep(RIGHT);
				if((ucLicznikPrzesuniec--)==1){
					eLedState=LED_LEWO;
				}
				break;
		}
		Delay(500);
	}
}*/


// zad4 
/*
enum LedState{LED_STOP, LED_PRZESUN};

int main(void){
	
	enum LedState eLedState=LED_STOP;
	unsigned char ucLicznik=0;
	
	LedInit();
	LedStep(RIGHT);			// ustawienie swiecacej diody w skrajnej lewej pozycji
	KeyboardInit();
	for(;;){
		switch(eLedState){
			case LED_STOP:
				if(eKeyboardRead()==BUTTON_1){
					for(;eKeyboardRead()!=RELASED;){}
					eLedState=LED_PRZESUN;
				}
				break;
			case LED_PRZESUN:
				if(ucLicznik<3){
					LedStep(RIGHT);
					ucLicznik++;
				}
				else{
					ucLicznik=0;
					eLedState=LED_STOP;
				}
				break;
		}
		Delay(50);
	}
}
*/

// zad5
/*
enum LedState{LED_STOP, LED_PRZESUN};

int main(void){
	
	enum LedState eLedState=LED_PRZESUN;	
	
	LedInit();
	KeyboardInit();
	for(;;){
		switch(eLedState){
			case LED_PRZESUN:
				if(eKeyboardRead()==BUTTON_1){
					for(;eKeyboardRead()!=RELASED;){}
					eLedState=LED_STOP;
				}
				else{
					LedStep(RIGHT);
				}
				break;
			case LED_STOP:
				if(eKeyboardRead()==BUTTON_2){
					for(;eKeyboardRead()!=RELASED;){}
					eLedState=LED_PRZESUN;
				}
				break;
		}
		Delay(50);
	}
}
*/

// zad6 
enum LedStatus {LED_LEWO, LED_STOP, LED_PRAWO, LED_LEWO_PRZERWA};

int main(void){
	
	enum LedStatus eLedStatus = LED_STOP;
	unsigned char ucCycleDelay=0;
	
	LedInit();
	LedStep(RIGHT);
	KeyboardInit();
	for(;;){
		switch(eLedStatus){
			case LED_LEWO:
				if(eKeyboardRead() == BUTTON_2){
					eLedStatus = LED_STOP;
				}
				else{
					LedStep(LEFT);
				}
				break;
			case LED_PRAWO:
				if(eKeyboardRead() == BUTTON_2){
					eLedStatus = LED_STOP;
				}
				else{
					LedStep(RIGHT);
				}
				break;
			case LED_STOP:
				if(eKeyboardRead() == BUTTON_1){
					eLedStatus = LED_LEWO;
				}
				else if(eKeyboardRead() == BUTTON_3){
					eLedStatus = LED_PRAWO;
				}
				else if(eKeyboardRead() == BUTTON_4){
					eLedStatus = LED_LEWO_PRZERWA;
				}
				break;
			case LED_LEWO_PRZERWA:
				if(ucCycleDelay == 4){
					eLedStatus = LED_LEWO;
					ucCycleDelay=0;
				}
				else{
					ucCycleDelay++;
				}
				break;
		}
		Delay(100);
	}
}

