#include "head.h"
#include "SVGAmode.H"
#include "outtext.h"
#include "mouse.h"
#include "function.h"
#include "module.h"
#include "module1.h"
#include"module11.h"
#include"module1.h"

void main()
{
      int main_flag=1;
	  int m,numb;
	  int n;		//存储当前用户在文件中的位置
	  User user;
	  Doctor *doctor;
	  SetSVGA64k();
	  
	    while(1)
	    {
	        switch(main_flag)
			{
			    case 1:
				{
				
				    LoginCheck(&user ,&main_flag,&n);             //登录界面函数
				    break;
				}
				case 2:
				{
				    Register(&main_flag);					//用户注册函数
					break;
				}
				case 3:
				{
					FindPassword(&main_flag);				//找回密码
					break;
				}
				case 4:
				{
					Interface(&main_flag); 					//主界面函数
					break;
				}
				case 5:
				{
					Selectdoc(&main_flag);					//找医生函数
					break;
				}
				case 6:
				{
					Admin(&main_flag);						//管理员函数
					break;
				}
				
				case 7:
				{
					Buymedicine(&main_flag,user,n);				//买药界面
					break;
				}
				case 8:
				{
					Personal(&main_flag,&user);					//个人中心
					break;
				}
				case 9:
				{
					BoughtM(&main_flag,&user);					//已购药物
					break;
				}
				case 10:
				{
					Charge(&main_flag,n,&user);						//充值界面
					break;
				}
				case 11:
				{
					Changepass(&main_flag,&user,n);					//修改密码界面
					break;
				}
				case 12:
				{
					Changeanswer(&main_flag);  					//用户密保查看与修改
					break;
				}
				case 13:
				{
					Deletedoc(&main_flag);
					break;
				}
				case 14:
				{
					Shutdown(m,&main_flag,doctor,numb);
					break;
				}
				case 15:
				{
					Invert(&main_flag);
					break;
				}
				case 16:
				{
					AboutUs(&main_flag);					//AboutUs界面功能
					break;
				}
			}
		}
}
	  