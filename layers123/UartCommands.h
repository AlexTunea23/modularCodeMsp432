/*
 * UartCommands.h
 *
 *  Created on: Mar 11, 2016
 *      Author: PetruAlexandru
 */

#ifndef UARTCOMMANDS_H_
#define UARTCOMMANDS_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef enum
{
	uartModule0,
	uartModule1,
	uartModule2
}UartMoudule;



void InitUarts(UartMoudule name);



void SendCharacterData(char c);
void SendAccelData(char *s);


#endif /* UARTCOMMANDS_H_ */
