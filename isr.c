#define ISR_C

#include <p24fxxxx.h>

#include "dmx.h"
#include "pd.h"
#include "isr.h"
#include "sev_seg_led.h"
#include "mydelay/mydelay.h"
#include "pic-uart.h"
#include "main.h"
#include "module_address_functions.h"
#include "power_save.h"


/****************************************************************************/
void __attribute__((__interrupt__,auto_psv)) _U1RXInterrupt(void)
{

	IFS0bits.U1RXIF = 0;
	
	//if(U1STAbits.PERR) { PICUart1GetByte(); return; }
	//if(U1STAbits.FERR) { return; }	
	//if(U1STAbits.OERR) { U1STAbits.OERR = 0; return; }
	
	parse_recvd_pd_data(PICUart1GetByte());
	XmitDMXData();
	return;
		
}
/****************************************************************************/


/****************************************************************************/
void __attribute__((__interrupt__,auto_psv)) _INT0Interrupt(void)
{
	// wake up / address change button

	IFS0bits.INT0IF = 0;
	if(iamsleeping) 
	{

		while(INCREMENT_BUTTON) { delay_ms(150); };  // debounce avoid changing address on wake up
		// do nothing else, just wake up 
	} 
	else 
	{
	//	delay_ms(150);      // debounce
	//	ChangeModuleAddress();
	}


}
/****************************************************************************/


/****************************************************************************/
void __attribute__((__interrupt__,auto_psv)) _INT1Interrupt(void)
{
	// PD ARMED WAKEUP INT
	IFS1bits.INT1IF = 0;
	
	/*
	if(INTCON2bits.INT1EP == 1) 	// if PD was just armed
	{ 
		pd_armed = 1; 
		SLEEP_TIMER_OFF;			// turn off timer
		INTCON2bits.INT1EP = 0;		// prepare for when PD is disarmed
	}
	else if(INTCON2bits.INT1EP == 0) // if pd was just disarmed
	{
		pd_armed = 0;
		INTCON2bits.INT1EP = 1;		// prepare for when PD is armed
		DMXChannelDataInit();
		SLEEP_TIMER_ON;
	}
	*/
	
}
/****************************************************************************/

/****************************************************************************/
void __attribute__((__interrupt__,auto_psv)) _INT2Interrupt(void)
{
	// BATTERY TOO LOW INT
	IFS1bits.INT2IF = 0;

}
/****************************************************************************/

/****************************************************************************/
void __attribute__((__interrupt__,auto_psv)) _T2Interrupt(void)
{
	// SLEEP TIMER INT	
	IFS0bits.T2IF = 0;
	sleep_timer_loop_count = sleep_timer_loop_count + 1;

	
}
/****************************************************************************/

/****************************************************************************/
void __attribute__((__interrupt__,auto_psv)) _T3Interrupt(void)
{
	// DISPLAY REFRESH TIME
	IFS0bits.T3IF = 0;
	TMR3 = 0xFE79;
	ModuleAddressDisplayRefresh();

	
}
/****************************************************************************/
