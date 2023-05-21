/*
 * led.c
 *
 * Created: 9/13/2022 12:14:54 AM
 *  Author: hp
 */ 

#include "led.h"

void LED_init (uint8_t ledPort, uint8_t ledPin)
{
DIO_init(ledPort, ledPin, OUT );
}

void LED_on (uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort, ledPin, HIGH);
}

void LED_off (uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort, ledPin, LOW);
}

void  LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	DIO_toggle (ledPort, ledPin);
}

/*uint8_t _size = sizeof(arr);*/

void toggle_5 (uint8_t array[] )
{
	TCCR0 = 0x00;
	TCCR2 = 0x00;
	i = 0;
	j = 0;
	uint8_t k = 0;
	
	T_init(0, Norm, one);
	while (i < 10)
	{
		for (k = 0; k < sizeof(&array); k++)
		{
		if(array[k] > 23)
			LED_toggle(portD, array[k] % 8);
		else if (array[k] > 15)
			LED_toggle(portC, array[k] % 8);
		else if (array[k] > 7)
			LED_toggle(portB, array[k] % 8);
		else if (array[k] >= 0)
			LED_toggle(portA, array[k] % 8);
		}

		T_init(2,Norm,oneTwoEight);
		while (j < 16)
		{
			TCNT2 = 0x0C;
			while ((TIFR & (1<<6))==0);
			TIFR |= (1<<6);
			j++;
		}
		T_stop(2);
		j = 0;
		while ((TIFR & (1<<0)) == 0);
		TIFR |= (1<<0);
		i ++;
	}
	T_stop(0);
	//Time has stopped
	i = 0;
}