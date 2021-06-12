#define CHANNEL_STATUS_LED_FUNCTIONS_C

#include <p24fxxxx.h>

#include "channel_status_led_functions.h"
#include "mydelay\mydelay.h"
#include "dmx.h"

/************************************************/
void ChannelStatusLEDControl(int led_num, int on_off)
{
	int new_value = 0;
  
  	led_num = led_num - 1;	  
    if(on_off == 1) 
	{ 
		new_value = (0x0001 << led_num)| STATUS_LED_PORT; 
  	}
  	else
  	{
  	  	new_value =  (~(0x0001 << led_num)) & STATUS_LED_PORT; 
  	};
	  
	  	
	STATUS_LED_PORT = new_value;

}
/************************************************/

/************************************************/
void UpdateChannelStatus(void)
{	
	unsigned int chan_num;
	
	for(chan_num = 1; chan_num <= DMX_MAX_CHAN; chan_num++)
	{	
		if(dmx_channel_data[chan_num] == 0xff) 
		{ 
			ChannelStatusLEDControl(chan_num, 1); 
		}
		else
		{  
			ChannelStatusLEDControl(chan_num, 0); 
		}
	}
	
}
/************************************************/
void ChannelStatusLEDInit(void)
{
	int c;
	
	AD1CON1bits.ADON = 0; 		// Turn off AD Module
	AD1PCFG = 0xFFFF;			// Set AN pins to digital I/O
	
	
	STATUS_LED_TRIS = 0x00; 
	STATUS_LED_PORT = 0x00;
	
	for(c = 1; c <= 16; c++)
	{
		ChannelStatusLEDControl(c, 1);
		delay_ms(50);
	};
	for(c = 16; c >= 0; c--)
	{
		ChannelStatusLEDControl(c, 0);
		delay_ms(50);
	};

}
/************************************************/

