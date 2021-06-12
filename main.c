#define MAIN_C

#include <p24fxxxx.h>
#include "mydelay\mydelay.h"
#include "pd.h"
#include "pic-uart.h"
#include "main.h"
#include "isr.h"
#include "module_address_functions.h"
#include "sev_seg_led.h"
#include "dmx.h"
#include "max3430-control.h"
#include "channel_status_led_functions.h"
#include "low_batt_control.h"
#include "power_save.h"

_CONFIG1( WDTPS_PS1 & FWPSA_PR32 & FWDTEN_OFF & WINDIS_OFF & ICS_PGx1 
		 & BKBUG_OFF & COE_OFF & GWRP_OFF & GCP_ON & JTAGEN_OFF);
		 
_CONFIG2( POSCMOD_HS & OSCIOFNC_ON & FCKSM_CSDCMD & FNOSC_PRI & IESO_OFF);

/***************************************************************************/
int main(void) 
{
	SetupSystem();	

	
	while(1)
	{	
			
			XmitDMXData();
 			UpdateChannelStatus();
 			
			if(INCREMENT_BUTTON)
			{
				SLEEP_TIMER_OFF; // since we got keypress, we want sleep timer off 
			 	sleep_timer_loop_count = 0;
			 	delay_ms(150);      // debounce
			 	
			 	ModuleAddressIncrement();
			 
			  	if(INCREMENT_BUTTON) 
			 	{ 
				 	delay_ms(800);
				 	// if its held down long enough then increment real fast
					while(INCREMENT_BUTTON) {  ModuleAddressIncrement(); delay_ms(20); };
				}		
			}
		
			
			if(PDARMED) 
			{ 	
				SLEEP_TIMER_OFF;
				
			}
			else 
			{
				DMXChannelDataInit();
				SLEEP_TIMER_ON;
		     	if(sleep_timer_loop_count > SLEEP_DELAY)
		   	 	{	
					
					PowerSave();
	
			 	}
			}
			
			
	}

}
/***************************************************************************/


/***************************************************************************/
void SetupSystem(void)
{

	SetupLowBatt();							// Enable Low Batt Led
	SetupPowerSave();						// enable timer and wake up btn
	DMXChannelDataInit();					// Init Array
	ChannelStatusLEDInit();					// Test/Dance LEDs
	MAX3430Control(MAX3430_XMIT_EN);  		// Turn on RS485 Line Driver
	SevSegLEDInit();						// Init Display
	LoadModuleAddress();					// Load Address from DEE
	
	//SetupPICUart1();						// PD Uart
	

	TRISFbits.TRISF2 = 1;
	asm("nop");
	TRISFbits.TRISF3 = 0;
	U1MODEbits.USIDL = 1;
	U1MODEbits.RTSMD; 	// POR
	U1MODEbits.UEN = 	00;
	U1MODEbits.WAKE = 	1;
	U1MODEbits.LPBACK = 0;
	U1MODEbits.ABAUD  = 0;
	U1MODEbits.RXINV = 0;
	// PDSEL1 and PDSEL0
	// 11 = 9-bit data, no parity
	// 10 = 8-bit data, odd parity
	// 01 = 8-bit data, even parity
	// 00 = 8-bit data, no parity
	U1MODEbits.PDSEL = 01;
	// 1 = Two Stop Bit
	// 0 = One Stop Bit
	U1MODEbits.STSEL  = 0;
	U1STAbits.UTXISEL1 = 0;
	U1STAbits.UTXISEL0 = 0;
	// TX Polarity Inversion
	// 1 = Inverted
	// 0 = Non Inverted / normal
	U1STAbits.UTXINV   = 1;
	U1STAbits.UTXBRK = 0;
	U1STAbits.URXISEL1 = 0;
	U1STAbits.URXISEL0 = 0;
	U1STAbits.ADDEN  = 0; 
	// 4800bps @ 20 mhz
	U1MODEbits.BRGH =	0;
	U1BRG = 129;
	U1MODEbits.UARTEN = 1;  
	U1STAbits.UTXEN =  1;
		
	// U1TXIE: UART1 Transmitter Interrupt
	IEC0bits.U1TXIE = 0;
	// U1RXIE: UART1 Receiver Interrupt Enable bit
	IPC2bits.U1RXIP = 7;
	IFS0bits.U1RXIF = 0;
	IEC0bits.U1RXIE = 1;
	

	SetupPICUart2();						// DMX Uart	

	XmitDMXData();						// 0% All DMX 
}
/***************************************************************************/
	
	



