/*
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff
 *Describe: clkƵ��Ϊ7.3728������
 */

#include "atmega16_uart.h"
#include "stdint.h"
#include <iom16v.h>

/*********************************************************************************************************
** Function name:       UARTInit
** Descriptions:        ���ô��ڵĲ�����
** input parameters:    PortNum�����ںſ�ȡֵUART0
** input parameters:    baudrate��_7_3728Mhz4800... �궨�嶨��
** input parameters:    receiveInterrupt:�����жϿ���
** output parameters:   ��
** Returned value:      ��
** ��ע���豸����8λ����У�飬1ֹͣλ
*********************************************************************************************************/
void UARTInit( uint8_t PortNum, uint16_t baudrate, uint8_t receiveInterrupt )
{
    if( UART0 == PortNum )
    {
        UCSRB |= BIT(TXEN);   //ʹ��UART0���Ϳ���
        UBRRH = (uint8_t)(baudrate >> 8);
        UBRRL = (uint8_t)(baudrate >> 0);  //���ò�����
        if( ENABLE == receiveInterrupt )
        {
            UCSRB |= BIT(RXCIE) ;//���������ж�
        }
        else if( DISABLE == receiveInterrupt )
        {
            UCSRB &= ~( BIT(RXCIE) );//�رս����ж�
        }
    }
}

/*********************************************************************************************************
** Function name:       UARTSendByte
** Descriptions:        ͨ����Ӧ���ڷ���һ���ֽڣ���ѯ��ʽ����ɷ��͡�
** input parameters:    PortNum�����ںſ�ȡֵUART0
** input parameters:    Byte��Ҫ���͵��ֽ�
** Returned value:      ���ͳɹ�Ϊ0,���ʹ���Ϊ��0
** ��ע��1+8+1+��У���ʽ
*********************************************************************************************************/
uint8_t UARTSendByte( uint8_t PortNum, uint8_t Byte )
{
    if( UART0 == PortNum )
    {
        UDR = Byte;
        while( (UCSRA & BIT(TXC)) == 0  );    //�ȴ��������
        UCSRA |= BIT(TXC);    //�����־λ
    }
    return 0;
}






#pragma interrupt_handler uart0_rx_isr: iv_USART0_RX        //UART0�����жϺ���
void uart0_rx_isr(void)
{
    _NOP();
}







