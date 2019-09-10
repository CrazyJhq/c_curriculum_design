/*********************************************************************************
 
		1.int MouseInit(void)
			鼠标初始化
		2.void MouseRange(int x1, int y1, int x2, int y2)
			设置鼠标移动范围
		3.int MouseStatus(MOUSE *mouse)
			读取鼠标状态，存入指定结构
		4.int MouseBarLeft(int x1, int y1, int x2, int y2)
			判断鼠标左键是否在指定位置按下
		5.void MouseStoreBk(int x, int y)
			存储被鼠标遮挡部分的显存内容
		6.void MousePutBk(int x, int y)
			恢复被鼠标挡住部分的显存
		7.void MouseReset(void)
			鼠标复位
		8.void MouseDraw(MOUSE mouse)
			画鼠标函数
			

******************************************************************/

/*****************************************************
	在dos.h中REGS的定义如下：
	struct WORDREGS
	{
		unsigned int ax, bx, cx, dx, si, di, cflag, flags;
	};
	
	struct BYTEREGS
	{
		unsigned char al, ah, bl, bh, cl, ch, dl, dh;
	};
	
	union REGS
	{
		struct WORDREGS x;
		struct BYTEREGS h;
	};
	这样al对应ax的低八位，ah对应ax的高八位，以此类推。
	调用时需要查表决定各入口参数取值,获取返回值表示的信息。
*****************************************************/



#include "head.h"
#include "SVGAmode.h"
#include "mouse.h"

int Cursor[19][12]={
	
	{2,0,0,0,0,0,0,0,0,0,0,0},
	{2,2,0,0,0,0,0,0,0,0,0,0},
	{2,1,2,0,0,0,0,0,0,0,0,0},
	{2,1,1,2,0,0,0,0,0,0,0,0},
	{2,1,1,1,2,0,0,0,0,0,0,0},
	{2,1,1,1,1,2,0,0,0,0,0,0},
	{2,1,1,1,1,1,2,0,0,0,0,0},
	{2,1,1,1,1,1,1,2,0,0,0,0},
	{2,1,1,1,1,1,1,1,2,0,0,0},
	{2,1,1,1,1,1,1,1,1,2,0,0},
	{2,1,1,1,1,1,1,1,1,1,2,0},
	{2,1,1,1,1,1,1,1,1,1,1,2},
	{2,1,1,1,1,1,1,2,2,2,2,2},
	{2,1,1,1,2,1,1,2,0,0,0,0},
	{2,1,1,2,2,1,1,2,0,0,0,0},
	{2,1,2,0,0,2,1,1,2,0,0,0},
	{2,2,0,0,0,2,1,1,2,0,0,0},
	{0,0,0,0,0,0,2,1,2,0,0,0},
	{0,0,0,0,0,0,0,2,0,0,0,0}
};								/*存储鼠标信息的二维数组*/


	

int mouse_bk[19][12]; 			/*储存被鼠标挡住部分的显存信息*/


/*鼠标初始化*/
unsigned int MouseInit(void)			
{
	union REGS mouse;
	mouse.x.ax=0;
	int86(0x33, &mouse, &mouse);
	return mouse.x.ax;
}



/*设置鼠标移动范围*/
void MouseRange(int x1, int y1, int x2, int y2)
{
	union REGS mouse;
	mouse.x.ax=7;
	mouse.x.cx=x1;
	mouse.x.dx=x2;
	int86(0x33, &mouse, &mouse);
	
	mouse.x.ax=8;
	mouse.x.cx=y1;
	mouse.x.dx=y2;
	int86(0x33, &mouse, &mouse);
}



/*读取鼠标状态，存入指定结构*/
int MouseStatus(MOUSE *mouse)	
{
		union REGS m;
		m.x.ax=3;
		int86(0x33, &m, &m);
		mouse->x=m.x.cx;
		mouse->y=m.x.dx;
		mouse->button=m.x.bx;
		return mouse->button;
}


/*判断鼠标左键是否在指定位置按下*/
int MouseBarLeft(int x1, int y1, int x2, int y2)
{
	MOUSE mouse={0,0,0};	//存放鼠标的结构体
	MouseStatus(&mouse);	//读取鼠标状态
	
	if((mouse.x>=x1)
	&&(mouse.x<=x2)
	&&(mouse.y>=y1)
	&&(mouse.y<=y2)
	&&(mouse.button & 1)==1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}


	

/*存储被鼠标遮挡部分的显存内容*/
void MouseStoreBk(int x, int y)
{
	int i,j;
	for(i=0;i<19;i++)
	{
		for(j=0;j<12;j++)
		{
			if(Cursor[i][j]!=0)
			{
				mouse_bk[i][j]=Getpixel64k(x + j, y + i);
			}
		}
	}
}


/*恢复被鼠标挡住部分的显存*/
void MousePutBk(int x, int y)
{
	int i,j;
	for(i=0;i<19;i++)
	{
		for(j=0;j<12;j++)							
		{	
			if(Cursor[i][j]!=0)
			{
				Putpixel64k(x + j, y + i,mouse_bk[i][j]);
			}
		}
	}
}



/*鼠标复位*/
void MouseReset(void)
{
	if(MouseInit() != 0xffff)
	{
		printf("Error MouseInit!\n");
		getch();
		exit(1);
	}
	MouseRange(0,0, SCR_WIDTH-1, SCR_HEIGHT-1);
	MouseStoreBk(0,0);
}


/*画鼠标函数*/
void MouseDraw(MOUSE mouse)
{
	int i,j;
	for(i=0;i<19;i++)
	{
		for(j=0;j<12;j++)
		{	
			if(Cursor[i][j]==0)
			{
				continue;
			}
			else if(Cursor[i][j]==1)
			{
				Putpixel64k(mouse.x+j,mouse.y+i,65003);
			}
			else if(Cursor[i][j]==2)
			{
				Putpixel64k(mouse.x+j,mouse.y+i,0);
			}
		}
	}
}

/*判断鼠标是否在指定位置上方*/
int MouseOn(int x1,int y1,int x2,int y2)
{
	MOUSE mouse={0,0,0};	//存放鼠标的结构体
	MouseStatus(&mouse);	//读取鼠标状态
	if(mouse.x>=x1&&mouse.x<=x2&&mouse.y>=y1&&mouse.y<=y2)
	return 1;
    else
	return 0;
}


/*判断鼠标是否在指定圆上方*/
int MouseCirOn(int x,int y,unsigned int r)
{
	MOUSE mouse={0,0,0};	//存放鼠标的结构体
	MouseStatus(&mouse);	//读取鼠标状态
	
	if((x-r)<mouse.x
	&&mouse.x<(x+r)
	&&(y-r)<mouse.y
	&&mouse.y<(y+r))
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

/*判断鼠标是否在某圆上按下*/
int MouseCirLeft(int x,int y,unsigned int r)
{
	MOUSE mouse={0,0,0};	//存放鼠标的结构体
	MouseStatus(&mouse);	//读取鼠标状态
	
	if((x-r)<mouse.x
	&&mouse.x<(x+r)
	&&(y-r)<mouse.y
	&&mouse.y<(y+r)
	&&(mouse.button & 1)==1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

