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
	while (1)
	{
	
			if (PORTB == 0x80){
				PORTB=0x01;
			}
			PORTB = (PORTB<<1);
			_delay_ms(TIME_DELAY);
			
		/*
		PORTB = 0x01; //00000001 The first LED is on
		_delay_ms(TIME_DELAY);
		PORTB = 0x02; //00000010 The second LED is on
		_delay_ms(TIME_DELAY);
		PORTB = 0x04; //00000100 The third LED is on
		_delay_ms(TIME_DELAY);
		PORTB = 0x08; //00001000 The fourth LED is on
		_delay_ms(TIME_DELAY);
		PORTB = 0x10; //00010000 The fifth LED is on
		_delay_ms(TIME_DELAY);
		PORTB = 0x20; //00100000 The sixth LED is on
		_delay_ms(TIME_DELAY);
		PORTB = 0x40; //01000000 The seventh LED is on
		_delay_ms(TIME_DELAY);
		PORTB = 0x80; //10000000 The eighth LED is on
		_delay_ms(TIME_DELAY);
		*/
	}
}



