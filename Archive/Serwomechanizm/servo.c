#include <LPC21xx.H>
#include "servo.h"
#include "led.h"
#include "timer_interrupts.h"

#define PIN10_bm (1<<10)
#define PIN16_bm (1<<16)
#define PIN17_bm (1<<17)
#define PIN18_bm (1<<18)
#define PIN19_bm (1<<19)

//unsigned int uiDelay;

enum DecetorState {ACTIVE, INACTIVE};
enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo{
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
};

struct Servo eServo;

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

void ServoCallib(void){
    
    eServo.eState = CALLIB;		// set servo to calibration
		while(eServo.eState == CALLIB){
		}
}

void ServoGoTo(unsigned int uiPosition){
    
		if(eServo.uiCurrentPosition != uiPosition){
			eServo.uiDesiredPosition = uiPosition;
			eServo.eState = IN_PROGRESS;
			while(eServo.eState == IN_PROGRESS){
			}
		}
}

//#########
enum LedStatus {LED_LEFT, LED_STOP, LED_RIGHT};

void Automat(void){
	
	switch(eServo.eState){
        case CALLIB:
            if(eReadDetector() == ACTIVE){
                eServo.eState = IDLE;
								eServo.uiCurrentPosition = 0;
								eServo.uiDesiredPosition = 0;
            }
            else{
                LedStep(LEFT);
            }
            break;
        case IDLE:
            if(eServo.uiCurrentPosition == eServo.uiDesiredPosition){
            }
            else{
                eServo.eState = IN_PROGRESS;
            }
            break;
        case IN_PROGRESS:
						if(eServo.uiCurrentPosition > eServo.uiDesiredPosition){
								LedStep(RIGHT);
								eServo.uiCurrentPosition--;
						}
						else if(eServo.uiCurrentPosition < eServo.uiDesiredPosition){
								LedStep(LEFT);
								eServo.uiCurrentPosition++;
						}
            else{
                eServo.eState = IDLE;
            }
            break;
    };
}

void ServoInit(unsigned int uiServoFrequency){
		// converting frequency to delay in milliseconds
	unsigned int uiServoDelayMS = (1000000/uiServoFrequency);
    
	LedInit();					// LED's initialization 
	DetectorInit();     // Detector initialization    
			// Initialization Timer0 interrupts and setting Automat() as action
	Timer0Interrupts_Init(uiServoDelayMS, &Automat); 
	ServoCallib();			// set servo to calibration
}
