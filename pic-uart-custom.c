
void SetupPICUart1(void)
{
	

	//SPI1STATbits.SPIEN = 0;
	//SPI1CONbits.DISSCK = 1;
	//SPI1CONbits.DISSDO = 1;

	//TRISFbits.TRISF2 = 1;
	//asm("nop");
	//TRISFbits.TRISF3 = 0;
	
	//U1MODEbits.USIDL = 1;
	//U1MODEbits.RTSMD; 	// POR
	//U1MODEbits.UEN = 	00;
	//U1MODEbits.WAKE = 	1;
	//U1MODEbits.LPBACK = 0;
	//U1MODEbits.ABAUD  = 0;
	//U1MODEbits.RXINV = 0;
	
	// PDSEL1 and PDSEL0
	// 11 = 9-bit data, no parity
	// 10 = 8-bit data, odd parity
	// 01 = 8-bit data, even parity
	// 00 = 8-bit data, no parity
	//U1MODEbits.PDSEL = 01;
	
		
	// 1 = Two Stop Bit
	// 0 = One Stop Bit
	//U1MODEbits.STSEL  = 0;
		
	//U1STAbits.UTXISEL1 = 0;
	//U1STAbits.UTXISEL0 = 0;

	// TX Polarity Inversion
	// 1 = Inverted
	// 0 = Non Inverted / normal
	//U1STAbits.UTXINV   = 1;
	
	//U1STAbits.UTXBRK = 0;
	
	//U1STAbits.URXISEL1 = 0;
	//U1STAbits.URXISEL0 = 0;
	//U1STAbits.ADDEN  = 0; 
	
	
	// 4800bps @ 20 mhz
	//U1MODEbits.BRGH =	0;
	//U1BRG = 129;
	
	//U1MODEbits.UARTEN = 1;  
	//U1STAbits.UTXEN =  1;
	
	//U1STAbits.OERR = 0;
	

	// U1TXIE: UART1 Transmitter Interrupt
	//IEC0bits.U1TXIE = 0;
	// U1RXIE: UART1 Receiver Interrupt Enable bit
	//IPC2bits.U1RXIP = 7;
	//IFS0bits.U1RXIF = 0;
	//IEC0bits.U1RXIE = 1;


}
/******************************************************/


/******************************************************/

void SetupPICUart2(void)
{

	
	TRISFbits.TRISF5 = 0;
	TRISFbits.TRISF4 = 0;
	
	U2MODEbits.USIDL; 	// POR
	U2MODEbits.RTSMD; 	// POR
	U2MODEbits.UEN1 = 	0;
	U2MODEbits.UEN0 =	0;
	U2MODEbits.WAKE = 	1;
	U2MODEbits.LPBACK = 0;
	U2MODEbits.ABAUD  = 0;
//	U2MODEbits.RXINV; 	// POR
	
	// PDSEL1 and PDSEL0
	// 11 = 9-bit data, no parity
	// 10 = 8-bit data, odd parity
	// 01 = 8-bit data, even parity
	// 00 = 8-bit data, no parity
	U2MODEbits.PDSEL1 = 0;
	U2MODEbits.PDSEL0 = 0;
		
	// 1 = Two Stop Bit
	// 0 = One Stop Bit
	U2MODEbits.STSEL  = 1;
		
	U2STAbits.UTXISEL1 = 0;
	U2STAbits.UTXISEL0 = 0;
	
	// TX Polarity
	// 1 = Inverted
	// 0 = Non Inverted / normal
	U2STAbits.UTXINV   = 0;
	
	U2STAbits.UTXBRK = 0;

	U2STAbits.URXISEL1 = 0;
	U2STAbits.URXISEL0 = 0;
	U2STAbits.ADDEN  = 0; 
	//U2TXREGbits.UTX8 = 0;
	
	// 250k bps @ 20 mhz
	U2MODEbits.BRGH =	1;
	U2BRG = 9;
	
	// U2TXIE: UART1 Transmitter Interrupt Enable bit
	IEC1bits.U2TXIE = 0;
	// U2RXIE: UART1 Receiver Interrupt Enable bit
	IEC1bits.U2RXIE = 0;
	// U2ERIE: UART1 Error Interrupt Enable bit
	// IEC4bits.U2ERIE = 0;
	
	// U2RXIP2:U2RXIP0: UART1 Receiver Interrupt Priority bits
	// 111 = Interrupt is priority 7 (highest priority interrupt)
	// •••
	// 001 = Interrupt is priority 1
	// 000 = Interrupt source is disabled	
	IPC7bits.U2RXIP = 0;
	
	// Uart Enable
	U2MODEbits.UARTEN = 1;  
	U2STAbits.UTXEN =  1;
	
}

/******************************************************/
