#include"head.h"
#include"mouse.h"
#include"SVGAMODE.h"
#include"picture.h"
#include"outtext.h"
#include"function.h"
#include"module1.h"
#include"module0.h"
#include"module.h"
#include"module11.h"

/***管理员界面功能函数***/
void Admin(int *main_flag)
{
	MOUSE mouse_new,mouse_old;
	int mouse_flag=1;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量
	
	Admin_pic();
	
	
	
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
		
		if(MouseBarLeft(978,0,1024,46)==1)      //鼠标点击退出按钮
		{
			while(MouseBarLeft(978,0,1024,46)==1)
			{
			}
			delay(100);							//返回登陆界面
			*main_flag=1;
			break;
		}
		else if(MouseBarLeft(296,222,842,314)==1)	//鼠标点击用户密保查看与修改
		{
			while(MouseBarLeft(296,222,842,314)==1)
			{
			}
			delay(100);
			*main_flag=12;
			break;
		}
		else if(MouseBarLeft(296,454,842,546)==1)	//鼠标点击删减医生信息
		{
			while(MouseBarLeft(296,454,842,546)==1)
			{
			}
			delay(100);
			*main_flag=13;
			break;
		}
		
	}
}	

/***管理员查看修改密保问题***/
void Changeanswer(int *main_flag)
{
	FILE *fp;
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量
	int i;
	
	int page=1,lastpage,num;
	User *p;
	num=Chaninit(p);

	
	//计算总页数
	if(num%7==0)
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
	/*Bar64k(0,0,1023,767,2463);		//画蓝色背景*/

	while(*main_flag==12)
	{
		Changeanswer_pic();
		delay(100);
		Chanuser_pic(p,num,page,lastpage);
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
		
			if(MouseBarLeft(978,0,1024,46)==1)      //鼠标点击退出按钮
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				*main_flag=6;
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
			
			/*for(i=0;i<7;i++)
			{
				if(MouseBarLeft(900,178+72*i,1000,232+72*i)==1)
				{
					MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
					mflag=1;
					
					Alternum((p+i),main_flag,i+7*(page-1),num);
					break;
				}
			}*/
			if(MouseBarLeft(900,178,1000,232)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
					
				Alternum(p,main_flag,7*page-7,num);
				break;
			}
			if(MouseBarLeft(900,250,1000,310)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
					
				Alternum(p,main_flag,7*page-6,num);
				break;
			}		
			if(MouseBarLeft(900,322,1000,382)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
					
				Alternum(p,main_flag,7*page-5,num);
				break;
			}	
			if(MouseBarLeft(900,394,1000,454)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
					
				Alternum(p,main_flag,7*page-4,num);
				break;
			}		
			if(MouseBarLeft(900,466,1000,526)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
					
				Alternum(p,main_flag,7*page-3,num);
				break;
			}	
			if(MouseBarLeft(900,538,1000,598)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
					
				Alternum(p,main_flag,7*page-2,num);
				break;
			}			
			if(MouseBarLeft(900,610,1000,670)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
					
				Alternum(p,main_flag,7*page-1,num);
				break;
			}
		}
	}
}

/***修改密保函数***/
void Alternum(User *user,int *main_flag,int m,int numm)
{
	FILE *fp;
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量	
	
	User *p=user;
	/*User *q;*/
	char numm1[11];
	char numm2[11];
	int i,j;
	
	Alternum_pic();
	delay(100);
	
	Outtext(350,200,(p+m)->num,48,50,0);
	
	/*if((fp=fopen("TXT\\USER\\user.txt","rt"))==NULL)
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
	for(i=0;i<num;i++)
	{
		fscanf(fp,"*%s %s %s %s\n",(q+i)->username,(q+i)->password,(q+i)->num,(q+i)->balance);
	}
	fclose(fp);*/

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
			
			*main_flag=12;
			break;
		}
		
		else if(MouseBarLeft(350,350,900,400)==1)
		{
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Bar64k(350,350,900,400,65503);
			strcpy(numm1,"");
			
			textbox(350,350,900,400,50,2,numm1);
		}
		
		else if(MouseBarLeft(350,500,900,550)==1)
		{
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Bar64k(350,500,900,550,65503);
			strcpy(numm2,"");
			
			textbox(350,500,900,400,50,2,numm2);
		}
		
		else if(MouseBarLeft(400,580,584,668)==1)
		{
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;		
			
			if(strcmp(numm1,numm2)==0)
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
				for(i=0;i<numm;i++)
				{
					if(i==m)
					{
						strcpy((p+i)->num,numm1);	
						fprintf(fp,"*%s %s %s %s\n",(p+i)->username,(p+i)->password,(p+i)->num,(p+i)->balance);
					}
					else
					{
						fprintf(fp,"*%s %s %s %s\n",(p+i)->username,(p+i)->password,(p+i)->num,(p+i)->balance);
					}
				}
				fclose(fp);
										
				Outtext(718,353,"修改成功",32,35,63488);
				delay(1000);
				*main_flag=12;
				break;
			}
			
			else 
			{
				
				Outtext(718,353,"请输入正确的答案",32,35,63488);
				delay(100);
				Bar64k(350,350,900,400,65503);
				Bar64k(350,500,900,550,65503);
			}
		}
	}
	
}

