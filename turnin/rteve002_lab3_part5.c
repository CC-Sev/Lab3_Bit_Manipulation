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
    //DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFE; PORTB = 0x01;
    //DDRC = 0xFF; PORTC = 0x00;
    DDRD = 0x00; PORTD = 0xFF;
    /* Insert your solution below */

    unsigned char weight = 0x0000;

    while (1) {
	
	weight = PIND;
	weight = (weight << 1);
	weight = weight | (PINB & 0x01);

	if(weight >= 0x0046){
		PORTB = 0x02;
	}

	else if ((weight > 0x0005) && (weight < 0x0046)){
		PORTB = 0x04;
	}

	else{
		PORTB = 0x00;
	}
	weight = 0x0000;
    }
    return 1;
}
