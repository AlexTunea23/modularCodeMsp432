
#include <driverlib.h>
#include "UartCommands.h"
#include "Sensors.h"
#include "Utils.h"
#include <stdint.h>
#include <string.h>
#include"i2c0.h"

void SendName()
{
	SendAccelData("x");
	SendAccelData(",");
	SendAccelData("y");
	SendAccelData(",");
	SendAccelData("z");
}

void SendUartTest(char *a, char *b, char *c)
{
	SendAccelData("x");
	SendAccelData(";");
	SendAccelData("y");
	SendAccelData(";");
	SendAccelData("z");
	SendAccelData(";");
	SendAccelData("a");
	SendAccelData("@");
	SendAccelData(a);
	SendAccelData(",");
	SendAccelData(b);
	SendAccelData(",");
	SendAccelData(c);
	SendAccelData(",");
	SendAccelData("40");
	//SendAccelData(",");

	SendCharacterData(10);
	SendCharacterData(13);
}

void SendTest()
{
	uint32_t i;
	static int32_t mpuXVal=0;

	static int32_t mpuYVal=0;

	static int32_t mpuZVal=0;

	mpuXVal=ReadSensors(xAxis);
	//HextoDecXVal=HexaToDec2G(mpuXVal);

	mpuYVal=ReadSensors(yAxis);
	//HextoDecYVal=HexaToDec2G(mpuYVal);

	mpuZVal=ReadSensors(zAxis);
	//HextoDecZVal=HexaToDec2G(mpuZVal);

	char xVal[16];
	char yVal[16];
	char zVal[16];

	strcpy(xVal, IntToString(mpuXVal));
    strcpy(yVal, IntToString(mpuYVal));
    strcpy(zVal, IntToString(mpuZVal));

    SendUartTest(xVal,yVal,zVal);

	for(i=0;i<=100000;i++);
}



int main(void)
{
	// uint8_t dataread=0;
    WDT_A_holdTimer();
    InitSensors(mpu);
    InitUarts(uartModule0);




    while(1)
    {

    	//SendingTest();
    	SendTest();
    }
}