/***用户信息初始化***/
int Chaninit(User *user)
{
	FILE *fp;
	char ch;
	User *user1=user;
	int i,num=0;
	
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

	while(!feof(fp))
	{
		ch = fgetc(fp);
		if(ch=='*')
		{
			num++;
		}
		
	}

	
	rewind(fp);
	for(i=0;i<num;i++)
	{
		fscanf(fp,"*%s %s %s %s\n",(user1+i)->username,(user1+i)->password,(user1+i)->num,(user1+i)->balance);
	}
	fclose(fp);
	user1=NULL;
	return(num);
}

/***用户信息输出函数***/
void Chanuser_pic(User *user,int num,int page,int lastpage)
{
	int i;
	int j=0;
	for(i=0; i<8; i++)
	{
		Bar64k(0,101+72*i,1023,161+72*i,2016);
	}
	for(i=1;i<8;i++)
	{
		Outtext(900,106+72*i,"修改",48,50,64264);
		LightBarWiden(900,101+72*i,1000,160+72*i,0);
	}
	Bar64k(294,101,306,664,57638);
	Bar64k(575,101,587,664,32784);
	
	Outtext(63,107,"用户名",48,50,0);
	Outtext(350,107,"密码",48,50,0);
	Outtext(658,107,"密保答案",48,50,0);
	
	if(page<lastpage)
	{
		i=7;
	}
	else if(page==lastpage)
	{
		if(num%7==0)
		{
			i=7;
		}
		else
		{
			i=num%7;
		}
	}
	
	if(j<i)
	{
		Outtext(20,183+72*j,(user+j)->username,24,25,0);
		Outtext(330,183+72*j,(user+j)->password,24,25,0);
		Outtext(600,183+72*j,(user+j)->num,24,25,0);
		j++;
	}		
	if(j<i)
	{
		Outtext(20,183+72*j,(user+j)->username,24,25,0);
		Outtext(330,183+72*j,(user+j)->password,24,25,0);
		Outtext(600,183+72*j,(user+j)->num,24,25,0);
		j++;
	}
	if(j<i)
	{
		Outtext(20,183+72*j,(user+j)->username,24,25,0);
		Outtext(330,183+72*j,(user+j)->password,24,25,0);
		Outtext(600,183+72*j,(user+j)->num,24,25,0);
		j++;
	}	
	if(j<i)
	{
		Outtext(20,183+72*j,(user+j)->username,24,25,0);
		Outtext(330,183+72*j,(user+j)->password,24,25,0);
		Outtext(600,183+72*j,(user+j)->num,24,25,0);
		j++;
	}	
	if(j<i)
	{
		Outtext(20,183+72*j,(user+j)->username,24,25,0);
		Outtext(330,183+72*j,(user+j)->password,24,25,0);
		Outtext(600,183+72*j,(user+j)->num,24,25,0);
		j++;
	}	
	if(j<i)
	{
		Outtext(20,183+72*j,(user+j)->username,24,25,0);
		Outtext(330,183+72*j,(user+j)->password,24,25,0);
		Outtext(600,183+72*j,(user+j)->num,24,25,0);
		j++;
	}	
	if(j<i)
	{
		Outtext(20,183+72*j,(user+j)->username,24,25,0);
		Outtext(330,183+72*j,(user+j)->password,24,25,0);
		Outtext(600,183+72*j,(user+j)->num,24,25,0);
		j++;
	}		
}

/***删减医生函数***/
void Deletedoc(int *main_flag)
{
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量
	
	Doctor doc[N];					//医生结构数组
	Doctor *p=doc;					
	int page=1,lastpage;			//页数标记函数
	int num = Deldocinti(doc);		//医生信息初始化
	int m;
	
		
	//计算总页数
	if(num%6==0)
	{
		lastpage=num/6;
	}
	else
	{
		lastpage = num/6+1;
	}
	
	Deldoc_pic();
	delay(100);
	
	while(*main_flag==13)
	{
		Deletedoc_pic(p,num,page,lastpage);
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
			if(MouseBarLeft(978,0,1024,46)==1)      //鼠标点击退出按钮
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
			
				*main_flag=6;
				break;
			}
			
			else if(MouseBarLeft(455,90,505,140)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
				
				Shutdown(6*page-5,main_flag,doc,num);
				break;
			}
			
			else if(MouseBarLeft(973,90,1023,140)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
				
				Shutdown(6*page-4,main_flag,doc,num);
				break;
			}

			else if(MouseBarLeft(455,279,505,329)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
				
				Shutdown(6*page-3,main_flag,doc,num);
				break;
			}

			else if(MouseBarLeft(973,279,1023,329)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
				
				Shutdown(6*page-2,main_flag,doc,num);
				break;
			}	

			else if(MouseBarLeft(455,468,505,518)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
				
				Shutdown(6*page-1,main_flag,doc,num);
				break;
			}	

			else if(MouseBarLeft(973,468,1023,518)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;	
				
				Shutdown(6*page,main_flag,doc,num);
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
		}
	}
}	

