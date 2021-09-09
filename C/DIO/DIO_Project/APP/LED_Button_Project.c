/*
 *  LED_Button_Project.c
 *
 *      Author: Basmala Magdy
 *
 *      Description: Turn on the led if the button is pressed and turn it off if the button is unpressed
 */

/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "LED_Button_Project.h"

/************************************************************************
  	  	  	  	  	  	  	  Function Definitions
 ***********************************************************************/
void APPlication(){
	
	uint32_t K;							/*  create delay */
	LED_Initialization();							/* Initialize LED */
	Button_Initialization();						/* Initialize Button */
	while(1){
		if(Check_Button()){				/* check if the button is pressed */
			LED_Toggle();				/* toggles the led */
			for(K=0; K<20000; K++);		/* Toggle the Led */
		}
	}
}
