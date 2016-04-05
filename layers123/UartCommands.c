/*
 * UartCommands.c
 *
 *  Created on: Mar 11, 2016
 *      Author: PetruAlexandru
 */

#include"Uart0.h"
#include "driverlib.h"
#include "i2c.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include"UartCommands.h"
#include"Utils.h"
#define sendingModule EUSCI_A0_MODULE

typedef struct Uarts
{
	uint32_t uartModuleBaseAdress;
	uint8_t uartPort;
	uint8_t pin1Uart;
	uint8_t pin2Uart;
	uint8_t pin3Uart;
	eUSCI_UART_Config uartConfiguration;
	uint8_t primaryModuleFunction;

}Uart;


Uart UartModule0=
{
		.uartModuleBaseAdress=EUSCI_A0_MODULE,
		.uartPort=GPIO_PORT_P1,
		.pin1Uart=GPIO_PIN1,
		.pin2Uart=GPIO_PIN2,
		.pin3Uart=GPIO_PIN3,
		.uartConfiguration=
		{
				EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
		        78,                                     // BRDIV = 78////hjjhihouiykiu7ku
		        2,                                       // UCxBRF = 2
		        0,                                       // UCxBRS = 0
		        EUSCI_A_UART_NO_PARITY,                  // No Parity
		        EUSCI_A_UART_LSB_FIRST,                  // MSB First
		        EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
		        EUSCI_A_UART_MODE,                       // UART mode
		        EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
		},
		.primaryModuleFunction=GPIO_PRIMARY_MODULE_FUNCTION
};

typedef enum
{
	xAccel,
	yAccel,
	zAccel
}UartSend;


Uart defaultUartModule;

void InitUarts(UartMoudule name)
{
	switch(name)
	{
	case uartModule0:
		defaultUartModule=UartModule0;
		InitUart(defaultUartModule.uartModuleBaseAdress,defaultUartModule.uartPort,defaultUartModule.pin1Uart
				,defaultUartModule.pin2Uart,defaultUartModule.pin3Uart,defaultUartModule.uartConfiguration,
				defaultUartModule.primaryModuleFunction);
		break;
	default:
		break;
	}
}


void SendCharacterData(char c)
{
	defaultUartModule=UartModule0;
	SendCharacter(defaultUartModule.uartModuleBaseAdress,c);
}

void SendAccelData(char *s)
{
	defaultUartModule=UartModule0;
	SendString(defaultUartModule.uartModuleBaseAdress,s);
}











