/*
 * UART driver for Atmega16 uC
 *
 * Karim Hamdy - 2019
 *  Karimhamdymo@gmail.com
 */ 



#ifndef SERIAL_H_
#define SERIAL_H_
#include <util/delay.h>
#include <avr/io.h>

#define BAUD 9600                  // define baud
#define BAUDRATE 103


void UART_Init (void);
void UART_Write (uint8_t data);
void UART_SendString(char *str);
void UART_SendStringln(char *str);
void UART_Read(void);



#endif /* SERIAL_DRIVER_H_ */