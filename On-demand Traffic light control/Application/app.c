/*
 * app.c
 *
 * Created: 9/14/2022 12:41:40 PM
 *  Author: hp
 */ 

#include "app.h"

uint8_t arr[]= {1, 9, 16, 0};

/************************************************************************/
/*app_init contains all instructions necessary for the start of the program.*/
/************************************************************************/
/*
void delay_5sec (void)
{		
		i = 0;
		T_init(0, Norm,twoFiveSix);
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
}
*/


void app_init(void)
{
	//Disabling WatchDog Timer

	//Switching interrupts ON in SREG
		sei();
	//Activating External interrupt_0, and setting its sensitivity to rising edge
		intSense0_1 (INT0, rise);
		intEN(INT0);
	//Clearing the used timers: TIMER0, TIMER2
		T_stop(0); //Clear Timer0
		T_stop(2); //Clear Timer2
		//Initializing LEDs
		
		//CARS
		LED_init (portA, 2);//R
		LED_init (portA, 1);//Y
		LED_init (portA, 0);//G
		//HUMAN
		LED_init (portB, 2);//R
		LED_init (portB, 1);//Y
		LED_init (portB, 0);//G
		
		LED_init(portC, 0);//This LED is for testing purposes...
		
		//Initializing Int button
		Button_init (portD, 2);
		act = 0;
}

/************************************************************************/
/* state_act inspects the value of "act" variable, resulting in a change in the perspective states */
/************************************************************************/

void state_act (void)
{
	switch (act)
	{
		case 0:// Pedestrian--> Red, Cars-->Green 			
				LED_on (portB, 2);
				LED_on (portA, 0);
				
				LED_off (portB, 1);
				LED_off (portA, 1);
		break;
		
		case 1: //Pedestrian--> Yellow, Cars-->Yellow
				LED_off (portB, 2);
				LED_off (portA, 0);
					
				LED_off(portB, 0);
				LED_off(portA, 2);
				
				LED_on (portB, 1);
				LED_on (portA, 1);	
		break;
		
		case 2: //Pedestrian--> Green, Cars-->Red
				LED_off (portB, 1);
				LED_off (portA, 1);
				
				LED_on(portB, 0);
				LED_on(portA, 2);	
		break;
		
		case 3: //Interrupt Case#1
				//When INT0 is activated at case 2, repeat case 2 again, then case 1 is activated while the pedestrian green light is ON
				T_stop(0); //Clear Timer0
				act = 2;
				state_act();
				T_delay(0, Norm, twoFiveSix, 77, 2);
				act = 1;
				state_act();
				LED_on(portB,0);
				toggle_5 (arr);

				WDTCR = 0x08;
				//Time has stopped
				i = 0;
				act = 0;
				while(1);
		break;
		case 4: //Interrupt Case#2
				//When INT0 is activated at case 1 or 0. Enter case 1 with car red light is on, enter case 2 then to intermediate state.
						T_stop(0);
						T_stop(2);
						act = 1;
						state_act();
						LED_on(portA, 2);;
						toggle_5 (arr);
						act = 2;
						state_act();
						T_delay(0, Norm, twoFiveSix, 77, 2);
						
						act = 1;
						state_act();
						LED_on(portB,0);
						toggle_5 (arr);

						WDTCR = 0x08;
						//Time has stopped
						i = 0;
						act = 0;
						while(1);
						break;
	}
}

void change_act(void)
{
	act = 0 ;
	state_act(); //ACT0: Cars-->Green Human-->Red
	T_delay(0, Norm, twoFiveSix, 77, 2);
	
	act ++; //act = 1;
	state_act();//ACT1: Cars-->Yellow Human-->Yellow
	toggle_5 (arr);
	
	
	act++; //act =2
	state_act(); //ACT2: Cars-->Red Human-->Green
	T_delay(0, Norm, twoFiveSix, 77, 2);
	
	act--;
	state_act();//ACT1: Cars-->Yellow Human-->Yellow
	toggle_5 (arr);
}
