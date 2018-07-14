/*
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff
 *Describe: 打开相关宏定义才可以使用相应外设
 */

#ifndef __atmega16_config_h
#define __atmega16_config_h

#include "stdint.h"


//#define TIMER_MODULE_ENABLED
#define UART_MODULE_ENABLED
//#define GPIO_MODULE_ENABLED
//#define ADC_MODULE_ENABLED



#ifdef TIMER_MODULE_ENABLED
 #include "atmega16_timer.h"
#endif /* TIMER_MODULE_ENABLED */

#ifdef UART_MODULE_ENABLED
 #include "atmega16_uart.h"
#endif /* UART_MODULE_ENABLED */

#ifdef GPIO_MODULE_ENABLED
 #include "atmega16_gpio.h"
#endif /* GPIO_MODULE_ENABLED */

#ifdef ADC_MODULE_ENABLED
 #include "atmega16_adc.h"
#endif /* ADC_MODULE_ENABLED */

#endif



