/*************************************
 ** Revision: V1.0
 ** Date: 2018-6-13
 ** Author: cff
 ** Describe:
 *************************************/



#include "stdint.h"
#include <iom16v.h>
#include <macros.h>

#include <atmega16_gpio.h>

/*********************************************************************************************************
** Function name:   GPIO_SetDir
** Descriptions:    设置端口方向
** input parameters: I/O口（PORT_A..F）
** input parameters: 位号（0.1.2.3.4.5.6.7）
** input parameters: 方向（IN OUT）
** output parameters:
** Returned value:
** 备注：
********************************************************************************************************/
void GPIO_SetDir( uint8_t portNum, uint8_t bitValue, uint8_t dir )
{
    uint8_t tmp;
    switch( portNum )
    {
        case PORT_A:
        if(dir)
            DDRA |= BIT(bitValue);
        else
            DDRA &= ~( BIT(bitValue) );
        break;
        case PORT_B:
        if(dir)
            DDRB |= BIT(bitValue);
        else
            DDRB &= ~( BIT(bitValue) );
        break;
        case PORT_C:
        if(dir)
            DDRC |= BIT(bitValue);
        else
            DDRC &= ~( BIT(bitValue) );
        break;
        case PORT_D:
        if(dir)
            DDRD |= BIT(bitValue);
        else
            DDRD &= ~( BIT(bitValue) );
        break;
        case PORT_E:
        if(dir)
            DDRE |= BIT(bitValue);
        else
            DDRE &= ~( BIT(bitValue) );
        break;
        case PORT_F:
        if(dir)
            DDRF |= BIT(bitValue);
        else
            DDRF &= ~( BIT(bitValue) );
        break;
        case PORT_G:
        if(dir)
            DDRG |= BIT(bitValue);
        else
            DDRG &= ~( BIT(bitValue) );
        break;
        default:
        break;
    }
}



/*********************************************************************************************************
** Function name:   GPIO_Set
** Descriptions:    引脚置位
** input parameters: I/O口（PORT_A..F）
** input parameters: 位号（0.1.2.3.4.5.6.7）
** input parameters: 位值( PORT_SET,PORT_SET )
** output parameters:
** Returned value:
** 备注：
**********************************************************************************************************/
void GPIO_Set(uint8_t portNum, uint8_t bitValue, uint8_t value)
{
    switch( portNum )
    {
        case PORT_A:
        if( value )
            PORTA = BIT(bitValue);
        else
            PORTA &= ~(BIT(bitValue));
        break;
        case PORT_B:
        if( value )
            PORTB = BIT(bitValue);
        else
            PORTB &= ~(BIT(bitValue));
        break;
        case PORT_C:
        if( value )
            PORTC = BIT(bitValue);
        else
            PORTC &= ~(BIT(bitValue));
        break;
        case PORT_D:
        if( value )
            PORTD = BIT(bitValue);
        else
            PORTD &= ~(BIT(bitValue));
        break;
        case PORT_E:
        if( value )
            PORTE = BIT(bitValue);
        else
            PORTE &= ~(BIT(bitValue));
        break;
        case PORT_F:
        if( value )
            PORTF = BIT(bitValue);
        else
            PORTF &= ~(BIT(bitValue));
        break;
        case PORT_G:
        if( value )
            PORTG = BIT(bitValue);
        else
            PORTG &= ~(BIT(bitValue));
        break;
        default:
        break;
    }
}


/*********************************************************************************************************
** Function name:   GPIO_Get
** Descriptions:    获得引脚值
** input parameters: I/O口（PORT_A..F）
** input parameters: 位号（0.1.2.3.4.5.6.7）
** output parameters:
** Returned value:
** 备注：
*********************************************************************************************************/
uint8_t GPIO_Get(uint8_t portNum, uint8_t bitValue )
{
    uint8_t tmp;
    switch( portNum )
    {
        case PORT_A:
        tmp = PINA;
        break;
        case PORT_B:
        tmp = PINB;
        break;
        case PORT_C:
        tmp = PINC;
        break;
        case PORT_D:
        tmp = PIND;
        break;
        case PORT_E:
        tmp = PINE;
        break;
        case PORT_F:
        tmp = PINF;
        break;
        case PORT_G:
        tmp = PING;
        break;
        default:
        break;
    }
    tmp &= BIT(bitValue);
    return (tmp? 1 : 0);
}


