#ifndef __OLED_H
#define __OLED_H

#include "stm32l4xx_hal.h"
#include "stdlib.h"


#define OLED_MODE 0
#define OLED_SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF
#define X_WIDTH 	128
#define Y_WIDTH 	64

/*********	GPIO定义	************/
#define OLED_SDA_Port		GPIOB
#define OLED_SDA_PIN		GPIO_PIN_4

#define OLED_SCL_Port		GPIOA
#define OLED_SCL_PIN		GPIO_PIN_7



//-----------------OLED IIC 端口定义----------------
//HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
#define OLED_SCLK_Clr() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, GPIO_PIN_RESET);//SDA IIC 接口的时钟信号
#define OLED_SCLK_Set() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, GPIO_PIN_SET);

#define OLED_SDIN_Clr() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4, GPIO_PIN_RESET);//SCL IIC 接口的数据信号
#define OLED_SDIN_Set() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4, GPIO_PIN_SET);


#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据


//OLED 接口控制用函数
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);
void OLED_ShowString(uint8_t x,uint8_t y, uint8_t *p,uint8_t Char_Size);
void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
void OLED_DrawLine(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2);
void OLED_DrawCircle(uint8_t x,uint8_t y,uint8_t r);


//OLED 基础函数
void OLED_Init(void);
void OLED_Clear(void);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_SetDir(uint8_t _ucDir);
void OLED_ColorTurn(uint8_t i);
void OLED_DisplayTurn(uint8_t i);
void OLED_Refresh(void);

#endif