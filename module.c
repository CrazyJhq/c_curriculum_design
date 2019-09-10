#include"head.h"
#include"mouse.h"
#include"SVGAMODE.h"
#include"picture.h"
#include"outtext.h"
#include"function.h"
#include"module.h"
#include"module0.h"
#include"module11.h"
#include"module1.h"


/***注册界面功能函数***/
void Register(int *main_flag)
{
	FILE *fp;
	
	char username[18]="";
	char password[18]="";
	char password1[18]="";
	char num[20]="";
	char balance[12]="1000.0";
	User p[U];			//用户数组
	int n=Userinti(p);	//用户初始化
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;
	int mflag=1;
	
	Register_pic();
	
	if(n>=N)
	{
		Bar64k(380,514,1023,580,2016);
		Outtext(391,517,"用户数量已达到上限，无法注册，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出",24,27,0x0000);
		
		while(bioskey(1))
		{
			getch();
		}
		
		getch();
		exit(1);
	}
	
	if((fp=fopen("TXT\\USER\\user.txt","at+"))==NULL)
	{
		Bar64k(380,514,1023,580,2016);
		Outtext(391,517,"打开指定文件失败，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出",24,27,0x0000);
		
		while(bioskey(1))
		{
			getch();
		}
		
		getch();
		exit(1);
	}
	
	while(1)
	{
		if (mouse_flag==0)																	//鼠
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
		
		//动画效果
		if(MouseOn(356,193,637,228)==1)
		{
			LightBarWiden(353,190,640,231,2016);
		}
		else
		{
			LightBarWiden(353,190,640,231,0);
		}
		if(MouseOn(356,273,637,308)==1)
		{
			LightBarWiden(353,270,640,311,2016);
		}
		else
		{
			LightBarWiden(353,270,640,311,0);
		}
		if(MouseOn(356,353,637,388)==1)
		{
			LightBarWiden(353,350,640,391,2016);
		}
		else
		{
			LightBarWiden(353,350,640,391,0);
		}
		if(MouseOn(356,513,637,548)==1)
		{
			LightBarWiden(353,510,640,551,2016);
		}
		else
		{
			LightBarWiden(353,510,640,551,0);
		}
		if(MouseOn(356,433,637,468)==1)
		{
			LightBarWiden(353,430,640,471,2016);
		}
		else
		{
			LightBarWiden(353,430,640,471,0);
		}
		if(MouseOn(429,607,596,661)==1)
		{
			LightBarWiden(426,604,599,664,63488);
		}
		else
		{
			LightBarWiden(426,604,599,664,0);
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
		else if(MouseBarLeft(356,193,637,228)==1)		//在用户名框内点击鼠标
		{
			MousePutBk(mouse_old.x,mouse_old.y);
			mflag=1;
			
			Bar64k(356,193,637,228,65503);				//清空用户名框内容
			strcpy(username,"");						//清空username内容
			
			textbox(356,193,637,228,2,1,username);
			if((JudgeWord(username)!=1)	||(strlen(username)<3)	||(strlen(username)>6))
			{
				Outtext(650,300,"用户名应为3到6位字",32,35,0);
				Outtext(650,345,"母或数字及其组合",32,35,0);
				delay(1500);
				Bar64k(650,300,1023,380,2463);			//覆盖提示字
				
				Bar64k(356,193,637,228,65503);				//清空用户名框内容
				strcpy(username,"");						//清空username内容
			}
			else if(Check(username,p,n)==1)			//如果用户名被用过
			{
				Outtext(650,300,"用户名已被别人使用",32,35,0);
				Outtext(650,345,"请换个用户名试试",32,35,0);
				delay(1500);
				Bar64k(650,300,1023,380,2463);			//覆盖提示字
				
				Bar64k(356,193,637,228,65503);				//清空用户名框内容
				strcpy(username,"");						//清空username内容
			}
		}
		else if(MouseBarLeft(356,273,637,308)==1)		//在密码输入框内点击鼠标
		{
			MousePutBk(mouse_old.x,mouse_old.y);
			mflag=1;
			
			Bar64k(356,273,637,308,65503);
			strcpy(password,"");
			textbox(356,273,637,308,2,2,password);
			
			if((JudgeWord(password)!=1)	||(strlen(password)<3)	||(strlen(password)>8))
			{
				Outtext(650,300,"密码应为3到8位字",32,35,0);
				Outtext(650,345,"母或数字及其组合",32,35,0);
				delay(1500);
				Bar64k(650,300,1023,380,2463);			//覆盖提示字
				
				Bar64k(356,273,637,308,65503);				//清空密码框内容
				strcpy(password,"");						//清空password内容
			}
		}
		else if(MouseBarLeft(356,353,637,388)==1)		//在确定密码框内点击鼠标
		{
			MousePutBk(mouse_old.x,mouse_old.y);
			mflag=1;
			
			Bar64k(356,353,637,388,65503);
			strcpy(password1,"");
			textbox(356,353,637,388,2,2,password1);
			
			if((JudgeWord(password1)!=1)	||(strlen(password1)<3)	||(strlen(password1)>8))
			{
				Outtext(650,300,"密码应为3到8位字",32,35,0);
				Outtext(650,345,"母或数字及其组合",32,35,0);
				delay(1500);
				Bar64k(650,300,1023,380,2463);			//覆盖提示字
				
				Bar64k(356,353,637,388,65503);				//清空确定密码框内容
				strcpy(password1,"");						//清空password1内容
			}
		}
		else if(MouseBarLeft(356,513,637,548)==1)		//在密保答案输入框内点击鼠标
		{
			MousePutBk(mouse_old.x,mouse_old.y);
			mflag=1;
			
			Bar64k(356,513,637,548,65503);
			strcpy(num,"");
			textbox(356,513,637,548,2,2,num);
		}
		else if(MouseBarLeft(429,607,596,661)==1)				//点击注册后
		{
			if((username!="")&&(password!="")&&(password1!="")&&(num!=""))		//输入信息完整
			{
				if(strcmp(password,password1)!=0)				//前后密码不一致
				{
					Outtext(718,353,"前后密码不一致",32,35,63488);
					delay(1000);
					Bar64k(718,353,1024,389,2463);				//去除刚才输出的提示性文字
				}
				else if(strlen(num)!=11)						//手机号位数不对
				{
					Outtext(718,353,"手机号位数不对",32,35,63488);
					delay(1000);
					Bar64k(718,353,1024,389,2463);	
				}
				else											//输入信息完整且符合要求
				{
					fprintf(fp,"*%s %s %s %s\n",username,password,num,balance);
					Outtext(718,353,"注册成功",48,50,2016);
					*main_flag=1;
					
					break;
					
				}
			}
			else											//输入信息不完整
			{
				Outtext(718,353,"输入信息不完整",32,35,63488);
				delay(1000);
				Bar64k(718,353,1024,389,2463);				//去除刚才输出的提示性文字
			}
		}
		
		
	}
	fclose(fp);		//关闭文件
}

/***用户信息初始化***/
int Userinti(User *user1)
{
	char ch;
	User *user=user1;
	FILE *fp;
	
	int i;			
	int num=0;		//已注册用户数量
	
	if((fp=fopen("TXT\\user\\user.txt","rt"))==NULL)
	{
		Outtext(391,517,"打开用户文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出",24,27,0x0000);
		
		while(bioskey(1))
		{
			getch();
		}
		
		getch();
		exit(1);
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
		fscanf(fp,"* %s %s %s %s\n",((user+i))->username,((user+i))->password,((user+i))->num,((user+i))->balance);
	}
	fclose(fp);
	
	return(num);
}

/***检查用户名是否已经被用过***/

int Check(char* s,User *user,int num)
{
	int i;
	for(i=0; i<num; i++)
	{
		if(strcmp(s,(user+i)->username)==0)
		{
			return 1;
		}
	}
	return 0;
}

/***找医生界面功能函数***/
void Selectdoc(int *main_flag)
{
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量
	
	Doctor doc[N];				//医生结构数组
	Doctor *p=doc;				//
	int page=1,lastpage;		//页数标记函数
	int num = Docinti(p);		//医生信息初始化
	int no = 0;
	
	
	int hour=0;				//小时数
	struct tm *ptr;
	time_t t;			//用于存储时间，定义为time_t型，是long int型的数
	
	int i,rx, ry;		//判断医生是否在线的循环参量
	
	
	//计算总页数
	if(num%6==0)
	{
		lastpage=num/6;
	}
	else
	{
		lastpage = num/6+1;
	}
	
	SelectDoc_pic();
	delay(100);
	
	
	while(*main_flag==5)
	{
		Docinfo_pic(p,num,page,lastpage);
		if(page<lastpage)		//如果不是最后一页
		{
			no=6;
		}
		else if(page==lastpage)		//如果是最后一页
		{
			if(num%6==0&&num!=0)
			{
				no=6;
			}
			else
			{
				no=num%6;
			}
		}
		Outtext(0,200,"从医年数:",24,25,0);
		while(1)
		{
			time(&t);
			ptr = localtime(&t);	//获取本地日历时间指针
			hour = (ptr->tm_hour);	//转化为int
			
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
			if(MouseOn(0,50,120,87)==1)					//降序
			{
				LightBarWiden(0,50,120,87,2016);
			}
			else
			{
				LightBarWiden(0,50,120,87,0);
			}
			if(MouseOn(122,50,242,87)==1)					//升序
			{
				LightBarWiden(122,50,242,87,63488);
			}
			else
			{
				LightBarWiden(122,50,242,87,0);
			}
			
			for(i=0 ; i<6 ; i++)		//判断医生是否在线，并画出图标
			{
				rx=374+((i)%2)*538;
				ry=105+((i)/2)*185;
				if(JudgeDoc((p+i)->t,hour,2)==1)
				{
					Circlefill64k(rx,ry,10,26592);
				}
				else
				{
					Circlefill64k(rx,ry,10,10857);
				}
			}
			
			if(MouseBarLeft(978,0,1024,46)==1)      //鼠标点击退出按钮
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
			
				*main_flag=1;
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
			else if(MouseBarLeft(0,50,120,87)==1)			//点击降序
			{
				while(MouseBarLeft(0,50,120,87)==1)
				{
				}
				mflag=0;
				
				memset(doc,'\0',sizeof(Doctor)*num);
				p=doc;
				Docinti(p);
				sort(p,num,1);
				page=1;
				break;
			}
			else if(MouseBarLeft(122,50,242,87)==1)			//点击升序
			{
				while(MouseBarLeft(122,50,242,87)==1)
				{
				}
				mflag=0;
				
				memset(doc,'\0',sizeof(Doctor)*num);
				p=doc;
				Docinti(p);
				sort(p,num,2);
				page=1;
				break;
			}
			
			
			
			else if(MouseCirLeft(470,174,36)==1&& no>0)		//点击该页第一个医生
			{
				while(MouseCirLeft(470,174,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				if(JudgeDoc((p+0)->t,hour,1)==1)
				{
					AskDoc(p);
					break;
				}
				else
				{
					delay(3000);
					break;
				}

			}
			
			
			
			else if(MouseCirLeft(987,174,36)==1&& no>1)		//点击该页第二个医生
			{
				while(MouseCirLeft(987,174,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				if(JudgeDoc((p+1)->t,hour,1)==1)
				{
					AskDoc(p+1);
					break;
				}
				else
				{
					delay(3000);
					break;
				}
			}
			else if(MouseCirLeft(470,367,36)==1 && no>2)		//点击该页第三个医生
			{
				while(MouseCirLeft(470,367,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				
				if(JudgeDoc((p+2)->t,hour,1)==1)
				{
					AskDoc(p+2);
					break;
				}
				else
				{
					delay(3000);
					break;
				}
			}
			else if(MouseCirLeft(987,367,36)==1&& no>3)		//点击该页第四个医生
			{
				while(MouseCirLeft(987,367,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				
				if(JudgeDoc((p+3)->t,hour,1)==1)
				{
					AskDoc(p+3);
					break;
				}
				else
				{
					delay(3000);
					break;
				}
			}
			else if(MouseCirLeft(470,556,36)==1 && no>4)		//点击该页第五个医生
			{
				while(MouseCirLeft(470,556,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				
				if(JudgeDoc((p+4)->t,hour,1)==1)
				{
					AskDoc(p+4);
					break;
				}
				else
				{
					delay(3000);
					break;
				}
			}
			else if(MouseCirLeft(987,556,36)==1 && no==6)		//点击该页第六个医生
			{
				while(MouseCirLeft(987,556,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				
				if(JudgeDoc((p+5)->t,hour,1)==1)
				{
					AskDoc(p+5);
					break;
				}
				else
				{
					delay(3000);
					break;
				}
			}
			
			
			
		}
			
	}
	free(doc);
	memset(doc,'\0',sizeof(Doctor)*num);
	
}



/***判断医生是否在线***/
int JudgeDoc(int a,int hour,int c)
{
	if(a==1 && hour<8)
	{
		return 1;
	}
	else if(a==2 && hour>=8 && hour <16)
	{
		return 1;
	}
	else if(a==3 && hour>=16)
	{
		return 1;
	}
	else
	{
		switch(c)
		{
			case 1:
			{
				Bar64k(212,202,812,505,2016);
				Outtext(265,224,"该医生此时不在线。",32,35,0);
				Outtext(236,278,"您可以选择去找其他医生问诊",32,35,0);
				Outtext(233,327,"或者等该医生上线，他的值班",32,35,0);
				Outtext(233,374,"时间为：",32,35,0);
				if(a==1)
				{
					Outtext(254,420,"0点到8点",48,50,0);
				}
				else if(a==2)
				{
					Outtext(254,420,"8点到16点",48,50,0);
				}
				else if(a==3)
				{
					Outtext(254,420,"16点到0点",48,50,0);
				}
				return 0;
			}
			case 2:
			{
				return 0;
			}
		}
	}
	return 0;
}


/***医生排序函数***/
void sort(Doctor *doc,int num,int s)
{
	int i,j;
	Doctor tmp;
	switch(s)
	{
		case 1:			//降序
		{
			for(i=0;i<num;i++)
			{
				for(j=i+1;j<num;j++)
				{
					if(((doc+i)->years)<((doc+j)->years))
					{
						tmp=*(doc+i);
						*(doc+i)=*(doc+j);
						*(doc+j)=tmp;
					}
				}
			}
			break;
		}
		case 2:			//升序
		{
			for(i=0;i<num;i++)
			{
				for(j=i+1;j<num;j++)
				{
					if(((doc+i)->years)>((doc+j)->years))
					{
						tmp=*(doc+i);
						*(doc+i)=*(doc+j);
						*(doc+j)=tmp;
					}
				}
			}
			break;
		}
	}
}

/***管理员密码输入***/
int Adminpass(int *main_flag)
{
	FILE *fp;
	
	char password[15];
	char *pass=NULL;
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量	
	
	Adminpass_pic();
	
	
	if((fp=fopen("TXT\\admin.txt","rt"))==NULL)
	{
		Outtext(391,517,"打开指定文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出程序",24,27,0x0000);
		
		while(bioskey(1))
		{
			getch();
		}
		
		getch();
		
		exit(0);
	}
	fscanf(fp,"%s",pass);			//读取管理员密码
	fclose(fp);						//关闭文件
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
		if(MouseBarLeft(308,355,715,431)==1)			//如果点击密码输入框
		{
			MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			
			Bar64k(308,355,715,431,65535);           //恢复用户名输入区
		
			strcpy(password,"");		
			
			textbox(308,355,715,431,25,1,password);
			mflag=1;
			if( strcmp(pass,"20181701") != 0 )
			{
				Outtext(315,481,"密码输入错误，请重新输入",32,34,57344);
				
				strcpy(password,"");		//重置密码
				
				while(bioskey(1)==0)
                {
                     
                }
				
				Adminpass_pic();
			}
			else if(strcmp(pass,password) == 0 )
			{
				
				delay(100);
				return 1;
				
			}
		}
		else if(MouseBarLeft(761,162,807,208)==1)
		{
			while(MouseBarLeft(761,162,807,208)==1)
			{
			}
			mflag=1;
			*main_flag=1;
			return 2;
		}
		else if(MouseBarLeft(978,0,1024,46)==1)  //在退出按钮内点击鼠标
		{
		    delay(100);
			exit(0);
		}
		
	}
}


/***医生信息读取函数***/
int Docinti(Doctor *doctor)
{
	char ch;
	Doctor *doc=doctor;
	FILE *fp;
	
	int i;			
	int num=0;		//医生数量
	
	if((fp=fopen("TXT\\DOCTORS\\doctors.txt","rt"))==NULL)
	{
		Outtext(391,517,"打开医生文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出",24,27,0x0000);
		
		while(bioskey(1))
		{
			getch();
		}
		
		getch();
		exit(1);
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
		fscanf(fp,"* %d %s %s %s # %d\n",&((doc+i))->t,((doc+i))->name,((doc+i))->department,((doc+i))->skill,&((doc+i))->years);
	}
	fclose(fp);
	
	return(num);
}


/***
字符串分割
***/

char* substr(char dst[],char src[],int start,int len)
{
	char* p = src + start;   //定义指针变量指向需要提取的字符的地址
	int n = strlen(p);       //求字符串长度
	int i = 0;
		if(n < len)
		{
			len = n;
		}
		while(len != 0)
		{
			dst[i] = src[i+start];
			len --;
			i++;
		}                        //复制字符串到dst中
		dst[i] = '\0';
	return dst;
}

/***医生信息输出函数***/

void Docinfo_pic(Doctor *doc,int num,int page,int lastpage)
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
		if(num%6==0&&num!=0)
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
	if(j<i)
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
	}
}

/***个人中心功能函数***/

void Personal(int *main_flag,User *user)
{
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量
	char *ch;
	
	
	Personal_pic();
	delay(100);
	
	Outtext(420,208,user->username,48,50,0);
	while(1)
	{
		if (mouse_flag==0)																	//鼠
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
		
		//动画效果
		if(MouseOn(0,409,256,501)==1)		//已购药物
		{
			LightBarWiden(0,406,258,503,63488);
		}
		else
		{
			LightBarWiden(0,406,258,503,0);
		}
		if(MouseOn(258,409,514,501)==1)		//用户余额
		{
			LightBarWiden(256,406,516,503,2016);
		}
		else
		{
			LightBarWiden(256,406,516,503,0);
		}
		if(MouseOn(516,409,772,501)==1)		//用户充值
		{
			LightBarWiden(514,406,775,503,63488);
		}
		else
		{
			LightBarWiden(514,406,775,503,0);
		}
		if(MouseOn(774,409,1023,501)==1)		//修改密码
		{
			LightBarWiden(772,406,1024,503,2016);
		}
		else
		{
			LightBarWiden(772,406,1024,503,0);
		}
		if(MouseCirOn(143,232,100)==1)
		{
			LightCirWiden(143,232,100,63488);
		}
		else
		{
			LightCirWiden(143,232,100,0);
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
		else if(MouseBarLeft(0,696,265,767)==1)	//点击首页
		{
			while(MouseBarLeft(0,696,265,767)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;	
		
			*main_flag=4;
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
		else if(MouseBarLeft(0,409,256,501)==1)		//点击已购药物
		{
			while(MouseBarLeft(0,409,256,501)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			*main_flag=9;
			break;
		}
		else if(MouseBarLeft(258,409,514,501)==1)	//点击用户余额
		{
			while(MouseBarLeft(258,409,514,501)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Balance();
			Outtext(500,430,user->balance,48,50,0);
			
			while(bioskey(1))
			{
				getch();
			}
		
			getch();
			
			Bar64k(0,365,1023,628,2463);
			Bar64k(0,409,256,501,26592);
			Outtext(27,430,"已购药物",48,50,0);
			Bar64k(258,409,514,501,34847);
			Outtext(294,429,"用户余额",48,50,0);
			Bar64k(516,409,772,501,53216);
			Outtext(553,429,"用户充值",48,50,0);
			Bar64k(774,409,1023,501,57344);
			Outtext(808,428,"修改密码",48,50,0);
	
			Outtext(441,517,"版本号:1.0",24,26,0);
	
			Bar64k(335,569,695,625,2016);
			Outtext(370,580,"ABOUT    US",24,26,0);
		}
		else if(MouseBarLeft(516,409,772,501)==1)	//点击用户充值
		{
			while(MouseBarLeft(516,409,772,501)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			*main_flag=10;							//进入充值界面
			break;
		}
		else if(MouseBarLeft(774,409,1023,501)==1)	//点击修改密码
		{
			while(MouseBarLeft(774,409,1023,501)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			*main_flag=11;							//进入修改密码界面
			break;
		}
		else if(MouseBarLeft(335,569,695,625)==1)	//点击ABOUT US
		{
			while(MouseBarLeft(335,569,695,625)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			*main_flag=16;
			break;
		}
		
	}
}


/***已购药物界面功能函数***/
void BoughtM(int *main_flag,User *user)
{
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量
	
	int page=1,lastpage,num;
	Bought *p;
	num=Bouinti(p,user);
	
	
	//计算总页数
	if(num%6==0&&num!=0)
	{
		lastpage=num/7;
	}
	else if(num==0)
	{
		lastpage=1;
	}
	else
	{
		lastpage = num/7+1;
	}
	
	
	Bought_pic();
	delay(100);
	
	while(*main_flag==9)
	{
		MedBou_pic(p,page,lastpage,num);
		while(1)
		{
			if (mouse_flag==0)																	//鼠
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
				
				*main_flag=8;						//返回个人中心界面
				break;
			}
			else if((MouseBarLeft(942,730,1002,750)==1 || MouseBarLeft(1002,719,1023,761)==1) && page<lastpage)				//点击下一页
			{
				while(MouseBarLeft(942,730,1002,750)==1|| MouseBarLeft(1002,719,1023,761)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				p=p+7;
				page++;
				break;
			}
			else if((MouseBarLeft(942,730,1002,750)==1 || MouseBarLeft(1002,719,1023,761)==1) && page==lastpage)	
			{
				while(MouseBarLeft(942,730,1002,750)==1 || MouseBarLeft(1002,719,1023,761)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				Outtext(236,730,"已经是最后一页了，不能继续往下翻了",32,35,63503);
				delay(1500);
				Bar64k(236,730,900,765,2463);			//恢复原来的背景
				break;
			}
			else if((MouseBarLeft(21,730,81,750)==1 || MouseBarLeft(0,719,21,680)==1 )&& page>1)		//点击上一页
			{
				while(MouseBarLeft(21,730,81,750)==1 || MouseBarLeft(0,719,21,680)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				p=p-7;
				page--;
				break;
			}
			else if((MouseBarLeft(21,730,81,750)==1 || MouseBarLeft(0,719,21,761)==1 )&& page==1)
			{
				while(MouseBarLeft(21,730,81,750)==1 || MouseBarLeft(0,719,21,761)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				Outtext(236,730,"已经是第一页了，不能继续往上翻了",32,35,63503);
				delay(1500);
				Bar64k(236,730,900,765,2463);			//恢复原来的背景
				break;
			}
		}
	}
}
	

/***已购药物信息框***/
void MedBou_pic(Bought *bought,int page,int lastpage,int num)
{
	int i,j;
	
	for(i=0; i<8; i++)
	{
		Bar64k(0,101+72*i,1023,161+72*i,2016);
	}
	Bar64k(494,101,506,664,57638);
	Bar64k(775,101,787,664,32784);
	
	if(page<lastpage)		//如果不是最后一页
	{
		j=7;
	}
	else if(page==lastpage)		//如果是最后一页
	{
		if(num%7==0&&num!=0)
		{
			j=7;
		}
		else
		{
			j=num%7;
		}
	}
	
	Outtext(163,107,"药品名",48,50,0);
	Outtext(590,107,"数量",48,50,0);
	Outtext(858,107,"费用",48,50,0);
	
	for(i=0; i<j; i++)
	{
		Outtext(20,183+72*i,(bought+i)->name,32,35,0);
		Outtext(610,183+72*i,(bought+i)->num,32,35,0);
		Outtext(782,183+72*i,(bought+i)->fee,32,35,0);
	}
}

/***已购药物信息初始化***/
int Bouinti(Bought *bought,User *user)
{
	FILE *fp;
	char ch;
	Bought *bou=bought;
	Bought b;		//暂时存放别人的购药信息
	char name[8];
	
	
	int i;			
	int num=0;		//已购药物数量
	
	if((fp=fopen("TXT\\user\\buy.txt","rt"))==NULL)
	{
		Bar64k(390,510,1023,580,2016);
		Outtext(391,517,"打开已购药物文件失败，无法进行后续操作",24,27,0);
		Outtext(391,540,"按任意键退出",24,27,0);
		
		while(bioskey(1))
		{
			getch();
		}
		
		getch();
		exit(1);
	}
	
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if(ch=='*')
		{
			num++;
		}
		
	}
	
	num/=2;
	
	rewind(fp);
	for(i=0; i<num; i++)
	{
		fscanf(fp,"*%s\n",name);
		if(strcmp(user->username,name)==0)
		{
			fscanf(fp,"* %s %s %s\n",((bou+i))->name,((bou+i))->num,((bou+i))->fee);
		}
		else
		{
			fscanf(fp,"* %s %s %s\n",b.name,b.num,b.fee);
		}
	}
	fclose(fp);
	return(num);
}


/***余额显示窗口***/
void Balance(void)
{
	Bar64k(138,365,894,628,65504);
	LightBarWiden(138,365,894,628,0);
	Outtext(173,433,"当前余额：",48,50,0);
	Bar64k(494,429,833,506,2016);
	Outtext(359,564,"按任意键关闭该窗口",24,26,34847);
	
}
	

/***充值功能函数***/
void Charge(int *main_flag,int n,User *user)
{
	FILE *fp1,*fp;
	char c;
	
	char username[10];
	char password[10];
	char num[15];
	char balance[12];
	long bal;
	char s[10]="";
	unsigned int size=12;
	double m;		//充值金额
	int i;			//文件指针移动参数
	long j1,j2,j;			//文件指针偏移量
	
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量	
	
	Charge_pic();
	
	
	
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
		if(MouseBarLeft(457,181,777,246)==1)			//如果点击输入框
		{
			MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			mflag=1;
			
			Bar64k(457,181,777,246,65535);           //恢复输入区
		
			strcpy(s,"");		
			
			textbox(457,181,777,246,25,1,s);
		}
		else if(MouseBarLeft(543,262,691,335)==1)	//点击充值
		{
			while(MouseBarLeft(543,262,691,335)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			mflag=1;
			
			
			if(s=="")
			{
				Outtext(200,273,"请输入充值金额",32,35,0);
				delay(1000);
				Bar64k(200,273,530,310,2016);		//去除刚才的提示
			}
			else if(s!="")
			{
				if(JudgeNum(s)==0)
				{
					Outtext(200,273,"输入错误",32,35,0);
					delay(1000);
					Bar64k(200,273,530,310,2016);		//去除刚才的提示
				}
				else if(JudgeNum(s)==1)
				{
					if((fp1=fopen("TXT\\USER\\user.txt","rt+"))==NULL)
					{
						Outtext(391,517,"打开指定文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
						Outtext(391,540,"按任意键退出程序",24,27,0x0000);
						
						while(bioskey(1))
						{
							getch();
						}
						
						getch();
						
						exit(1);
					}
					
					//将指针移动到相应用户位置
					for(i=1; i<n; i++)
					{
						fscanf(fp1,"*%s %s %s %s\n",username,password,num,balance);
					}
					j1=ftell(fp1);
					fscanf(fp1,"*%s %s %s %s\n",username,password,num,balance);
					j2=ftell(fp1);
					j=j2-j1;
					//删除该行用户信息
					if((fp=fopen("TXT\\USER\\tem.txt","w"))==NULL)
					{
						Outtext(391,517,"创建临时文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
						Outtext(391,540,"按任意键退出程序",24,27,0x0000);
				
						while(bioskey(1))
						{
							getch();
						}
			
						getch();
			
						exit(1);
					}
					rewind(fp1);
					for(i=1;i<=j1;i++)
					{
						c=fgetc(fp1);
						fputc(c,fp);
					}
					fseek(fp1,j,1);
					for(i=j2;	!feof(fp1)	;i++)
					{
						c=fgetc(fp1);
						fputc(c,fp);
					}
					fseek(fp,j1,0);
					//改变余额
					m=atof(s);
					bal=atof(balance);
					bal+=m;
					fprintf(fp,"*%s %s %s %s\n",username,password,num,gcvt(bal,size,balance));
					strcpy(user->balance,gcvt(bal,size,balance));
					Outtext(200,273,"充值成功",32,35,0);
					Bar64k(457,181,777,246,65535);           //恢复输入区
					strcpy(s,"");		
					
					delay(1000);
					Bar64k(200,273,530,310,2016);		//去除刚才的提示
					fclose(fp);
					fclose(fp1);
					remove("TXT\\USER\\user.txt");
					rename("TXT\\USER\\tem.txt","TXT\\USER\\user.txt");
				}
			}
			
				
		}
		else if(MouseBarLeft(812,130,866,186)==1)			//点击关闭
		{
			while(MouseBarLeft(812,130,866,186)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			mflag=1;
			
			*main_flag=8;			//回到个人中心
			fclose(fp1);
			break;
		}
	}
}
	
/***修改密码功能函数***/
void Changepass(int *main_flag,User *user,int n)
{
	FILE *fp,*fp1;
	char c;
	
	char username[10]="";		//用户名
	char password[10]="";		//密码
	char password0[10]="";		//输入的原密码
	char password1[10]="";		//输入的新密码
	char password2[10]="";		//再次输入的新密码
	char num[15]="";
	char balance[12]="";
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;
	int mflag=1;
	int i;
	
	int j1,j2,j;
	
	Change_pic();
	
	while(1)
	{
		if (mouse_flag==0)																	//鼠
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
			
			*main_flag=8;						//返回个人中心
			break;
		}
		else if(MouseBarLeft(343,165,759,230)==1)
		{
			
			MousePutBk(mouse_old.x,mouse_old.y);
			mflag=1;
			
			Bar64k(343,165,759,230,65503);				//清空原密码框内容
			strcpy(password0,"");						//清空原密码内容
			
			textbox(343,165,759,230,20,1,password0);
		}
		else if(MouseBarLeft(343,260,759,325)==1)
		{
			
			MousePutBk(mouse_old.x,mouse_old.y);
			mflag=1;
			
			Bar64k(343,260,759,325,65503);				//清空新密码框内容
			strcpy(password1,"");						//清空新密码内容
			
			textbox(343,260,759,325,20,2,password1);
		}
		else if(MouseBarLeft(343,355,759,420)==1)
		{
			
			MousePutBk(mouse_old.x,mouse_old.y);
			mflag=1;
			
			Bar64k(343,355,759,420,65503);				//清空新密码2框内容
			strcpy(password2,"");						//清空新密码2内容
			
			textbox(343,355,759,420,20,2,password2);
		}
		else if(MouseBarLeft(334,539,695,628)==1)		//点击修改密码
		{
			if((password0!="")&&(password1!="")&&(password2!=""))			//每个框都输入的有内容
			{
				if(strcmp(user->password,password0)==0&&strcmp(password1,password2)==0)		//输入均正确
				{
					if((fp=fopen("TXT\\USER\\user.txt","rt+"))==NULL)
					{
						Outtext(391,517,"打开指定文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
						Outtext(391,540,"按任意键退出",24,27,0x0000);
		
						while(bioskey(1))
						{
							getch();
						}
		
						getch();
						exit(1);
					}
					
					//将指针移动到相应用户位置
					for(i=1; i<n; i++)
					{
						fscanf(fp,"*%s %s %s %s\n",username,password,num,balance);
					}
					j1=ftell(fp);
					fscanf(fp,"*%s %s %s %s\n",username,password,num,balance);
					j2=ftell(fp);
					j=j2-j1;
					
					//删除该行用户信息
					if((fp1=fopen("TXT\\USER\\tem.txt","w+"))==NULL)
					{
						Outtext(391,517,"创建临时文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
						Outtext(391,540,"按任意键退出程序",24,27,0x0000);
				
						while(bioskey(1))
						{
							getch();
						}
			
						getch();
			
						exit(0);
					}
					rewind(fp);
					for(i=1;i<=j1;i++)
					{
						c=fgetc(fp);
						fputc(c,fp1);
					}
					fseek(fp,j,1);
					for(i=j2;	!feof(fp)	;i++)
					{
						c=fgetc(fp);
						fputc(c,fp1);
					}
						
						
					fseek(fp1,j1,0);		//指针移动到相应位置
					
					
					fprintf(fp1,"*%s %s %s %s\n",username,password1,num,balance);
					fclose(fp);
					fclose(fp1);
					remove("TXT\\USER\\user.txt");
					rename("TXT\\USER\\tem.txt","TXT\\USER\\user.txt");
					Outtext(218,663,"修改成功,按任意键返回登陆界面重新登录",32,35,63488);
					delay(100);
					while(bioskey(1))
					{
						getch();
					}
		
					getch();
					
					*main_flag=1;
					break;
				}
				else if(strcmp(user->password,password0)!=0)
				{
					Outtext(760,165,"原密码输入错误",32,35,63488);
					delay(1000);
					Bar64k(759,165,1023,220,2463);
				}
				else if(strcmp(password1,password2)!=0)
				{
					Outtext(760,260,"新密码前后不一致",32,35,63488);
					delay(1000);
					Bar64k(759,260,1023,300,2463);
				}
			}
			else
			{
				Outtext(418,633,"信息输入不完整",32,35,63503);
				delay(1000);
				Bar64k(418,623,800,700,2463);
			}
		}
	}
	fclose(fp);
}

/***

AboutUs界面功能

***/
void AboutUs(int *main_flag)
{
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;
	int mflag=1;
	
	About_pic();
	
	while(1)
	{
		if (mouse_flag==0)																	//鼠
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
			
			*main_flag=8;						//返回个人中心
			break;
		}
		if(MouseBarLeft(827,180,878,231)==1)      //鼠标点击退出按钮
		{
			while(MouseBarLeft(827,180,878,231)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			*main_flag=8;						//返回个人中心
			break;
		}
	}
}
/***
判断字符是不是全为数字和小数点
若全为数字，则返回1
否则返回0
***/	
int JudgeNum(char *s)
{
	char ch;
	int i,k=0;
	
	for(i=0;	i<strlen(s);	i++)
	{
		ch=s[i];
		if(ch>='0'&&ch<='9'||ch=='.')
		{
			k++;
		}
	}
	if(k==strlen(s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	
	
	
/***

判断输入字符是否都是字母加数字

可用于判断用户名和密码输入是否正确
***/	
int JudgeWord(char *s)
{
	char ch;
	int i,k=0;
	
	for(i=0;	i<strlen(s);	i++)
	{
		ch=s[i];
		if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
		{
			k++;
		}
	}
	if(k==strlen(s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}	
	
	
	
	
/***购药函数***/
void BuyM(Medicine *medicine,User *user,int n)
{
	FILE *fp1,*fp3;	//已购药物文件指针
	FILE *fp2,*fp;	//用户信息文件指针
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量	
	int B_num=0;			//购买数量
	char* tol="";			//总价
	double Total;			//总价
	char* ch;			//购买数量

	char* username="";
	char* password="";
	char* num="";
	char* balance="";
	double bal;
	char c;
	
	int i=1,tx=0;
	int j1,j2,j;		//定义文件指针参数
	
	unsigned int size=7;	//定义了总价输出的最大长度
	
	BuyM_pic(medicine);
	
	
	
	balance=user->balance;			//余额初始化
	if(fp3=fopen("TXT\\USER\\chufang.txt","at")==NULL)
	{
		Outtext(391,517,"打开记录文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出程序",24,27,0x0000);
						
						
		while(bioskey(1))
		{
			getch();
		}
						
		getch();
						
		exit(1);
	}
	fprintf(fp3," %s\n",medicine->name);
	fclose(fp3);
	fp1=fopen("TXT\\user\\buy.txt","at");
	delay(100);
	if((fp1)==NULL)
	{
		Outtext(391,517,"打开记录文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出程序",24,27,0x0000);
						
						
		while(bioskey(1))
		{
			getch();
		}
						
		getch();
						
		exit(1);
	}
	if((fp2=fopen("TXT\\USER\\user.txt","rt+"))==NULL)
	{
		Outtext(391,517,"打开用户文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出程序",24,27,0x0000);
					
		while(bioskey(1))
		{
			getch();
		}
					
		getch();
					
		exit(1);
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
		else if(MouseBarLeft(188,405,285,461)==1&&(B_num>0))		//点击减号
		{
			MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			mflag=1;
			
			
			delay(200);
			//购买数量变化
			ch="";
			B_num--;
			Bar64k(285,405,380,461,65535);
			itoa(B_num,ch,10);
			Outtext(290,405,ch,48,50,0);
			//总价变化
			Total=B_num*(atof(medicine->price));
			Bar64k(578,408,828,458,26620);	
			Outtext(582,410,gcvt(Total,size,tol),32,35,0);
		}
		else if(MouseBarLeft(380,405,480,461)==1&&(B_num<100))		//点击加号
		{
			MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			mflag=1;
			
			
			delay(200);
			//购买数量变化
			ch="";
			B_num++;
			Bar64k(285,405,380,461,65535);
			itoa(B_num,ch,10);
			Outtext(290,405,ch,48,50,0);
			//总价变化
			Total=B_num*(atof(medicine->price));
			Bar64k(578,408,828,458,26620);
			Outtext(582,410,gcvt(Total,size,tol),32,35,0);
		}
		if(MouseBarLeft(455,483,578,543)==1)		//点击购买
		{
			while(MouseBarLeft(455,483,578,543)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);     //恢复鼠标
			mflag=1;
			
			bal=atof(balance);
			if(bal>=Total)
			{
				
				
				//将指针移动到相应用户位置
				for(i=1; i<n; i++)
				{
					fscanf(fp2,"*%s %s %s %s\n",username,password,num,balance);
				}
				j1=ftell(fp2);
				fscanf(fp2,"*%s %s %s %s\n",username,password,num,balance);
				j2=ftell(fp2);
				j=j2-j1;
				//删除该行用户信息
				if((fp=fopen("TXT\\USER\\tem.txt","w+"))==NULL)
				{
					Outtext(391,517,"创建临时文件失败，无法进行后续操作",24,27,0x0000);
					Outtext(391,540,"按任意键退出程序",24,27,0x0000);
			
					while(bioskey(1))
					{
						getch();
					}
		
					getch();
		
					exit(0);
				}
				rewind(fp2);
				for(i=1;i<=j1;i++)
				{
					c=fgetc(fp2);
					fputc(c,fp);
				}
				fseek(fp2,j,1);
				for(i=j2;	!feof(fp2)	;i++)
				{
					c=fgetc(fp2);
					fputc(c,fp);
				}
				fseek(fp,j1,0);
				//余额变化
				bal=bal-Total;
				balance=gcvt(bal,size,balance);
				fprintf(fp,"*%s %s %s %s\n",user->username,user->password,user->num,gcvt(bal,size,balance));
				strcpy(user->balance,gcvt(bal,size,balance));
				
				fclose(fp);
				fclose(fp2);
				
				remove("TXT\\USER\\user.txt");
				rename("TXT\\USER\\tem.txt","TXT\\USER\\user.txt");
				
			
				
				//购买记录
				fprintf(fp1,"*%s\n",user->username);
				fprintf(fp1,"* %s %s %s\n",medicine->name,ch,gcvt(Total,size,tol));
				Outtext(580,490,"购买成功",32,35,63503);
				fclose(fp1);
				
				
				tx=1;
				delay(1000);
				break;
			}
			else
			{
				Outtext(580,490,"余额不足",32,35,63503);
				tx=2;
				delay(1000);
				Bar64k(580,490,720,525,9248);
			}
		}
	}
	if(tx==0)
	{
		fclose(fp);
		fclose(fp2);
		fclose(fp1);
	}
	else if(tx==2)
	{
		fclose(fp2);
		fclose(fp1);
	}
}


