/*
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff
 *Describe:
 */

#include "atmega64_timer.h"
#include "stdint.h"
#include <iom64v.h>


static uint8_t ticks;       //在硬件无法完成长时间计时时，作为软件分频器使用

uint16_t Timer1ticks, Timer2ticks, Timer3ticks, Timer4ticks;       //定时器计数

/*********************************************************************************************************
** Function name: Timer_Init
** Descriptions:  初始化定时器Timer
** input parameters:timeport: 定时器号
** input parameters:time_ms: 定时时间，单位ms
** input parameters:
** output parameters:
** Returned value:
** 备注：晶振频率为7.3728Mhz,(0.1356us)
*********************************************************************************************************/
void Timer_Init( uint8_t timeport, uint16_t time_ms)
{
    uint8_t tmp;
    if( TIMER0 == timeport )
    {
        TCCR0 = (1<<CS02) | (1<<CS01) | (1<<CS00) ; //分频配置1024分    7.2khz
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
** Function name: Timer0
** Descriptions:  定时器中断函数
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** 备注：
*********************************************************************************************************/
#pragma interrupt_handler timer0_ovf_isr:iv_TIM0_OVF
void timer0_ovf_isr(void)
{
    Timer0ticks ++;
    Timer0Callback();
}


/*********************************************************************************************************
** Function name: Timer1
** Descriptions:  定时器中断函数
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** 备注：
*********************************************************************************************************/
#pragma interrupt_handler timer1_ovf_isr:iv_TIM1_OVF
void timer1_ovf_isr(void)
{
    Timer1ticks ++;
    Timer1Callback();
}

/*********************************************************************************************************
** Function name: Timer2
** Descriptions:  定时器中断函数
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** 备注：
*********************************************************************************************************/
#pragma interrupt_handler timer2_ovf_isr:iv_TIM2_OVF
void timer2_ovf_isr(void)
{
    Timer2ticks ++;
    Timer2Callback();
}

/*********************************************************************************************************
** Function name: Timer3
** Descriptions:  定时器中断函数
** input parameters:
** input parameters:
** input parameters:
** output parameters:
** Returned value:
** 备注：
*********************************************************************************************************/
#pragma interrupt_handler timer3_ovf_isr:iv_TIM3_OVF
void timer3_ovf_isr(void)
{
    Timer3ticks ++;
    Timer3Callback();
}





/*********************************************************************************************************
** Function name: ClearTimerFlag
** Descriptions:用于清除ticks变量的函数
** input parameters: void
** output parameters: 无
** Returned value:   0
** 备注：
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
** output parameters: 无
** Returned value:   0
** 备注：
*********************************************************************************************************/
void Timer1Callback()
{

}



/*********************************************************************************************************
** Function name: Timer2Callback
** Descriptions:
** input parameters: void
** output parameters: 无
** Returned value:   0
** 备注：
*********************************************************************************************************/
void Timer2Callback()
{

}


/*********************************************************************************************************
** Function name: Timer3Callback
** Descriptions:
** input parameters: void
** output parameters: 无
** Returned value:   0
** 备注：
*********************************************************************************************************/
void Timer3Callback()
{

}


/*********************************************************************************************************
** Function name: Timer4Callback
** Descriptions:
** input parameters: void
** output parameters: 无
** Returned value:   0
** 备注：
*********************************************************************************************************/
void Timer4Callback()
{

}








