/*	Author: lab
 *  Partner(s) Name: roz
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    //DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */

    unsigned char fLevel = 0x00;
    unsigned char temp = 0x00;
    unsigned char seatBelt = 0x00;

    while (1) {
	
	fLevel = PINA & 0x0F;
	seatBelt = PINA & 0x70;;

	if((fLevel > 0x00) && (fLevel <= 0x02)){
		temp = 0x60;
	}
	
	if((fLevel > 0x02) && (fLevel <= 0x04)){
		temp = 0x70;
	}

	if((fLevel > 0x04) && (fLevel <= 0x06)){
		temp = 0x38;
	}

	if((fLevel > 0x06) && (fLevel <= 0x09)){
		temp = 0x3C;
	}

	if((fLevel > 0x09) && (fLevel <= 0x0C)){
		temp = 0x3E;
	}

	if((fLevel > 0x0C) && (fLevel <= 0x0F)){
		temp = 0x3F;
	}

	if(fLevel == 0x00){
		temp = 0x40;
	}

	if(seatBelt == 0x30){
		temp = temp | 0x80;
	}

	PORTC = temp;
	temp = 0x00;
	seatBelt = 0x00;
	}
    return 1;
}
