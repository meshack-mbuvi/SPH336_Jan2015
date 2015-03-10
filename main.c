/*
 * File: main.c
 *
 * Copyright (c) 2015, karfes@gmail.com
 *
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 *
 */
#include<ctype.h>
#include"gpio.h"
#include"uart.h"
#include "led_blinker.h"

int main(void){	
	//temporally UART data holder
	uint8_t byte=0;

	//initialize system
	SystemInit();

	//initialize UART5 with 8-N-1 settings, 57600 baudrate
	init_uart(UART5_BASE_PTR,periph_clk_khz,57600);

	//clear all interrupts and enable interrupts
	nvic->ICPR[2] |= 1 << (87 & 0x1F); //Clear Pending Interrupts
	nvic->ISER[2] |= 1 << (87 & 0x1F); //Enable Interrupts
	
	//initialize GPIO ports
	gpio_init();

	//Loop forever
	while(1)
	{
		//toggle_LED1();
		
		if(data_available()){
			LOOP: byte = uart_read();
			if (isdigit(byte)){//check that data received is an digit
				led_blinker(byte);//call function to blink leds with byte
					//as the argument
			}
			// TODO: check character being given as input to be part of boundary
			else{
				reset();
				goto LOOP;
			}
		}
	}

}

