#include "led.h"
#include "keyboard.h"

char ReadButton1(void){
	
	enum ButtonState {RELASED, PRESSED};
	enum KeyboarState {RELASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4};
	char cResult = RELASED;
	
	IO0DIR &= !BUTTON2_bm;
	if(!(IO0PIN & BUTTON2_bm)){
		cResult = PRESSED;
	}
	switch(cResult){
		case RELASED:
			LedOn(0);
			break;
		case PRESSED:
			LedOn(1);
			break;
	}
	return cResult;
}

void KeyboardInit(){
	
	IO0DIR &= !(BUTTON1_bm|BUTTON2_bm|BUTTON3_bm|BUTTON4_bm);
}

void ReadButton(enum KeyboarState){
	
	switch(eKeyboarRead){
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
		default:
			break;		
			LedOn(4);
	}
}

enum KeyboarState eKeyboarRead(){

	if(0 == (IO0PIN & BUTTON1_bm)){
		return BUTTON_1;
	}
	else if(0 == (IO0PIN & BUTTON1_bm){
		return BUTTON_2;
	}
	else if(0 == (IO0PIN & BUTTON1_bm){
		return BUTTON_3;
	}
	else if(0 == (IO0PIN & BUTTON1_bm){
		return BUTTON_4;
	}
	else{
		return RELASED;
	}
}
