#include <stdio.h>
#include <string.h>
#include "stm32f10x.h"
#include "command.h"

/**************************************************************************
函数功能：串口3接收中断
入口参数：无
返回  值：无
**************************************************************************/


struct usart_buff_t usart_buff;
struct usart_buff_t *CMD=&usart_buff;

void command_proc(unsigned char data)
{	
	CMD->buff[CMD->index] = data;
	CMD->index = (CMD->index+1)%CMDLEN;
} 

void command_init(void)
{
	memset(CMD,0,sizeof(struct usart_buff_t));
}
