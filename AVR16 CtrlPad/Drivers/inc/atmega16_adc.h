/*
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff
 *Describe:
 */

#ifndef __atmega64_adc_h
#define __atmega64_adc_h

#include "stdint.h"
#include <macros.h>

#define CH0 0
#define CH1 1
#define CH2 2
#define CH3 3
#define CH4 4
#define CH5 5
#define CH6 6
#define CH7 7



typedef struct{
    uint8_t stateFlag;          //
    uint8_t newDataFlag;        //����λ�ж������Ƿ�ˢ��
    uint16_t channelData[8];    //ADCת����洢��λ��
    uint8_t endFlag;            //ת��������־
} AdcDef;



#endif
