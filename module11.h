#ifndef MODULE11_H
#define MODULE11_H

//����Ա����
void Admin(int *main_flag);

//����Ա�鿴���޸��ܱ�����
void Changeanswer(int *main_flag);

//�û���Ϣ�������
void Chanuser_pic(User *user,int num,int page,int lastpage);

//�û���Ϣ��ʼ������
int Chaninit(User *user);

//�޸��ܱ�����
void Alternum(User *user,int *main_flag,int m,int num);

//ɾ��ҽ������
void Deletedoc(int *main_flag);

//����Ա����ҽ����Ϣ�������
void Deletedoc_pic(Doctor *doctor,int num,int page,int lastpage);

//����Աҽ����Ϣ��ȡ����
int Deldocinti(Doctor *doctor);

//ɾ��ҽ���ļ���������
void Shutdown(int m,int *main_flag,Doctor *doctor,int numb);

//ת������
void Invert(int *main_flag);
#endif