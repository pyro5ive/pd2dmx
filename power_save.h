#ifndef POWER_SAVE_H
	#define POWER_SAVE_H

	#define	WAKEUP_BUTTON_PIN	!(PORTFbits.RF6)
	#define	WAKEUP_BUTTON_TRIS	TRISFbits.TRISF6
	
	#define PDARMED_INPUT_TRIS	TRISDbits.TRISD8
	#define PDARMED_INPUT_PIN	PORTDbits.RD8			
	#define PDARMED			!(PORTDbits.RD8)
		
	#define	SLEEP_DELAY			115 	
	#define SLEEP_TIMER_OFF 	T2CONbits.TON = 0
	#define SLEEP_TIMER_ON  	T2CONbits.TON = 1
	

	
	void PowerSave(void);
	void SetupPowerSave(void);
	void SetupPDARMEDWakeup(void);
	
	#ifdef POWER_SAVE_C
	
		unsigned int sleep_timer_loop_count = 0;
		unsigned int iamsleeping;	
	#else
	
		extern unsigned int sleep_timer_loop_count;
		extern unsigned int iamsleeping;
	#endif
	
#endif
