/*app.h*/

#ifndef APP_H_
#define APP_H_

#include "../ECUAL/LED/led.h"
#include "../ECUAL/button/button.h"
#include "../MCAL/INT/interrupt.h"

void app_init(void); //Initializes LEDs, Button, Timers and Interrupt
void app (void); // The main application
void change_act (void); //Uses Timer to change state
void state_act (void); //Depending on the value of variable "act", the state of the LEDs are defined.
void delay_5sec (void); //Uses Timer0 to delay action for 5 seconds.


#endif