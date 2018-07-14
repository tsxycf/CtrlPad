/*
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff
 *Describe:
 */

#include "atmega64_timer.h"
#include "stdint.h"
#include <iom64v.h>


static uint8_t ticks;       //��Ӳ���޷���ɳ�ʱ���ʱʱ����Ϊ�����Ƶ��ʹ��

uint16_t Timer1ticks, Timer2ticks, Timer3ticks, Timer4ticks;       //��ʱ������

/*********************************************************************************************************
** Function name: Timer_Init
** Descriptions:  ��ʼ����ʱ��Timer
** input parameters:timeport: ��ʱ����
** input parameters:time_ms: ��ʱʱ�䣬��λms
** input parameters:
** output parameters:
** Returned value:
** ��ע������Ƶ��Ϊ7.3728Mhz,(0.1356us)
*********************************************************************************************************/
void Timer_Init( uint8_t timeport, uint16_t time_ms)
{
    uint8_t tmp;
    if( TIMER0 == timeport )
    {
        TCCR0 = (1<<CS02) | (1<<CS01) | (1<<CS00) ; //��Ƶ����1024��    7.2khz
        tmp = (uint8_t)(7.2 * time_ms);
        tmp = 0xff - tmp;
        TCNT0 =  tmp;
    }
    else if( TIMER1 == timeport )
    {

    }
    else if( TIMER2 == timeport )
    {

    }
    else if( TIMER3 == timeport )
    {

    }
}




/*********************************************************************************************************
** Function name: Timer1
** Descriptions:  ��ʱ���жϺ���
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** ��ע��
*********************************************************************************************************/
#pragma interrupt_handler timer1_ovf_isr:iv_TIM1_OVF
void timer1_ovf_isr(void)
{
    Timer1ticks ++;
    Timer1Callback();
}

/*********************************************************************************************************
** Function name: Timer2
** Descriptions:  ��ʱ���жϺ���
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** ��ע��
*********************************************************************************************************/
#pragma interrupt_handler timer2_ovf_isr:iv_TIM2_OVF
void timer2_ovf_isr(void)
{
    Timer2ticks ++;
    Timer2Callback();
}

/*********************************************************************************************************
** Function name: Timer3
** Descriptions:  ��ʱ���жϺ���
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** ��ע��
*********************************************************************************************************/
#pragma interrupt_handler timer3_ovf_isr:iv_TIM3_OVF
void timer3_ovf_isr(void)
{
    Timer3ticks ++;
    Timer3Callback();
}





/*********************************************************************************************************
** Function name: ClearTimerFlag
** Descriptions:�������ticks�����ĺ���
** input parameters: void
** output parameters: ��
** Returned value:   0
** ��ע��
*********************************************************************************************************/
static void ClearTimerTicks( uint8_t tmp )
{
    switch( tmp )
    {
        case 1:
            Timer1ticks = 0;    //
            break;
        case 2:
            Timer2ticks = 0;    //
            break;
        case 3:
            Timer3ticks = 0;    //
            break;
        default:
            break;
    }
}



/*********************************************************************************************************
** Function name: Timer1Callback
** Descriptions:
** input parameters: void
** output parameters: ��
** Returned value:   0
** ��ע��
*********************************************************************************************************/
void Timer1Callback()
{

}



/*********************************************************************************************************
** Function name: Timer2Callback
** Descriptions:
** input parameters: void
** output parameters: ��
** Returned value:   0
** ��ע��
*********************************************************************************************************/
void Timer2Callback()
{

}


/*********************************************************************************************************
** Function name: Timer3Callback
** Descriptions:
** input parameters: void
** output parameters: ��
** Returned value:   0
** ��ע��
*********************************************************************************************************/
void Timer3Callback()
{

}


/*********************************************************************************************************
** Function name: Timer4Callback
** Descriptions:
** input parameters: void
** output parameters: ��
** Returned value:   0
** ��ע��
*********************************************************************************************************/
void Timer4Callback()
{

}








