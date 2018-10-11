/*
 * keypad.h
 *
 *  Created on: Sep 16, 2018
 *      Author: PC
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
#define KEYPADPORTDATADIRECTION DDRA
#define KEYPADOUTPUTREG PORTA
#define KEYPADINPUTREG PINA
void keypad_init(void) ;
uint8 keypad_read(void) ;


#endif /* KEYPAD_H_ */
