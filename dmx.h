#ifndef DMX_H
	#define DMX_H
	
	#define 	DMX_BREAK_BIT_PIN					PORTDbits.RD0
	#define 	DMX_BREAK_BIT_TRIS					TRISDbits.TRISD0
	#define		DMX_MAX_CHAN					 	30

	void 	SendDMXMAB(void);
	void	SendDMXBreak(void);
	void	XmitDMXData(void);
	void	DMXChannelDataInit(void);

	#ifdef DMX_C
		

		int dmx_channel_data[DMX_MAX_CHAN];
	#else

		extern int dmx_channel_data[DMX_MAX_CHAN];
	#endif
	
#endif
