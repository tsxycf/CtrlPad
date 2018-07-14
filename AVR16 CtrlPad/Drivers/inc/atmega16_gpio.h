/*
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff
 *Describe:
 */

#ifndef __atmega16_gpio_h
#define __atmega16_gpio_h

#include "stdint.h"
#include <macros.h>


#define PORT_A  0x00
#define PORT_B  0x01
#define PORT_C  0x02
#define PORT_D  0x03
#define PORT_E  0x04
#define PORT_F  0x05
#define PORT_G  0x06


#define PORT_DIR_OUT    0x01
#define PORT_DIR_IN     0x00

#define PORT_SET    0x01
#define PORT_CLR    0x00

#endif
