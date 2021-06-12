#ifndef ISR_H
	#define ISR_H

	void ISRSetup(void);
	void __attribute__((__interrupt__)) _U1RXInterrupt(void);
	void __attribute__((__interrupt__)) _INT0Interrupt(void);
	void __attribute__((__interrupt__)) _INT1Interrupt(void);
	void __attribute__((__interrupt__)) _INT2Interrupt(void);
	void __attribute__((__interrupt__)) _T1Interrupt(void);
	void __attribute__((__interrupt__)) _T2Interrupt(void);

	#ifdef ISR_C
	
	#else
	
	
	#endif

#endif
