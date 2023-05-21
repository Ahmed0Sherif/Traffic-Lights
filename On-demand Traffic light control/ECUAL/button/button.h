/*
 * button.h
 *
 * Created: 9/13/2022 2:10:23 AM
 *  Author: hp
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/INT/interrupt.h"

//Button States
#define OFF   0
#define ON 1


void Button_init (uint8_t b_port, uint8_t b_pin);
void Button_read (uint8_t b_port, uint8_t b_pin, uint8_t* state);





#endif /* BUTTON_H_ */