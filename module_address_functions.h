#ifndef MODULE_ADDRESS_FUNCTIONS_H
	#define MODULE_ADDRESS_FUNCTIONS_H
	
	#define OUR_MODULE_ADDRESS_EEPROM_LOCATION	0
	#define FIRSTBOOT_EEPROM_LOCATION	1
	#define	INCREMENT_BUTTON				   !(PORTFbits.RF6)
	
	void LoadModuleAddress(void);
	void SaveModuleAddress(int ModuleAddress);
	void ModuleAddressIncrement(void);
	void ModuleAddressDisplayRefresh(void);
	void ChangeModuleAddress(void);
	
	#ifdef MODULE_ADDRESS_FUNCTIONS_C

		int our_module_address;

	#else

		extern int our_module_address;
	
	#endif

#endif
