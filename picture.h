/*********************************************************************************

����ͼƬ������ͷ�ļ�
		
******************************************************************/

#ifndef PICTURE_H
#define PICTURE_H

#include"SVGAMODE.h"
#include"outtext.h"
#include"function.h"

/***��½����ͼƬ����***/
void Login_pic(void);

/***��½��������ͼƬ����***/
void Interface_pic(void);

/***ע�����ͼƬ����***/
void Register_pic(void);

/***�����������ͼƬ����***/
void Forget_user_pic(void);

/***��ҽ������ͼƬ����***/
void SelectDoc_pic(void);

/***ҽ����Ϣ�ı���***/
void Doc_backpic(void);

/***����Ա����ͼƬ����***/
void Admin_pic(void);

/***����Ա�����������***/
void Adminpass_pic(void);

/***��ҩ����ͼƬ����***/
void Buymedicine_pic(void);

/***��������***/
void Personal_pic(void);

/***�ѹ�ҩ�����***/
void Bought_pic(void);

/***�޸��������***/	
void Change_pic(void);

/***��ֵ����***/
void Charge_pic(void);

/***�������ǽ���***/
void About_pic(void);

/***��ҩ����ͼƬ***/
void BuyM_pic(Medicine *medicine);

/***�������***/
void Ask_pic(Doctor *doc);

/***�����������***/
void OverAsk_pic(void);

/***��������֢״***/
void erke_pic(void);

/***��������֢״***/
void fuke_pic(void);

/***Ƥ����֢״***/
void skin_pic(void);

/***�ǿ�֢״***/
void bone_pic(void);

/***���Ǻ��֢״***/
void erbihou_pic(void);

/***�����֢״***/
void xinli_pic(void);

/***���ڿ�֢״***/
void neike_pic(void);

/***���ڿ�֢״***/
void waike_pic(void);

/***����Ա�޸��ܱ�����***/
void Changeanswer_pic(void);

/***�޸��ܱ����溯��***/
void Alternum_pic(void);

/***����Աɾ��ҽ������***/
void Deletedoc_bpic(void);

/***ɾ��ҽ������***/
void Deldoc_pic(void);
#endif