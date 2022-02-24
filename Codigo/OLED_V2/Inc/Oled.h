/*
 * Oled.h
 *
 *  Created on: 18 feb. 2022
 *      Author: Lenovo
 */

#ifndef OLED_H_
#define OLED_H_

#include "stm32f4xx.h"
#include "Config.h"
#include <stdlib.h>
#include <string.h>
#include "delay.h"
/**********************************************************************************/
#define I2C_OLED	I2C1
/***********************************************************************************/


/******************************************************************************/

#define PAGE_SIZE    	8
#define XLevelL			0x00
#define XLevelH			0x10
#define YLevel       	0xB0
#define	Brightness	 	0xFF
#define WIDTH 	     	128
#define HEIGHT 	     	64
#define u8				uint8_t
#define u16				uint16_t
#define u32				uint32_t
#define IIC_SLAVE_ADDR 0x78>>1  //IIC slave device address
//-------------COMMAND/DATA-------------------
#define OLED_CMD     0	//COMMAND
#define OLED_DATA    1	//DATA





void OLED_WR_Byte(unsigned dat,unsigned cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Reset(void);
void OLED_Init(void);
void OLED_Set_Pixel(unsigned char x, unsigned char y,unsigned char color);
void OLED_Display(void);
void OLED_Clear(unsigned dat);


#endif /* OLED_H_ */
