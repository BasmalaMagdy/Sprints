/*
 * motors.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Bassant Yasser
 */

#include "motors.h"

typedef enum{
	low,
	high
}motor_state;

void motor_init()
{
	PORT_Config_t port_config_C = {0x00, 0x0f, C};
	Port_Init(&port_config_C);
	PORT_Config_t port_config_D = {0x00, 0x30, D};
	Port_Init(&port_config_D);
	Write_Port(&port_config_C);
}

void motor_start(uint8_t speed, Direction dir)
{
	set_speed(speed);
	set_direction(dir);
}

void set_speed(uint8_t duty_cycle)
{
	uint16_t co = (duty_cycle*65535/100);
	Timer_ConfigType timer_config = {F_CPU_CLOCK, PWM_FAST, CLEAR_ON_COMPARE, PWM_2, OC1A, 0, co, 0xffff, FALSE, CHANNEL_A};
	TIMER1_init(&timer_config);
	timer_config.channel = CHANNEL_B;
	timer_config.OutputPin = OC1B;
	TIMER1_init(&timer_config);


}

void set_direction(uint8_t dir)
{
	switch(dir)
	{
	case Forward:
		Write_Pin(C, P0, low);
		Write_Pin(C, P1, high);
		Write_Pin(C, P2, low);
		Write_Pin(C, P3, high);
		break;
	case Backward:
		Write_Pin(C, P0, high);
		Write_Pin(C, P1, low);
		Write_Pin(C, P2, high);
		Write_Pin(C, P3, low);
		break;
	case Left:
		Write_Pin(C, P0, low);
		Write_Pin(C, P1, high);
		Write_Pin(C, P2, high);
		Write_Pin(C, P3, low);
		break;
	case Right:
		Write_Pin(C, P0, high);
		Write_Pin(C, P1, low);
		Write_Pin(C, P2, low);
		Write_Pin(C, P3, high);
		break;
	}
}

void motor_stop()
{
	Write_Pin(C, P0, low);
	Write_Pin(C, P1, low);
	Write_Pin(C, P2, low);
	Write_Pin(C, P3, low);
}
