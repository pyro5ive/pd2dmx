#ifndef LOW_BATT_CONTROL_H
	#define LOW_BATT_CONTROL_H
	
	#define LOW_BATT_LED_TRIS 	TRISGbits.TRISG9
	#define	LOW_BATT_LED_PIN	PORTGbits.RG9
	
	void SetupLowBatt(void);
	
	
	#ifdef LOW_BATT_CONTROL_C
	
	
	#else
	
	
	#endif
#endif

