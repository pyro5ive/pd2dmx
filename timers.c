#define TIMERS_C

#include <p24fxxxx.h>
#include "timers.h"


void Timer1Setup(void)
{
	

	//Timer1 Registers Prescaler= 8 - TMR1 Preset = 0 - Freq = 9.54 Hz - Period = 0.104858 seconds -- 104 ms
	T1CONbits.TCKPS1 = 1;   // bits 5-4  Prescaler Rate Select bits
	T1CONbits.TCKPS0 = 1;   // bit 4
	T1CONbits.TOSCEN = 1;   // bit 3 Timer1 Oscillator Enable Control bit 1 = on
	T1CONbits.TSYNC = 1;    // bit 2 Timer1 External Clock Input Synchronization Control bit...1 = Do not synchronize external clock input
	T1CONbits.TCS = 0;    // bit 1 Timer1 Clock Source Select bit...0 = Internal clock (FOSC/4)
	T1CONbits.TON = 1;    // bit 0 enables timer
	PR1 = 0;             // preset for timer1 MSB register
	

}

void Timer2Setup(void)
{
	//Timer2 Registers Prescaler= 16 - TMR2 PostScaler = 16 - PR2 = 254 - Freq = 76.89 Hz - Period = 0.013005 seconds - 13msS
	T2CONbits.TON = 1;  // bit 2 turn timer2 on;
	T2CONbits.TCKPS1 = 1; // bits 1-0  Prescaler Rate Select bits
	T2CONbits.TCKPS0 = 0;
	T2CONbits.T32 = 0;
	PR2 = 254;         // PR2 (Timer2 Match value)
	
}
