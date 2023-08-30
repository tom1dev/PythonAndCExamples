/*
 * lab3_comsys201.c
 *
 * Created: 10/05/2023 8:08:44 am
 * Author : tdev429

* Answer to the example on page 54 of slides - CS201 2023
* Making a ring counter on port B LEDs
*/
//CPU frequency is set to 16MHz
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define TIME_DELAY 60
int main(void)
{
	//Port B is set as output
	DDRB = 0xFF; //DDRB = 0b11111111;
	PORTB = 0x01;
	while (PINC5==1)
	{
	
			if (PORTB == 0x80){
				PORTB=0x01;
			}
			PORTB = (PORTB<<1);
			_delay_ms(TIME_DELAY);
			
	}
}



