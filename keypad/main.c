/*
 * main.c
 *
 *  Created on: Sep 16, 2018
 *      Author: PC
 */
#include "keypad.h"

int main ()

{
	DDRC|=0x0f ;
	DDRC|=0x0f ;
	DDRC|=0x0f ;
	DDRC|=0x0f ;


	while(1) {
	PORTC=(PORTC&0xF0) |   (keypad_read()&0x0F  )  ; //RULE : 2bl elinsert lazmm andf elbits elawl 8ltt kza mra

	}
}


