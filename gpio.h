/*
 * gpio.h
 *
 *  Created on: Mar 2, 2015
 *      Author: karibe
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "Mk60.h"
#include "main.h"

void  displayBinary(char);
void gpio_init(void);
<<<<<<< HEAD
void toggle_LED2(void);
extern void put(uint8_t *s);
=======
//void toggle_LED1(void);
//void toggle_LED2(void);
extern void toggle_LEDS(void);
extern void toggle_LED2(void);
extern void puts(uint8_t *s);
>>>>>>> cd325d88c5957456e9f237e88e3edd91f62c6dfa
extern void SystemInit(void);
/*
	brief PORTA initialization
*/
void gpio_init(void)
{
	//PTA19 as a button input
	PA->PCR[19].mux = 0x01; //PortA pin 19 as GPIO
	PA->PCR[19].irqc = 0xA; //Interrupt on falling edge
	PA->PCR[19].pe = 0x01; //pull-up enable
	PA->PCR[19].ps = 0x01; //select internal pull-up resistor
	//PortA pins 10, 11, 28 and 29 as alt1=GPIO
	PA->PCR[10].mux = 0x01;
	PA->PCR[11].mux = 0x01;
	PA->PCR[28].mux = 0x01;
	PA->PCR[29].mux = 0x01;
	//PTE8 and PTE9 as UART5
	PE->PCR[8].mux = 0x0;	//clear default function
	PE->PCR[9].mux = 0x0;	//clear default function
	PE->PCR[8].mux = 0x3;	//alt3 = UART5_TX
	PE->PCR[9].mux = 0x3; 	//alt3 = UART5_RX
	//GPIO port data direction Port A as output for LEDs (pin 11, 28, 29 and 10), Port E UART5(PTE8 TX, PTE9 RX)
	GPIOA->PDDR.bit_reg.bit11 = out;
	GPIOA->PDDR.bit_reg.bit28 = out;
	GPIOA->PDDR.bit_reg.bit29 = out;
	GPIOA->PDDR.bit_reg.bit10 = out;
	GPIOE->PDDR.bit_reg.bit8 = out; //UART5_TX is an output
	//No need to configure GPIO for as an input, by default all pins are inputs
	//GPIOA->PDDR.bit_reg.bit19 = IN;
	//GPIOE->PDDR.bit_reg.bit9 = IN //UART5_RX is an input
}

<<<<<<< HEAD
=======
/*
void toggle_LED1(void){
	//volatile int mask=1<<29;
	//GPIOA->PTOR.bit_reg.bit11 = on; //0x20000000
	//GPIOA->PTOR.bit_reg.bit29 = on;
	asm(	".equ mask, 0x20000000;" // declare a mask for bit 29
			"LDR R1, =0x400ff00c;" // create a pointer to GPIOA->PTOR
			"LDR R2, [R1];" //load GPIOA->PTOR to R2 using R1 as pointer
			"ORR R2, mask;" //mask bit 29
			"STR R2, [R1]" //write back the result to GPIOA->PTOR
		);
}
*/
/*
>>>>>>> cd325d88c5957456e9f237e88e3edd91f62c6dfa
void toggle_LED2(void){
	//GPIOA->PTOR.bit_reg.bit28 = on;
	GPIOA->PTOR.bit_reg.bit10 = on;
	put((uint8_t*)("Hello World\r\n"));
}
<<<<<<< HEAD
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
=======
*/
//display a number inbinary with the 4 LEDs
//LED1 -> bit11
//LED2 -> bit28
//LED3 -> bit29
//LED4 -> bit10
void display(char number){
	char bits[4]={0,0,0,0};
	int i=0;
	for(i=0;i<4;i++){
		bits[i]=~(number>>i)&1;
	}
	GPIOA->PDOR.word_reg = (uint32_t)(bits[0]<<11 | bits[1]<<28 | bits[2]<<29 | bits[3]<<10);
>>>>>>> cd325d88c5957456e9f237e88e3edd91f62c6dfa
}

/*
	brief  Port A ISR Handler
 */
void PORTA_IRQHandler(void)
{
	PA->ISFR.word_reg = 0xFFFFFFFF; //clear Interrupt Status Register by writing ones in all bits --- why???
	toggle_LED2(); //toggle the second LED to indicate interrupt serviced
}



#endif /* GPIO_H_ */
