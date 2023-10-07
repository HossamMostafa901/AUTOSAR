/*
 * DIO.c
 *
 *  Created on: Oct 7, 2023
 *      Author: DELL
 */

#include"DIO.h"

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*Dio_ReadChannel function*/
/*INPUTS: ChannelId of type Dio_ChannelType */
/*OUTPUTS:STD_HIGH |STD_LOW of type Dio_LevelType */
/*Description: This Function Read channel value in specific PORT*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId)
{   /*flag to know there is error*/
    uint8 Error_State=0xff;
    /*to get the port we want */
    uint8 PORT=ChannelId / 8;
    /*to get the PIN we want */
    uint8 channel=ChannelId % 8;
    uint8 state;/*state of pin*/
    if(ChannelId>MAX_NUMBER_OF_CHANNELS)
    {
        /*if user give number bigger than number channels return error_state to know its wrong*/
        state=Error_State;
    }
    else
    {
        switch(PORT)
        {
        case PORTA:state= GET_BIT(GPIO_PORTA_DATA_R,channel);    break;
        case PORTB:state= GET_BIT(GPIO_PORTB_DATA_R,channel);    break;
        case PORTC:state= GET_BIT(GPIO_PORTC_DATA_R,channel);    break;
        case PORTD:state= GET_BIT(GPIO_PORTD_DATA_R,channel);    break;
        case PORTE:state= GET_BIT(GPIO_PORTE_DATA_R,channel);    break;
        case PORTF:state= GET_BIT(GPIO_PORTF_DATA_R,channel);    break;
        default:break;
        }
    }
    return state;
}

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*Dio_WriteChannel*/
/*INPUTS: ChannelId of type Dio_ChannelType,level of type Dio_LevelType  */
/*OUTPUTS:void */
/*Description: This Function write on channel value either STD_HIGH |STD_LOW in specific PORT*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
    uint8 PORT=ChannelId / 8;
    uint8 channel=ChannelId % 8;
    switch(PORT)
    {
    case PORTA:
        if(Level==STD_HIGH)
        {
            SET_BIT(GPIO_PORTA_DATA_R,channel);
        }
        else
        {
            CLR_BIT(GPIO_PORTA_DATA_R,channel);
        }
        break;
    case PORTB:
        if(Level==STD_HIGH)
        {
            SET_BIT(GPIO_PORTB_DATA_R,channel);
        }
        else
        {
            CLR_BIT(GPIO_PORTB_DATA_R,channel);
        }
        break;
    case PORTC:
        if(Level==STD_HIGH)
        {
            SET_BIT(GPIO_PORTC_DATA_R,channel);
        }
        else
        {
            CLR_BIT(GPIO_PORTC_DATA_R,channel);
        }
        break;
    case PORTD:
        if(Level==STD_HIGH)
        {
            SET_BIT(GPIO_PORTD_DATA_R,channel);
        }
        else
        {
            CLR_BIT(GPIO_PORTD_DATA_R,channel);
        }
        break;
    case PORTE:
        if(Level==STD_HIGH)
        {
            SET_BIT(GPIO_PORTE_DATA_R,channel);
        }
        else
        {
            CLR_BIT(GPIO_PORTE_DATA_R,channel);
        }
        break;
    case PORTF:
        if(Level==STD_HIGH)
        {
            SET_BIT(GPIO_PORTF_DATA_R,channel);
        }
        else
        {
            CLR_BIT(GPIO_PORTF_DATA_R,channel);
        }
        break;
    }
}
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*Dio_ReadPort function*/
/*INPUTS: PortId of type Dio_PortType */
/*OUTPUTS:value of type Dio_PortLevelType */
/*Description: This Function Read  value in specific PORT*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId)
{
    /*flag to know there is error*/
    uint32 Error_State=0xffff;
    uint32 Port_Value;/*flag has PORT_Value*/

    if(PortId>MAX_NUMBER_OF_PORT)
    {
        /*if the user input number bigger than port port_value=error_state*/
        Port_Value=Error_State;
    }
    else
    {
        switch(PortId)
         {
        case PORTA:Port_Value=GPIO_PORTA_DATA_R;break;
        case PORTB:Port_Value=GPIO_PORTB_DATA_R;break;
        case PORTC:Port_Value=GPIO_PORTC_DATA_R;break;
        case PORTD:Port_Value=GPIO_PORTD_DATA_R;break;
        case PORTE:Port_Value=GPIO_PORTE_DATA_R;break;
        case PORTF:Port_Value=GPIO_PORTF_DATA_R;break;
        default:break;
          }
    }
    return Port_Value;
}
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*Dio_WritePort function*/
/*INPUTS: PortId of type Dio_PortType,level of type Dio_PortLevelType */
/*OUTPUTS:void */
/*Description: This Function write  value in specific PORT*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level)
{
    switch(PortId)
    {
    case PORTA:GPIO_PORTA_DATA_R= Level;   break;
    case PORTB:GPIO_PORTB_DATA_R= Level;   break;
    case PORTC:GPIO_PORTC_DATA_R= Level;   break;
    case PORTD:GPIO_PORTD_DATA_R= Level;   break;
    case PORTE:GPIO_PORTE_DATA_R= Level;   break;
    case PORTF:GPIO_PORTA_DATA_R= Level;   break;
    default:/*wrong port so nothing will be write*/break;
    }

}


