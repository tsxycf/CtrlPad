/*
*MCU:   ATMEGA64
使用频率 7.3728Mhz
*/

#include <macros.h>
#include <iom16v.h>
#include "atmega16_config.h"



int main(void)
{
    uint8_t tmp = 0xaa;
    UARTInit( UART0, _7_3728Mhz19200, ENABLE );

    while(1)
    {
        UARTSendByte( UART0, tmp );
    }
    return 1;
}






