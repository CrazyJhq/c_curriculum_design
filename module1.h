#ifndef MODULE1_H
#define MODULE1_H

	
//登录界面函数
void LoginCheck(User *user , int *main_flag,int *n);

//忘记密码函数
void FindPassword(int *main_flag);

//主界面功能函数
void Interface(int *main_flag);

//药物信息读取函数
int Medinti(Medicine *medicine);

//购药界面功能函数
void Buymedicine(int *main_flag,User user,int n);

//药物信息输出函数
void Medinfo_pic(Medicine *medicine,int num,int page,int lastpage);

//点击对应科室函数
void Clicksub(char *dept,int *main_flag);

//医生信息输出函数
void Docinfo1_pic(Doctor *doc,int num,int page,int lastpage);

//药物详情输出函数
void Details_pic(Medicine *medicine);
#endif