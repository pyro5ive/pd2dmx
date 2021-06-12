#ifndef SEV_SEG_LED_H
	#define	SEVEN_SEG_LED_H
	
	#define	SEVSEG_DISPLAY_PORT			PORTE
	#define SEVSEG_DISPLAY_TRIS			TRISE
	
	#define	SEVSEG_DIGIT1_EN_TRIS		TRISFbits.TRISF0	
	#define	SEVSEG_DIGIT1_EN_PIN		PORTFbits.RF0	
	
	#define	SEVSEG_DIGIT2_EN_TRIS		TRISFbits.TRISF1	
	#define	SEVSEG_DIGIT2_EN_PIN		PORTFbits.RF1		
	
	void 	SevSegLEDInit(void);
	void 	SevSegLEDDisplay(int digit1, int digit2);
	void 	SevSegLEDisplayOff(void);
	void SetupDisplayRefreshTimer(void);
	
	#ifdef SEV_SEG_LED_C
		unsigned int seven_seg_digits[] =  {	0x3f, 	// 0
	/* for some reason element 0 dont work */	0x3f,	// odd bug workaround
							  		    		0x06, 	// 1
							  					0x5B, 	// 2
							  					0x4F, 	// 3
									  			0x66, 	// 4
						  						0x6D, 	// 5
						  						0x7D, 	// 6
						  						0x07, 	// 7
								  				0x7f, 	// 8
									  			0x6f, 	// 9
												0x77, 	// A uc
							  					0x7c, 	// b lc
							  					0x39, 	// C uc
					  							0x5E, 	// d lc
					  							0x79, 	// E
						  						0x71	// F
							  				 };
	#else
		extern unsigned int seven_seg_digits[];
	#endif

#endif
		
		
				  			
				  			
				  
