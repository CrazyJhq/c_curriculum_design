/*********************************************************************************
Description: ���ֿ�



******************************************************************/

#include "head.h"
#include "SVGAmode.h"
#include "outtext.h"


/*********************************************************
���ú���
	void Putpixel64k(int x, int y, unsigned char color);
	
**************************************************/
void Outtext(int x,int y, char *s, int size, int part, int color)
{
	FILE *hzk_p;
	unsigned char quma,weima;	
	unsigned long offset;		
	int i,j,pos;
	int shift;
	unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	
	switch(size)
	{
		case 16:
			{			
				char mat[32];													//����32�ֽڵ��ַ����鴢����Ϣ
				hzk_p=fopen("HZK\\HZK16.dat","rb");					//�򿪺��ֿ��ļ�
				
				if(hzk_p==NULL)
				{
					printf("\n Can't open file HZK ! Press any key to return.");
					getch();
					exit(1);
				}
				while(*s!='\0')													//���ַ���û�н���ʱ
				{
				
					if(*s>0&&*s<127)//����ַ����г��ַ�����
					{
						weima=*s-32;//��ȡλ��
						offset=(94*2+weima-1)*32l;
						shift=1;
					}
					else
					{
						quma=s[0]-128-32;
						weima=s[1]-128-32;											//������λ��
						offset=(94 * (quma-1) + (weima-1)) * 32L;
						shift=2;
					}
					fseek(hzk_p,offset,0);
					fread(mat,32,1,hzk_p);
					for(i=0;i<16;i++)
					{
						pos=2*i;
						for(j=0;j<16;j++)
						{
							if(( mask[j%8]&mat[pos+j/8] ) != NULL)
								Putpixel64k(x + j ,y + i ,color);		
						}
					
					}
					s+=shift;
					x+=part;
						
				}
				fclose(hzk_p);
				break;
			}
			
			
			
			
			
		case 24:
			{		
					char mat[72];
					hzk_p=fopen("HZK\\HZK24.dat","rb");
					if(hzk_p==NULL)
					{
						printf("\n Can't open file HZK ! Press any key to return.");
						getch();
						exit(1);
					}
					while(*s!='\0')
					{
						if(*s>0&&*s<127)//����ַ����г��ַ�����
						{
							weima=*s-32;//��ȡλ��
							offset=(94*2+weima-1)*72l;
							shift=1;
						}
						else
						{
							quma=s[0]-128-32;
							weima=s[1]-128-32;
							offset=(94 * (quma-1) + (weima-1)) * 72L;
							shift=2;
						}
						fseek(hzk_p,offset,0);
						fread(mat,72,1,hzk_p);
						for(i=0;i<24;i++)
						{
							pos=3*i;
							for(j=0;j<24;j++)
							{
								if(( mask[j%8]&mat[pos+j/8] ) != NULL)
									Putpixel64k(x + j ,y + i  ,color);		
							}
						
						}
						s+=shift;
						x+=part;
							
					}
					fclose(hzk_p);
					break;
			
			}
				
		case 32:
			{		
					char mat[128];
					hzk_p=fopen("HZK\\HZK32K","rb");
					if(hzk_p==NULL)
					{
						printf("\n Can't open file HZK ! Press any key to return.");
						getch();
						exit(1);
					}
					while(*s!='\0')
					{
						if(*s>0&&*s<127)//����ַ����г��ַ�����
						{
							weima=*s-32;//��ȡλ��
							offset=(94*2+weima-1)*128l;
							shift=1;
						}
						else
						{
							quma=s[0]-128-32;
							weima=s[1]-128-32;
							offset=(94 * (quma-1) + (weima-1)) * 128L;
							shift=2;
						}
						fseek(hzk_p,offset,0);
						fread(mat,128,1,hzk_p);
						for(i=0;i<32;i++)
						{
							pos=4*i;
							for(j=0;j<32;j++)
							{
								if(( mask[j%8]&mat[pos+j/8] ) != NULL)
									Putpixel64k(x + j ,y + i  ,color);			
						
							}
						}
						s+=shift;
						x+=part;
							
					}
					fclose(hzk_p);
					break;
			}
			
		
			
		case 48:
			{		
				char mat[288];
				hzk_p=fopen("HZK\\HZK48K","rb");
				if(hzk_p==NULL)
				{
					printf("\n Can't open file HZK ! Press any key to return.");
					getch();
					exit(1);
				}
				while(*s!='\0')
				{
					if(*s>0&&*s<127)//����ַ����г��ַ�����
					{
						weima=*s-32;//��ȡλ��
						offset=(94*2+weima-1)*288l;
						shift=1;
					}
					else
					{
						quma=s[0]-128-32;
						weima=s[1]-128-32;
						offset=(94 * (quma-1) + (weima-1)) * 288L;
						shift=2;
					}
					fseek(hzk_p,offset,0);
					fread(mat,288,1,hzk_p);
					for(i=0;i<48;i++)
					{
						pos=6*i;
						for(j=0;j<48;j++)
						{
							if(( mask[j%8]&mat[pos+j/8] ) != NULL)
								Putpixel64k(x + j ,y + i  ,color);		
						}
					}
					s+=shift;
					x+=part;
						
				}
				fclose(hzk_p);
				break;
			}
	}
}

