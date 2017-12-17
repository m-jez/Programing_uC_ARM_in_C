#include <LPC21xx.H>

#define ENABLE_TIMER_0								T0TCR|=(1<<0)
#define ENABLE_TIMER_1  							T1TCR|=(1<<0)

#define DISABLE_TIMER_0 							T0TCR&=!(1<<0)
#define DISABLE_TIMER_1 							T1TCR&=!(1<<0)

#define RESET_TIMER_0									T0TCR|=(1<<1)
#define RESET_TIMER_1   							T1TCR&=!(1<<1)

#define TIMER_0 											T0TC
#define TIMER_1 											T1TC

#define SET_TIMEOUT_TIMER_0(TIME_MS)  T0MR0=TIME_MS
#define SET_TIMEOUT_TIMER_1(TIME_MS)  T1MR0=TIME_MS

#define ENABLE_INTERRUPT_MR0_0				T0MCR|=(1<<0)
#define ENABLE_INTERRUPT_MRO_1				T1MCR|=(1<<0)

#define DISABLE_INTERRUPT_MR0_0				T0MCR&=!(1<<0)
#define DISABLE_INTERRUPT_MR0_1				T1MCR&=!(1<<0)

void InitTimer0(void);
void WaitOnTimer0(unsigned int uiTime);
void InitTimer0Match0(unsigned int iDelayTimer);
void WaitOnTimer0Match0(void);
