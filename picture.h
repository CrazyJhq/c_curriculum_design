/*********************************************************************************

界面图片函数的头文件
		
******************************************************************/

#ifndef PICTURE_H
#define PICTURE_H

#include"SVGAMODE.h"
#include"outtext.h"
#include"function.h"

/***登陆界面图片函数***/
void Login_pic(void);

/***登陆后主界面图片函数***/
void Interface_pic(void);

/***注册界面图片函数***/
void Register_pic(void);

/***忘记密码界面图片函数***/
void Forget_user_pic(void);

/***找医生界面图片函数***/
void SelectDoc_pic(void);

/***医生信息的背景***/
void Doc_backpic(void);

/***管理员界面图片函数***/
void Admin_pic(void);

/***管理员密码输入界面***/
void Adminpass_pic(void);

/***购药界面图片函数***/
void Buymedicine_pic(void);

/***个人中心***/
void Personal_pic(void);

/***已购药物界面***/
void Bought_pic(void);

/***修改密码界面***/	
void Change_pic(void);

/***充值界面***/
void Charge_pic(void);

/***关于我们界面***/
void About_pic(void);

/***购药窗口图片***/
void BuyM_pic(Medicine *medicine);

/***问诊界面***/
void Ask_pic(Doctor *doc);

/***结束问诊界面***/
void OverAsk_pic(void);

/***儿科问诊症状***/
void erke_pic(void);

/***妇科问诊症状***/
void fuke_pic(void);

/***皮肤科症状***/
void skin_pic(void);

/***骨科症状***/
void bone_pic(void);

/***耳鼻喉科症状***/
void erbihou_pic(void);

/***心理科症状***/
void xinli_pic(void);

/***普内科症状***/
void neike_pic(void);

/***普内科症状***/
void waike_pic(void);

/***管理员修改密保界面***/
void Changeanswer_pic(void);

/***修改密保界面函数***/
void Alternum_pic(void);

/***管理员删减医生界面***/
void Deletedoc_bpic(void);

/***删减医生界面***/
void Deldoc_pic(void);
#endif