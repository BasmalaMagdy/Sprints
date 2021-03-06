#include "timer.h"

void toggle_led();


/* global variable contain the ticks count of the timer */
unsigned char g_tick = 0;

int main()
{
	/* Configure the led pin as output pin. */
	PORTA_DIR  |= (1<<P3);

	/* LED is off at the beginning (Positive Logic). */
	PORTA_OUT &= ~(1<<P3);

	/* Enable global interrupts in MC. */
	SREG  |= (1<<7);

	/* Create configuration structure for Timer driver */
	Timer_ConfigType Config_Ptr = {COMPARE, 0, F_CPU_1024, 500, Timer0};
	Timer_init(&Config_Ptr);

	Timer_setCallBack(toggle_led);

	while(1)
	{

	}

}

void toggle_led()
{
	g_tick++;
	if(g_tick == 3)
	{
		PORTA_OUT ^= (1<<P3);
	}
	else if(g_tick == 5)
	{
		PORTA_OUT ^= (1<<P3);
		g_tick = 0;
	}

}
