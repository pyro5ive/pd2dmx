#define	MAX3430CSA_CONTROL_C

#include <p24fxxxx.h>
#include "max3430-control.h"
#include "max3430-control-custom.h"

/***********************************************/
void MAX3430Control(int mode)
{
	RE_PORT_TRIS = 0;
	DE_PORT_TRIS = 0;
		
	if(mode == MAX3430_RECV_EN)   // RE 
	{
		RE_PORT_PIN = 0; // Active Low - On
		DE_PORT_PIN = 0; // off
	}
	else if(mode == MAX3430_XMIT_EN)	// DE
	{
		RE_PORT_PIN = 1; // Active Low - Off		
		DE_PORT_PIN = 1; // On
	}
	else if(mode == MAX3430_OFF) // Power Down
	{
		RE_PORT_PIN = 1; // Active Low - Off		
		DE_PORT_PIN = 0; // off
	}
}	
/***********************************************/

