#include <LPC21xx.H>

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

enum eStepDirection{Left, Right};

void LedInit(void);
void LedOn(unsigned char ucLedIndeks);
void StepLeft(void);
void StepRight(void);
void LedStep(enum eStepDirection dir);
void LedStepLeft(void);
void LedStepRight(void);
