/*
 * main.c
 *
 *  Created on: Sep 17, 2021
 *      Author: Basmala
 */


#include <math.h>
#include "LCD/lcd.h"
#include "keypad/keypad.h"
#include "MCAL/DIO.h"
#include "timer.h"

void Timer1_INT();

//Timer_ConfigType timer1_Strut;

//uint8_t count = 0;
int main(void)
{
	/*timer1 init interrupt*/
	//SREG |= (1<<7);                   /* Enable Global Interrupt */


	LCD_init();                        /* initialize LCD */
	//Button_Init();                     /* initialize Buttons */
	LCD_displayStringRowColumn(0,2,"Please Guess");
	LCD_displayStringRowColumn(1,3,"the number");
	//_delay_ms(4000); /* wait four seconds */


	//LCD_clearScreen(); /* clear the LCD display */

	/*timer1_Strut.mode				= CTC_MODE;
	timer1_Strut.clock				= F_CPU_1024;
	timer1_Strut.PWM				= PWM_0;
	timer1_Strut.initial			= 0;
	timer1_Strut.top_count			= 5000;
	timer1_Strut.interrupt			= TRUE;
	TIMER1_init(&timer1_Strut);
	Timer1_setCallBack(Timer1_INT);  */     /* CallBack Function for timer 1 CTC Channel A Interrupt Function */

	unsigned char key;
	unsigned char count;

	while(1)
	{

		/* if any switch pressed for more than 500 ms it counts more than one press */
		key = KeyPad_getPressedKey(); /* get the pressed key number */
		count = key;
		if((key <= 9) && (key >= 0))
		{
			LCD_clearScreen(); /* clear the LCD display */
			LCD_intgerToString(key); /* display the pressed keypad switch */
		}
		_delay_ms(500); /* Press time */
		key = KeyPad_getPressedKey(); /* get the pressed key number */
		if(key == '=')
		{

			if (count > 15)
			{
				LCD_clearScreen(); /* clear the LCD display */
				LCD_displayStringRowColumn(0,2,"press from");
				LCD_displayStringRowColumn(1,0," ");
				LCD_intgerToString(1);
				LCD_displayStringRowColumn(1,2,"< press <= ");
				LCD_intgerToString(15);
			}
			else if(count < 1)
			{
				LCD_clearScreen(); /* clear the LCD display */
				LCD_displayStringRowColumn(0,0,"you should press");
			}
			else
			{
				int num = (rand()% (15 - 1 +1))+ 1;
				if (count == num)
				{
					LCD_clearScreen(); /* clear the LCD display */
					LCD_displayStringRowColumn(0,2,"you WIN");
				}
				else
				{
					LCD_clearScreen(); /* clear the LCD display */
					LCD_displayStringRowColumn(0,2,"you LOSE");
				}
			}
		}


	}

}
/*void Timer1_INT(){

    if (count > 15)
    {

    	LCD_displayStringRowColumn(0,2,"press from");
    	LCD_displayStringRowColumn(1,0," ");
    	LCD_intgerToString(1);
    	LCD_displayStringRowColumn(1,2,"< press <= ");
    	LCD_intgerToString(15);
    }
    else if(count < 1)
    {
    	LCD_clearScreen();
    	LCD_displayStringRowColumn(0,0,"you should press");
    }
    else
    {
    	int num = (rand()% (15 - 1 +1))+ 1;
    	if (count == num)
    	{
        	LCD_clearScreen();
        	LCD_displayStringRowColumn(0,2,"you WIN");
    	}
    	else
    	{
        	LCD_clearScreen();
        	LCD_displayStringRowColumn(0,2,"you LOSE");
    	}
    }
	TIMER1_init(&timer1_Strut);
}*/
