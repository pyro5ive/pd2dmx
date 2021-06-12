#define DMX_C

#include <p24fxxxx.h>

#include "pic-uart.h"
#include "dmx.h"
#include "pd.h"
#include "main.h"
#include "channel_status_led_functions.h"
#include "mydelay\mydelay.h"


/*******************************************************************/
void XmitDMXData(void) 
{

	int chan_num;
	
	SendDMXBreak(); 
	SendDMXMAB();
	
	for(chan_num = 1; chan_num <= DMX_MAX_CHAN; chan_num++)
	{	
			
		PICUart2XmitByte(dmx_channel_data[chan_num]);
		__delay_us(40); /**** FIX THIS WORKAROUND - 2 STOP BITS DONT WORK ***/
		
		
	};		

}
/*******************************************************************/


/*******************************************************************/
void SendDMXMAB(void) 
{
	
	__delay_us(6);
	
	PICUart2XmitByte(0x00);
	__delay_us(60);
		
	
}
/*******************************************************************/


/*******************************************************************/
void SendDMXBreak(void)
{
	
	// Set Break Bit to Output and drive low
	__delay_us(150);
	
	DMX_BREAK_BIT_TRIS = 0;
	DMX_BREAK_BIT_PIN = 0;

	__delay_us(100);
	
	// back to high impendeance
	DMX_BREAK_BIT_TRIS = 1;

	return;
}
/*******************************************************************/


/*******************************************************************/
void DMXChannelDataInit(void)
{

	int chan_num;
	for(chan_num = 0; chan_num <= DMX_MAX_CHAN; chan_num++)
	{	
		dmx_channel_data[chan_num] = 0x00;
			
	};
}
/*******************************************************************/



