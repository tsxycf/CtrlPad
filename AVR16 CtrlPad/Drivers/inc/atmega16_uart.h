/*
 *File name:atmega64_uart.h
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff
 *Describe: ϵͳ����ʱ��Ϊ7.3728
 */

#ifndef __atmega64_uart_h
#define __atmega64_uart_h

#include "stdint.h"
#include <macros.h>


extern void UARTInit( uint8_t PortNum, uint16_t baudrate, uint8_t receiveInterrupt );//��ʼ�����ں���
extern uint8_t UARTSendByte( uint8_t PortNum, uint8_t Byte );//����һ���ֽ�

//���ں�
#define UART0   0
#define UART1   1
//������
#define _7_3728Mhz4800      95
#define _7_3728Mhz9600      47
#define _7_3728Mhz19200     23
#define _7_3728Mhz38400     11
#define _7_3728Mhz57600     7
#define _7_3728Mhz115200    3
//�жϿ�������
#define ENABLE  1
#define DISABLE 0


//uint8_t UART0_SendByte (int ucData);
//void UARTInit( uint8_t PortNum, uint16_t baudrate, uint8_t receiveInterrupt );


#endif
