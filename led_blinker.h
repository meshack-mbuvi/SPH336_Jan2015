/*
 * led_blinker.h
 *
 *  Created on: Mar 6, 2015
 *      Author: meshack mbuvi
 */

#ifndef LED_BLINKER_H_
#define LED_BLINKER_H_
#include "gpio.h"

void displayBinary(char);
void  displayBinary(char byte1){
	  int i,k;
	  int LED[4];//An array of four leds
	  for (i = 0; i < 4; i++) {//looping through the byte 
	  k = (( byte1 << i));	//left bitshifting

	   if (k & 0x08){	//applying bitwise operator AND to k and the mask
	    	LED[i] = 1;}	//if in the result there is 1,position i is set
	    else{
	    	LED[i] = 0;}
	  }
		//assigning GPIOA's controlling the leds to bit position of the array LED[4]
		GPIOA->PDDR.bit_reg.bit11 = LED[0]; //e1
	  	GPIOA->PDDR.bit_reg.bit28 = LED[1]; //e2
	  	GPIOA->PDDR.bit_reg.bit29 = LED[2]; //e3
	  	GPIOA->PDDR.bit_reg.bit10 = LED[3]; //e4
}

#endif /* LED_BLINKER_H_ */
