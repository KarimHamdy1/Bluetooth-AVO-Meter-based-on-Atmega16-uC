/*
 * ADC driver for Atmega16 uC
 *
 * Karim Hamdy - 2019
 *  Karimhamdymo@gmail.com
 */ 


#ifndef ADC_ATMEGA16_H_
#define ADC_ATMEGA16_H_
#include <util/delay.h>
#include <avr/io.h>


#include <avr/io.h>

void ADC_Init();
int ADC_Read_pin(char channel);


#endif /* ADC_ATMEGA16_H_ */