#include <LPC21xx.H>

// TIMER
#define mCOUNTER_ENABLE 	(1<<0)
#define mCOUNTER_RESET  	(1<<1)

// CompareMatch
#define mINTERRUPT_ON_MR0 (1<<0)
#define mRESET_ON_MR0     (1<<1)
#define mMR0_INTERRUPT    (1<<0)
#define mINTERRUPT_ON_MR1 (1<<3)
#define mRESET_ON_MR1     (1<<4)
#define mMR1_INTERRUPT    (1<<1)

// VIC (Vector Interrupt Controller) VICIntEnable
#define VIC_TIMER0_CHANNEL_NR 4 
#define VIC_TIMER1_CHANNEL_NR 5

// VICVectCntlx Vector Control Registers
#define mIRQ_SLOT_ENABLE (1<<5)

// Global Variable
void (*ptrTimer0InterruptFunction)(void);
void (*ptrTimer1InterruptFunction)(void);

__irq void Timer0IRQHandler(){
// timer 1 slot 13
	T0IR=mMR0_INTERRUPT; 	// skasowanie flagi przerwania 
	ptrTimer0InterruptFunction();
	VICVectAddr=0x00; 		// potwierdzenie wykonania procedury obslugi przerwania
}
//
__irq void Timer1IRQHandler(){
// timer 1 slot 13
	T1IR=mMR1_INTERRUPT; 	
	ptrTimer1InterruptFunction();
	VICVectAddr=0x00; 		
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
	T0MR0 = 15 * uiPeriod;                 	      							// value 
	T0MCR |= (mINTERRUPT_ON_MR0 | mRESET_ON_MR0); 							// action 
				//
	
        // timer
	T0TCR |=  mCOUNTER_ENABLE; // start 

}


void Timer1Interrupts_Init(unsigned int uiPeriod, void (*ptrInterruptFunction)(void)){ 
	
	ptrTimer1InterruptFunction = *ptrInterruptFunction;
	
	VICIntEnable |= (0x1 << VIC_TIMER1_CHANNEL_NR);
	VICVectCntl13 = mIRQ_SLOT_ENABLE | VIC_TIMER1_CHANNEL_NR;
	VICVectAddr13 = (unsigned long)Timer1IRQHandler;
	
	T1MR1 = 15 * uiPeriod;
	T1MCR |= (mINTERRUPT_ON_MR1 | mRESET_ON_MR1);
	
	T1TCR |=  mCOUNTER_ENABLE;
}
