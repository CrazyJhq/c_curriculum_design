/*********************************************************************************
字符屏幕输出函数
******************************************************************/




#ifndef  outtext_h
#define  outtext_h

#include "SVGAmode.h"


void Outtext(int x,int y, char *s, int size, int part, int color);
 
void out_ASC(int x, int y, char *s, int color);

void out_ASCplus(int x, int y, char *s, int color);
#endif