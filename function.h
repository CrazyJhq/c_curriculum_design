/*******************************************************************

部分未归类的功能函数的头文件
	
******************************************************************/

#ifndef FUNCTION_H
#define FUNCTION_H


#include "module.h"

/***在文本框指定位置输出键盘键入的字符（主要用于登陆界面的文本输入）***/
void textbox(int x1, int y1, int x2, int y2, int offset, int mode, char *str);

/***单个字符的文本框的输出***/
void Charbox(int x, int y ,char *s);


/***画亮色边框函数***/
void LightBar(int x1, int y1, int x2 ,int y2 ,int color);

/***加宽版画亮色边框函数***/
void LightBarWiden(int x1, int y1, int x2 ,int y2 ,int color);

/***加宽版画圆亮色边框函数***/
void LightCirWiden(int x,int y,int r,int color);

#endif
