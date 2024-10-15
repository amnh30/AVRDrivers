/*
 * main.c
 *
 *  Created on: Sep 13, 2024
 *      Author: Ahmed Nageeb
 */
#include"avr/delay.h"
#define C_CPU 8000000Ul
/*Library*/
#include "STD_Types.h"
/*MCAL Layer*/
#include "MDIO/MDIO_Interface.h"
/*HAL Layer*/
#include "HLCD_interface.h"

int main(int argc, char **argv)
{
	/* MDIO Init */

	MDIO_IntialPins();
	HLCD_VoidLcdIint();
	/* Draw Special Chars */
	/* 1- Sned Command to set CGRAM Address */
	/* Draw 1 Special Char into First Char in CGRAM*/
	HLCD_VoidLcdWriteCmd(0x40+(8*0));
	/* 2- Draw Char */
	HLCD_VoidLcdWriteChar(0B01111);
	HLCD_VoidLcdWriteChar(0B01000);
	HLCD_VoidLcdWriteChar(0B11111);
	HLCD_VoidLcdWriteChar(0B00100);
	HLCD_VoidLcdWriteChar(0B00100);
	HLCD_VoidLcdWriteChar(0B00100);
	HLCD_VoidLcdWriteChar(0B00100);
	HLCD_VoidLcdWriteChar(0B00100);
	/* Draw 1 Special Char into Second Char in CGRAM*/
	HLCD_VoidLcdWriteCmd(0x40+(8*1));
	/* 2- Draw Char */
		HLCD_VoidLcdWriteChar(0B00000);
		HLCD_VoidLcdWriteChar(0B10000);
		HLCD_VoidLcdWriteChar(0B11100);
		HLCD_VoidLcdWriteChar(0B00111);
		HLCD_VoidLcdWriteChar(0B00011);
		HLCD_VoidLcdWriteChar(0B11111);
		HLCD_VoidLcdWriteChar(0B00000);
		HLCD_VoidLcdWriteChar(0B00000);
	/* 3- Display this patterns on LCD */
		HLCD_VoidSetCurser(HLCD_LINE_1,0);
		HLCD_VoidLcdWriteChar(1);
		HLCD_VoidLcdWriteChar(0);
		/**/
		for(u8 i = 0 ; i < 10 ; i++){
		HLCD_VoidLcdWriteCmd(0x1C);
		_delay_ms(50);
		}
		for(u8 i = 0 ; i < 10 ; i++){
				HLCD_VoidLcdWriteCmd(0x18);
				_delay_ms(50);
				}

	while(1){
		for(u8 i = 0 ; i < 10 ; i++){
				HLCD_VoidLcdWriteCmd(0x1C);
				_delay_ms(200);
				}
				for(u8 i = 0 ; i < 10 ; i++){
						HLCD_VoidLcdWriteCmd(0x18);
						_delay_ms(200);
						}
	}

}
