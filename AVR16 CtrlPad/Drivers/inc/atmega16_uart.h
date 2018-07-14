/*
 *File name:atmega64_uart.h
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff
 *Describe: 系统晶振时钟为7.3728
 */

#ifndef __atmega64_uart_h
#define __atmega64_uart_h

#include "stdint.h"
#include <macros.h>


extern void UARTInit( uint8_t PortNum, uint16_t baudrate, uint8_t receiveInterrupt );//初始化串口函数
extern uint8_t UARTSendByte( uint8_t PortNum, uint8_t Byte );//发送一个字节

//串口号
#define UART0   0
#define UART1   1
//波特率
#define _7_3728Mhz4800      95
#define _7_3728Mhz9600      47
#define _7_3728Mhz19200     23
#define _7_3728Mhz38400     11
#define _7_3728Mhz57600     7
#define _7_3728Mhz115200    3
//中断开启定义
#define ENABLE  1
#define DISABLE 0


//uint8_t UART0_SendByte (int ucData);
//void UARTInit( uint8_t PortNum, uint16_t baudrate, uint8_t receiveInterrupt );


#endif
