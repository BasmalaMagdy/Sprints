/*
 * App.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Sarah
 */
/*****************************************************
 *                   INCLUDES
 *****************************************************/
#include "App.h"
/*****************************************************
 *                   Global Variables
 *****************************************************/
static uint8_t sp = 30;
static Direction direct = Forward;
static uint8_t count = 0;
static uint8_t flag[5] = {0};

void APP_init(void){
	/*Initializations*/
	motor_init();
	motor_start(30, Forward);
	button_init();
}

void APP_update(void){
	if(button_read() == 0 )
	{
		if(button_read() == 0)
		{
			if(flag[0] == 0)
			{
				motor_stop();
				flag[0] = 1;
			}
		}
	}
	else
	{
		flag[0] = 0;
	}

	if(button_read() == 1)
	{
		if(button_read() == 1)
		{
			if(flag[1] == 0)
			{
				motor_start(30, Left);
				flag[1] = 1;
			}
		}
	}
	else
	{
		flag[1] = 0;
	}
	if(button_read() == 2)
	{
		if(button_read() == 2)
		{
			if(flag[2] == 0)
			{
				motor_start(30, Right);
				flag[2] = 1;
			}
		}
	}
	else
	{
		flag[2] = 0;
	}

	if(button_read() == 4)
	{
		if(button_read() == 4)
		{
			if(flag[3] == 0)
			{
				motor_start(sp, direct);
				flag[3] = 1;
			}
		}
	}
	else
	{
		flag[3] = 0;
	}
	if(button_read() == 8)
	{
		if(button_read() == 8)
		{
			if(flag[4] == 0)
			{
				if(count == 3){
					count = 0;
					sp = 30;
					direct = Backward;
				}
				else{
					switch(count){
					case 0:
						sp = 30;
						direct = Forward;
						break;
					case 1:
						sp = 60;
						direct = Forward;
						break;
					case 2:
						sp = 90;
						direct = Forward;
						break;
					}
				}
				count++;
				flag[4] = 1;
			}
		}
	}
	else
	{
		flag[4] = 0;
	}
}
