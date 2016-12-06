/*
 * Timer.h
 *
 * Created: 11/15/16 1:26:17 PM
 *  Author: ianmcdoom
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/interrupt.h>

int count_timer = 0;


void timer_init(void){
	TCCR1B |= 1<<CS10 | 1<<CS11 | 1<<WGM12; //WGM12 - clear timer on compare
	TIMSK1 |= 1<<OCIE1A;
	OCR1A = 15624;
}

ISR(TIMER1_COMPA_vect)
{
	if(count_timer == 20){
		read_TMP36();
		PORTD ^= 1<<PIND6;
		uart_transmit_string(str_temp);
		uart_transmit(13);
		count_timer = 0;
	}
	else{
		count_timer++;
	}
}

#endif /* TIMER_H_ */