/***删减医生文件操作函数***/
void Shutdown(int m,int *main_flag,Doctor *doc,int numb)
{
	FILE *fp;
	int i;
	Doctor *p=doc;
	Doctor q[50];
	
	/*if((fp=fopen("TXT\\DOCTORS\\doctors.txt","rt"))==NULL)
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
	for(i=0;i<50;i++)
	{
		fscanf("*%s %s %s %s\n",(p+i)->name,(p+i)->department,(p+i)->skill,(p+i)->years);
	}
	fclose(fp);*/
	
	if((fp=fopen("TXT\\DOCTORS\\doctors.txt","w+"))==NULL)
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
	if(m==1)
	{
		for(i=0;i<numb-1;i++)
		{
			strcpy((q+i)->name,(p+i+1)->name);
			strcpy((q+i)->department,(p+i+1)->department);
			strcpy((q+i)->skill,(p+i+1)->skill);
			(q+i)->years=(p+i+1)->years;
			fprintf(fp,"* %d %s %s %s # %d\n",((q+i)->t),(q+i)->name,(q+i)->department,(q+i)->skill,((q+i)->years));
		}
	}
	else
	{
		for(i=0;i<m-1;i++)
		{
			strcpy((q+i)->name,(p+i)->name);
			strcpy((q+i)->department,(p+i)->department);
			strcpy((q+i)->skill,(p+i)->skill);
			(q+i)->years=(p+i)->years;
			fprintf(fp,"* %d %s %s %s # %d\n",((q+i)->t),(q+i)->name,(q+i)->department,(q+i)->skill,((q+i)->years));
		}
		for(i=m-1;i<numb-1;i++)
		{
			strcpy((q+i)->name,(p+i+1)->name);
			strcpy((q+i)->department,(p+i+1)->department);
			strcpy((q+i)->skill,(p+i+1)->skill);
			(q+i)->years=(p+i+1)->years;	
			fprintf(fp,"* %d %s %s %s # %d\n",((q+i)->t),(q+i)->name,(q+i)->department,(q+i)->skill,((q+i)->years));
		}
	}		
	fclose(fp);
	*main_flag=15;
}

/***转换函数***/
void Invert(int *main_flag)
{
	*main_flag=13;
}

/***管理员界面医生信息输出函数***/
void Deletedoc_pic(Doctor *doc,int num,int page,int lastpage)
{

	
	int i;  		//计算本页共有几个医生
	int j=0;
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
	//char s0[2][20],s1[2][20],s2[2][20],s3[2][20],s4[2][20],s5[2][20];		//便于换行输出

	/*
	strcpy(s0,doc->skill);
	strcpy(s1,(doc+1)->skill);
	strcpy(s2,(doc+2)->skill);
	strcpy(s3,(doc+3)->skill);
	strcpy(s4,(doc+4)->skill);
	strcpy(s5,(doc+5)->skill);
	*/
	Deletedoc_bpic();
	if(j<i)
	{
		Outtext(0,96,doc->name,32,35,0);
		Outtext(150,96,doc->department,24,25,0);
		Outtext(0,150,doc->skill,16,18,0);
		//out_ASC(0,150,(doc->years),0);
		
		j++;
	}
	if(j<i)
	{
		Outtext(517,96,(doc+1)->name,32,35,0);
		Outtext(667,96,(doc+1)->department,24,25,0);
		Outtext(517,150,(doc+1)->skill,16,18,0);
		//out_ASC(517,96,(doc+1)->years,0);
		
		j++;
	}
	if(j<i)
	{
		Outtext(0,285,(doc+2)->name,32,35,0);
		Outtext(150,285,(doc+2)->department,24,25,0);
		Outtext(0,339,(doc+2)->skill,16,18,0);
		//out_ASC(0,285,(doc+2)->years,0);
		
		j++;
	}
	if(j<i)
	{
		Outtext(517,286,(doc+3)->name,32,35,0);
		Outtext(667,286,(doc+3)->department,24,25,0);
		Outtext(517,339,(doc+3)->skill,16,18,0);
		//out_ASC(517,286,(doc+3)->years,0);
		
		j++;
	}
	if(j<i)
	{
		Outtext(0,474,(doc+4)->name,32,35,0);
		Outtext(150,474,(doc+4)->department,24,25,0);
		Outtext(0,518,(doc+4)->skill,16,18,0);
		//out_ASC(0,474,(doc+4)->years,0);
		
		j++;
	}
	if(j<i)
	{
		Outtext(517,474,(doc+5)->name,32,35,0);
		Outtext(667,474,(doc+5)->department,24,25,0);
		Outtext(517,518,(doc+5)->skill,16,18,0);
		//out_ASC(517,474,(doc+5)->years,0);
		
		j++;
	}
}

/***管理员医生信息读取函数***/
int Deldocinti(Doctor *doctor)
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
		fscanf(fp,"* %d %s %s %s # %d\n",&((doc+i))->t,((doc+i))->name,((doc+i))->department,((doc+i))->skill,&((doc+i))->years);
	}
	fclose(fp);
	
	return(num);
}