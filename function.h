/*******************************************************************

����δ����Ĺ��ܺ�����ͷ�ļ�
	
******************************************************************/

#ifndef FUNCTION_H
#define FUNCTION_H


#include "module.h"

/***���ı���ָ��λ��������̼�����ַ�����Ҫ���ڵ�½������ı����룩***/
void textbox(int x1, int y1, int x2, int y2, int offset, int mode, char *str);

/***�����ַ����ı�������***/
void Charbox(int x, int y ,char *s);


/***����ɫ�߿���***/
void LightBar(int x1, int y1, int x2 ,int y2 ,int color);

/***�ӿ�滭��ɫ�߿���***/
void LightBarWiden(int x1, int y1, int x2 ,int y2 ,int color);

/***�ӿ�滭Բ��ɫ�߿���***/
void LightCirWiden(int x,int y,int r,int color);

#endif
