/*
 * Serial driver for Atmega16 uC
 *
 * Karim Hamdy - 2019
 *  Karimhamdymo@gmail.com
 */ 


#include "Serial_Atmega16.h"

void UART_Init (void)
{
	UBRRH = (BAUDRATE>>8);
	UBRRL = BAUDRATE;
	UCSRB |=(1<<TXEN)|(1<<RXEN);
	UCSRC |=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void UART_Write (uint8_t data)
{
	while(!(UCSRA&(1<<UDRE)));
	UDR = data;
}
void UART_SendString(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		UART_Write(str[j]);
		j++;
	}
}
void UART_SendStringln(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		UART_Write(str[j]);
		j++;
	}
	UART_SendString("\r");
}

void UART_Read(void)
{
	while(!(UCSRA&(1<<RXC)));
	return UDR;
}
