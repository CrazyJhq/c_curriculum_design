/**********************************************************
Copyright (C) 2017 潘孝枫 金豆  多层车库管理系统
File name:		SVGAmode.c
Author:			姜君&潘孝枫
Version：		3.1
Date：			2017/9/3
Description：	SVGA显示模式实现文件，包括该模式下基本的初始化函数、操作函数、画图函数、读图函数等的实现。
				宏处理在SVGAmode.h中。
				
				因为宏定义的缘故，严禁在其他文件中定义名称为R、G、B、r、g、b的变量！
				为了与graphics.h中的函数区别，所有自写函数名首字母大写！
				所有自写函数均以屏幕参考系为准！
				
				Putbmp16函数采用其他同学代码，函数Line、Circle、Circlefill为资料代码，不计入工作量！
				
				对本文件的修改请及时按如下格式记录在下面（每个修改单独列出）！

Function List：
	1.void SetSVGA256(void);
		SVGA显示模式设置函数，设为0x105
		
	2.void SetSVGA64k(void);
		SVGA显示模式设置函数，设为0x117
	
	3.unsigned int GetSVGA(void);
		获取SVGA显示模式号bx
		
	4.void Selectpage(register char page);
		带判断功能的换页函数，解决读写显存时跨段寻址问题
		
		
	6.void Putpixel64k(int x, int y, unsigned int color);
		画点函数，其他画图函数的基础，仅适用于0x117模式！
		

	
	9.void Xorpixel(int x, int y, unsigned char color);
		按位异或画点函数
		
	10.void Horizline(int x, int y, int width, unsigned char color);
		画水平线函数
		
	12.void Line64k(int x1, int y1, int x2, int y2, unsigned int color)；
		64k模式画一般直线函数
		
	14.void Bar64k(int x1, int y1, int x2, int y2, unsigned int color);
		64k模式画矩形块函数
		
	16.void Circle64k(int xc, int yc, int radius, unsigned int color);
		64k模式画圆圈函数
		
	18.void Circlefill64k(int xc, int yc, int radius, unsigned int color);
		64k模式画实心圆函数
	
	19.unsigned int Getpixel64k(int x, int y);
		取点颜色函数，仅适用于0x117模式！
		
**********************************************************/

#ifndef	SVGA_H
#define	SVGA_H

#include"head.h"

/*画图函数调色板颜色结构*/
typedef struct
{
	unsigned char R;	/*红色分量，RED缩写*/
	unsigned char G;	/*绿色分量，GREEN缩写*/
	unsigned char B;	/*蓝色分量，BLUE缩写*/
} COLORS;

/*24位bmp图颜色结构*/
typedef struct
{
	unsigned char B;	/*蓝色分量，BLUE缩写*/
	unsigned char G;	/*绿色分量，GREEN缩写*/
	unsigned char R;	/*红色分量，RED缩写*/
} COLORS24;

/*bmp位图颜色表颜色结构*/
typedef struct tagRGBQUAD
{
    unsigned char b;	/*蓝色分量，RED缩写*/
	unsigned char g;	/*绿色分量，GREEN缩写*/
	unsigned char r;	/*红色分量，BLUE缩写*/
	unsigned char reserved;		/*保留字*/
} RGBQUAD;

/*bmp位图信息头数据用于说明位图的尺寸等信息*/



extern void SetSVGA256(void);


extern void SetSVGA64k(void);

extern unsigned int GetSVGA(void);

extern void Selectpage(register char page);

extern void Putpixel64k(int x, int y, unsigned int color);


extern void Xorpixel(int x, int y, unsigned char color);

extern void Horizline(int x, int y, int width, unsigned char color);

extern void Line64k(int x1, int y1, int x2, int y2, unsigned int color);

extern void Bar64k(int x1, int y1, int x2, int y2, unsigned int color);

extern void Circle64k(int xc, int yc, int radius, unsigned int color);

extern void Circlefill64k(int xc, int yc, int radius, unsigned int color);

extern unsigned int Getpixel64k(int x, int y);

extern void Capsule(int x,int y,int size);				//画胶囊函数

extern void Doctordraw(int x,int y,int size);				//画医生函数

extern void Medicinebot(int x,int y,int size);            //画药瓶函数

extern void Ask_ico(int x, int y);						//问诊按钮

extern void Pageup(int x,int y,unsigned int color);						//上一页按钮

extern void Pagedown(int x,int y,unsigned int color);						//下一页按钮

#endif