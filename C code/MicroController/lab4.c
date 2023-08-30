#define F_CPU 16000000//crystal

/***** Includes *****/
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/***** Hardware macros *****/
//Hardware macros for outputs
#define SET_LED_TENTHS   PORTD |= (1<<PD3)
#define CLR_LED_TENTHS   PORTD &= ~(1<<PD3)
#define SET_LED_ONES   PORTD |= (1<<PD5)
#define CLR_LED_ONES   PORTD &= ~(1<<PD5)
#define SET_LED_TENS   PORTD |= (1<<PD6)
#define CLR_LED_TENS   PORTD &= ~(1<<PD6)


/***** User macros *****/
#define BLINK_DELAY 250
#define ALL_LEDS_ON PORTD |= (1<<PD3) |(1<<PD5) |(1<<PD6)
#define ALL_LEDS_OFF PORTD &= ~( (1<<PD3) |(1<<PD5) |(1<<PD6) )

#define ICP_ON_POS_EDGE  TCCR1B & (1<<ICES1) //detect if ICP positive edge detect

/***** Declare & initialise global variables *****/
volatile uint16_t t1_count = 0;
volatile uint16_t t2_count = 0;
volatile uint16_t overflow_count = 0;
volatile uint32_t total_count = 0;
volatile uint8_t pulse_width = 0;

/***** Interrupt Service Routines *****/
ISR(TIMER1_CAPT_vect)
{
	if ( ICP_ON_POS_EDGE ){         //pulse start, positive edge of ICP
		overflow_count = 0;         //reset overflow counter
		t1_count = ICR1;            // capture TCNT1 read both bytes ICR1H and ICR1L
		TCCR1B &= ~(1<<ICES1); 		//change setup for negative edge capture
	}
	else {                          //pulse finish, negative edge
		t2_count = ICR1;            // capture TCNT1
		total_count = (overflow_count*65536) + t2_count - t1_count;	//work out total time
		total_count *= 64;          //to get uS
		total_count /= 100000 ;     //to get tenths of sec
		TCCR1B |= (1<<ICES1);       //change setup for positive edge capture
	}
}
ISR(TIMER1_OVF_vect) {
	overflow_count++; //increment overflow count
}


/***** Prototypes for Functions *****/
void display_count(uint8_t tenthsToDisplay);

/***** Main program *****/
int main(void) {
	/***** IO Hardware Config *****/
	DDRD = 0xFF; 			//set as outputs
	DDRB &= ~(1 << DDB0);	// set PB0 as an input
	
	/***** Input Capture Unit Config *****/
	TCCR1B |= 1<<CS12 | 1<<CS10;    //prescaler = 1024, 64uS resolution
	TCCR1B |= (1<<ICES1);           //setup ICP positive edge detect
	TCCR1B |= (1<<ICNC1);           //enable noise canceling
	TIMSK1 |= (1<<ICIE1);           //enable ICP interrupt
	TIMSK1 |= (1<<TOIE1);           //enable Timer1 OVF interrupt
	sei();                          //enable global interrupts

	/***** Loop code *****/
	while (1) {
		if (total_count > 0){
			pulse_width = total_count; //truncate 16bit var to 8 bits
			display_count(pulse_width); // call the display_count function
			total_count = 0;    //to indicate hat the value has been displayed
		}
	} //end while(1)
} //end of main

/***** Functions *****/
void display_count(uint8_t tenthsToDisplay) {
	uint8_t tens = tenthsToDisplay / 100 ;
	uint8_t ones = (tenthsToDisplay - tens * 100 ) /10;
	uint8_t tenths = tenthsToDisplay - tens * 100 - ones * 10;
	
	ALL_LEDS_ON;
	_delay_ms(BLINK_DELAY);
	ALL_LEDS_OFF;
	_delay_ms(BLINK_DELAY);
	_delay_ms(BLINK_DELAY);
	_delay_ms(BLINK_DELAY);

	int i = 0;
	for (i = 0; i < tens; i++) {
		SET_LED_TENS;
		_delay_ms(BLINK_DELAY);
		CLR_LED_TENS;
		_delay_ms(BLINK_DELAY);
	}
	_delay_ms(BLINK_DELAY);
	_delay_ms(BLINK_DELAY);
	for (i = 0; i < ones; i++) {
		SET_LED_ONES;
		_delay_ms(BLINK_DELAY);
		CLR_LED_ONES;
		_delay_ms(BLINK_DELAY);
	}
	_delay_ms(BLINK_DELAY);
	_delay_ms(BLINK_DELAY);
	for (i = 0; i < tenths; i++) {
		SET_LED_TENTHS;
		_delay_ms(BLINK_DELAY);
		CLR_LED_TENTHS;
		_delay_ms(BLINK_DELAY);
	}
}
