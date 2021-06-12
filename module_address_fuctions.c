#define MODULE_ADDRESS_FUNCTIONS_C

#include <p24fxxxx.h>
#include "sev_seg_led.h"
#include "DEE16\DEE16.h"
#include "module_address_functions.h"
#include "pd.h"
#include "power_save.h"
#include "mydelay\mydelay.h"


/****************************************************************************/
void LoadModuleAddress(void)
{	
	DataEEInit();
	if(DataEERead(FIRSTBOOT_EEPROM_LOCATION) == 0xFF) 
	{ 
		our_module_address = 0x81;
		DataEEWrite(0x00, FIRSTBOOT_EEPROM_LOCATION);		
		DataEEWrite(our_module_address, OUR_MODULE_ADDRESS_EEPROM_LOCATION);
		asm("RESET");

	}
	else
	{	
		our_module_address = DataEERead(OUR_MODULE_ADDRESS_EEPROM_LOCATION);
	}
	
	
}
/****************************************************************************/


/****************************************************************************/
void SaveModuleAddress(int ModuleAddress)
{
	DataEEWrite(ModuleAddress, OUR_MODULE_ADDRESS_EEPROM_LOCATION);
}
/****************************************************************************/


/****************************************************************************/
void ModuleAddressIncrement(void)
{
	
	if(our_module_address == 0xFF)
	{ our_module_address = 0x81; }
	else { our_module_address = our_module_address + 1; };
	
}
/*****************************************************************************/


/*****************************************************************************/
void ModuleAddressDisplayRefresh(void)
{			
	
	SevSegLEDDisplay( ((our_module_address & 0x7F) >> 4), ((our_module_address & 0x7F) & 0x0F) );
	
	
}
/*****************************************************************************/
void ChangeModuleAddress(void)
{

	SLEEP_TIMER_OFF; // since we got keypress, we want sleep timer off 
 	sleep_timer_loop_count = 0;
 		 	
  	ModuleAddressIncrement();
  
   	if(INCREMENT_BUTTON) 
 	{ 
	 	delay_ms(800);
	 	// if its held down long enough then increment real fast
		while(INCREMENT_BUTTON) {  ModuleAddressIncrement(); delay_ms(20); };
	}		

}
