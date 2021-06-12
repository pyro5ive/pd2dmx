#define PD_C

#include <p24fxxxx.h>

#include "dmx.h"
#include "pd.h"
#include "mydelay\mydelay.h"
#include "module_address_functions.h"
#include "pic-uart.h"


/*****************************************************************************/
void parse_recvd_pd_data(int byte)
{
	int dmx_channel;

	if(byte == our_module_address) { our_module_selected = 1;	return; }
	
	if(our_module_selected)
	{
			our_module_selected = 0;
				
			if((PD_FIRE_COMMAND_MASK & byte) == PD_FIRE_COMMAND_MASK) 
			{
				
				dmx_channel = ((byte & 0x0F) + 1);  // move cue 0 to dmx channel 1, cue 1 to dmx channel 2,etc
				
				if(dmx_channel_data[dmx_channel] == 0xFF) 
				{ 
					dmx_channel_data[dmx_channel]  = 0x00; 
				} 
				else if(dmx_channel_data[dmx_channel] == 0x00) 
				{
					dmx_channel_data[dmx_channel]  = 0xFF; 
				}
				
				//dmx_channel_data[dmx_channel] = ~(dmx_channel_data[dmx_channel]);
							
				return;
			}
		
			if(byte == 0x00)
			{

				SendPDTestReply(); 
				return; 	
			}
	
	}

}
/*****************************************************************************/


	
/*****************************************************************************/
void SendPDTestReply(void)
{
	static int step = 0; 
	int data;
	__delay_ms(1);
	
	data = ~(0x0001 << step); 
	
	/*
	PICUart1XmitByte((data & 0x00ff) );
	PICUart1XmitByte((data & 0xFF00) >> 8);
	step = step + 1; 
	if(step > 0x8000) { step = 0x01; } ;
	*/
	PICUart1XmitByte(0b00000000);
	PICUart1XmitByte(0b00000000);
}
/*****************************************************************************/
