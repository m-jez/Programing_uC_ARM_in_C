#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

#define ClocksToMiliSecRatio 5455

enum LedState{LEWO, PRAWO, STOP, PRZESUN};

void Delay(unsigned int uiDelayMS){
	
	unsigned int uiIndex;
	
	for(uiIndex=0; uiIndex<(ClockToMiliSecRatio*uiDelayMS); uiIndex++){}
}

/* zad3
int main(void){
	
	enum LedState eLedState=LEWO;
	unsigned char ucLicznikPrzesuniec=0;
	
	LedInit();
	for(;;){
		switch(eLedState){
			case LEWO:
				LedStepLeft();
				if((ucLicznikPrzesuniec++)==3){
					eLedState=PRAWO;
				}
				break;
			case PRAWO:
				LedStepRight();
				if((ucLicznikPrzesuniec--)==0){
					eLedState =LEWO;
				}
				break;
		}
		DelayMS(500);
	}
}
*/

/* zad4 
int main(void){
	
	enum LedStatus eLedStatus=STOP;
	unsigned char ucLicznik=0;
	
	LedInit();
	LedStepRight();			// ustawienie swiecacej diody w skrajnej lewej pozycji
	KeyboardInit();
	for(;;){
		switch(eLedStatus){
			case STOP:
				if(eKeyboarRead()==BUTTON_1){
					for(;eKeyboarRead()!=RELASED;){}
					eLedStatus=PRZESUN;
				}
				break;
			case PRZESUN:
				if(ucLicznik<3){
					LedStepRight();
					ucLicznik++;
				}
				else{
					ucLicznik=0;
					eLedStatus=STOP;
				}
				break;
		}
		DelayMS(500);
	}
}
*/

/* zad5
int main(void){
	
	enum LedStatus 	
	
	LedInit();
	KeyboardInit();
	for(;;){
		switch(eLedStatus){
			case PRZESUN:
				if(eKeyboarRead()==BUTTON_1){
					for(;ReadKey()!=RELASED;){}
					eLedStatus=STOP;
				}
				else{
					LedStepRight();
				}
				break;
			case STOP:
				if(ReadKey()==BUTTON_2){
					for(;ReadKey()!=RELASED;){}
					eLedStatus=PRZESUN;
				}
				break;
		}
		DelayMS(500);
	}
}
*/

/* zad6 
enum LedStatus {LEWO, STOP, PRAWO};

void zad6(void){
	
	enum LedStatus eLedStatus = STOP;
	
	LedInit();
	LedStepRight();
	KeyboardInit();
	for(;;){
		switch(eLedStatus){
			case LEWO:
				if(ReadKey() == BUTTON_2){
					eLedStatus = STOP;
				}
				else{
					LedStepLeft();
				}
				break;
			case PRAWO:
				if(ReadKey() == BUTTON_2){
					eLedStatus = STOP;
				}
				else{
					LedStepRight();
				}
				break;
			case STOP:
				if(ReadKey() == BUTTON_1){
					eLedStatus = LEWO;
				}
				else if(ReadKey() == BUTTON_3){
					eLedStatus = PRAWO;
				}
				break;
		}
		DelayMS(500);
	}
}
*/
