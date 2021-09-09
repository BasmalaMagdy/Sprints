/*
 * LED_driver.c
 *
 *      Author: Basmala Magdy
 */

/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "LED_driver.h"
#include "../../MCAL/DIO.h"

/************************************************************************
  	  	  	  	  	  	  	  Local Macros
 ***********************************************************************/
#define LED 	0x20

/************************************************************************
  	  	  	  	  	  	  	  Global Static Variables
 ***********************************************************************/
static PORT_Config_t Portc;


/************************************************************************
  	  	  	  	  	  	  	  Function Definitions
 ***********************************************************************/
void LED_Initialization(){
	Portc.port = C;
	Portc.direction = LED;
	Portc.Data &= ~LED;
	Port_Init(&Portc);
	Write_Port(&Portc);
}

void OPEN_LED(){
	Portc.Data |= LED;
	Write_Port(&Portc);
}


void CLOSE_LED(){
	Portc.Data &= ~LED;
	Write_Port(&Portc);
}

void LED_Toggle(){
	Portc.Data ^= LED;
	Write_Port(&Portc);
}

