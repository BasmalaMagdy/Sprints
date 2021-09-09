/*
 * DIO.h
 *
 *      Author: Basmala Magdy
 */

#ifndef DIO_H_
#define DIO_H_

/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "../registers.h"

/************************************************************************
  	  	  	  	  	  	  	  ENUMS
 ***********************************************************************/
typedef enum{
	INPUT,
	OUTPUT
}Direction_t;

typedef enum{
	A,
	B,
	C,
	D
}PORT_t;


/************************************************************************
  	  	  	  	  	  	  	  STRUCTS & UNIONS
 ***********************************************************************/
typedef struct{
	uint8_t Data;
	uint8_t direction;
	PORT_t port;
}PORT_Config_t;



/************************************************************************
  	  	  	  	  	  	  	  Function Decelerations
 ***********************************************************************/
void Port_Initialization(PORT_Config_t * Port);
void Write_Port(PORT_Config_t *Port);
void Read_Port(PORT_Config_t *Port);
void Write_Pin(PORT_t port, uint8_t pin, uint8_t Data);



#endif /* DIO_H_ */
