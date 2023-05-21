
#include "ECUAL/LED/led.h"
#include "ECUAL/button/button.h"
#include "MCAL/INT/interrupt.h"

unsigned char act, i , j;

int main(void)
{
		sei();
		
		intSense0_1 (INT0, 1);
		intEN(INT0);
		T_stop(0); //Clear Timer0
		T_stop(0); //Clear Timer2
		//Initializing LEDs
		
		//CARS
		LED_init (portA, 2);//R
		LED_init (portA, 1);//Y
		LED_init (portA, 0);//G
		//HUMAN
		LED_init (portB, 2);//R
		LED_init (portB, 1);//Y
		LED_init (portB, 0);//G
		
		LED_init(portC, 0);
		//Initializing Int button
		Button_init (portD, 2);

		TCCR2 |= (1<<0);
		while(j < 10)
		{
			LED_toggle(portA, 2);
			TCCR0 |= (1<<0); //Delay for 512 ms
			while (i < 2000)
			{
				while ((TIFR & (1<<0))==0);
				TIFR |= (1<<0);
				i++;
			}
			TCCR0 = 0x00;
			i = 0;

			while ((TIFR & (1<<6))==0);
			TIFR |= (1<<6);
			j++;
	}
	TCCR2 =0x00;		
	j = 0;


/*
    while (1) 
    {
		
		//Cars: Green
		//Pedestrians: Red

		LED_on (portB, 2);
		LED_on  (portA, 0);
		T_init(0, Norm);
		T_prescalar(0, twoFiveSix);
		while (i < 77)
		{
			TCNT0 |= (1<<1);
			while ((TIFR & (1<<0)) == 0);
			TIFR |= (1<<0);
			i++;
		}
		T_stop(0);
		//Time has stopped
		i = 0;
		
		LED_off (portB, 2);
		LED_off  (portA, 0);
		
		//Cars: Yellow
		//Pedestrians: Yellow		
		act ++;
		LED_on (portB, 1);
		LED_on  (portA, 1);
	
		//Timer Begins
		T_init(0, Norm);
		T_prescalar(0, one);
		while (i < 20)
		{
			LED_toggle(portB, 1);
			LED_toggle(portA, 1);
			T_init(2, Norm);
			T_prescalar(2, one);
			while (j < 1000) //Delay occurs for 256ms
			{
				while((TIFR & (1<<6)) == 0);
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
		
		LED_off (portB, 1);
		LED_off  (portA, 1);

		//Cars: Red
		//Pedestrians: Green	
		act ++;
		LED_on (portB, 0);
		LED_on  (portA, 2);
		
		//Timer Begins
		T_init(0, Norm);
		T_prescalar(0, twoFiveSix);
		while (i < 77)
		{
			TCNT0 |= (1<<1);
			while ((TIFR & (1<<0)) == 0);
			TIFR |= (1<<0);
			i++;
		}
		T_stop(0);
		//Time has stopped	
		i = 0;	
		LED_off (portB, 0);
		LED_off (portA, 2);			
    }

}

ISR(INT0_vect)
{
switch (act)
	{
		
	case 0:
			LED_off (portB, 0);
			LED_off (portA, 2);
			LED_on (portC, 0);
			
			T_init(0, Norm);
			T_prescalar(0, twoFiveSix);
			while (i < 77)
			{
				TCNT0 |= (1<<1);
				while ((TIFR & (1<<0)) == 0);
				TIFR |= (1<<0);
				i++;
			}
			T_stop(0);
			//Time has stopped
			i = 0;
			
			act ++;
			break;
	}
}
*/
