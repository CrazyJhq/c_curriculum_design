/*********************************************************************************

Description: �����ı��Ի���

		
******************************************************************/
#include "head.h"
#include "SVGAmode.h"
#include "outtext.h"
#include "function.h"
#include "module.h"

	/***���ı���ָ��λ��������̼�����ַ�***/
void textbox(int x1, int y1, int x2, int y2,int offset, int mode, char *str)
{
	int n1=x1+offset;   //�߽����
	int n=0;
	char ka[2]=" ";
	y2++;
	while(bioskey(1))
	{
			getch();
	}												//������̻�����
	switch(mode)
	{	
		case 1:										//mode 1��Ӧ��Ϊ��ͨ����
		{
			
			while((ka[0]=bioskey(0))!=0x0D)			//���벻�ǻس�
			{
				
				if((n1>=x1+offset)
					&& (n1<(x2-offset))
					
					&& 	(ka[0]!=0x08)					//���µĲ����˸��
					)
				{
					out_ASCplus(n1,y1+10,ka,0);
					str[n]=ka[0];
					n1+=20;
					n++;
				}
				else if(ka[0]==0x08)		//��������˸��
				{
					
					if(n1>x1+offset)			//��ֹ���ǹ���
					{	
						n1-=20;	
						Bar64k(n1,y1+2,n1+20,y1+33,0xffff);
						if(n>0)
						{
							str[n]='\0';
							n--;	
						}
						else
						{
							n=0;
						}
					}
				}	
			}
			str[n]='\0';
			break;
		}
	

		case 2:									//mode 2��Ӧ������������
		{
			
			while((ka[0]=bioskey(0))!=0x0D )		//���벻�ǻس����Ҳ���Խ��
			{
				
				if((n1>=x1+offset)
					&& (n1<(x2-offset))
					&& 	(ka[0]!=0x08)					//���µĲ����˸��
					)
				{
					out_ASCplus(n1,y1+10,"*",0);
					str[n]=ka[0];
					n1+=20;
					n++;
				}
				else if(ka[0]==0x08)		//��������˸��
				{	
					
					if(n1>x1+offset)				//��ֹ���ǹ���
					{	
						n1-=20;
						Bar64k(n1,y1+2,n1+20,y1+33,0xffff);
						if(n>0)
						{
							str[n]='\0';
							n--;
						}
						else
						{
							n=0;
						}
					}
				}
			}
			str[n]='\0';
			break;
		}
	}

}

/***�����ַ����ı�������***/
void Charbox(int x, int y ,char *s)
{
	int n=x+10;
	
	char ka[2]="";
	
	while (bioskey(1))		//������̻���������
	{
		getch();
	}
	
	while ((ka[0] = bioskey(0)) != 0x0D)
	{
		if	( ka[0] != 0x08 )
		{
			Bar64k(n,y,n+20,y+37,0xffff);
			out_ASCplus(n,y+10,ka,0x0000);
			*s = ka[0];
		}
		else if( ka[0] == 0x08 )
		{
			Bar64k(n,y,n+18,y+37,0xffff);
		}
	}
}


/***����ɫ�߿���***/
void LightBar(int x1, int y1, int x2 ,int y2 ,int color)
{
	Line64k(x1+2, y1+2, x2-2, y1+2,color);			//���ϲ�ˮƽֱ��
	Line64k(x1+2, y1+2, x1+2, y2-2,color);			//�������ֱֱ��
	Line64k(x1+2, y2-2, x2-2, y2-2,color);			//���²�ˮƽֱ��
	Line64k(x2-2, y2-2, x2-2, y1+2,color);			//���Ҳ���ֱֱ��
}



/***�ӿ�滭��ɫ�߿���***/
void LightBarWiden(int x1, int y1, int x2 ,int y2 ,int color)
{
	Line64k(x1+1, y1+1, x2-1, y1+1,color);			//���ϲ�ˮƽֱ��
	Line64k(x1+1, y1+1, x1+1, y2-1,color);			//�������ֱֱ��
	Line64k(x1+1, y2-1, x2-1, y2-1,color);			//���²�ˮƽֱ��
	Line64k(x2-1, y2-1, x2-1, y1+1,color);			//���Ҳ���ֱֱ��
	
	Line64k(x1+2, y1+2, x2-2, y1+2,color);			//���ϲ�ˮƽֱ��
	Line64k(x1+2, y1+2, x1+2, y2-2,color);			//�������ֱֱ��
	Line64k(x1+2, y2-2, x2-2, y2-2,color);			//���²�ˮƽֱ��
	Line64k(x2-2, y2-2, x2-2, y1+2,color);			//���Ҳ���ֱֱ��
}

/***�ӿ�滭Բ��ɫ�߿���***/
void LightCirWiden(int x,int y,int r,int color)
{
	int i;
	for(i=0;i<3;i++)
	{
		Circle64k(x,y,r+i,color);
	}
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		