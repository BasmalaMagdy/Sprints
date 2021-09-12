/*
 * DIO.h
 *
 *  Created on: Sep 5, 2021
 *      Author: ah132
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include "../../registers.h"

typedef enum{
	A,
	B,
	C,
	D
}PORT;

typedef struct{
	uint8_t Data;
	uint8_t direction;
	PORT port;

}PORT_Config_t;

/************************************************************************
  	  	  	  	  	  	  	  Function Decelerations
 ***********************************************************************/
void Port_Init(PORT_Config_t * Port);
void Write_Port(PORT_Config_t *Port);
void Read_Port(PORT_Config_t *Port);
//void Set_PIN(PORT port, uint8_t pin, uint8_t Data);
void Write_Pin(PORT port, uint8_t pin, uint8_t value);

#endif /* MCAL_DIO_DIO_H_ */
