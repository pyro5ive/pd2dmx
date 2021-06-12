#define POWER_SAVE_C

#include <p24fxxxx.h>
#include "module_address_functions.h"
#include "sev_seg_led.h"
#include "dmx.h"
#include "max3430-control.h"
#include "channel_status_led_functions.h"
#include "power_save.h"
#include "mydelay/mydelay.h"


/***************************************************************************/
void PowerSave(void) 
{
	SLEEP_TIMER_OFF;						// disable sleep timer
	iamsleeping = 1;	

	SaveModuleAddress(our_module_address);	// Save module address to EE
	DMXChannelDataInit(); 					// reset channel data
	XmitDMXData();	  						// send it out
	delay_ms(100);							// wait before turning off RS485
	MAX3430Control(MAX3430_OFF);   			// RS485 PowerSave
	SevSegLEDisplayOff();					// Turn off Display
	
	IFS0bits.INT0IF = 0;		
	IEC0bits.INT0IE = 1;					// Change Address Button is now a Wake button
	
	IFS1bits.INT1IF = 0;					// PD ARMED Wake up 
	IEC1bits.INT1IE	= 1;					
	
	
	asm("PWRSAV #0");						// sleep  and wake up in ISR,
											// Resume here
	IFS0bits.INT0IF = 0;					// Clear INT IF
	IEC0bits.INT0IE = 0;					// Change Address Button is back to normal
	
	IFS1bits.INT1IF = 0;		
	IEC1bits.INT1IE	= 0;					
	

	DMXChannelDataInit();  					// reset channel data, we will xmit in main while()
	MAX3430Control(MAX3430_XMIT_EN);    	// Driver Enable
	sleep_timer_loop_count = 0;  			// reset timer loop count
	iamsleeping = 0;
}
/***************************************************************************/

/***************************************************************************/
void SetupPowerSave(void)
{
	
	T2CONbits.T32 = 0;		// Timer 2 and Timer 3 indvid. timers
	T2CONbits.TCS = 0;		// Clock Source Internal
	T2CONbits.TCKPS = 01;	// 1:256 Prescaler
	IPC1bits.T2IP = 5;		// Timer Int Prio.
	IFS0bits.T2IF = 0;		// clr flag.
	IEC0bits.T2IE = 1;		// INT En
						// Timer will turned on in main loop
	iamsleeping = 0;
		
	// Wake up button
	WAKEUP_BUTTON_TRIS = 1; // Pin is input
	IPC0bits.INT0IP = 2;	// INT Prio.
	INTCON2bits.INT0EP = 0; // INT on pos edge
	IFS0bits.INT0IF = 0;
	//IEC0bits.INT0IE = 0;

	SetupPDARMEDWakeup();

}

void SetupPDARMEDWakeup(void)
{
	// TRIS and Pin
	PDARMED_INPUT_PIN = 0;
	PDARMED_INPUT_TRIS = 1;
	 
	// INT
	INTCON2bits.INT1EP = 1;
	IPC5bits.INT1IP = 6;
	
	
}


