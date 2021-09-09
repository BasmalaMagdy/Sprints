/*
 * Button_driver.c
 *
 *      Author: Basmala Magdy
 */

/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "Button_driver.h"
#include "../../MCAL/DIO.h"

/************************************************************************
  	  	  	  	  	  	  	  Local Macros
 ***********************************************************************/
#define BUTTON1		0x01

/************************************************************************
  	  	  	  	  	  	  	  Global Static Variables
 ***********************************************************************/
static PORT_Config_t Porta;


/************************************************************************
  	  	  	  	  	  	  	  Function Definitions
 ***********************************************************************/

void Button_Initialization(){
	Porta.port = A;					// set port to PORT A
	Porta.direction &= ~BUTTON1;	// set direction of PA0 to input
	Port_Init(&Porta);				// initialize Port A
}



uint8_t Check_Button(){
	Read_Port(&Porta);				// Read Value of PORT A
	return (Porta.Data & BUTTON1);	// return only the value of button after the mask
}
