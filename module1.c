#include"head.h"
#include"mouse.h"
#include"SVGAMODE.h"
#include"picture.h"
#include"outtext.h"
#include"function.h"
#include"module1.h"
#include"module.h"
#include"module0.h"
#include"module11.h"

void LoginCheck(User *user , int *main_flag,int *n)
{
	FILE *fp;
	
    char username[10];
	char password[10];
	char num[11];
	char password1[10];
	int admin=0,mark=0;
	char *balance;
	int i;
	int j=0;
	User puser;
	char *bb;

	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量
	
	int sign1=0,sign2=0,sign3=0,sign4=0,sign5=0;   //标记参数
	
	Login_pic();
	
	//读取账号密码
	while(1)
	{
	    if (mouse_flag==0)
		{
		MouseReset();
		mouse_flag=1;																	
		}																					
																						
		MouseStatus(&mouse_new);			//获取鼠标状态								
																							
		if(mflag==0)					
		{
			MousePutBk(mouse_old.x,mouse_old.y);	//恢复被鼠标挡住部分的显存										
		}																					
		
		else
		{																					
			mflag=0;																		
		}
		MouseStoreBk(mouse_new.x,mouse_new.y);		//存储图像							
		MouseDraw(mouse_new);						//画鼠标
		mouse_old=mouse_new;						//记录
		delay(50);
		
	    if( (mouse_new.x >=484) && (mouse_new.y>=455)&&(mouse_new.x <= 715) && (mouse_new.y <= 546 ) )	    sign1=1;//在登录按钮范围内
		if( (mouse_new.x >=319) && (mouse_new.y>=615)&&(mouse_new.x <= 515) && (mouse_new.y <= 675 ) )		sign2=1;//在忘记密码范围内
		if( (mouse_new.x >=631) && (mouse_new.y>=615)&&(mouse_new.x <= 827) && (mouse_new.y <= 673 ) )		sign3=1;//在注册按钮范围内
		if( (mouse_new.x >=385) && (mouse_new.y>=227)&&(mouse_new.x <= 884) && (mouse_new.y <= 300 ) )		sign4=1;//在用户名框范围内
		if( (mouse_new.x >=385) && (mouse_new.y>=341)&&(mouse_new.x <= 884) && (mouse_new.y <= 418 ) )		sign5=1;//在密码框框范围内
		//动画效果
		
		if(sign1 == 0)                              //恢复登录按钮框
		{ 
		    LightBarWiden(484,455,715,546,0);
		}
		if(sign1 == 1)                              //强调登录按钮框
		{
		    LightBarWiden(484,455,715,546,26592);
			sign1=0;
		}
		
		if(sign2 == 0)                              //恢复忘记密码框
		{
		    LightBarWiden(319,615,515,675,0);
		}
		if(sign2 == 1)                              //强调忘记密码框
		{
		    LightBarWiden(319,615,515,675,26592);;
			sign2=0;
		}
		
		if(sign3 == 0)                              //恢复注册按钮框
		{
		    LightBarWiden(631,615,827,673,0);
		}
		if(sign3 == 1)                              //强调注册按钮框
		{
		    LightBarWiden(631,615,827,673,26592);
			sign3=0;
		}
		
		if(sign4 == 0)                              //恢复用户名框
		{
		    LightBarWiden(385,227,884,300,0);
		}
		if(sign4 == 1)                              //强调用户名框
		{
		    LightBarWiden(385,227,884,300,26592);
			sign4=0;
		}
		
		if(sign5 == 0)                              //恢复密码框
		{
		    LightBarWiden(385,341,884,418,0);
		}            
		if(sign5==1)                                //强调密码框
		{
		    LightBarWiden(385,341,884,418,26592);
		    sign5=0;
		}
		
		if(MouseOn(0,0,196,70)==1&&admin==0)					//鼠标放到左上角
		{
			admin=1;
			Bar64k(0,0,196,70,2047);
			Outtext(13,9,"管理员",48,50,65504);				//显示管理员
		}
		
		
		if(MouseBarLeft(387,229,882,298)==1)        //在用户名框内点击鼠标
		{
		    MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			
			Bar64k(388,230,881,297,65535);           //恢复用户名输入区
			
			strcpy(username,"");                      //重置用户名字符数组
			
			textbox(387,229,882,298,25,1,username);
			mflag=1;
		}
		
		
		else if(MouseBarLeft(0,0,196,70)==1)   //在管理员内点击鼠标
		{
		
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			mark=Adminpass(main_flag);
			if(mark==1)
			{
				*main_flag=6;
				delay(100);
				break;
			}
			
		}
		if(mark==2)
		{
			break;
		}
		
		else if(MouseBarLeft(387,343,882,416)==1)   //在密码框内点击鼠标
		{
		    MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			
			Bar64k(388,344,881,415,65535);           //恢复密码输入区
			
			strcpy(password,"");                     //重置密码字符数组
			
			textbox(387,343,882,416,25,2,password);
			mflag=1;
		}
				
		else if(MouseBarLeft(486,457,711,542)==1)   //在登录框内点击鼠标
		{
			if((fp=fopen("TXT\\USER\\user.txt","rt"))==NULL)
			{
				Outtext(391,517,"打开指定文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
				Outtext(391,540,"按任意键退出",24,27,0x0000);
			
			while(bioskey(1))
			{
				getch();
			}
	
			getch();
			exit(0);
			}
			for(i=0;i<10;i++)
			{
				fscanf(fp,"*%s %s %s %s\n",puser.username,puser.password,puser.num,puser.balance);
				j++;
				if(strcmp(puser.username,username)==0)
				{
					fclose(fp);
					break;
				}
			}
			*n=j;
			strcpy(user->username,puser.username);
			strcpy(user->password,puser.password);
			strcpy(user->num,puser.num);
			strcpy(user->balance,puser.balance);
		    
			if(strcmp(username,puser.username)==0
			   &&strcmp(password,puser.password)==0)
			{
			   *main_flag=4;
			   delay(100);
			   break;
			}

			else if((strcmp(username,puser.username)!=0||strcmp(password,puser.password)!=0)&&strcmp(username,"")!=0);
			{
				if(strcmp(username,"")==0||strcmp(password,"")==0)		//解决不输入用户名和密码就去点登陆按钮
				{
					Outtext(100,450,"信息输入不完整,按任意键继续",24,25,65535);
				
					strcpy(username,"");					//重置用户名字符数组
					strcpy(password,"");				//重置密码字符数组	
				
					while(bioskey(1)==0)
					{
                     
					}
					delay(500);
					Login_pic();
				}
				else
				{
					Outtext(100,450,"密码输入错误，请按任意键继续",24,25,65535);
									
					strcpy(username,"");					//重置用户名字符数组
					strcpy(password,"");				//重置密码字符数组	
	            
					while(bioskey(1)==0)
					{
                     
					}
					delay(500);
					Login_pic();
				}
            }
			
			
		}
		else if(MouseBarLeft(322,618,512,672)==1)  //在忘记密码框内点击鼠标
		{
		    *main_flag=3;
			delay(100);
			break;
		}
		else if(MouseBarLeft(633,617,825,671)==1)  //在注册框内点击鼠标
		{
		    *main_flag=2;
			delay(100);
			break;
		}
		else if(MouseBarLeft(978,0,1024,46)==1)  //在退出按钮内点击鼠标
		{
		    delay(100);
			exit(0);
		}
		
	}
	
	/*fclose(fp);*/
}
		
void FindPassword(int *main_flag)
{
	FILE *fp;
	char username[20];
	char password1[20];
	char password2[20];
	char num[11];
	User *user;
	User *p;
	int num1,i;
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量		
	
	int sign1=0,sign3=0,sign4=0,sign5=0;   //标记参数	
		
	Forget_user_pic();	
	num1=Chaninit(p);
	while(1)
	{
	    if(mouse_flag==0)
		{
		MouseReset();
		mouse_flag=1;																	
		}																					
																						
		MouseStatus(&mouse_new);			//获取鼠标状态								
																							
		if(mflag==0)					
		{
			MousePutBk(mouse_old.x,mouse_old.y);	//恢复被鼠标挡住部分的显存										
		}																					
		
		else
		{																					
			mflag=0;																		
		}
		MouseStoreBk(mouse_new.x,mouse_new.y);		//存储图像							
		MouseDraw(mouse_new);						//画鼠标
		mouse_old=mouse_new;						//记录
		delay(50);
		
		 if( (mouse_new.x >=440) && (mouse_new.y>=183)&&(mouse_new.x <= 710) && (mouse_new.y <= 226 ) )	    sign1=1;//在用户名输入范围内
		 //if( (mouse_new.x >=440) && (mouse_new.y>=269)&&(mouse_new.x <= 710) && (mouse_new.y <= 312 ) )	    sign2=1;//在密保问题输入范围内
		 if( (mouse_new.x >=440) && (mouse_new.y>=355)&&(mouse_new.x <= 710) && (mouse_new.y <= 398 ) )	    sign3=1;//在密保答案输入范围内
		 if( (mouse_new.x >=440) && (mouse_new.y>=441)&&(mouse_new.x <= 710) && (mouse_new.y <= 484 ) )	    sign4=1;//在新密码输入范围内
		 if( (mouse_new.x >=440) && (mouse_new.y>=527)&&(mouse_new.x <= 710) && (mouse_new.y <= 570 ) )	    sign5=1;//在确定密码输入范围内
	     	
	     
		if(sign1 == 0)                              //恢复用户名输入框
		{ 
		    LightBarWiden(440,183,710,226,0);
		}
		if(sign1 == 1)                              //强调用户名输入框
		{
		    LightBarWiden(440,183,710,226,26592);
			sign1=0;
		}
		/*
		if(sign2 == 0)                              //恢复密保问题输入框
		{ 
		    LightBarWiden(440,269,710,312,0);
		}
		if(sign2 == 1)                              //强调密保问题输入框
		{
		    LightBarWiden(440,269,710,312,26592);
			sign2=0;
		}
		*/
		if(sign3 == 0)                              //恢复密保答案输入框
		{ 
		    LightBarWiden(440,355,710,398,0);
		}
		if(sign3 == 1)                              //强调密保答案输入框
		{
		    LightBarWiden(440,355,710,398,26592);
			sign3=0;
		}
		
		if(sign4 == 0)                              //恢复新密码输入框
		{ 
		    LightBarWiden(440,441,710,484,0);
		}
		if(sign4 == 1)                              //强调新密码输入框
		{
		    LightBarWiden(440,441,710,484,26592);
			sign4=0;
		}
		
		if(sign5 == 0)                              //恢复登录按钮框
		{ 
		    LightBarWiden(440,527,710,570,0);
		}
		if(sign5 == 1)                              //强调登录按钮框
		{
		    LightBarWiden(440,527,710,570,26592);
			sign5=0;
		}
		
		
		if(MouseBarLeft(442,185,708,224)==1)        //在用户名输入框内点击鼠标
		{
		    MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			
			Bar64k(443,186,707,223,65535);           //恢复用户名输入区
			
			strcpy(username,"");                      //重置用户名字符数组
			
			textbox(442,185,708,223,25,1,username);
			mflag=1;
		}
		
		/*else if(MouseBarLeft(442,271,708,310)==1)        //在密保问题输入框内点击鼠标
		{
		    MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			
			Bar64k(443,272,707,309,65535);           //恢复密保问题输入区
			
			strcpy(MBquestion,"");                   //重置密保问题字符数组
			
			textbox(442,,882,298,25,1,MBquestion);
			mflag=1;
		}
		*/
		else if(MouseBarLeft(442,357,708,396)==1)        //在密保答案输入框内点击鼠标
		{
		    MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			
			Bar64k(443,358,707,395,65535);           //恢复密保答案输入区
			
			strcpy(num,"");                     //重置密保问题字符数组
			
			textbox(442,357,708,396,25,1,num);
			mflag=1;
			
			if((strcmp(username,user->username)==0)              //判断信息匹配
			   &&(strcmp(num,user->num)==0))
			{
				Outtext(640,610,"请输入新密码",24,25,65535);
			}
			else
		    {
				Outtext(640,610,"请输入正确信息",24,25,65535);
			}
		}
		
		else if(MouseBarLeft(442,443,708,482)==1)        //在新密码输入框内点击鼠标
		{
		    MousePutBk(mouse_old.x,mouse_old.y);          //恢复鼠标
			
			Bar64k(443,444,707,481,65535);                //恢复新密码输入区
			 
			strcpy(password1,"");                         //重置新密码字符数组
			
			textbox(442,443,708,482,25,1,password1);
			mflag=1;
		}
		
		else if (MouseBarLeft(442,529,708,568)==1)        //在确定密码输入框内点击鼠标
		{
			MousePutBk(mouse_old.x,mouse_old.y);          //恢复鼠标
			 
			Bar64k(443,530,707,567,65503);                      //恢复确定密码输入区
			
			strcpy(password2,"");                         //重置确定密码字符数组
			
			textbox(442,529,708,568,25,1,password2);
			mflag=1;
		}
		
		else if(MouseBarLeft(424,661,602,718)==1)        //在找回密码框内点击鼠标
		{
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;		
			
			if(strcmp(password1,password2)==0)            //两次输入密码一致
			{
				if((fp=fopen("TXT\\USER\\user.txt","w+"))==NULL)
				{
					Outtext(391,517,"打开指定文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
					Outtext(391,540,"按任意键退出",24,27,0x0000);
			
					while(bioskey(1))
					{
						getch();
					}
				
					getch();
					exit(0);
				}
				for(i=0;i<num1;i++)
				{
					if(strcmp((p+i)->username,username)==0&&strcmp((p+i)->num,num)==0)
					{
						strcpy((p+i)->password,password1);
						fprintf(fp,"*%s %s %s %s\n",(p+i)->username,(p+i)->password,(p+i)->num,(p+i)->balance);
					}
					else
					{
						fprintf(fp,"*%s %s %s %s\n",(p+i)->username,(p+i)->password,(p+i)->num,(p+i)->balance);
					}
				}
				fclose(fp);
				Outtext(718,700,"修改成功",32,35,63488);
				delay(1000);
				*main_flag=1;
				break;
			}
			else
			{
				Outtext(640,610,"前后密码不一致，请重新输入",25,1,65535);
				strcpy(password1,"");
				strcpy(password2,"");
			}
		}
		else if(MouseBarLeft(978,0,1024,46)==1)  //在退出按钮内点击鼠标
		{
		    delay(100);
			*main_flag=1;
			break;
		}
	}
}

/***主界面功能函数***/
void Interface(int *main_flag)
{
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;    	//鼠标操作过程参数变量
	int xflag=0;

	char dep[8][20]={"儿科",
	               "妇科",
				   "皮肤科",
				   "普外科",
				   "骨科",
				   "耳鼻喉科",
				   "心理咨询师",
				   "普内科"};
	Interface_pic();
	delay(100);
		
	while(*main_flag==4)
	{

		xflag=0;
		while(1)
		{
			if (mouse_flag==0)																	
			{																					
				MouseReset();																	//标
				mouse_flag=1;																	
			}																					
																							//的
			MouseStatus(&mouse_new);		//获取鼠标状态										
																							
			if(mflag==0)					//通过鼠标操作过程参数来控制鼠标的背景的贴图次数	//一
			{
				MousePutBk(mouse_old.x,mouse_old.y);											
			}																					//套
		
			else
			{																					
				mflag=0;																		//操
			}
			MouseStoreBk(mouse_new.x,mouse_new.y);		//存储图像										
			MouseDraw(mouse_new);						//画鼠标								//作
			mouse_old=mouse_new;						//记录
			delay(50);
			if(MouseBarLeft(978,0,1024,46)==1)      //鼠标点击退出按钮
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				*main_flag=1;
				break;
			}
			else if(MouseBarLeft(265,696,512,767)==1)	//点击找医生
			{
				while(MouseBarLeft(265,696,512,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
				
				*main_flag=5;
				break;
			}
		
			else if(MouseBarLeft(512,696,768,767)==1)	//点击购药		
			{
				while(MouseBarLeft(512,696,768,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				*main_flag=7;
				break;
			}
			else if(MouseBarLeft(768,696,1023,767)==1)	//点击个人中心		
			{
				while(MouseBarLeft(768,696,1023,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
				
				*main_flag=8;
				break;
			}
			else if(MouseBarLeft(0,160,256,260)==1)    //点击儿科
			{
				while(MouseBarLeft(0,160,256,260)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				Clicksub(dep[0],main_flag);
				break;
			}
			else if(MouseBarLeft(256,160,512,260)==1)    //点击妇科
			{
				while(MouseBarLeft(256,160,512,260)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				Clicksub(dep[1],main_flag);
				break;
			}
			else if(MouseBarLeft(512,160,768,260)==1)    //点击皮肤科
			{
				while(MouseBarLeft(512,160,768,260)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				Clicksub(dep[2],main_flag);
				break;
			}
			else if(MouseBarLeft(768,160,1023,260)==1)    //点击外科
			{
				while(MouseBarLeft(768,160,1023,260)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				Clicksub(dep[3],main_flag);
				break;
			}
			else if(MouseBarLeft(0,260,256,360)==1)    //点击骨科
			{
				while(MouseBarLeft(0,260,256,360)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				Clicksub(dep[4],main_flag);
				break;
			}
			else if(MouseBarLeft(256,260,512,360)==1)    //点击耳鼻喉科
			{
				while(MouseBarLeft(256,260,512,360)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				Clicksub(dep[5],main_flag);
				break;
			}
			else if(MouseBarLeft(512,260,768,360)==1)    //点击心理科
			{
				while(MouseBarLeft(512,260,768,360)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				Clicksub(dep[6],main_flag);
				break;
			}
			else if(MouseBarLeft(768,260,1023,360)==1)    //点击内科
			{
				while(MouseBarLeft(768,260,1023,360)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				Clicksub(dep[7],main_flag);

				break;
			}
			
			if(MouseCirOn(43,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"治疗感冒类药物：午时茶、正柴胡饮、小柴",24,27,0);
				Outtext(256,187,"胡冲剂、圣济感冒灵、三九感冒灵等可任备",24,27,0);
				Outtext(256,214,"2种。百服宁、扑热息痛、阿司匹林、去痛",24,27,0);
				Outtext(256,241,"片等可任备一种。同时应备有体温表。",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(129,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"治疗疼痛类药物：头痛可各用正天丸、复方",24,27,0);
				Outtext(256,187,"羊角胶囊、颅痛定；心绞痛可备用速效救心",24,27,0);
				Outtext(256,214,"消心痛、胃痛可备用654－2片、唯安林",24,27,0);
				Outtext(256,241,"腹痛可备用附子理中丸、藿香正气胶囊等；",24,27,0);
				Outtext(256,268,"腰痛可备用壮骨庆节丸，关节痛可备用芬必",24,27,0);
				Outtext(256,297,"得、扶他林等。",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(215,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"抗生素类药物：应常备氟哌酸、乙酰螺旋霉",24,27,0);
				Outtext(256,187,"素、黄连素、来滴灵、头孢子拉啶、西力欣",24,27,0);
				Outtext(256,214,"片、氟嗪酸等。",24,27,0);
				xflag=1;
				}
			}
		    else if(MouseCirOn(301,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"助睡眠药物：应备有案定片、硝基安定、颅",24,27,0);
				Outtext(256,187,"痛定、非百草安神片、柏子养心丸等。",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(386,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"抗过敏药物：应备有扑尔敏、克敏能、消风",24,27,0);
				Outtext(256,187,"冲剂等。",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(470,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"治疗胃肠病类药物：应备有藿香正气水",24,27,0);
				Outtext(256,187,"人丹、胃复安、黄连素、纯正气丸、易蒙停",24,27,0);
				Outtext(256,214,"、思密达等。",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(554,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"治疗便秘药物：可备黄连清丸、麻仁丸、果",24,27,0);
				Outtext(256,187,"导片等。",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(638,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"助消化药物：可备复方B族生素液、吗丁啉",24,27,0);
				Outtext(256,187,"、多酶片等。",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(723,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"解暑药：可备风油精、清凉油、人丹等。",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(809,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"外用止痛药：可备伤湿止痛膏、止痛喷雾剂。",24,27,0);
				Outtext(256,187,"、扶他林软膏、南星止痛膏、麝香止痛膏、",24,27,0);
				Outtext(256,214,"红花油等。",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(895,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"外用消炎解毒药：如创可贴、碘酒、红药水",24,27,0);
				Outtext(256,187,"、紫药水、高锰酸钾、75％酒精以及消毒",24,27,0);
				Outtext(256,214,"药棉和纱布、剪刀、镊子等。",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(981,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"其它：如季德胜蛇药片、晕海宁、烫伤药水",24,27,0);
				Outtext(256,187,"等。",24,27,0);
				xflag=1;
				}
			}
			else
			{
				if(xflag==1)
				{
					Bar64k(256,160,768,360,26592);
					Outtext(335,184,"妇科",48,50,0);
					Outtext(564,184,"皮肤科",48,50,0);
					Outtext(283,283,"耳鼻喉科",48,50,0);
					Outtext(564,283,"心理科",48,50,0);
					LightBarWiden(256,160,512,260,0);
					LightBarWiden(512,160,768,260,0);
					LightBarWiden(256,260,512,360,0);
					LightBarWiden(512,260,768,360,0);
					delay(100);
					xflag=0;
				}
			}
			
			
			
		}
	}
	
	
}

/***主界面点击科室功能函数***/
void Clicksub(char *dept,int *main_flag)
{
	int i,j=0;
	int k=1;
	Doctor doc[N];	//医生结构数组
	Doctor doct[N];
	Doctor *p=doct;			//
	int page=1,lastpage;		//页数标记函数
	int num = Docinti(doc);		//医生信息初始化
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量
			
	for(i=0;i<num;i++)
	{
		if(strcmp((doc+i)->department,dept)==0)
		{
			stpcpy((doct+j)->department,(doc+i)->department);
			stpcpy((doct+j)->name,(doc+i)->name);
			stpcpy((doct+j)->skill,(doc+i)->skill);
			(doct+j)->years=(doc+i)->years;
			j++;
		}
		
	}
	
	if(j%6==0)
	{
		lastpage=j/6;
	}
	else
	{
		lastpage=j/6+1;
	}
	
	SelectDoc_pic();
	delay(100);

	
	while(k==1)
	{		
		Docinfo1_pic(p,num,page,lastpage);
		Outtext(0,200,"从医年数:",24,25,0);
		while(1)
		{
			if(mouse_flag==0)
			{
			MouseReset();
			mouse_flag=1;																	
			}																					
																						
			MouseStatus(&mouse_new);			//获取鼠标状态								
																							
			if(mflag==0)					
			{
				MousePutBk(mouse_old.x,mouse_old.y);	//恢复被鼠标挡住部分的显存										
			}																					
		
			else
			{																					
				mflag=0;																		
			}
			MouseStoreBk(mouse_new.x,mouse_new.y);		//存储图像							
			MouseDraw(mouse_new);						//画鼠标
			mouse_old=mouse_new;						//记录
			delay(50);																					
			
			//动画效果
			if(MouseCirOn(470,174,36)==0)				//第一个问诊图标
			{
				LightCirWiden(470,174,36,0);
			}
			else
			{
				LightCirWiden(470,174,36,2016);
			}
			
			if(MouseCirOn(987,174,36)==0)				//第二个问诊图标
			{
				LightCirWiden(987,174,36,0);
			}
			else
			{
				LightCirWiden(987,174,36,2016);
			}
			
			if(MouseCirOn(470,367,36)==0)				//第三个问诊图标
			{
				LightCirWiden(470,367,36,0);
			}
			else
			{
				LightCirWiden(470,367,36,2016);
			}
			
			if(MouseCirOn(987,367,36)==0)				//第四个问诊图标
			{
				LightCirWiden(987,367,36,0);
			}
			else
			{
				LightCirWiden(987,367,36,2016);
			}
			
			if(MouseCirOn(470,556,36)==0)				//第五个问诊图标
			{
				LightCirWiden(470,556,36,0);
			}
			else
			{
				LightCirWiden(470,556,36,2016);
			}
			
			if(MouseCirOn(987,556,36)==0)				//第六个问诊图标
			{
				LightCirWiden(987,556,36,0);
			}
			else
			{
				LightCirWiden(987,556,36,2016);
			}
			
			
			
			if(MouseBarLeft(978,0,1024,46)==1)      //鼠标点击退出按钮
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
			
				*main_flag=1;
				k=0;
				break;
			}
			else if(MouseBarLeft(0,696,265,767)==1)	//点击首页
			{
				while(MouseBarLeft(0,696,265,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
			
				*main_flag=4;
				k=0;
				Interface_pic();
				break;
			}
			
			else if(MouseBarLeft(512,696,768,767)==1)	//点击购药		
			{
				while(MouseBarLeft(512,696,768,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				*main_flag=7;
				k=0;
				break;
			}
			else if(MouseBarLeft(768,696,1023,767)==1)	//点击个人中心		
			{
				while(MouseBarLeft(768,696,1023,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
			
				*main_flag=8;
				k=0;
				break;
			}
			else if((MouseBarLeft(942,659,1002,679)==1 || MouseBarLeft(1002,648,1023,690)==1) && page<lastpage)				//点击下一页
			{
				while(MouseBarLeft(942,659,1002,679)==1|| MouseBarLeft(1002,670,1023,690)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				p=p+6;
				page++;
				break;
			}
			else if((MouseBarLeft(942,659,1002,679)==1 || MouseBarLeft(1002,648,1023,690)==1) && page==lastpage)	
			{
				while(MouseBarLeft(942,659,1002,679)==1 || MouseBarLeft(1002,670,1023,690)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				Outtext(136,659,"已经是最后一页了，不能继续往下翻了",32,35,63503);
				delay(1500);
				Bar64k(136,655,900,696,2463);			//恢复原来的背景
				break;
			}
			else if((MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1 )&& page>1)		//点击上一页
			{
				while(MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				p=p-6;
				page--;
				break;
			}
			else if((MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1 )&& page==1)
			{
				while(MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				Outtext(136,659,"已经是第一页了，不能继续往上翻了",32,35,63503);
				delay(1500);
				Bar64k(136,655,900,696,2463);			//恢复原来的背景
				break;
			}
			
			else if(MouseCirLeft(470,174,36)==1&&num>0)		//点击该页第一个医生
			{
				while(MouseCirLeft(470,174,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				AskDoc(doct);
				break;
			}
			else if(MouseCirLeft(987,174,36)==1&&num>1)		//点击该页第二个医生
			{
				while(MouseCirLeft(987,174,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				AskDoc(doct+1);
				break;								
			}
			else if(MouseCirLeft(470,367,36)==1&&num>2)		//点击该页第三个医生
			{
				while(MouseCirLeft(470,367,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				AskDoc(doct+2);
				break;						
			}
			/*else if(MouseCirLeft(987,367,36)==1&&num>3)		//点击该页第四个医生
			{
				while(MouseCirLeft(987,367,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				AskDoc(doct+3);
				break;						
			}
			else if(MouseCirLeft(470,556,36)==1&&num>4)		//点击该页第五个医生
			{
				while(MouseCirLeft(470,556,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				AskDoc(doct+4);
				break;						
			}
			else if(MouseCirLeft(987,556,36)==1&&num>5)		//点击该页第六个医生
			{
				while(MouseCirLeft(987,556,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				AskDoc(doct+5);
				break;						
			}	*/	
		}
			
	}		 
}

	/***医生信息输出函数***/
void Docinfo1_pic(Doctor *doc,int num,int page,int lastpage)
{
	char s[64];	//便于换行输出
	int i;  		//计算本页共有几个医生
	int j=0;
	char *year="\0";
	if(page<lastpage)		//如果不是最后一页
	{
		i=6;
	}
	else if(page==lastpage)		//如果是最后一页
	{
		if(num%6==0)
		{
			i=6;
		}
		else
		{
			i=num%6;
		}
	}
	Doc_backpic();					//医生信息背景

	if(j<i)
	{
		s[0]='\0';
		Outtext(0,96,doc->name,32,35,0);
		Outtext(150,96,doc->department,24,25,0);
		substr(s,doc->skill,0,32);
		Outtext(0,150,s,16,18,0);
		substr(s,doc->skill,32,64);
		Outtext(0,170,s,16,18,0);
		Outtext(0,200,"从医年数:",24,25,0);
		itoa((doc->years),year,10);
		out_ASC(120,205,year,0);
		
		j++;
	}
	if(j<i)
	{
		s[0]='\0';
		Outtext(517,96,(doc+1)->name,32,35,0);
		Outtext(667,96,(doc+1)->department,24,25,0);
		substr(s,(doc+1)->skill,0,32);
		Outtext(517,150,s,16,18,0);
		substr(s,(doc+1)->skill,32,64);
		Outtext(517,170,s,16,18,0);
		Outtext(517,200,"从医年数:",24,25,0);
		itoa((doc+1)->years,year,10);
		out_ASC(637,205,year,0);
		
		j++;
	}
	if(j<i)
	{
		s[0]='\0';
		Outtext(0,285,(doc+2)->name,32,35,0);
		Outtext(150,285,(doc+2)->department,24,25,0);
		substr(s,(doc+2)->skill,0,32);
		Outtext(0,339,s,16,18,0);
		substr(s,(doc+2)->skill,32,64);
		Outtext(0,359,s,16,18,0);
		Outtext(0,389,"从医年数:",24,25,0);
		itoa((doc+2)->years,year,10);
		out_ASC(120,394,year,0);
		
		j++;
	}
	/*if(j<i)
	{
		s[0]='\0';
		Outtext(517,286,(doc+3)->name,32,35,0);
		Outtext(667,286,(doc+3)->department,24,25,0);
		substr(s,(doc+3)->skill,0,32);
		Outtext(517,339,s,16,18,0);
		substr(s,(doc+3)->skill,32,64);
		Outtext(517,359,s,16,18,0);
		Outtext(517,389,"从医年数:",24,25,0);
		itoa((doc+3)->years,year,10);
		out_ASC(637,394,year,0);
		
		j++;
	}
	if(j<i)
	{
		s[0]='\0';
		Outtext(0,474,(doc+4)->name,32,35,0);
		Outtext(150,474,(doc+4)->department,24,25,0);
		substr(s,(doc+4)->skill,0,32);
		Outtext(0,518,s,16,18,0);
		substr(s,(doc+4)->skill,32,64);
		Outtext(0,538,s,16,18,0);
		Outtext(0,568,"从医年数:",24,25,0);
		itoa((doc+4)->years,year,10);
		out_ASC(120,573,year,0);
		
		j++;
	}
	if(j<i)
	{
		s[0]='\0';
		Outtext(517,474,(doc+5)->name,32,35,0);
		Outtext(667,474,(doc+5)->department,24,25,0);
		substr(s,(doc+5)->skill,0,32);
		Outtext(517,518,s,16,18,0);
		substr(s,(doc+5)->skill,32,64);
		Outtext(517,538,s,16,18,0);
		Outtext(517,568,"从医年数:",24,25,0);
		itoa((doc+5)->years,year,10);
		out_ASC(637,573,year,0);
		
		j++;
	}*/

}



/***药品信息读取函数***/
int Medinti(Medicine *medicine)
{
	char ch;
	Medicine *med=medicine;
	FILE *fp;
	
	int i,num=0;
	
	if((fp=fopen("TXT\\MEDICINE\\medicine.txt","r"))==NULL)
	{
		Outtext(391,517,"打开药品文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出",24,27,0x0000);
		
		while(bioskey(1))
		{
			getch();
		}
		
		getch();
		exit(0);
	}
	
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if(ch=='*')
		{
			num++;
		}
		
	}
	rewind(fp);
	for(i=0; i<num; i++)
	{
		fscanf(fp,"* %s %s %s\n",((med+i))->name,((med+i))->price,((med+i))->function);
	}
	
	fclose(fp);
	return(num);
}


/***购药界面功能函数***/
void Buymedicine(int *main_flag,User user,int n)
{
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;          //鼠标重置参数变量
	int mflag=1;               //鼠标操作过程参数变量
	int *amount;
	
	Medicine med[N];	
	Medicine *p=med;
	int page=1,lastpage;
	int num = Medinti(med);
	
	
	//计算总页数
	if(num%12==0)
	{
		lastpage=num/12;
	}
	else
	{
		lastpage=num/12+1;
	}
	
	/*Buymedicine_pic(p);
	delay(100);
	
	Medinfo_pic(p);*/
	
	while(*main_flag==7)
	{   
        Medinfo_pic(p,num,page,lastpage);

		while(1)
		{
																							
			if(mouse_flag==0)
			{
			MouseReset();
			mouse_flag=1;																	
			}																					
																						
			MouseStatus(&mouse_new);			//获取鼠标状态								
																							
			if(mflag==0)					
			{
				MousePutBk(mouse_old.x,mouse_old.y);	//恢复被鼠标挡住部分的显存										
			}																					
		
			else
			{																					
				mflag=0;																		
			}
			MouseStoreBk(mouse_new.x,mouse_new.y);		//存储图像							
			MouseDraw(mouse_new);						//画鼠标
			mouse_old=mouse_new;						//记录
			delay(50);																					
		
		//动画效果
			if(MouseOn(186,233,255,272)==1)             //第一个购买框
			{
				LightBarWiden(186,233,255,272,57344);
			}
			else
			{
				LightBarWiden(186,233,255,272,0);
			}
		
			if(MouseOn(442,233,511,272)==1)             //第二个购买框
			{
				LightBarWiden(442,233,511,272,57344);
			}
			else
			{
				LightBarWiden(442,233,511,272,0);
			}
		
			if(MouseOn(698,233,767,272)==1)             //第三个购买框
			{
				LightBarWiden(698,233,767,272,57344);
			}
			else
			{
				LightBarWiden(698,233,767,272,0);
			}
		
			if(MouseOn(954,233,1023,272)==1)             //第四个购买框
			{
				LightBarWiden(954,233,1023,272,57344);
			}
			else
			{
				LightBarWiden(954,233,1023,272,0);
			}
		
			if(MouseOn(186,422,255,461)==1)             //第五个购买框
			{
				LightBarWiden(186,422,255,461,57344);
			}
			else
			{
				LightBarWiden(186,422,255,461,0);
			}
		
			if(MouseOn(442,422,511,461)==1)             //第六个购买框
			{
				LightBarWiden(442,422,511,461,57344);
			}
			else
			{
				LightBarWiden(442,422,511,461,0);
			}
		
			if(MouseOn(698,422,767,461)==1)             //第七个购买框
			{
				LightBarWiden(698,422,767,461,57344);
			}
			else
			{
				LightBarWiden(698,422,767,461,0);
			}
		
			if(MouseOn(954,422,1023,461)==1)             //第八个购买框
			{
				LightBarWiden(954,422,1023,461,57344);
			}
			else
			{
				LightBarWiden(954,422,1023,461,0);
			}
		
			if(MouseOn(186,611,255,650)==1)             //第九个购买框
			{
				LightBarWiden(186,611,255,650,57344);
			}
			else
			{
				LightBarWiden(186,611,255,650,0);
			}
		
			if(MouseOn(442,611,511,650)==1)             //第十个购买框
			{
				LightBarWiden(442,611,511,650,57344);
			}
			else
			{
				LightBarWiden(442,611,511,650,0);
			}
		
			if(MouseOn(698,611,767,650)==1)             //第十一个购买框
			{
				LightBarWiden(698,611,767,650,57344);
			}
			else
			{
				LightBarWiden(698,611,767,650,0);
			}
		
			if(MouseOn(954,611,1023,650)==1)             //第十二个购买框
			{
				LightBarWiden(954,611,1023,650,57344);
			}
			else
			{
				LightBarWiden(954,611,1023,650,0);
			}
			
			if(MouseOn(186,194,255,233)==1)             //第一个详情框
			{
				LightBarWiden(186,194,255,233,57344);
			}
			else
			{
				LightBarWiden(186,194,255,233,0);
			}
		
			if(MouseOn(442,194,511,233)==1)             //第二个详情框
			{
				LightBarWiden(442,194,511,233,57344);
			}
			else
			{
				LightBarWiden(442,194,511,233,0);
			}
		
			if(MouseOn(698,194,767,233)==1)             //第三个详情框
			{
				LightBarWiden(698,194,767,233,57344);
			}
			else
			{
				LightBarWiden(698,194,767,233,0);
			}
		
			if(MouseOn(954,194,1023,233)==1)             //第四个详情框
			{
				LightBarWiden(954,194,1023,233,57344);
			}
			else
			{
				LightBarWiden(954,194,1023,233,0);
			}
		
			if(MouseOn(186,383,255,422)==1)             //第五个详情框
			{
				LightBarWiden(186,383,255,422,57344);
			}
			else
			{
				LightBarWiden(186,383,255,422,0);
			}
		
			if(MouseOn(442,383,511,422)==1)             //第六个详情框
			{
				LightBarWiden(442,383,511,422,57344);
			}
			else
			{
				LightBarWiden(442,383,511,422,0);
			}
		
			if(MouseOn(698,383,767,422)==1)             //第七个详情框
			{
				LightBarWiden(698,383,767,422,57344);
			}
			else
			{
				LightBarWiden(698,383,767,422,0);
			}
		
			if(MouseOn(954,383,1023,422)==1)             //第八个详情框
			{
				LightBarWiden(954,383,1023,422,57344);
			}
			else
			{
				LightBarWiden(954,383,1023,422,0);
			}
		
			if(MouseOn(186,572,255,611)==1)             //第九个详情框
			{
				LightBarWiden(186,572,255,611,57344);
			}
			else
			{
				LightBarWiden(186,572,255,611,0);
			}
		
			if(MouseOn(442,572,511,611)==1)             //第十个详情框
			{
				LightBarWiden(442,572,511,611,57344);
			}
			else
			{
				LightBarWiden(442,572,511,611,0);
			}
		
			if(MouseOn(698,572,767,611)==1)             //第十一个详情框
			{
				LightBarWiden(698,572,767,611,57344);
			}
			else
			{
				LightBarWiden(698,572,767,611,0);
			}
		
			if(MouseOn(954,572,1023,611)==1)             //第十二个详情框
			{
				LightBarWiden(954,572,1023,611,57344);
			}
			else
			{
				LightBarWiden(954,572,1023,611,0);
			}
		
		
			if(MouseBarLeft(978,0,1024,46)==1)      //鼠标点击退出按钮
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
			
				*main_flag=1;
				break;
			}
			else if(MouseBarLeft(314,715,592,767)==1)	//点击找医生
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
			
				*main_flag=5;
				break;
			}
		
			else if(MouseBarLeft(0,696,265,767)==1)    //点击首页
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
			
				*main_flag=4;
				break;
			}
		
		
			else if(MouseBarLeft(768,696,1023,767)==1)   //点击个人中心
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
			
				*main_flag=8;
				break;
			}
		
			else if((MouseBarLeft(942,659,1002,679)==1 || MouseBarLeft(1002,648,1023,690)==1) && page<lastpage)				//点击下一页
			{
				while(MouseBarLeft(942,659,1002,679)==1|| MouseBarLeft(1002,670,1023,690)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				p=p+12;
				page++;
				break;
			}
			else if((MouseBarLeft(942,659,1002,679)==1 || MouseBarLeft(1002,648,1023,690)==1) && page==lastpage)	
			{
				while(MouseBarLeft(942,659,1002,679)==1 || MouseBarLeft(1002,670,1023,690)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				Outtext(136,659,"已经是最后一页了，不能继续往下翻了",32,35,63503);
				delay(1500);
				Bar64k(136,655,900,710,2463);			//恢复原来的背景
				break;
			}
			else if((MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1 )&& page>1)		//点击上一页
			{
				while(MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				p=p-12;
				page--;
				break;
			}
			
			else if((MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1 )&& page==1)
			{
				while(MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				Outtext(136,659,"已经是第一页了，不能继续往上翻了",32,35,63503);
				delay(1500);
				Bar64k(136,655,900,710,2463);			//恢复原来的背景
				break;
			}
			
			else if(MouseBarLeft(186,233,255,272)==1)  //点击购买框1
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p,&user,n);
				break;
			}
			else if(MouseBarLeft(442,233,511,272)==1)  //点击购买框2
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+1,&user,n);
				break;
			}
			else if(MouseBarLeft(698,233,767,272)==1)  //点击购买框3
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+2,&user,n);
				break;
			}
			else if(MouseBarLeft(954,233,1023,272)==1)  //点击购买框4
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+3,&user,n);
				break;
			}
			else if(MouseBarLeft(186,422,255,461)==1)  //点击购买框5
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+4,&user,n);
				break;
			}
			else if(MouseBarLeft(442,422,511,461)==1)  //点击购买框6
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+5,&user,n);
				break;
			}
			else if(MouseBarLeft(698,422,767,461)==1)  //点击购买框7
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+6,&user,n);
				break;
			}
			else if(MouseBarLeft(954,422,1023,461)==1)  //点击购买框8
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+7,&user,n);
				break;
			}
			else if(MouseBarLeft(186,611,255,650)==1)  //点击购买框9
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+8,&user,n);
				break;
			}else if(MouseBarLeft(442,611,511,650)==1)  //点击购买框10
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+9,&user,n);
				break;
			}else if(MouseBarLeft(698,611,767,650)==1)  //点击购买框11
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+10,&user,n);
				break;
			}
			else if(MouseBarLeft(954,611,1023,650)==1)  //点击购买框12
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				BuyM(p+11,&user,n);
				break;
			}
			else if(MouseBarLeft(186,194,255,233)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p);
				break;
			}
			else if(MouseBarLeft(442,194,511,233)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+1);
				break;
			}
			else if(MouseBarLeft(698,194,767,233)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+2);
				break;
			}			
			else if(MouseBarLeft(954,194,1023,233)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+3);
				break;
			}	
			else if(MouseBarLeft(186,383,255,422)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+4);
				break;
			}				
			else if(MouseBarLeft(442,383,511,422)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+5);
				break;
			}				
			else if(MouseBarLeft(698,383,767,422)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+6);
				break;
			}
			else if(MouseBarLeft(954,383,1023,422)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+7);
				break;
			}
			else if(MouseBarLeft(186,572,255,611)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+8);
				break;
			}			
			else if(MouseBarLeft(442,572,511,611)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+9);
				break;
			}	
			else if(MouseBarLeft(698,572,767,611)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+10);
				break;
			}				
			else if(MouseBarLeft(954,572,1023,611)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				Details_pic(p+11);
				break;
			}					
		}
	}
}

/***药物详情输出函数***/
void Details_pic(Medicine *medicine)
{
	char s[64];	//便于换行输出
	int i=0;
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量	
		
	Bar64k(146,180,878,554,9284);	//背景
	LightBarWiden(144,178,880,556,65465);
	
	Bar64k(827,180,878,231,57344);
	Line64k(827,180,878,231,64518);
	Line64k(827,231,878,180,64518);		//退出
	
	Outtext(161,205,"药名：",48,50,63503);
	Outtext(161,275,"单价：",48,50,63503);
	Outtext(161,345,"简介：",48,50,63503);

	Bar64k(296,210,792,252,26620);		//药名
	Bar64k(296,279,792,321,65504);		//单价
	/*Bar64k(296,348,792,495,26620);		//总价*/
	
	Outtext(296,210,medicine->name,32,35,0);
	Outtext(296,279,medicine->price,32,35,0);	
	/*substr(s,medicine->function,0,30);
	Outtext(296,348,s,32,35,0);
	substr(s,medicine->function,30,30);
	Outtext(296,384,s,32,35,0);
	substr(s,medicine->function,60,30);
	Outtext(296,420,s,32,35,0);
	substr(s,medicine->function,90,30);
	Outtext(296,456,s,32,35,0);*/
	for(i=0;i<3;i++)
	{
		if(strstr(s,"#")==NULL)
		{
			substr(s,medicine->function,i*30,30);
			Outtext(296,348+i*36,s,32,35,0);	
		}
		else
		{
			break;
		}
	}

	while(1)
	{
	    if(mouse_flag==0)
		{
		MouseReset();
		mouse_flag=1;																	
		}																					
																						
		MouseStatus(&mouse_new);			//获取鼠标状态								
																							
		if(mflag==0)					
		{
			MousePutBk(mouse_old.x,mouse_old.y);	//恢复被鼠标挡住部分的显存										
		}																					
		
		else
		{																					
			mflag=0;																		
		}
		MouseStoreBk(mouse_new.x,mouse_new.y);		//存储图像							
		MouseDraw(mouse_new);						//画鼠标
		mouse_old=mouse_new;						//记录
		delay(50);
		if(MouseBarLeft(827,180,878,231)==1)			//退出按钮
		{
			while(MouseBarLeft(827,180,878,231)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			mflag=1;
			
			break;
		}
	}
}	
	
/***药物信息输出函数***/
void Medinfo_pic(Medicine *med,int num,int page,int lastpage)
{
	int i;
	int j=0;
	if(page<lastpage)
	{
		i=12;
	}
	else if(page==lastpage)
	{
		if(num%12==0)
		{
			i=12;
		}
		else
		{
			i=num%12;
		}
	}
	
	Buymedicine_pic();      //购药背景图
	
	//药物名字输出  	药物价格输出
	if(j<i)
	{
		Outtext(11,89,med->name,16,18,0);
		out_ASC(201,89,med->price,0);
		j++;
	}
	if(j<i)
	{
		Outtext(257,89,(med+1)->name,16,18,0);
		out_ASC(457,89,(med+1)->price,0);
		j++;
	}
	if(j<i)
	{
		Outtext(513,89,(med+2)->name,16,18,0);
		out_ASC(713,89,(med+2)->price,0);
		j++;
	}
	if(j<i)
	{
		Outtext(769,89,(med+3)->name,16,18,0);
		out_ASC(969,89,(med+3)->price,0);
		j++;
	}
	if(j<i)
	{
		Outtext(1,274,(med+4)->name,16,18,0);
		out_ASC(201,274,(med+4)->price,0);
		j++;
	}
	if(j<i)
	{	
		Outtext(257,274,(med+5)->name,16,18,0);
		out_ASC(457,274,(med+5)->price,0);
		j++;
	}
	if(j<i)
	{
		Outtext(513,274,(med+6)->name,16,18,0);
		out_ASC(713,274,(med+6)->price,0);
		j++;
	}
	if(j<i)
	{
		Outtext(769,274,(med+7)->name,16,18,0);
		out_ASC(969,274,(med+7)->price,0);
		j++;
	}
	if(j<i)
	{
		Outtext(1,463,(med+8)->name,16,18,0);
		out_ASC(201,463,(med+8)->price,0);
		j++;
	}
	if(j<i)
	{
		Outtext(257,463,(med+9)->name,16,18,0);
		out_ASC(457,463,(med+9)->price,0);
		j++;
	}
	if(j<i)
	{
		Outtext(513,463,(med+10)->name,16,18,0);
		out_ASC(713,463,(med+10)->price,0);
		j++;
	}
	if(j<i)
	{
		Outtext(769,463,(med+11)->name,16,18,0);
		out_ASC(969,463,(med+11)->price,0);
		j++;
	}
	
}

