#ifndef CHANNEL_STATUS_LED_FUNCTIONS_H
	#define CHANNEL_STATUS_LED_FUNCTIONS_H

	#define STATUS_LED_TRIS	TRISB
	#define	STATUS_LED_PORT	PORTB
	
	void ChannelStatusLEDControl(int led_num, int on_off);
	void ChannelStatusLEDInit(void);
	void UpdateChannelStatus(void);
	
	#ifdef CHANNEL_STATUS_LED_FUNCTIONS_C
	
	#else
	
	#endif

#endif



