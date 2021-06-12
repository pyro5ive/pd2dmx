#define SEV_SEG_LED_C



#include <p24fxxxx.h>
#include "sev_seg_led.h"
#include "mydelay\mydelay.h"


/******************************************/
void SevSegLEDInit(void) 
{
	
		
	int c;
	int blah	= 0b00000001;
	
	SEVSEG_DISPLAY_TRIS		= 0x00;
	SEVSEG_DIGIT1_EN_TRIS	= 0;
	SEVSEG_DIGIT2_EN_TRIS	= 0;
	
	SEVSEG_DIGIT1_EN_PIN = 1;
	asm("nop");
	SEVSEG_DIGIT2_EN_PIN = 1;	
	
	for(c = 0; c <= 25; c++)
	{		
		SEVSEG_DISPLAY_PORT = blah;
		
		blah = blah << 1;
		if(blah == 0b01000000) { blah = 0b00000001; };
		delay_ms(50);
	};  				


	SEVSEG_DISPLAY_PORT = 0b01111111;
		__delay_ms(1000);
	SetupDisplayRefreshTimer();

	
}
/******************************************/


/******************************************/
void SevSegLEDDisplay(int digit1, int digit2)
{
	static unsigned int next_digit_on = 1;
	
	switch(next_digit_on)
	{
		case 1: 
		
			SEVSEG_DISPLAY_PORT = seven_seg_digits[(digit1 + 1)];
			SEVSEG_DIGIT2_EN_PIN = 0;
			asm("nop");
			SEVSEG_DIGIT1_EN_PIN = 1;
			next_digit_on = 2;
			break;
		
		case 2:
		
			SEVSEG_DISPLAY_PORT = seven_seg_digits[(digit2 + 1)];
			SEVSEG_DIGIT1_EN_PIN = 0;
			asm("nop");
			SEVSEG_DIGIT2_EN_PIN = 1;
			next_digit_on = 1;
			break;
	}
	
}
/******************************************/

/******************************************/
void SevSegLEDisplayOff(void)
{
	SEVSEG_DIGIT1_EN_PIN = 0;
	SEVSEG_DIGIT2_EN_PIN = 0;
	SEVSEG_DISPLAY_PORT = 0x00;
	
}
/******************************************/

/******************************************/
void SetupDisplayRefreshTimer(void)
{
	// 0.02008400 seconds = 20 ms = ~50hz
	T3CONbits.TSIDL = 1;	// Stop timer is sleep mdoe
	T3CONbits.TCS = 0;		// Clock Source Internal
	T3CONbits.TCKPS = 01;	// 1:256	 Prescaler
	IPC2bits.T3IP = 5;		// Timer Int Prio.
	IFS0bits.T3IF = 0;		// Clr flag. 
	IEC0bits.T3IE = 1;		// INT En
	TMR3 = 0xFE79;
	T3CONbits.TON = 1;		// Timer On
}
/******************************************/

