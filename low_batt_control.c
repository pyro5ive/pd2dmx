#define LOW_BATT_CONTROL_C


#include <p24fxxxx.h>
#include "low_batt_control.h"



/*************************************************/	
void SetupLowBatt(void)
{
	
	// Enable Low Batt LED
	LOW_BATT_LED_TRIS = 0; // Output
	LOW_BATT_LED_PIN  = 1; // Source current for LED
						   // and voltage comparator will sink current
	
	
}
/*************************************************/


