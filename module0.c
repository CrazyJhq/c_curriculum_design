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


/***问诊函数***/
void AskDoc(Doctor *doc)
{
	FILE *fp;
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量
	
	int b;		//科室选择参数
	
	Ask_pic(doc);
	delay(100);
	
	
	
	if(strcmp((doc->department),"儿科")==0)		//如果医生为儿科医生
	{
		erke_pic();
		b=1;
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
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			else if(MouseBarLeft(301,685,723,754)==1)		//点击结束问诊
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				OverAsk_pic();
				
				delay(1500);
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			if(MouseBarLeft(0,469,256,569)==1)				//如果点击发烧
			{
				while(MouseBarLeft(0,469,256,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(1,b,doc);
				break;
			}
			else if(MouseBarLeft(256,469,512,569)==1)		//点击感冒
			{
				while(MouseBarLeft(256,469,512,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(2,b,doc);
				break;
			}
			else if(MouseBarLeft(512,469,768,569)==1)		//点击拉肚子
			{
				while(MouseBarLeft(512,469,768,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(3,b,doc);
				break;
			}
			else if(MouseBarLeft(768,469,1023,569)==1)		//点击生长迟缓
			{
				while(MouseBarLeft(768,469,1023,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(4,b,doc);
				break;
			}
		}
		
	}
	/*
	else if(strcmp((doc->department),"妇科")==0)		//如果医生为妇科医生
	{
		fuke_pic();
		b=2;
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
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			else if(MouseBarLeft(301,685,723,754)==1)		//点击结束问诊
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				Bar64k(167,171,857,629,26620);
				LightBarWiden(167,171,857,629,0);
				Outtext(283,224,"谢谢您的问诊，希望",48,50,0);
				Outtext(281,281,"您能感到满意！",48,50,0);
				Outtext(354,402,"祝您早日康复！",48,50,0);
				Outtext(453,514,"拜拜！",48,50,0);
				
				delay(1500);
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			if(MouseBarLeft(0,469,256,569)==1)				//点击第一个症状
			{
				while(MouseBarLeft(0,469,256,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(1,b);
				break;
			}
			else if(MouseBarLeft(256,469,512,569)==1)		//点击第二个症状
			{
				while(MouseBarLeft(256,469,512,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(2,b);
				break;
			}
			else if(MouseBarLeft(512,469,768,569)==1)		//点击第三个症状
			{
				while(MouseBarLeft(512,469,768,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(3,b);
				break;
			}
			else if(MouseBarLeft(768,469,1023,569)==1)		//点击第四个症状
			{
				while(MouseBarLeft(768,469,1023,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(4,b);
				break;
			}
	
		}
		
	}
	else if(strcmp((doc->department),"皮肤科")==0)		//如果医生为皮肤科医生
	{
		skin_pic();
		b=3;
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
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			else if(MouseBarLeft(301,685,723,754)==1)		//点击结束问诊
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				Bar64k(167,171,857,629,26620);
				LightBarWiden(167,171,857,629,0);
				Outtext(283,224,"谢谢您的问诊，希望",48,50,0);
				Outtext(281,281,"您能感到满意！",48,50,0);
				Outtext(354,402,"祝您早日康复！",48,50,0);
				Outtext(453,514,"拜拜！",48,50,0);
				
				delay(1500);
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			if(MouseBarLeft(0,469,256,569)==1)				//点击第一个症状
			{
				while(MouseBarLeft(0,469,256,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(1,b);
				break;
			}
			else if(MouseBarLeft(256,469,512,569)==1)		//点击第二个症状
			{
				while(MouseBarLeft(256,469,512,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(2,b);
				break;
			}
			else if(MouseBarLeft(512,469,768,569)==1)		//点击第三个症状
			{
				while(MouseBarLeft(512,469,768,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(3,b);
				break;
			}
			else if(MouseBarLeft(768,469,1023,569)==1)		//点击第四个症状
			{
				while(MouseBarLeft(768,469,1023,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(4,b);
				break;
			}
		}
		
	}
	else if(strcmp((doc->department),"骨科")==0)		//如果医生为骨科医生
	{
		bone_pic();
		b=4;
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
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			else if(MouseBarLeft(301,685,723,754)==1)		//点击结束问诊
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				Bar64k(167,171,857,629,26620);
				LightBarWiden(167,171,857,629,0);
				Outtext(283,224,"谢谢您的问诊，希望",48,50,0);
				Outtext(281,281,"您能感到满意！",48,50,0);
				Outtext(354,402,"祝您早日康复！",48,50,0);
				Outtext(453,514,"拜拜！",48,50,0);
				
				delay(1500);
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			if(MouseBarLeft(0,469,256,569)==1)				//点击第一个症状
			{
				while(MouseBarLeft(0,469,256,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(1,b);
				break;
			}
			else if(MouseBarLeft(256,469,512,569)==1)		//点击第二个症状
			{
				while(MouseBarLeft(256,469,512,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(2,b);
				break;
			}
			else if(MouseBarLeft(512,469,768,569)==1)		//点击第三个症状
			{
				while(MouseBarLeft(512,469,768,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(3,b);
				break;
			}
			else if(MouseBarLeft(768,469,1023,569)==1)		//点击第四个症状
			{
				while(MouseBarLeft(768,469,1023,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(4,b);
				break;
			}
		}
		
	}
	else if(strcmp((doc->department),"耳鼻喉科")==0)		//如果医生为耳鼻喉科医生
	{
		erbihou_pic();
		b=5;
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
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			else if(MouseBarLeft(301,685,723,754)==1)		//点击结束问诊
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				OverAsk_pic();
				
				delay(1500);
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			if(MouseBarLeft(0,469,256,569)==1)				//点击第一个症状
			{
				while(MouseBarLeft(0,469,256,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(1,b);
				break;
			}
			else if(MouseBarLeft(256,469,512,569)==1)		//点击第二个症状
			{
				while(MouseBarLeft(256,469,512,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(2,b);
				break;
			}
			else if(MouseBarLeft(512,469,768,569)==1)		//点击第三个症状
			{
				while(MouseBarLeft(512,469,768,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(3,b);
				break;
			}
			else if(MouseBarLeft(768,469,1023,569)==1)		//点击第四个症状
			{
				while(MouseBarLeft(768,469,1023,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(4,b);
				break;
			}
		}
		
	}
	else if(strcmp((doc->department),"心理咨询师")==0)		//如果医生为心理科医生
	{
		xinli_pic();
		b=6;
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
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			else if(MouseBarLeft(301,685,723,754)==1)		//点击结束问诊
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				OverAsk_pic();
				
				delay(1500);
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			if(MouseBarLeft(0,469,256,569)==1)				//点击第一个症状
			{
				while(MouseBarLeft(0,469,256,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(1,b);
				break;
			}
			else if(MouseBarLeft(256,469,512,569)==1)		//点击第二个症状
			{
				while(MouseBarLeft(256,469,512,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(2,b);
				break;
			}
			else if(MouseBarLeft(512,469,768,569)==1)		//点击第三个症状
			{
				while(MouseBarLeft(512,469,768,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(3,b);
				break;
			}
			else if(MouseBarLeft(768,469,1023,569)==1)		//点击第四个症状
			{
				while(MouseBarLeft(768,469,1023,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(4,b);
				break;
			}
		}
		
	}
	else if(strcmp((doc->department),"普内科")==0)		//如果医生为普内科医生
	{
		neike_pic();
		b=7;
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
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			else if(MouseBarLeft(301,685,723,754)==1)		//点击结束问诊
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				OverAsk_pic();
				
				delay(1500);
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			if(MouseBarLeft(0,469,256,569)==1)				//点击第一个症状
			{
				while(MouseBarLeft(0,469,256,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(1,b);
				break;
			}
			else if(MouseBarLeft(256,469,512,569)==1)		//点击第二个症状
			{
				while(MouseBarLeft(256,469,512,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(2,b);
				break;
			}
			else if(MouseBarLeft(512,469,768,569)==1)		//点击第三个症状
			{
				while(MouseBarLeft(512,469,768,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(3,b);
				break;
			}
			else if(MouseBarLeft(768,469,1023,569)==1)		//点击第四个症状
			{
				while(MouseBarLeft(768,469,1023,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(4,b);
				break;
			}
		}
		
	}
	else if(strcmp((doc->department),"普外科")==0)		//如果医生为普外科医生
	{
		waike_pic();
		b=8;
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
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			else if(MouseBarLeft(301,685,723,754)==1)		//点击结束问诊
			{
				while(MouseBarLeft(978,0,1024,46)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				OverAsk_pic();
				
				delay(1500);
				
				SelectDoc_pic();
			
				delay(100);
				break;
			}
			if(MouseBarLeft(0,469,256,569)==1)				//点击第一个症状
			{
				while(MouseBarLeft(0,469,256,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(1,b);
				break;
			}
			else if(MouseBarLeft(256,469,512,569)==1)		//点击第二个症状
			{
				while(MouseBarLeft(256,469,512,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(2,b);
				break;
			}
			else if(MouseBarLeft(512,469,768,569)==1)		//点击第三个症状
			{
				while(MouseBarLeft(512,469,768,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
				
				ke(3,b);
				break;
			}
			else if(MouseBarLeft(768,469,1023,569)==1)		//点击第四个症状
			{
				while(MouseBarLeft(768,469,1023,569)==1)
				{
				}
				MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
				mflag=1;
		
				ke(4,b);
				break;
			}
		}
		
		
	}
	*/

}


/***问诊问题***/
void ke(int a,int b,Doctor *doc)
{
	FILE *fp;
	char ch,*aa;
	Sym sym;
	Resu res;
	char *p=NULL;
	
	
	if(b==1)
	{
		strcpy(p,"");
		strcpy(p,"TXT\\depart\\erke.txt");
	}
	else if(b==2)
	{
		strcpy(p,"");
		strcpy(p,"TXT\\depart\\fuke.txt");
	}
	else if(b==3)
	{
		strcpy(p,"");
		strcpy(p,"TXT\\depart\\pifuke.txt");
	}
	else if(b==4)
	{
		strcpy(p,"");
		strcpy(p,"TXT\\depart\\guke.txt");
	}
	else if(b==5)
	{
		strcpy(p,"");
		strcpy(p,"TXT\\depart\\erbike.txt");
	}
	else if(b==6)
	{
		strcpy(p,"");
		strcpy(p,"TXT\\depart\\xinlike.txt");
	}
	else if(b==7)
	{
		strcpy(p,"");
		strcpy(p,"TXT\\depart\\neike.txt");
	}
	else if(b==8)
	{
		strcpy(p,"");
		strcpy(p,"TXT\\depart\\waike.txt");
	}

	//Outtext(0,0,p,48,50,0);
	if((fp = fopen(p,"rt"))==NULL)
	{
		Outtext(391,517,"打开文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出程序",24,27,0x0000);
					
		while(bioskey(1))
		{
			getch();
		}
					
		getch();
					
		exit(1);
	}
	aa=itoa(a,aa,10);
	Bar64k(277,350,896,437,65269);		//用户对话框
	//选择栏
	Bar64k(0,469,256,569,26620);		//第一个选择框
	Bar64k(256,469,512,569,34847);		//第二个选择框
	Bar64k(512,469,768,569,64704);		//第三个选择框
	Bar64k(768,469,1023,569,2016);		//第四个选择框
	Bar64k(0,569,256,669,2016);			//第五个选择框
	Bar64k(256,569,512,669,64704);		//第六个选择框
	Bar64k(512,569,768,669,26620);		//第七个选择框
	Bar64k(768,569,1023,669,34847);		//第八个选择框
	
	delay(100);
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if(ch=='*')
		{
			ch=fgetc(fp);
			if(ch == aa[0])
			{
				/*fscanf(fp,"%s\n%s\n%s\n%s %s %s %s\n%s %s %s %s\n",(&sym)->user1,
				(&sym)->doc1,(&sym)->doc2,(&sym)->sym1,(&sym)->sym2,(&sym)->sym3,
				(&sym)->sym4,(&sym)->sym5,(&sym)->sym6,(&sym)->sym7,(&sym)->sym8);*/
				fscanf(fp,"%s\n",(&sym)->user1);
				fscanf(fp,"%s\n",(&sym)->doc1);
				fscanf(fp,"%s\n",(&sym)->doc2);
				fscanf(fp,"%s %s %s %s\n",(&sym)->sym1,(&sym)->sym2,(&sym)->sym3,(&sym)->sym4);
				fscanf(fp,"%s %s %s %s\n",(&sym)->sym5,(&sym)->sym6,(&sym)->sym7,(&sym)->sym8);
				/*fscanf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
				(&res)->res1,(&res)->res2,(&res)->res3,(&res)->res4,(&res)->res5,
				(&res)->res6,(&res)->res7,(&res)->res8,(&res)->res9,(&res)->res10,
				(&res)->res11,(&res)->res12,(&res)->res13,(&res)->res14,(&res)->res15,
				(&res)->res16);*/
				fscanf(fp,"%s\n",(&res)->res1);
				fscanf(fp,"%s\n",(&res)->res2);
				fscanf(fp,"%s\n",(&res)->res3);
				fscanf(fp,"%s\n",(&res)->res4);
				fscanf(fp,"%s\n",(&res)->res5);
				fscanf(fp,"%s\n",(&res)->res6);
				fscanf(fp,"%s\n",(&res)->res7);
				fscanf(fp,"%s\n",(&res)->res8);
				fscanf(fp,"%s\n",(&res)->res9);
				fscanf(fp,"%s\n",(&res)->res10);
				fscanf(fp,"%s\n",(&res)->res11);
				fscanf(fp,"%s\n",(&res)->res12);
				fscanf(fp,"%s\n",(&res)->res13);
				fscanf(fp,"%s\n",(&res)->res14);
				fscanf(fp,"%s\n",(&res)->res15);
				fscanf(fp,"%s\n",(&res)->res16);
				
				break;
			}
		}
	}
	fclose(fp);
	free(p);
	p=NULL;
	if(ferror(fp)!=0)
	{
		Outtext(391,517,"打开文件失败，无法进行后续操作，请联系开发人员",24,27,0x0000);
		Outtext(391,540,"按任意键退出程序",24,27,0x0000);
					
		while(bioskey(1))
		{
			getch();
		}
					
		getch();
					
		exit(1);
	}
	kesmy(sym,res,doc);
	memset(&sym,'\0',sizeof(sym));
	memset(&res,'\0',sizeof(res));
}


/***科室问题***/
void kesmy(Sym sym,Resu res,Doctor *doc)
{
	MOUSE mouse_new,mouse_old;
	int mouse_flag=0;		//鼠标重置参数变量
	int mflag=1;            //鼠标操作过程参数变量
	
	int i=0,j=0,a=0,b=0,c=0;			//相应参数
	
	Bar64k(277,350,896,437,65269);					//用户对话框
	Outtext(280,354,(&sym)->user1,48,50,0);		//用户对话内容
	delay(1000);
	Bar64k(121,210,814,325,64704);					//医生对话框
	Outtext(130,215,(&sym)->doc1,32,35,0);
	Outtext(130,260,(&sym)->doc2,32,35,0);
	Outtext(40,501,(&sym)->sym1,32,35,0);
	Outtext(305,501,(&sym)->sym2,32,35,0);
	Outtext(546,501,(&sym)->sym3,32,35,0);
	Outtext(828,501,(&sym)->sym4,32,35,0);
	Outtext(80,596,(&sym)->sym5,32,35,0);
	Outtext(327,596,(&sym)->sym6,32,35,0);
	Outtext(584,596,(&sym)->sym7,32,35,0);
	Outtext(829,596,(&sym)->sym8,32,35,0);
	
	delay(100);
	while(c==0)
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
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			SelectDoc_pic();
		
			delay(100);
			break;
		}
		else if(MouseBarLeft(301,685,723,754)==1)		//点击结束问诊
		{
			while(MouseBarLeft(978,0,1024,46)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			OverAsk_pic();
							
			delay(1500);
		
			SelectDoc_pic();			
			delay(100);
			break;
		}
		if(MouseBarLeft(0,469,256,569)==1)							//点击37~38
		{
			while(MouseBarLeft(0,469,256,569)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Outtext(40,501,(&sym)->sym1,32,35,63503);
			Outtext(305,501,(&sym)->sym2,32,35,0);
			Outtext(546,501,(&sym)->sym3,32,35,0);
			Outtext(828,501,(&sym)->sym4,32,35,0);
			
			i=1;
			j=1;
		}
		else if(MouseBarLeft(256,469,512,569)==1)					//点击38~39
		{
			while(MouseBarLeft(256,469,512,569)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Outtext(40,501,(&sym)->sym1,32,35,0);
			Outtext(305,501,(&sym)->sym2,32,35,63503);
			Outtext(546,501,(&sym)->sym3,32,35,0);
			Outtext(828,501,(&sym)->sym4,32,35,0);
			
			i=1;
			j=2;
		}
		else if(MouseBarLeft(512,469,768,569)==1)					//点击39~40
		{
			while(MouseBarLeft(512,469,768,569)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Outtext(40,501,(&sym)->sym1,32,35,0);
			Outtext(305,501,(&sym)->sym2,32,35,0);
			Outtext(546,501,(&sym)->sym3,32,35,63503);
			Outtext(828,501,(&sym)->sym4,32,35,0);
			
			i=1;
			j=3;
		}
		else if(MouseBarLeft(768,469,1023,569)==1)					//点击40+
		{
			while(MouseBarLeft(768,469,1023,569)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Outtext(40,501,(&sym)->sym1,32,35,0);
			Outtext(305,501,(&sym)->sym2,32,35,0);
			Outtext(546,501,(&sym)->sym3,32,35,0);
			Outtext(828,501,(&sym)->sym4,32,35,63503);
			
			i=1;
			j=4;
		}
		if(MouseBarLeft(0,569,256,669)==1)							//点击精神正常
		{
			while(MouseBarLeft(0,569,256,669)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Outtext(80,596,(&sym)->sym5,32,35,63503);
			Outtext(327,596,(&sym)->sym6,32,35,0);
			Outtext(584,596,(&sym)->sym7,32,35,0);
			Outtext(829,596,(&sym)->sym8,32,35,0);
			
			a=1;
			b=1;
		}
		else if(MouseBarLeft(256,569,512,669)==1)					//点击精神呆滞
		{
			while(MouseBarLeft(256,569,512,669)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Outtext(80,596,(&sym)->sym5,32,35,0);
			Outtext(327,596,(&sym)->sym6,32,35,63503);
			Outtext(584,596,(&sym)->sym7,32,35,0);
			Outtext(829,596,(&sym)->sym8,32,35,0);
			
			a=1;
			b=2;
		}
		else if(MouseBarLeft(512,569,768,669)==1)					//点击精神狂躁
		{
			while(MouseBarLeft(512,569,768,669)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Outtext(80,596,(&sym)->sym5,32,35,0);
			Outtext(327,596,(&sym)->sym6,32,35,0);
			Outtext(584,596,(&sym)->sym7,32,35,63503);
			Outtext(829,596,(&sym)->sym8,32,35,0);
			
			a=1;
			b=3;
		}
		else if(MouseBarLeft(768,569,1023,669)==1)					//点击精神萎靡
		{
			while(MouseBarLeft(768,569,1023,669)==1)
			{
			}
			MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
			mflag=1;
			
			Outtext(80,596,(&sym)->sym5,32,35,0);
			Outtext(327,596,(&sym)->sym6,32,35,0);
			Outtext(584,596,(&sym)->sym7,32,35,0);
			Outtext(829,596,(&sym)->sym8,32,35,63503);
			
			a=1;
			b=4;
		}
		
		if(i==1	&&	a==1)					//两项都已经选择
		{
			Bar64k(277,350,896,437,65269);				//用户对话框
			if(j==1)					//点击了37~38
			{
				Outtext(280,352,(&sym)->sym1,32,35,0);
			}
			else if(j==2)					//点击了38~39
			{
				Outtext(280,352,(&sym)->sym2,32,35,0);
			}
			else if(j==3)					//点击了39~40
			{
				Outtext(280,352,(&sym)->sym3,32,35,0);
			}
			else if(j==4)					//点击了40+
			{
				Outtext(280,352,(&sym)->sym4,32,35,0);
			}
			if(b==1)			//点击精神正常
			{
				Outtext(280,395,(&sym)->sym5,32,35,0);
			}
			else if(b==2)		//点击精神呆滞
			{
				Outtext(280,395,(&sym)->sym6,32,35,0);
			}
			else if(b==3)		//点击精神狂躁
			{
				Outtext(280,395,(&sym)->sym7,32,35,0);
			}
			else if(b==4)		//点击精神萎靡
			{
				Outtext(280,395,(&sym)->sym8,32,35,0);
			}
		}
		
		if(i==1	&&	a==1)					//两项都已经选择
		{
			Bar64k(277,350,896,437,65269);				//用户对话框
			if(j==1)					//点击了37~38
			{
				Outtext(280,352,(&sym)->sym1,32,35,0);
			}
			else if(j==2)					//点击了38~39
			{
				Outtext(280,352,(&sym)->sym2,32,35,0);
			}
			else if(j==3)					//点击了39~40
			{
				Outtext(280,352,(&sym)->sym3,32,35,0);
			}
			else if(j==4)					//点击了40+
			{
				Outtext(280,352,(&sym)->sym4,32,35,0);
			}
			if(b==1)			//点击精神正常
			{
				Outtext(280,395,(&sym)->sym5,32,35,0);
			}
			else if(b==2)		//点击精神呆滞
			{
				Outtext(280,395,(&sym)->sym6,32,35,0);
			}
			else if(b==3)		//点击精神狂躁
			{
				Outtext(280,395,(&sym)->sym7,32,35,0);
			}
			else if(b==4)		//点击精神萎靡
			{
				Outtext(280,395,(&sym)->sym8,32,35,0);
			}
			delay(400);
			Bar64k(121,210,814,325,64704);					//医生对话框
			Outtext(130,215,"正在输入中......",32,35,0);
			delay(1000);
			Bar64k(121,210,814,325,64704);					//医生对话框
			if(j==1)									//点击了37~38
			{
				if(b==1)
				{
					Outtext(130,215,(&res)->res1,32,35,0);
					Outtext(130,260,(&res)->res2,32,35,0);
				}
				else if(b==2)
				{
					Outtext(130,215,(&res)->res3,32,35,0);
					Outtext(130,260,(&res)->res4,32,35,0);
				}
				else if(b==3)
				{
					Outtext(130,215,(&res)->res5,32,35,0);
					Outtext(130,260,(&res)->res6,32,35,0);
				}
				else if(b==4)
				{
					Outtext(130,215,(&res)->res7,32,35,0);
					Outtext(130,260,(&res)->res8,32,35,0);
				}
			}
			if(j==2)									//点击了38~39
			{
				if(b==1 || b==2)
				{
					Outtext(130,215,(&res)->res9,32,35,0);
					Outtext(130,260,(&res)->res10,32,35,0);
				}
				else if(b==3 || b==4)
				{
					Outtext(130,215,(&res)->res11,32,35,0);
					Outtext(130,260,(&res)->res12,32,35,0);
				}
			}
			if(j==3 || j==4)									//点击了39~40或40+
			{
					Outtext(130,215,(&res)->res13,32,35,0);
					Outtext(130,260,(&res)->res14,32,35,0);
					delay(1000);
					Bar64k(121,210,814,325,64704);					//医生对话框
					Outtext(130,215,(&res)->res15,32,35,0);
					Outtext(130,260,(&res)->res16,32,35,0);
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
				if(MouseBarLeft(978,0,1024,46)==1)      //鼠标点击退出按钮
				{
					while(MouseBarLeft(978,0,1024,46)==1)
					{
					}
					MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
					mflag=1;
			
					SelectDoc_pic();
		
					delay(100);
					c=1;
					break;
				}
				else if(MouseBarLeft(301,685,723,754)==1)		//点击结束问诊
				{
					while(MouseBarLeft(978,0,1024,46)==1)
					{
					}
					MousePutBk(mouse_old.x,mouse_old.y);  //恢复原鼠标
					mflag=1;
					
					
					Chufang_pic(doc,res,j,b);
					delay(3000);
					OverAsk_pic();
											
					delay(1500);
						
					SelectDoc_pic();			
					delay(100);
					c=1;
					break;
				}
			}
		}
	}
}

