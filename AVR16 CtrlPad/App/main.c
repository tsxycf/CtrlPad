/*
*MCU:   ATMEGA64
时钟频率 7.3728Mhz
*/

#include <macros.h>
#include <iom16v.h>
#include "atmega16_config.h"

uint8_t ReadGpioFlag = 0;		//读取GPIO的标志位
uint8_t FreshPanelStateFlag = 0;		//刷新面板的状态
uint8_t LockFlag = 0;			//状态保护锁
uint8_t StateUpdata = 0;		//状态更新标志


CtrlPadClass CtrlPad1; 


int main(void)
{
    uint8_t tmp = 0xaa;
    UARTInit( UART0, _7_3728Mhz19200, ENABLE );
	Timer_Init( TIMER0, 5);

    while(1)
    {
        if( 1 == FreshPanelStateFlag )
        {
			FreshPanelStateFlag = 0;
			if( 1 == StateUpdata )
			{
				StateUpdata = 0;
				PackData();
				SendData();
			}
        }
    }
    return 1;
}



Timer0Callback()		//定时器0中断
{
	ReadGpioFlag = 1;
	if( 1 == Timer0ticks )
	{
		FreshPanelStateFlag = 1;
	}
	if( 2 <= Timer0ticks )
	{
		Timer0ticks = 0;
	}
}





void PackData()
{
	CtrlPad1.OptMod = NORMAL;	//正常模式
	CtrlPad1.SubSys_ARM1.ID = ;
	CtrlPad1.SubSys_ARM1.direction = ;
	CtrlPad1.SubSys_ARM1.speed = ;
	CtrlPad1.SubSys_ARM1.brake = ;

	
}