void out_ASC(int x, int y, char *s, int color)
{
	FILE *hzk_p;
	unsigned long offset;		
	int i,j;
	char mat[16];													//����32�ֽڵ��ַ����鴢����Ϣ
	hzk_p=fopen("HZK\\ASC16","rb");					//�򿪺��ֿ��ļ�
	if(hzk_p==NULL)
	{
		printf("\n Can't open file HZK ! Press any key to return.");
		getch();
		exit(1);
	}
	while(*s!='\0')
	{
		offset=(*s)*16+1;			 //������ַ����ֿ���ƫ����
		fseek(hzk_p,offset,SEEK_SET);
		fread(mat,16,1,hzk_p); 			//ȡ���ַ�16�ֽڵĵ�����ģ����buffer��
		for(i=0;i<16;i++)
		{
			for(j=0;j<8;j++)
			{
				if(((mat[i]>>(7-j))&0x1)!=NULL)
				{
					Putpixel64k(x+j,y+i,color);
				}
			}
		}

		s++; //һ���ַ�����ռ��һ���ֽ�
		x+=8;//�ַ�����
	}	
	fclose(hzk_p);
	
		
}


void out_ASCplus(int x, int y, char *s, int color)
{
	FILE *hzk_p;
	unsigned long offset;		
	int i,j,m,n;
	char mat[16];													//����32�ֽڵ��ַ����鴢����Ϣ
	hzk_p=fopen("HZK\\ASC16","rb");					//�򿪺��ֿ��ļ�
	if(hzk_p==NULL)
	{
		printf("\n Can't open file HZK ! Press any key to return.");
		getch();
		exit(1);
	}
	while(*s!='\0')
	{
		offset=(*s)*16+1;			 //������ַ����ֿ���ƫ����
		fseek(hzk_p,offset,SEEK_SET);
		fread(mat,16,1,hzk_p); 			//ȡ���ַ�16�ֽڵĵ�����ģ����buffer��
		for(i=0;i<16;i++)
		{
			for(j=0;j<8;j++)
			{
				if(((mat[i]>>(7-j))&0x1)!=NULL)
				{
					for(m=0;m<2;m++)
					{
						for(n=0;n<2;n++)
						{
								Putpixel64k(x + j * 2 + m,y + i * 2 + n,color);
						}
					}
				}
			}
		}

		s++; //һ���ַ�����ռ��һ���ֽ�
		x+=20;//�ַ�����
	}	
	fclose(hzk_p);
	
}