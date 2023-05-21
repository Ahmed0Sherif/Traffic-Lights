/*
 * led.h
 *
 * Created: 9/13/2022 12:15:27 AM
 *  Author: hp
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/TIMER/timer.h"

void LED_init (uint8_t ledPort, uint8_t ledPin);
void LED_on (uint8_t ledPort, uint8_t ledPin);
void LED_off (uint8_t ledPort, uint8_t ledPin);
void LED_toggle (uint8_t ledPort, uint8_t ledPin);
void toggle_5 (uint8_t array[] ); //Takes an array of numbers, and toggles the state of these pins for 5 seconds with a periodic time of 512ms




#endif /* LED_H_ */