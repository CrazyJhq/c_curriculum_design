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
	int mouse_flag=0;		//������ò�������
	int mflag=1;            //���������̲�������
	
	int sign1=0,sign2=0,sign3=0,sign4=0,sign5=0;   //��ǲ���
	
	Login_pic();
	
	//��ȡ�˺�����
	while(1)
	{
	    if (mouse_flag==0)
		{
		MouseReset();
		mouse_flag=1;																	
		}																					
																						
		MouseStatus(&mouse_new);			//��ȡ���״̬								
																							
		if(mflag==0)					
		{
			MousePutBk(mouse_old.x,mouse_old.y);	//�ָ�����굲ס���ֵ��Դ�										
		}																					
		
		else
		{																					
			mflag=0;																		
		}
		MouseStoreBk(mouse_new.x,mouse_new.y);		//�洢ͼ��							
		MouseDraw(mouse_new);						//�����
		mouse_old=mouse_new;						//��¼
		delay(50);
		
	    if( (mouse_new.x >=484) && (mouse_new.y>=455)&&(mouse_new.x <= 715) && (mouse_new.y <= 546 ) )	    sign1=1;//�ڵ�¼��ť��Χ��
		if( (mouse_new.x >=319) && (mouse_new.y>=615)&&(mouse_new.x <= 515) && (mouse_new.y <= 675 ) )		sign2=1;//���������뷶Χ��
		if( (mouse_new.x >=631) && (mouse_new.y>=615)&&(mouse_new.x <= 827) && (mouse_new.y <= 673 ) )		sign3=1;//��ע�ᰴť��Χ��
		if( (mouse_new.x >=385) && (mouse_new.y>=227)&&(mouse_new.x <= 884) && (mouse_new.y <= 300 ) )		sign4=1;//���û�����Χ��
		if( (mouse_new.x >=385) && (mouse_new.y>=341)&&(mouse_new.x <= 884) && (mouse_new.y <= 418 ) )		sign5=1;//��������Χ��
		//����Ч��
		
		if(sign1 == 0)                              //�ָ���¼��ť��
		{ 
		    LightBarWiden(484,455,715,546,0);
		}
		if(sign1 == 1)                              //ǿ����¼��ť��
		{
		    LightBarWiden(484,455,715,546,26592);
			sign1=0;
		}
		
		if(sign2 == 0)                              //�ָ����������
		{
		    LightBarWiden(319,615,515,675,0);
		}
		if(sign2 == 1)                              //ǿ�����������
		{
		    LightBarWiden(319,615,515,675,26592);;
			sign2=0;
		}
		
		if(sign3 == 0)                              //�ָ�ע�ᰴť��
		{
		    LightBarWiden(631,615,827,673,0);
		}
		if(sign3 == 1)                              //ǿ��ע�ᰴť��
		{
		    LightBarWiden(631,615,827,673,26592);
			sign3=0;
		}
		
		if(sign4 == 0)                              //�ָ��û�����
		{
		    LightBarWiden(385,227,884,300,0);
		}
		if(sign4 == 1)                              //ǿ���û�����
		{
		    LightBarWiden(385,227,884,300,26592);
			sign4=0;
		}
		
		if(sign5 == 0)                              //�ָ������
		{
		    LightBarWiden(385,341,884,418,0);
		}            
		if(sign5==1)                                //ǿ�������
		{
		    LightBarWiden(385,341,884,418,26592);
		    sign5=0;
		}
		
		if(MouseOn(0,0,196,70)==1&&admin==0)					//���ŵ����Ͻ�
		{
			admin=1;
			Bar64k(0,0,196,70,2047);
			Outtext(13,9,"����Ա",48,50,65504);				//��ʾ����Ա
		}
		
		
		if(MouseBarLeft(387,229,882,298)==1)        //���û������ڵ�����
		{
		    MousePutBk(mouse_old.x,mouse_old.y);     //�ָ����
			
			Bar64k(388,230,881,297,65535);           //�ָ��û���������
			
			strcpy(username,"");                      //�����û����ַ�����
			
			textbox(387,229,882,298,25,1,username);
			mflag=1;
		}
		
		
		else if(MouseBarLeft(0,0,196,70)==1)   //�ڹ���Ա�ڵ�����
		{
		
			MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
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
		
		else if(MouseBarLeft(387,343,882,416)==1)   //��������ڵ�����
		{
		    MousePutBk(mouse_old.x,mouse_old.y);     //�ָ����
			
			Bar64k(388,344,881,415,65535);           //�ָ�����������
			
			strcpy(password,"");                     //���������ַ�����
			
			textbox(387,343,882,416,25,2,password);
			mflag=1;
		}
				
		else if(MouseBarLeft(486,457,711,542)==1)   //�ڵ�¼���ڵ�����
		{
			if((fp=fopen("TXT\\USER\\user.txt","rt"))==NULL)
			{
				Outtext(391,517,"��ָ���ļ�ʧ�ܣ��޷����к�������������ϵ������Ա",24,27,0x0000);
				Outtext(391,540,"��������˳�",24,27,0x0000);
			
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
				if(strcmp(username,"")==0||strcmp(password,"")==0)		//����������û����������ȥ���½��ť
				{
					Outtext(100,450,"��Ϣ���벻����,�����������",24,25,65535);
				
					strcpy(username,"");					//�����û����ַ�����
					strcpy(password,"");				//���������ַ�����	
				
					while(bioskey(1)==0)
					{
                     
					}
					delay(500);
					Login_pic();
				}
				else
				{
					Outtext(100,450,"������������밴���������",24,25,65535);
									
					strcpy(username,"");					//�����û����ַ�����
					strcpy(password,"");				//���������ַ�����	
	            
					while(bioskey(1)==0)
					{
                     
					}
					delay(500);
					Login_pic();
				}
            }
			
			
		}
		else if(MouseBarLeft(322,618,512,672)==1)  //������������ڵ�����
		{
		    *main_flag=3;
			delay(100);
			break;
		}
		else if(MouseBarLeft(633,617,825,671)==1)  //��ע����ڵ�����
		{
		    *main_flag=2;
			delay(100);
			break;
		}
		else if(MouseBarLeft(978,0,1024,46)==1)  //���˳���ť�ڵ�����
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
	int mouse_flag=0;		//������ò�������
	int mflag=1;            //���������̲�������		
	
	int sign1=0,sign3=0,sign4=0,sign5=0;   //��ǲ���	
		
	Forget_user_pic();	
	num1=Chaninit(p);
	while(1)
	{
	    if(mouse_flag==0)
		{
		MouseReset();
		mouse_flag=1;																	
		}																					
																						
		MouseStatus(&mouse_new);			//��ȡ���״̬								
																							
		if(mflag==0)					
		{
			MousePutBk(mouse_old.x,mouse_old.y);	//�ָ�����굲ס���ֵ��Դ�										
		}																					
		
		else
		{																					
			mflag=0;																		
		}
		MouseStoreBk(mouse_new.x,mouse_new.y);		//�洢ͼ��							
		MouseDraw(mouse_new);						//�����
		mouse_old=mouse_new;						//��¼
		delay(50);
		
		 if( (mouse_new.x >=440) && (mouse_new.y>=183)&&(mouse_new.x <= 710) && (mouse_new.y <= 226 ) )	    sign1=1;//���û������뷶Χ��
		 //if( (mouse_new.x >=440) && (mouse_new.y>=269)&&(mouse_new.x <= 710) && (mouse_new.y <= 312 ) )	    sign2=1;//���ܱ��������뷶Χ��
		 if( (mouse_new.x >=440) && (mouse_new.y>=355)&&(mouse_new.x <= 710) && (mouse_new.y <= 398 ) )	    sign3=1;//���ܱ������뷶Χ��
		 if( (mouse_new.x >=440) && (mouse_new.y>=441)&&(mouse_new.x <= 710) && (mouse_new.y <= 484 ) )	    sign4=1;//�����������뷶Χ��
		 if( (mouse_new.x >=440) && (mouse_new.y>=527)&&(mouse_new.x <= 710) && (mouse_new.y <= 570 ) )	    sign5=1;//��ȷ���������뷶Χ��
	     	
	     
		if(sign1 == 0)                              //�ָ��û��������
		{ 
		    LightBarWiden(440,183,710,226,0);
		}
		if(sign1 == 1)                              //ǿ���û��������
		{
		    LightBarWiden(440,183,710,226,26592);
			sign1=0;
		}
		/*
		if(sign2 == 0)                              //�ָ��ܱ����������
		{ 
		    LightBarWiden(440,269,710,312,0);
		}
		if(sign2 == 1)                              //ǿ���ܱ����������
		{
		    LightBarWiden(440,269,710,312,26592);
			sign2=0;
		}
		*/
		if(sign3 == 0)                              //�ָ��ܱ��������
		{ 
		    LightBarWiden(440,355,710,398,0);
		}
		if(sign3 == 1)                              //ǿ���ܱ��������
		{
		    LightBarWiden(440,355,710,398,26592);
			sign3=0;
		}
		
		if(sign4 == 0)                              //�ָ������������
		{ 
		    LightBarWiden(440,441,710,484,0);
		}
		if(sign4 == 1)                              //ǿ�������������
		{
		    LightBarWiden(440,441,710,484,26592);
			sign4=0;
		}
		
		if(sign5 == 0)                              //�ָ���¼��ť��
		{ 
		    LightBarWiden(440,527,710,570,0);
		}
		if(sign5 == 1)                              //ǿ����¼��ť��
		{
		    LightBarWiden(440,527,710,570,26592);
			sign5=0;
		}
		
		
		if(MouseBarLeft(442,185,708,224)==1)        //���û���������ڵ�����
		{
		    MousePutBk(mouse_old.x,mouse_old.y);     //�ָ����
			
			Bar64k(443,186,707,223,65535);           //�ָ��û���������
			
			strcpy(username,"");                      //�����û����ַ�����
			
			textbox(442,185,708,223,25,1,username);
			mflag=1;
		}
		
		/*else if(MouseBarLeft(442,271,708,310)==1)        //���ܱ�����������ڵ�����
		{
		    MousePutBk(mouse_old.x,mouse_old.y);     //�ָ����
			
			Bar64k(443,272,707,309,65535);           //�ָ��ܱ�����������
			
			strcpy(MBquestion,"");                   //�����ܱ������ַ�����
			
			textbox(442,,882,298,25,1,MBquestion);
			mflag=1;
		}
		*/
		else if(MouseBarLeft(442,357,708,396)==1)        //���ܱ���������ڵ�����
		{
		    MousePutBk(mouse_old.x,mouse_old.y);     //�ָ����
			
			Bar64k(443,358,707,395,65535);           //�ָ��ܱ���������
			
			strcpy(num,"");                     //�����ܱ������ַ�����
			
			textbox(442,357,708,396,25,1,num);
			mflag=1;
			
			if((strcmp(username,user->username)==0)              //�ж���Ϣƥ��
			   &&(strcmp(num,user->num)==0))
			{
				Outtext(640,610,"������������",24,25,65535);
			}
			else
		    {
				Outtext(640,610,"��������ȷ��Ϣ",24,25,65535);
			}
		}
		
		else if(MouseBarLeft(442,443,708,482)==1)        //��������������ڵ�����
		{
		    MousePutBk(mouse_old.x,mouse_old.y);          //�ָ����
			
			Bar64k(443,444,707,481,65535);                //�ָ�������������
			 
			strcpy(password1,"");                         //�����������ַ�����
			
			textbox(442,443,708,482,25,1,password1);
			mflag=1;
		}
		
		else if (MouseBarLeft(442,529,708,568)==1)        //��ȷ������������ڵ�����
		{
			MousePutBk(mouse_old.x,mouse_old.y);          //�ָ����
			 
			Bar64k(443,530,707,567,65503);                      //�ָ�ȷ������������
			
			strcpy(password2,"");                         //����ȷ�������ַ�����
			
			textbox(442,529,708,568,25,1,password2);
			mflag=1;
		}
		
		else if(MouseBarLeft(424,661,602,718)==1)        //���һ�������ڵ�����
		{
			MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
			mflag=1;		
			
			if(strcmp(password1,password2)==0)            //������������һ��
			{
				if((fp=fopen("TXT\\USER\\user.txt","w+"))==NULL)
				{
					Outtext(391,517,"��ָ���ļ�ʧ�ܣ��޷����к�������������ϵ������Ա",24,27,0x0000);
					Outtext(391,540,"��������˳�",24,27,0x0000);
			
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
				Outtext(718,700,"�޸ĳɹ�",32,35,63488);
				delay(1000);
				*main_flag=1;
				break;
			}
			else
			{
				Outtext(640,610,"ǰ�����벻һ�£�����������",25,1,65535);
				strcpy(password1,"");
				strcpy(password2,"");
			}
		}
		else if(MouseBarLeft(978,0,1024,46)==1)  //���˳���ť�ڵ�����
		{
		    delay(100);
			*main_flag=1;
			break;
		}
	}
}

/***�����湦�ܺ���***/
void Interface(int *main_flag)
{
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//������ò�������
	int mflag=1;    	//���������̲�������
	int xflag=0;

	char dep[8][20]={"����",
	               "����",
				   "Ƥ����",
				   "�����",
				   "�ǿ�",
				   "���Ǻ��",
				   "������ѯʦ",
				   "���ڿ�"};
	Interface_pic();
	delay(100);
		
	while(*main_flag==4)
	{

		xflag=0;
		while(1)
		{
			if (mouse_flag==0)																	
			{																					
				MouseReset();																	//��
				mouse_flag=1;																	
			}																					
																							//��
			MouseStatus(&mouse_new);		//��ȡ���״̬										
																							
			if(mflag==0)					//ͨ�����������̲������������ı�������ͼ����	//һ
			{
				MousePutBk(mouse_old.x,mouse_old.y);											
			}																					//��
		
			else
			{																					
				mflag=0;																		//��
			}
			MouseStoreBk(mouse_new.x,mouse_new.y);		//�洢ͼ��										
			MouseDraw(mouse_new);						//�����								//��
			mouse_old=mouse_new;						//��¼
			delay(50);
			if(MouseBarLeft(978,0,1024,46)==1)      //������˳���ť
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				*main_flag=1;
				break;
			}
			else if(MouseBarLeft(265,696,512,767)==1)	//�����ҽ��
			{
				while(MouseBarLeft(265,696,512,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;	
				
				*main_flag=5;
				break;
			}
		
			else if(MouseBarLeft(512,696,768,767)==1)	//�����ҩ		
			{
				while(MouseBarLeft(512,696,768,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				*main_flag=7;
				break;
			}
			else if(MouseBarLeft(768,696,1023,767)==1)	//�����������		
			{
				while(MouseBarLeft(768,696,1023,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;	
				
				*main_flag=8;
				break;
			}
			else if(MouseBarLeft(0,160,256,260)==1)    //�������
			{
				while(MouseBarLeft(0,160,256,260)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				Clicksub(dep[0],main_flag);
				break;
			}
			else if(MouseBarLeft(256,160,512,260)==1)    //�������
			{
				while(MouseBarLeft(256,160,512,260)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				Clicksub(dep[1],main_flag);
				break;
			}
			else if(MouseBarLeft(512,160,768,260)==1)    //���Ƥ����
			{
				while(MouseBarLeft(512,160,768,260)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				Clicksub(dep[2],main_flag);
				break;
			}
			else if(MouseBarLeft(768,160,1023,260)==1)    //������
			{
				while(MouseBarLeft(768,160,1023,260)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				Clicksub(dep[3],main_flag);
				break;
			}
			else if(MouseBarLeft(0,260,256,360)==1)    //����ǿ�
			{
				while(MouseBarLeft(0,260,256,360)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				Clicksub(dep[4],main_flag);
				break;
			}
			else if(MouseBarLeft(256,260,512,360)==1)    //������Ǻ��
			{
				while(MouseBarLeft(256,260,512,360)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				Clicksub(dep[5],main_flag);
				break;
			}
			else if(MouseBarLeft(512,260,768,360)==1)    //��������
			{
				while(MouseBarLeft(512,260,768,360)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				Clicksub(dep[6],main_flag);
				break;
			}
			else if(MouseBarLeft(768,260,1023,360)==1)    //����ڿ�
			{
				while(MouseBarLeft(768,260,1023,360)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				Clicksub(dep[7],main_flag);

				break;
			}
			
			if(MouseCirOn(43,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"���Ƹ�ð��ҩ���ʱ�衢���������С��",24,27,0);
				Outtext(256,187,"�������ʥ�ø�ð�顢���Ÿ�ð��ȿ��α�",24,27,0);
				Outtext(256,214,"2�֡��ٷ���������Ϣʹ����˾ƥ�֡�ȥʹ",24,27,0);
				Outtext(256,241,"Ƭ�ȿ��α�һ�֡�ͬʱӦ�������±�",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(129,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"������ʹ��ҩ�ͷʹ�ɸ��������衢����",24,27,0);
				Outtext(256,187,"��ǽ��ҡ�­ʹ�����Ľ�ʹ�ɱ�����Ч����",24,27,0);
				Outtext(256,214,"����ʹ��θʹ�ɱ���654��2Ƭ��Ψ����",24,27,0);
				Outtext(256,241,"��ʹ�ɱ��ø��������衢޽���������ҵȣ�",24,27,0);
				Outtext(256,268,"��ʹ�ɱ���׳������裬�ؽ�ʹ�ɱ��÷ұ�",24,27,0);
				Outtext(256,297,"�á������ֵȡ�",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(215,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"��������ҩ�Ӧ���������ᡢ��������ù",24,27,0);
				Outtext(256,187,"�ء������ء������顢ͷ������ड�������",24,27,0);
				Outtext(256,214,"Ƭ�������ȡ�",24,27,0);
				xflag=1;
				}
			}
		    else if(MouseCirOn(301,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"��˯��ҩ�Ӧ���а���Ƭ������������­",24,27,0);
				Outtext(256,187,"ʹ�����ǰٲݰ���Ƭ������������ȡ�",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(386,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"������ҩ�Ӧ�����˶����������ܡ�����",24,27,0);
				Outtext(256,187,"����ȡ�",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(470,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"����θ������ҩ�Ӧ����޽������ˮ",24,27,0);
				Outtext(256,187,"�˵���θ�����������ء��������衢����ͣ",24,27,0);
				Outtext(256,214,"��˼�ܴ�ȡ�",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(554,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"���Ʊ���ҩ��ɱ��������衢�����衢��",24,27,0);
				Outtext(256,187,"��Ƭ�ȡ�",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(638,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"������ҩ��ɱ�����B������Һ������",24,27,0);
				Outtext(256,187,"����øƬ�ȡ�",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(723,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"����ҩ���ɱ����;��������͡��˵��ȡ�",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(809,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"����ֹʹҩ���ɱ���ʪֹʹ�ࡢֹʹ�������",24,27,0);
				Outtext(256,187,"����������ࡢ����ֹʹ�ࡢ����ֹʹ�ࡢ",24,27,0);
				Outtext(256,214,"�컨�͵ȡ�",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(895,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"�������׽ⶾҩ���紴��������ơ���ҩˮ",24,27,0);
				Outtext(256,187,"����ҩˮ��������ء�75���ƾ��Լ�����",24,27,0);
				Outtext(256,214,"ҩ�޺�ɴ�������������ӵȡ�",24,27,0);
				xflag=1;
				}
			}
			else if(MouseCirOn(981,653,43)==1)
			{
				if(xflag==0)
				{
				Bar64k(256,160,768,360,64704);
				Outtext(256,160,"�������缾��ʤ��ҩƬ���κ���������ҩˮ",24,27,0);
				Outtext(256,187,"�ȡ�",24,27,0);
				xflag=1;
				}
			}
			else
			{
				if(xflag==1)
				{
					Bar64k(256,160,768,360,26592);
					Outtext(335,184,"����",48,50,0);
					Outtext(564,184,"Ƥ����",48,50,0);
					Outtext(283,283,"���Ǻ��",48,50,0);
					Outtext(564,283,"�����",48,50,0);
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

/***�����������ҹ��ܺ���***/
void Clicksub(char *dept,int *main_flag)
{
	int i,j=0;
	int k=1;
	Doctor doc[N];	//ҽ���ṹ����
	Doctor doct[N];
	Doctor *p=doct;			//
	int page=1,lastpage;		//ҳ����Ǻ���
	int num = Docinti(doc);		//ҽ����Ϣ��ʼ��
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//������ò�������
	int mflag=1;            //���������̲�������
			
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
		Outtext(0,200,"��ҽ����:",24,25,0);
		while(1)
		{
			if(mouse_flag==0)
			{
			MouseReset();
			mouse_flag=1;																	
			}																					
																						
			MouseStatus(&mouse_new);			//��ȡ���״̬								
																							
			if(mflag==0)					
			{
				MousePutBk(mouse_old.x,mouse_old.y);	//�ָ�����굲ס���ֵ��Դ�										
			}																					
		
			else
			{																					
				mflag=0;																		
			}
			MouseStoreBk(mouse_new.x,mouse_new.y);		//�洢ͼ��							
			MouseDraw(mouse_new);						//�����
			mouse_old=mouse_new;						//��¼
			delay(50);																					
			
			//����Ч��
			if(MouseCirOn(470,174,36)==0)				//��һ������ͼ��
			{
				LightCirWiden(470,174,36,0);
			}
			else
			{
				LightCirWiden(470,174,36,2016);
			}
			
			if(MouseCirOn(987,174,36)==0)				//�ڶ�������ͼ��
			{
				LightCirWiden(987,174,36,0);
			}
			else
			{
				LightCirWiden(987,174,36,2016);
			}
			
			if(MouseCirOn(470,367,36)==0)				//����������ͼ��
			{
				LightCirWiden(470,367,36,0);
			}
			else
			{
				LightCirWiden(470,367,36,2016);
			}
			
			if(MouseCirOn(987,367,36)==0)				//���ĸ�����ͼ��
			{
				LightCirWiden(987,367,36,0);
			}
			else
			{
				LightCirWiden(987,367,36,2016);
			}
			
			if(MouseCirOn(470,556,36)==0)				//���������ͼ��
			{
				LightCirWiden(470,556,36,0);
			}
			else
			{
				LightCirWiden(470,556,36,2016);
			}
			
			if(MouseCirOn(987,556,36)==0)				//����������ͼ��
			{
				LightCirWiden(987,556,36,0);
			}
			else
			{
				LightCirWiden(987,556,36,2016);
			}
			
			
			
			if(MouseBarLeft(978,0,1024,46)==1)      //������˳���ť
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
			
				*main_flag=1;
				k=0;
				break;
			}
			else if(MouseBarLeft(0,696,265,767)==1)	//�����ҳ
			{
				while(MouseBarLeft(0,696,265,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;	
			
				*main_flag=4;
				k=0;
				Interface_pic();
				break;
			}
			
			else if(MouseBarLeft(512,696,768,767)==1)	//�����ҩ		
			{
				while(MouseBarLeft(512,696,768,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				*main_flag=7;
				k=0;
				break;
			}
			else if(MouseBarLeft(768,696,1023,767)==1)	//�����������		
			{
				while(MouseBarLeft(768,696,1023,767)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;	
			
				*main_flag=8;
				k=0;
				break;
			}
			else if((MouseBarLeft(942,659,1002,679)==1 || MouseBarLeft(1002,648,1023,690)==1) && page<lastpage)				//�����һҳ
			{
				while(MouseBarLeft(942,659,1002,679)==1|| MouseBarLeft(1002,670,1023,690)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
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
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				Outtext(136,659,"�Ѿ������һҳ�ˣ����ܼ������·���",32,35,63503);
				delay(1500);
				Bar64k(136,655,900,696,2463);			//�ָ�ԭ���ı���
				break;
			}
			else if((MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1 )&& page>1)		//�����һҳ
			{
				while(MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
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
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				Outtext(136,659,"�Ѿ��ǵ�һҳ�ˣ����ܼ������Ϸ���",32,35,63503);
				delay(1500);
				Bar64k(136,655,900,696,2463);			//�ָ�ԭ���ı���
				break;
			}
			
			else if(MouseCirLeft(470,174,36)==1&&num>0)		//�����ҳ��һ��ҽ��
			{
				while(MouseCirLeft(470,174,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				AskDoc(doct);
				break;
			}
			else if(MouseCirLeft(987,174,36)==1&&num>1)		//�����ҳ�ڶ���ҽ��
			{
				while(MouseCirLeft(987,174,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				AskDoc(doct+1);
				break;								
			}
			else if(MouseCirLeft(470,367,36)==1&&num>2)		//�����ҳ������ҽ��
			{
				while(MouseCirLeft(470,367,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				AskDoc(doct+2);
				break;						
			}
			/*else if(MouseCirLeft(987,367,36)==1&&num>3)		//�����ҳ���ĸ�ҽ��
			{
				while(MouseCirLeft(987,367,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				AskDoc(doct+3);
				break;						
			}
			else if(MouseCirLeft(470,556,36)==1&&num>4)		//�����ҳ�����ҽ��
			{
				while(MouseCirLeft(470,556,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				AskDoc(doct+4);
				break;						
			}
			else if(MouseCirLeft(987,556,36)==1&&num>5)		//�����ҳ������ҽ��
			{
				while(MouseCirLeft(987,556,36)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				AskDoc(doct+5);
				break;						
			}	*/	
		}
			
	}		 
}

	/***ҽ����Ϣ�������***/
void Docinfo1_pic(Doctor *doc,int num,int page,int lastpage)
{
	char s[64];	//���ڻ������
	int i;  		//���㱾ҳ���м���ҽ��
	int j=0;
	char *year="\0";
	if(page<lastpage)		//����������һҳ
	{
		i=6;
	}
	else if(page==lastpage)		//��������һҳ
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
	Doc_backpic();					//ҽ����Ϣ����

	if(j<i)
	{
		s[0]='\0';
		Outtext(0,96,doc->name,32,35,0);
		Outtext(150,96,doc->department,24,25,0);
		substr(s,doc->skill,0,32);
		Outtext(0,150,s,16,18,0);
		substr(s,doc->skill,32,64);
		Outtext(0,170,s,16,18,0);
		Outtext(0,200,"��ҽ����:",24,25,0);
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
		Outtext(517,200,"��ҽ����:",24,25,0);
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
		Outtext(0,389,"��ҽ����:",24,25,0);
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
		Outtext(517,389,"��ҽ����:",24,25,0);
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
		Outtext(0,568,"��ҽ����:",24,25,0);
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
		Outtext(517,568,"��ҽ����:",24,25,0);
		itoa((doc+5)->years,year,10);
		out_ASC(637,573,year,0);
		
		j++;
	}*/

}



/***ҩƷ��Ϣ��ȡ����***/
int Medinti(Medicine *medicine)
{
	char ch;
	Medicine *med=medicine;
	FILE *fp;
	
	int i,num=0;
	
	if((fp=fopen("TXT\\MEDICINE\\medicine.txt","r"))==NULL)
	{
		Outtext(391,517,"��ҩƷ�ļ�ʧ�ܣ��޷����к�������������ϵ������Ա",24,27,0x0000);
		Outtext(391,540,"��������˳�",24,27,0x0000);
		
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


/***��ҩ���湦�ܺ���***/
void Buymedicine(int *main_flag,User user,int n)
{
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;          //������ò�������
	int mflag=1;               //���������̲�������
	int *amount;
	
	Medicine med[N];	
	Medicine *p=med;
	int page=1,lastpage;
	int num = Medinti(med);
	
	
	//������ҳ��
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
																						
			MouseStatus(&mouse_new);			//��ȡ���״̬								
																							
			if(mflag==0)					
			{
				MousePutBk(mouse_old.x,mouse_old.y);	//�ָ�����굲ס���ֵ��Դ�										
			}																					
		
			else
			{																					
				mflag=0;																		
			}
			MouseStoreBk(mouse_new.x,mouse_new.y);		//�洢ͼ��							
			MouseDraw(mouse_new);						//�����
			mouse_old=mouse_new;						//��¼
			delay(50);																					
		
		//����Ч��
			if(MouseOn(186,233,255,272)==1)             //��һ�������
			{
				LightBarWiden(186,233,255,272,57344);
			}
			else
			{
				LightBarWiden(186,233,255,272,0);
			}
		
			if(MouseOn(442,233,511,272)==1)             //�ڶ��������
			{
				LightBarWiden(442,233,511,272,57344);
			}
			else
			{
				LightBarWiden(442,233,511,272,0);
			}
		
			if(MouseOn(698,233,767,272)==1)             //�����������
			{
				LightBarWiden(698,233,767,272,57344);
			}
			else
			{
				LightBarWiden(698,233,767,272,0);
			}
		
			if(MouseOn(954,233,1023,272)==1)             //���ĸ������
			{
				LightBarWiden(954,233,1023,272,57344);
			}
			else
			{
				LightBarWiden(954,233,1023,272,0);
			}
		
			if(MouseOn(186,422,255,461)==1)             //����������
			{
				LightBarWiden(186,422,255,461,57344);
			}
			else
			{
				LightBarWiden(186,422,255,461,0);
			}
		
			if(MouseOn(442,422,511,461)==1)             //�����������
			{
				LightBarWiden(442,422,511,461,57344);
			}
			else
			{
				LightBarWiden(442,422,511,461,0);
			}
		
			if(MouseOn(698,422,767,461)==1)             //���߸������
			{
				LightBarWiden(698,422,767,461,57344);
			}
			else
			{
				LightBarWiden(698,422,767,461,0);
			}
		
			if(MouseOn(954,422,1023,461)==1)             //�ڰ˸������
			{
				LightBarWiden(954,422,1023,461,57344);
			}
			else
			{
				LightBarWiden(954,422,1023,461,0);
			}
		
			if(MouseOn(186,611,255,650)==1)             //�ھŸ������
			{
				LightBarWiden(186,611,255,650,57344);
			}
			else
			{
				LightBarWiden(186,611,255,650,0);
			}
		
			if(MouseOn(442,611,511,650)==1)             //��ʮ�������
			{
				LightBarWiden(442,611,511,650,57344);
			}
			else
			{
				LightBarWiden(442,611,511,650,0);
			}
		
			if(MouseOn(698,611,767,650)==1)             //��ʮһ�������
			{
				LightBarWiden(698,611,767,650,57344);
			}
			else
			{
				LightBarWiden(698,611,767,650,0);
			}
		
			if(MouseOn(954,611,1023,650)==1)             //��ʮ���������
			{
				LightBarWiden(954,611,1023,650,57344);
			}
			else
			{
				LightBarWiden(954,611,1023,650,0);
			}
			
			if(MouseOn(186,194,255,233)==1)             //��һ�������
			{
				LightBarWiden(186,194,255,233,57344);
			}
			else
			{
				LightBarWiden(186,194,255,233,0);
			}
		
			if(MouseOn(442,194,511,233)==1)             //�ڶ��������
			{
				LightBarWiden(442,194,511,233,57344);
			}
			else
			{
				LightBarWiden(442,194,511,233,0);
			}
		
			if(MouseOn(698,194,767,233)==1)             //�����������
			{
				LightBarWiden(698,194,767,233,57344);
			}
			else
			{
				LightBarWiden(698,194,767,233,0);
			}
		
			if(MouseOn(954,194,1023,233)==1)             //���ĸ������
			{
				LightBarWiden(954,194,1023,233,57344);
			}
			else
			{
				LightBarWiden(954,194,1023,233,0);
			}
		
			if(MouseOn(186,383,255,422)==1)             //����������
			{
				LightBarWiden(186,383,255,422,57344);
			}
			else
			{
				LightBarWiden(186,383,255,422,0);
			}
		
			if(MouseOn(442,383,511,422)==1)             //�����������
			{
				LightBarWiden(442,383,511,422,57344);
			}
			else
			{
				LightBarWiden(442,383,511,422,0);
			}
		
			if(MouseOn(698,383,767,422)==1)             //���߸������
			{
				LightBarWiden(698,383,767,422,57344);
			}
			else
			{
				LightBarWiden(698,383,767,422,0);
			}
		
			if(MouseOn(954,383,1023,422)==1)             //�ڰ˸������
			{
				LightBarWiden(954,383,1023,422,57344);
			}
			else
			{
				LightBarWiden(954,383,1023,422,0);
			}
		
			if(MouseOn(186,572,255,611)==1)             //�ھŸ������
			{
				LightBarWiden(186,572,255,611,57344);
			}
			else
			{
				LightBarWiden(186,572,255,611,0);
			}
		
			if(MouseOn(442,572,511,611)==1)             //��ʮ�������
			{
				LightBarWiden(442,572,511,611,57344);
			}
			else
			{
				LightBarWiden(442,572,511,611,0);
			}
		
			if(MouseOn(698,572,767,611)==1)             //��ʮһ�������
			{
				LightBarWiden(698,572,767,611,57344);
			}
			else
			{
				LightBarWiden(698,572,767,611,0);
			}
		
			if(MouseOn(954,572,1023,611)==1)             //��ʮ���������
			{
				LightBarWiden(954,572,1023,611,57344);
			}
			else
			{
				LightBarWiden(954,572,1023,611,0);
			}
		
		
			if(MouseBarLeft(978,0,1024,46)==1)      //������˳���ť
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
			
				*main_flag=1;
				break;
			}
			else if(MouseBarLeft(314,715,592,767)==1)	//�����ҽ��
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;	
			
				*main_flag=5;
				break;
			}
		
			else if(MouseBarLeft(0,696,265,767)==1)    //�����ҳ
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;	
			
				*main_flag=4;
				break;
			}
		
		
			else if(MouseBarLeft(768,696,1023,767)==1)   //�����������
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;	
			
				*main_flag=8;
				break;
			}
		
			else if((MouseBarLeft(942,659,1002,679)==1 || MouseBarLeft(1002,648,1023,690)==1) && page<lastpage)				//�����һҳ
			{
				while(MouseBarLeft(942,659,1002,679)==1|| MouseBarLeft(1002,670,1023,690)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
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
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				Outtext(136,659,"�Ѿ������һҳ�ˣ����ܼ������·���",32,35,63503);
				delay(1500);
				Bar64k(136,655,900,710,2463);			//�ָ�ԭ���ı���
				break;
			}
			else if((MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1 )&& page>1)		//�����һҳ
			{
				while(MouseBarLeft(21,659,81,679)==1 || MouseBarLeft(0,638,21,680)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
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
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				
				Outtext(136,659,"�Ѿ��ǵ�һҳ�ˣ����ܼ������Ϸ���",32,35,63503);
				delay(1500);
				Bar64k(136,655,900,710,2463);			//�ָ�ԭ���ı���
				break;
			}
			
			else if(MouseBarLeft(186,233,255,272)==1)  //��������1
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p,&user,n);
				break;
			}
			else if(MouseBarLeft(442,233,511,272)==1)  //��������2
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+1,&user,n);
				break;
			}
			else if(MouseBarLeft(698,233,767,272)==1)  //��������3
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+2,&user,n);
				break;
			}
			else if(MouseBarLeft(954,233,1023,272)==1)  //��������4
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+3,&user,n);
				break;
			}
			else if(MouseBarLeft(186,422,255,461)==1)  //��������5
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+4,&user,n);
				break;
			}
			else if(MouseBarLeft(442,422,511,461)==1)  //��������6
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+5,&user,n);
				break;
			}
			else if(MouseBarLeft(698,422,767,461)==1)  //��������7
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+6,&user,n);
				break;
			}
			else if(MouseBarLeft(954,422,1023,461)==1)  //��������8
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+7,&user,n);
				break;
			}
			else if(MouseBarLeft(186,611,255,650)==1)  //��������9
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+8,&user,n);
				break;
			}else if(MouseBarLeft(442,611,511,650)==1)  //��������10
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+9,&user,n);
				break;
			}else if(MouseBarLeft(698,611,767,650)==1)  //��������11
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+10,&user,n);
				break;
			}
			else if(MouseBarLeft(954,611,1023,650)==1)  //��������12
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				BuyM(p+11,&user,n);
				break;
			}
			else if(MouseBarLeft(186,194,255,233)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p);
				break;
			}
			else if(MouseBarLeft(442,194,511,233)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+1);
				break;
			}
			else if(MouseBarLeft(698,194,767,233)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+2);
				break;
			}			
			else if(MouseBarLeft(954,194,1023,233)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+3);
				break;
			}	
			else if(MouseBarLeft(186,383,255,422)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+4);
				break;
			}				
			else if(MouseBarLeft(442,383,511,422)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+5);
				break;
			}				
			else if(MouseBarLeft(698,383,767,422)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+6);
				break;
			}
			else if(MouseBarLeft(954,383,1023,422)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+7);
				break;
			}
			else if(MouseBarLeft(186,572,255,611)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+8);
				break;
			}			
			else if(MouseBarLeft(442,572,511,611)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+9);
				break;
			}	
			else if(MouseBarLeft(698,572,767,611)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+10);
				break;
			}				
			else if(MouseBarLeft(954,572,1023,611)==1)
			{
				MousePutBk(mouse_old.x,mouse_old.y);  //�ָ�ԭ���
				mflag=1;
				Details_pic(p+11);
				break;
			}					
		}
	}
}

/***ҩ�������������***/
void Details_pic(Medicine *medicine)
{
	char s[64];	//���ڻ������
	int i=0;
	
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//������ò�������
	int mflag=1;            //���������̲�������	
		
	Bar64k(146,180,878,554,9284);	//����
	LightBarWiden(144,178,880,556,65465);
	
	Bar64k(827,180,878,231,57344);
	Line64k(827,180,878,231,64518);
	Line64k(827,231,878,180,64518);		//�˳�
	
	Outtext(161,205,"ҩ����",48,50,63503);
	Outtext(161,275,"���ۣ�",48,50,63503);
	Outtext(161,345,"��飺",48,50,63503);

	Bar64k(296,210,792,252,26620);		//ҩ��
	Bar64k(296,279,792,321,65504);		//����
	/*Bar64k(296,348,792,495,26620);		//�ܼ�*/
	
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
																						
		MouseStatus(&mouse_new);			//��ȡ���״̬								
																							
		if(mflag==0)					
		{
			MousePutBk(mouse_old.x,mouse_old.y);	//�ָ�����굲ס���ֵ��Դ�										
		}																					
		
		else
		{																					
			mflag=0;																		
		}
		MouseStoreBk(mouse_new.x,mouse_new.y);		//�洢ͼ��							
		MouseDraw(mouse_new);						//�����
		mouse_old=mouse_new;						//��¼
		delay(50);
		if(MouseBarLeft(827,180,878,231)==1)			//�˳���ť
		{
			while(MouseBarLeft(827,180,878,231)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);     //�ָ����
			mflag=1;
			
			break;
		}
	}
}	
	
/***ҩ����Ϣ�������***/
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
	
	Buymedicine_pic();      //��ҩ����ͼ
	
	//ҩ���������  	ҩ��۸����
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

