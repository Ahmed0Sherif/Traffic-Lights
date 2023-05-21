/*
 * button.c
 *
 * Created: 9/13/2022 2:22:41 AM
 *  Author: hp
 */ 

#include "button.h"

void Button_init (uint8_t b_port, uint8_t b_pin)
{
DIO_init(b_port, b_pin, IN);
}


void Button_read (uint8_t b_port, uint8_t b_pin, uint8_t* state)
{
	DIO_read(b_port, b_pin, state);
}
