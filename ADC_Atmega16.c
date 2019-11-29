/*
 * ADC driver for Atmega16 uC
 *
 * Karim Hamdy - 2019
 *  Karimhamdymo@gmail.com
 */ 



#include "ADC_Atmega16.h"

void ADC_Init()
{
	DDRA=0x0;			/* Make ADC port as input */
	ADCSRA = 0x87;			/* Enable ADC, fr/128  */
	ADMUX = 0x47;			/* Vref: Avcc, ADC channel: 0 */
	
}

int ADC_Read_pin(char channel)
{
	char mask_value;	
	int Ain,AinLow;
	
	ADMUX = 0x40;
	ADMUX |= channel;
	
	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
	
	_delay_us(10);
	AinLow = (int)ADCL;		/* Read lower byte*/
	Ain = (int)ADCH*256;		/* Read higher 2 bits and 
					Multiply with weight */
	Ain = Ain + AinLow;				
	return(Ain);			/* Return digital value*/
}
