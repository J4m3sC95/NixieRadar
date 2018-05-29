/*
 * main.h
 *
 * Created: 08/05/2018 20:33:03
 *  Author: James
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 4000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*
// night override time out in mins
#define TIMEOUT 1
#define TIMEOUT_SECS (TIMEOUT*60)
#define HALF_TIMEOUT_SECS (TIMEOUT_SECS/2)
*/

#define HALF_TIMEOUT_SECS 1

#define ADJ_HOLD_TIME 200

#define IN_PIN PB3
#define SPEAKER_PIN PB4
#define ADJ_PIN	PB1

// bit mod definitions
#define bitSet(reg, bit) reg |= (1 << bit)
#define bitClear(reg, bit) reg &= ~(1<<bit)
#define bitRead(reg, bit) ((reg & (1<<bit))>>bit)
#define bitToggle(reg, bit) reg ^= (1<<bit)

void pressADJ(void);


#endif /* MAIN_H_ */