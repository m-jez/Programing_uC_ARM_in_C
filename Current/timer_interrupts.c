#include <LPC21xx.H>

// TIMER
#define mCOUNTER_ENABLE 	(1<<0)
#define mCOUNTER_RESET  	(1<<1)

// CompareMatch
#define mINTERRUPT_ON_MR0 (1<<0)
#define mRESET_ON_MR0     (1<<1)
#define mMR0_INTERRUPT    (1<<0)

// VIC (Vector Interrupt Controller) VICIntEnable
#define VIC_TIMER1_CHANNEL_NR 5
#define VIC_TIMER0_CHANNEL_NR 4

// VICVectCntlx Vector Control Registers
#define mIRQ_SLOT_ENABLE (1<<5)

// Global Variable
void (*ptrTimer0InterruptFunction)(void);

__irq void Timer0IRQHandler(){

	T0IR=mMR0_INTERRUPT; 	// skasowanie flagi przerwania 
	//LedStep(RIGHT);				// cos do roboty
	ptrTimer0InterruptFunction();
	VICVectAddr=0x00; 		// potwierdzenie wykonania procedury obslugi przerwania
}
/**********************************************/
void Timer0Interrupts_Init(unsigned int uiPeriod, void (*ptrInterruptFunction)(void)){ // microseconds

				// handing adress to global variable 
	ptrTimer0InterruptFunction = *ptrInterruptFunction;
        // interrupts
	VICIntEnable |= (0x1 << VIC_TIMER0_CHANNEL_NR);            	// Enable Timer 0 interrupt channel 
	VICVectCntl1  = mIRQ_SLOT_ENABLE | VIC_TIMER0_CHANNEL_NR;  	// Enable Slot 0 and assign it to Timer 0 interrupt channel
	VICVectAddr1  =(unsigned long)Timer0IRQHandler; 	   				// Set to Slot 0 Address of Interrupt Service Routine 
        // match module
	T0MR0 = 15000 * uiPeriod;                 	      					// value 
	T0MCR |= (mINTERRUPT_ON_MR0 | mRESET_ON_MR0); 							// action 
        // timer
	T0TCR |=  mCOUNTER_ENABLE; // start 
}

void Timer0Interrupts_End(void){
	
	VICIntEnable &= !(0x1 << VIC_TIMER0_CHANNEL_NR);
	VICVectCntl1 &= !mIRQ_SLOT_ENABLE;
	T0TCR &= !mCOUNTER_ENABLE;
}
