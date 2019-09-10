/*********************************************************************************

Description: 输入文本对话框

		
******************************************************************/
#include "head.h"
#include "SVGAmode.h"
#include "outtext.h"
#include "function.h"
#include "module.h"

	/***在文本框指定位置输出键盘键入的字符***/
void textbox(int x1, int y1, int x2, int y2,int offset, int mode, char *str)
{
	int n1=x1+offset;   //边界参数
	int n=0;
	char ka[2]=" ";
	y2++;
	while(bioskey(1))
	{
			getch();
	}												//清除键盘缓存区
	switch(mode)
	{	
		case 1:										//mode 1对应的为普通输入
		{
			
			while((ka[0]=bioskey(0))!=0x0D)			//输入不是回车
			{
				
				if((n1>=x1+offset)
					&& (n1<(x2-offset))
					
					&& 	(ka[0]!=0x08)					//按下的不是退格键
					)
				{
					out_ASCplus(n1,y1+10,ka,0);
					str[n]=ka[0];
					n1+=20;
					n++;
				}
				else if(ka[0]==0x08)		//如果按下退格键
				{
					
					if(n1>x1+offset)			//防止覆盖过度
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
	

		case 2:									//mode 2对应的是密码输入
		{
			
			while((ka[0]=bioskey(0))!=0x0D )		//输入不是回车并且不会越界
			{
				
				if((n1>=x1+offset)
					&& (n1<(x2-offset))
					&& 	(ka[0]!=0x08)					//按下的不是退格键
					)
				{
					out_ASCplus(n1,y1+10,"*",0);
					str[n]=ka[0];
					n1+=20;
					n++;
				}
				else if(ka[0]==0x08)		//如果按下退格键
				{	
					
					if(n1>x1+offset)				//防止覆盖过度
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

/***单个字符的文本框的输出***/
void Charbox(int x, int y ,char *s)
{
	int n=x+10;
	
	char ka[2]="";
	
	while (bioskey(1))		//清除键盘缓存区缓存
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


/***画亮色边框函数***/
void LightBar(int x1, int y1, int x2 ,int y2 ,int color)
{
	Line64k(x1+2, y1+2, x2-2, y1+2,color);			//画上侧水平直线
	Line64k(x1+2, y1+2, x1+2, y2-2,color);			//画左侧竖直直线
	Line64k(x1+2, y2-2, x2-2, y2-2,color);			//画下侧水平直线
	Line64k(x2-2, y2-2, x2-2, y1+2,color);			//画右侧竖直直线
}



/***加宽版画亮色边框函数***/
void LightBarWiden(int x1, int y1, int x2 ,int y2 ,int color)
{
	Line64k(x1+1, y1+1, x2-1, y1+1,color);			//画上侧水平直线
	Line64k(x1+1, y1+1, x1+1, y2-1,color);			//画左侧竖直直线
	Line64k(x1+1, y2-1, x2-1, y2-1,color);			//画下侧水平直线
	Line64k(x2-1, y2-1, x2-1, y1+1,color);			//画右侧竖直直线
	
	Line64k(x1+2, y1+2, x2-2, y1+2,color);			//画上侧水平直线
	Line64k(x1+2, y1+2, x1+2, y2-2,color);			//画左侧竖直直线
	Line64k(x1+2, y2-2, x2-2, y2-2,color);			//画下侧水平直线
	Line64k(x2-2, y2-2, x2-2, y1+2,color);			//画右侧竖直直线
}

/***加宽版画圆亮色边框函数***/
void LightCirWiden(int x,int y,int r,int color)
{
	int i;
	for(i=0;i<3;i++)
	{
		Circle64k(x,y,r+i,color);
	}
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		