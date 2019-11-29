/*
Basic Osciliscope implementation using ADC peripheral on Atmega16 uC.
By: Karim Hamdy - 2019
Karimhamdymo@gmail.com

*/
#define F_CPU 16000000 
#include <util/delay.h>
#include <avr/io.h>

#include "Serial_Atmega16.h"
#include "ADC_Atmega16.h"


#define VCC 5.0
#define R_OHM_METER 982
#define ohm_pin 5
#define current_pin 6
#define volt_pin 7
#define average_counter 10


float read_ohm()
{
	int ADC_ohm_int;
	float ADC_ohm_float,ohm_res;
	
	
	ADC_ohm_int = ADC_Read_pin(ohm_pin);
	ADC_ohm_float = ADC_ohm_int;
	ADC_ohm_float *= 0.0048828;				//Sensitivity for every 1 step = 4.88 mv
	ohm_res = (ADC_ohm_float*R_OHM_METER)/(VCC-ADC_ohm_float);		//voltage divider compensation
	ohm_res -=95;													// in efficiencies in wiring and errors compensation.
	return (ohm_res);
}

float read_current()
/*
Used ACS712 current sensor IC.
*/
{
	int ADC_curr_int;
	float ADC_current_float,current_res;
	
	
	ADC_curr_int = ADC_Read_pin(current_pin);
	ADC_current_float = ADC_curr_int;
	ADC_current_float *= 4.88;				//Sensitivity for every 1 step = 4.88 mv
	current_res = (ADC_current_float - 2500)/185.0;		// calibration based on the sensor.
	return (current_res);
}

float read_volt()
{
	int ADC_volt_val;
	float volt_res;
	
	ADC_volt_val = ADC_Read_pin(volt_pin);
	volt_res = ADC_volt_val;
	volt_res *= 4.88;				//Sensitivity for every 1 step = 4.88 mv
	volt_res *= (45.9+9.8)/9.8;		//voltage divider compensation
	volt_res /= 1000.0;			// parsing for two digits only and a decimal point.
	return (volt_res);
}


int main(void)
{
	float volt_result,curr_result,ohm_result;
	int counter;
	char str_volt_res[20],str_curr_res[20],str_ohm_res[20];
	
	
	UART_Init();
	ADC_Init();
    while(1)
    {
	
	volt_result = read_volt();
	sprintf(str_volt_res, "%.2f", volt_result);	//converting the float to string to be printed.
	UART_SendString("ADC volt value = ");
	UART_SendString(str_volt_res);
	UART_SendStringln(" v");
	
	
	
	
	
	curr_result = read_current();			
	sprintf(str_curr_res, "%.2f", curr_result);	//converting the float to string to be printed.
	
	UART_SendString("ADC current value = ");
	UART_SendString(str_curr_res);
	UART_SendStringln(" A");
	
	
	ohm_result=0;
	for (counter =0;counter<average_counter;counter++)	// reading multiple readings and calculating the average of them.
	{
		ohm_result += read_ohm();
	}
	ohm_result /= average_counter;
	sprintf(str_ohm_res, "%.2f", ohm_result);	//converting the float to string to be printed.
	UART_SendString("ADC ohm value = ");
	UART_SendString(str_ohm_res);
	UART_SendStringln(" ohm");
	
	_delay_ms(1000);
	
	
	
	
	}
}

