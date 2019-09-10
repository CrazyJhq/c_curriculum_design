#ifndef MODULE11_H
#define MODULE11_H

//管理员界面
void Admin(int *main_flag);

//管理员查看与修改密保函数
void Changeanswer(int *main_flag);

//用户信息输出函数
void Chanuser_pic(User *user,int num,int page,int lastpage);

//用户信息初始化函数
int Chaninit(User *user);

//修改密保函数
void Alternum(User *user,int *main_flag,int m,int num);

//删减医生函数
void Deletedoc(int *main_flag);

//管理员界面医生信息输出函数
void Deletedoc_pic(Doctor *doctor,int num,int page,int lastpage);

//管理员医生信息读取函数
int Deldocinti(Doctor *doctor);

//删减医生文件操作函数
void Shutdown(int m,int *main_flag,Doctor *doctor,int numb);

//转换函数
void Invert(int *main_flag);
#endif