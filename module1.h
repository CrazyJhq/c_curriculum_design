#ifndef MODULE1_H
#define MODULE1_H

	
//��¼���溯��
void LoginCheck(User *user , int *main_flag,int *n);

//�������뺯��
void FindPassword(int *main_flag);

//�����湦�ܺ���
void Interface(int *main_flag);

//ҩ����Ϣ��ȡ����
int Medinti(Medicine *medicine);

//��ҩ���湦�ܺ���
void Buymedicine(int *main_flag,User user,int n);

//ҩ����Ϣ�������
void Medinfo_pic(Medicine *medicine,int num,int page,int lastpage);

//�����Ӧ���Һ���
void Clicksub(char *dept,int *main_flag);

//ҽ����Ϣ�������
void Docinfo1_pic(Doctor *doc,int num,int page,int lastpage);

//ҩ�������������
void Details_pic(Medicine *medicine);
#endif