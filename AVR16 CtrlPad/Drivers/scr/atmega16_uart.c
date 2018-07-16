/*
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff
 *Describe: clk频率为7.3728下配置
 */

#include "atmega16_uart.h"
#include "stdint.h"
#include <iom16v.h>

/*********************************************************************************************************
** Function name:       UARTInit
** Descriptions:        配置串口的波特率
** input parameters:    PortNum：串口号可取值UART0
** input parameters:    baudrate：_7_3728Mhz4800... 宏定义定义
** input parameters:    receiveInterrupt:接收中断开启
** output parameters:   无
** Returned value:      无
** 备注：设备按照8位，无校验，1停止位
*********************************************************************************************************/
void UARTInit( uint8_t PortNum, uint16_t baudrate, uint8_t receiveInterrupt )
{
    if( UART0 == PortNum )
    {
        UCSRB |= BIT(TXEN);   //使能UART0发送开关
        UBRRH = (uint8_t)(baudrate >> 8);
        UBRRL = (uint8_t)(baudrate >> 0);  //设置波特率
        if( ENABLE == receiveInterrupt )
        {
            UCSRB |= BIT(RXCIE) ;//开启接收中断
        }
        else if( DISABLE == receiveInterrupt )
        {
            UCSRB &= ~( BIT(RXCIE) );//关闭接收中断
        }
    }
}

/*********************************************************************************************************
** Function name:       UARTSendByte
** Descriptions:        通过相应串口发送一个字节，查询方式下完成发送。
** input parameters:    PortNum：串口号可取值UART0
** input parameters:    Byte：要发送的字节
** Returned value:      发送成功为0,发送错误为非0
** 备注：1+8+1+无校验格式
*********************************************************************************************************/
uint8_t UARTSendByte( uint8_t PortNum, uint8_t Byte )
{
    if( UART0 == PortNum )
    {
        UDR = Byte;
        while( (UCSRA & BIT(TXC)) == 0  );    //等待发送完成
        UCSRA |= BIT(TXC);    //清除标志位
    }
    return 0;
}






#pragma interrupt_handler uart0_rx_isr: iv_USART0_RX        //UART0接收中断函数
void uart0_rx_isr(void)
{
    _NOP();
}







