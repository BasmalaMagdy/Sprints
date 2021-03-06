/*
 * main.c
 *
 *  Created on: Sep 17, 2021
 *      Author: Basmala
 */


#include <math.h>
#include "LCD/lcd.h"
#include "Button/Button_driver.h"
#include "MCAL/DIO.h"
#include "timer.h"

void Timer1_INT();

Timer_ConfigType timer1_Strut;

uint8_t count = 0;
int main(void)
{
	/*timer1 init interrupt*/
	SREG |= (1<<7);                   /* Enable Global Interrupt */


	LCD_init();                        /* initialize LCD */
	Button_Init();                     /* initialize Buttons */
	LCD_displayStringRowColumn(0,2,"Please Guess");
	LCD_displayStringRowColumn(1,3,"the number");
	//_delay_ms(4000); /* wait four seconds */


	//LCD_clearScreen(); /* clear the LCD display */

	timer1_Strut.mode				= CTC_MODE;
	timer1_Strut.clock				= F_CPU_1024;
	timer1_Strut.PWM				= PWM_0;
	timer1_Strut.initial			= 0;
	timer1_Strut.top_count			= 5000;
	timer1_Strut.interrupt			= TRUE;
	TIMER1_init(&timer1_Strut);
	Timer1_setCallBack(Timer1_INT);       /* CallBack Function for timer 1 CTC Channel A Interrupt Function */


    while(1)
    {
    	if (Check_Button() == 1)
    	{
    		_delay_ms(200);
            count++;
    	}
    }

}
void Timer1_INT(){

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
	TIMER1_init(&timer1_Strut);
}
