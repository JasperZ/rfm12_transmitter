/*
 * rfm12Sender.c
 *
 * Created: 22.04.2012 14:01:41
 *  Author: Jasper
 */ 

#define F_CPU 8000000UL
#define TEST 200

#include <avr/io.h>
#include "../../RFM12/RFM12/rfm12.h"
#include <stdio.h>
#include <util/delay.h>

int main(void)
{
	rfm_init(TX_MODE);
	
	uint8_t i;
	uint8_t data1[TEST];
	uint8_t data2[20];
	struct DataPackage* pkg1;
	struct DataPackage* pkg2;

	for(i=0; i<TEST; i++)
	{
		data1[i] = i;
	}
/*	
	for(i=0; i<20; i++)
	{
		data2[i] = i+TEST;
	}
	
	pkg1 = createDataPackage(1, 2, 0, data1, TEST);
	i = sendPackageBlocking(pkg1);
	deleteDataPackage(pkg1);
	
	if(i == 1)
	{
		for(i=0; i<200; i++)
			_delay_ms(10);
		pkg2 = createDataPackage(1, 2, 2, data2, 20);
		sendPackageBlocking(pkg2);
		deleteDataPackage(pkg2);
	}
	*/
    while(1)
    {
		struct DataPackage* pkg3 = createDataPackage(1, 2, 0, data1, TEST);
		sendPackageBlocking(pkg3);
		deleteDataPackage(pkg3);
/*		
		for(i=0; i<5; i++)
			_delay_ms(10);
*/	}
}