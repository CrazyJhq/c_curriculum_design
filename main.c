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
	  int n;		//�洢��ǰ�û����ļ��е�λ��
	  User user;
	  Doctor *doctor;
	  SetSVGA64k();
	  
	    while(1)
	    {
	        switch(main_flag)
			{
			    case 1:
				{
				
				    LoginCheck(&user ,&main_flag,&n);             //��¼���溯��
				    break;
				}
				case 2:
				{
				    Register(&main_flag);					//�û�ע�ắ��
					break;
				}
				case 3:
				{
					FindPassword(&main_flag);				//�һ�����
					break;
				}
				case 4:
				{
					Interface(&main_flag); 					//�����溯��
					break;
				}
				case 5:
				{
					Selectdoc(&main_flag);					//��ҽ������
					break;
				}
				case 6:
				{
					Admin(&main_flag);						//����Ա����
					break;
				}
				
				case 7:
				{
					Buymedicine(&main_flag,user,n);				//��ҩ����
					break;
				}
				case 8:
				{
					Personal(&main_flag,&user);					//��������
					break;
				}
				case 9:
				{
					BoughtM(&main_flag,&user);					//�ѹ�ҩ��
					break;
				}
				case 10:
				{
					Charge(&main_flag,n,&user);						//��ֵ����
					break;
				}
				case 11:
				{
					Changepass(&main_flag,&user,n);					//�޸��������
					break;
				}
				case 12:
				{
					Changeanswer(&main_flag);  					//�û��ܱ��鿴���޸�
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
					AboutUs(&main_flag);					//AboutUs���湦��
					break;
				}
			}
		}
}
	  