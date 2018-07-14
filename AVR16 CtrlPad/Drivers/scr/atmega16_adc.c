/*
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff
 *Describe:
 */




#include "atmega64_adc.h"
#include "stdint.h"
#include <iom64v.h>



/*********************************************************************************************************
** Descriptions:  ȫ�ֱ�������
** input parameters:
*********************************************************************************************************/
AdcDef hadc;            //����ADC��ʵ��
uint8_t currentChannel;         //��ǰͨ��
uint8_t channelNum[8] = {0};    //ͨ�����
uint8_t channelCount = 0;       //ͨ������
uint8_t invalidFlag = 0;        //�ж��Ƿ���Ч��־

/*********************************************************************************************************
** Function name: ADC_Init
** Descriptions:  ��ʼ��ADC
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** ��ע��
*********************************************************************************************************/
void ADC_Init( )
{
    ADMUX |= (1<<ADLAR);	// ��������

}


/*********************************************************************************************************
** Function name: ADC_StartCon()
** Descriptions:  ����ADCת��
** input parameters:
** output parameters:
** Returned value:
** ��ע��
*********************************************************************************************************/
static void ADC_StartCon( void )
{
    ADCSRA |= (1<<ADSC);
}





/*********************************************************************************************************
** Function name: ADC_MulCon()
** Descriptions:  ����ADC���ж�·ת��
** input parameters:channel����ת����·��  BIT(CHx) | BIT(CHy)...
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** ��ע����Ҫ�����������������Ҫת������ͨ������������ͨ����������
*********************************************************************************************************/
void ADC_MulConv( uint8_t channel )
{
    hadc.newDataFlag = 0x00;        //��������ݱ�־
    if( hadc.endFlag == 0 ) //˵���ϴ�ת��δ���
    {
        invalidFlag = 1;    //��������һ���ж���Ч
    }
    else
    {
        invalidFlag = 0;    //�ͷ�Ϊ��Ч
    }
    ADC_secretary( channel );       //����ͨ��
    if( channelCount > 0 )
    {
        currentChannel = channelNum[0];
        ADMUX |= currentChannel;     //��ֵADת��ͨ����
        ADC_StartCon();              //����ת��
    }
}




/*********************************************************************************************************
** Function name: ADC_secretary()
** Descriptions:  ��ADC��ͨ��������������
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** ��ע����Ҫά��������ȫ�ֱ�����������Ҫת������ͨ������channelCount������ͨ��������channelNum[]��
*********************************************************************************************************/
void ADC_secretary( uint8_t channel)
{
    uint8_t i = 0,j = 0;
    uint8_t channelMask = 0x01;     //ͨ������
    for( i=0; i<8; i++ )
    {
        channelMask << i;
        if( 0 != (channel & channelMask) )
        {
            channelCount ++;
            channelNum[j] = i;
            j ++;
        }
    }
}



/*********************************************************************************************************
** Function name: adc_isr()
** Descriptions:  ADCת������жϺ���
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** ��ע��
*********************************************************************************************************/
#pragma interrupt_handler adc_isr:iv_ADC
void adc_isr(void)
{
    static uint8_t acdCount = 0;    //�жϼ���
    uint16_t ADResult;      //ת����ɵ�ADֵ
    if( 0 == invalidFlag )//����ж���Ч
    {
        if( hadc.stateFlag == 1)    //����һ���µ�ת��
        {
            hadc.stateFlag = 0;
            acdCount = 0;
        }
        ADResult = ADCL;            	    //Read 8 low bits first (important)
        ADResult |= (uint16_t)ADCH << 8;    //read 2 high bits and shift into top byte
        hadc.newDataFlag |= BIT(currentChannel);
        hadc.channelData[currentChannel] = ADResult;

        acdCount ++;        //�жϴ���++
        if( acdCount >= channelCount )
            hadc.endFlag = 1;
        if( 1 != hadc.endFlag )     //���ûת����ɣ�����ת��
        {
            currentChannel = channelNum[acdCount];
            ADMUX |= currentChannel;     //��ֵADת��ͨ����
            ADC_StartCon();
        }
    }
}







/*********************************************************************************************************
** Function name: AdcCompleteCallBack()
** Descriptions:  ADCת����ɱ��ûص�����
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** ��ע��
*********************************************************************************************************/
void AdcCompleteCallBack( void )
{

}




