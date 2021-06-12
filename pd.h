#ifndef PD_H
	#define PD_H

	
	#define		PD_ADDRESS_MASK						0x80
	#define		PD_FIRE_COMMAND_MASK				0x10
	#define		PD_TEST_COMMAND_MASK				0x00

	
	void 	parse_recvd_pd_data(int byte);
	void 	SendPDTestReply(void);
	
	#ifdef PD_C
	
		unsigned int our_module_selected = 0x00;
		unsigned int pd_data_recvd = 0;
		unsigned int pd_armed = 0;
	#else
		extern unsigned int our_module_selected;
		extern unsigned int pd_data_recvd;	
		extern unsigned int pd_armed;
	#endif
#endif
