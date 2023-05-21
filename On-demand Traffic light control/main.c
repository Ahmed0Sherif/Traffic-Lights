#include "ECUAL/LED/led.h"
#include "ECUAL/button/button.h"
#include "Application/app.h"



int main(void)
{	
	app_init();
	
    while (1) 
    {
		
	change_act();
	}
}
ISR(INT0_vect)
{
switch (act)
	{	case 2:	
		act = 3;
		state_act();
		break;
		
		case 1:
		act = 4;
		state_act();
		break;
		
	}
	
}