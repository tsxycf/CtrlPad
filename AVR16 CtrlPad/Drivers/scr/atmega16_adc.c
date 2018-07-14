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
** Descriptions:  全局变量定义
** input parameters:
*********************************************************************************************************/
AdcDef hadc;            //创建ADC组实体
uint8_t currentChannel;         //当前通道
uint8_t channelNum[8] = {0};    //通道编号
uint8_t channelCount = 0;       //通道总数
uint8_t invalidFlag = 0;        //中断是否有效标志

/*********************************************************************************************************
** Function name: ADC_Init
** Descriptions:  初始化ADC
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** 备注：
*********************************************************************************************************/
void ADC_Init( )
{
    ADMUX |= (1<<ADLAR);	// 结果左对齐

}


/*********************************************************************************************************
** Function name: ADC_StartCon()
** Descriptions:  启动ADC转换
** input parameters:
** output parameters:
** Returned value:
** 备注：
*********************************************************************************************************/
static void ADC_StartCon( void )
{
    ADCSRA |= (1<<ADSC);
}





/*********************************************************************************************************
** Function name: ADC_MulCon()
** Descriptions:  启动ADC进行多路转换
** input parameters:channel代表转换的路数  BIT(CHx) | BIT(CHy)...
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** 备注：需要整理出两个参数：需要转换化的通道总数，各个通道的索引，
*********************************************************************************************************/
void ADC_MulConv( uint8_t channel )
{
    hadc.newDataFlag = 0x00;        //清空新数据标志
    if( hadc.endFlag == 0 ) //说明上次转换未完成
    {
        invalidFlag = 1;    //标记最近的一次中断无效
    }
    else
    {
        invalidFlag = 0;    //释放为有效
    }
    ADC_secretary( channel );       //解析通道
    if( channelCount > 0 )
    {
        currentChannel = channelNum[0];
        ADMUX |= currentChannel;     //赋值AD转换通道号
        ADC_StartCon();              //启动转换
    }
}




/*********************************************************************************************************
** Function name: ADC_secretary()
** Descriptions:  将ADC的通道参数进行整理
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** 备注：需要维护出两个全局变量参数：需要转换化的通道总数channelCount，各个通道的索引channelNum[]，
*********************************************************************************************************/
void ADC_secretary( uint8_t channel)
{
    uint8_t i = 0,j = 0;
    uint8_t channelMask = 0x01;     //通道掩码
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
** Descriptions:  ADC转换完成中断函数
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** 备注：
*********************************************************************************************************/
#pragma interrupt_handler adc_isr:iv_ADC
void adc_isr(void)
{
    static uint8_t acdCount = 0;    //中断计数
    uint16_t ADResult;      //转换完成的AD值
    if( 0 == invalidFlag )//如果中断有效
    {
        if( hadc.stateFlag == 1)    //代表一次新的转换
        {
            hadc.stateFlag = 0;
            acdCount = 0;
        }
        ADResult = ADCL;            	    //Read 8 low bits first (important)
        ADResult |= (uint16_t)ADCH << 8;    //read 2 high bits and shift into top byte
        hadc.newDataFlag |= BIT(currentChannel);
        hadc.channelData[currentChannel] = ADResult;

        acdCount ++;        //中断次数++
        if( acdCount >= channelCount )
            hadc.endFlag = 1;
        if( 1 != hadc.endFlag )     //如果没转换完成，继续转换
        {
            currentChannel = channelNum[acdCount];
            ADMUX |= currentChannel;     //赋值AD转换通道号
            ADC_StartCon();
        }
    }
}







/*********************************************************************************************************
** Function name: AdcCompleteCallBack()
** Descriptions:  ADC转换完成备用回调函数
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** 备注：
*********************************************************************************************************/
void AdcCompleteCallBack( void )
{

}




