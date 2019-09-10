/*******************************************************************

		1.int MouseInit(void)
			鼠标初始化
		2.void MouseRange(int x1, int y1, int x2, int y2)
			设置鼠标移动范围
		3.int MouseStatus(MOUSE *mouse)
			读取鼠标状态，存入指定结构
		4.int MouseBarLeft(int x1, int y1, int x2, int y2)
			判断鼠标左键是否在指定位置按下
		5.void MouseStoreBk(int x, int y)
			存储被鼠标遮挡部分的显存内容
		6.void MousePutBk(int x, int y)
			恢复被鼠标挡住部分的显存
		7.void MouseReset(void)
			鼠标复位
		8.void MouseDraw(MOUSE mouse)
			画鼠标函数
		9.int MouseOn(int x1,int y1,int x2,int y2)
			判断鼠标是否在指定位置上方

******************************************************************/

#ifndef MOUSE_h
#define MOUSE_h

#include "SVGAmode.h"

/*鼠标的结构体*/
typedef struct mouse_
{
	int x;			//鼠标的横坐标
	int y;			//鼠标的纵坐标
	int button;		//鼠标的左键的状态，0表示未按下，1表示按下
} MOUSE;

extern unsigned int MouseInit(void);  //鼠标初始化函数

extern void MouseRange(int x1,int y1, int x2, int y2);	//设置鼠标移动范围

extern int MouseStatus(MOUSE *mouse);	//读取鼠标状态，存入指定结构

extern int MouseBarLeft(int x1, int y1, int x2, int y2);	//判断鼠标左键是否在指定位置按下

extern void MouseStoreBk(int x, int y);	//存储被鼠标遮挡部分的显存内容

extern void MousePutBk(int x, int y);  //恢复被鼠标挡住部分的显存

extern void MouseReset(void);	//鼠标复位

extern void MouseDraw(MOUSE mouse);	//画鼠标函数

extern int MouseOn(int x1,int y1,int x2,int y2);//判断鼠标是否在指定位置上方

extern int MouseCirOn(int x,int y,unsigned int r);//判断鼠标是否在指定圆上方

extern int MouseCirLeft(int x,int y,unsigned int r);//判断鼠标是否在指定圆按下

#endif