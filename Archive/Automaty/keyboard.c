#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


#define BUTTON1_bm	(1<<4)
#define BUTTON2_bm	(1<<6)
#define BUTTON3_bm	(1<<5)
#define BUTTON4_bm	(1<<7)

void KeyboardInit(){
	
	IO0DIR &= !(BUTTON1_bm|BUTTON2_bm|BUTTON3_bm|BUTTON4_bm);
}

enum KeyboarState eKeyboarRead(){
	
	enum KeyboarState eKeyboarState;

	if(!(IO0PIN&BUTTON1_bm)){
		eKeyboarState=BUTTON_1;
	}
	else if(!(IO0PIN&BUTTON2_bm)){
		eKeyboarState=BUTTON_2;
	}
	else if(!(IO0PIN&BUTTON3_bm)){
		eKeyboarState=BUTTON_3;
	}
	else if(!(IO0PIN&BUTTON4_bm)){
		eKeyboarState=BUTTON_4;
	}
	else{
		eKeyboarState=RELASED;
	}
	switch(eKeyboarState){
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
		default:
			break;		
	}
	return eKeyboarState;
}
