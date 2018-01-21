#include "keyboard.h"
#include "servo.h"

int main (){
	
  KeyboardInit();
	ServoInit(20);
	for(;;){
		switch(eKeyboardRead()){
			case BUTTON_1:
					ServoCallib();
					break;
			case BUTTON_2:
					ServoGoTo(50);
					break;
			case BUTTON_3:
					ServoGoTo(100);
					break;
			case BUTTON_4:
					ServoGoTo(150);
					break;
			default:
					break;
		};
	}
}
