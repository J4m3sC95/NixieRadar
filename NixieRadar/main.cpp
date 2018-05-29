/*
 * NixieRadar.cpp
 *
 * Created: 05/05/2018 17:07:14
 * Author : James
 */ 

#include "main.h"

volatile unsigned long senseTime = 0;

int main(void)
{
    // disable all pull-ups
	bitSet(MCUCR, PUD);
	// setup system clock prescalar to 2, system clock = 4MHz
	CLKPR = 0x80;
	CLKPR = 1;

	// set Timer1 prescalar to 16384
	TCCR1 |= 0b1111;
	// enable overflow interrupt, occurs every 1.05secs
	bitSet(TIMSK, TOIE1);	
	sei();
	
    while (1);	
}

// Timer overflow interrupt
ISR(TIMER1_OVF_vect){
	senseTime++;
	
	if(bitRead(PINB, IN_PIN)){
		senseTime = 0;
	}
	else if(senseTime > HALF_TIMEOUT_SECS){
		return;
	}
	pressADJ();
}

// function for pressing ADJ
void pressADJ(){
	// enable output for a short period of time
	bitSet(DDRB, SPEAKER_PIN);
	bitSet(DDRB, ADJ_PIN);
	_delay_ms(ADJ_HOLD_TIME);
	bitClear(DDRB, SPEAKER_PIN);
	bitClear(DDRB, ADJ_PIN);
}



