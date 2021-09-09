/*
 * DIO.c
 *
 *      Author: Basmala Magdy
 */

/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "DIO.h"


/************************************************************************
  	  	  	  	  	  	  	  Function Definitions
 ***********************************************************************/
void Port_Initialization(PORT_Config_t * Port){
	switch(Port->port){
	case A:
		PORTA_DIR = Port->direction;
		break;
	case B:
		PORTB_DIR = Port->direction;
		break;
	case C:
		PORTC_DIR = Port->direction;
		break;
	case D:
		PORTD_DIR = Port->direction;
		break;
	}
}

void Write_Port(PORT_Config_t *Port){
	switch(Port->port){
	case A:
		PORTA_OUT = Port->Data;
		break;
	case B:
		PORTB_OUT = Port->Data;
		break;
	case C:
		PORTC_OUT = Port->Data;
		break;
	case D:
		PORTD_OUT = Port->Data;
		break;
	}
}

void Write_Pin(PORT_t port, uint8_t pin, uint8_t Data){
	switch(port){
	case A:
		PORTA_OUT = (PORTA_OUT & (~(1<<pin))) | ((Data & 0x01) <<pin);
		break;
	case B:
		PORTB_OUT = (PORTB_OUT & (~(1<<pin))) | ((Data & 0x01) <<pin);
		break;
	case C:
		PORTC_OUT = (PORTC_OUT & (~(1<<pin))) | ((Data & 0x01) <<pin);
		break;
	case D:
		PORTD_OUT = (PORTD_OUT & (~(1<<pin))) | ((Data & 0x01) <<pin);
		break;
	}
}

void Read_Port(PORT_Config_t *Port){
	switch(Port->port){
	case A:
		Port->Data= PORTA_IN;
		break;
	case B:
		Port->Data= PORTB_IN;
		break;
	case C:
		Port->Data= PORTC_IN;
		break;
	case D:
		Port->Data= PORTD_IN;
		break;
	}
}
