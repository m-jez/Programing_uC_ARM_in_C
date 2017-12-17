#include <LPC21xx.H>

/*
#define ON_LED(LED_NUMBER) 			IO1SET|=(1<<(LED_NUMBER+16))
#define OFF_LED(LED_NUMBER) 		IO1CLR|=(1<<(LED_NUMBER+16))
#define OUTPUT_LED(LED_NUMBER) 	IO1DIR|=(1<<(LED_NUMBER+16))
*/

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

enum eStepDirection{Left, Right};

void Delay(unsigned int uiDelayMS);
void LedInit(void);
void LedOn(unsigned char ucLedIndeks);
void StepLeft(void);
void StepRight(void);
void LedStep(enum eStepDirection dir);
void LedStepLeft(void);
void LedStepRight(void);
