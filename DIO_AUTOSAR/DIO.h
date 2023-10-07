/*
 * DIO.h
 *
 *  Created on: Oct 7, 2023
 *      Author: DELL
 */

#ifndef DIO_H_
#define DIO_H_
#include"tm4c123gh6pm.h"
#include"std_types.h"
#include "bitwise_operation.h"

typedef uint8  Dio_LevelType;
typedef uint8  Dio_ChannelType;
typedef uint32 Dio_PortLevelType;
typedef uint8  Dio_PortType;

#define STD_HIGH 1U
#define STD_LOW  0U

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5
#define MAX_NUMBER_OF_CHANNELS 48
#define MAX_NUMBER_OF_PORT 6

Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId);
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId);
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level);

#endif /* DIO_H_ */
