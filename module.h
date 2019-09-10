#ifndef MODULE_H
#define MODULE_H


typedef struct User
{
	 char username[18];
	 char password[18];
	 char num[20];
	 char balance[12];
}User;

typedef struct Doctor
{
	int t;		//ҽ��ֵ��ʱ�����
	//0�㵽8��Ϊ1,8�㵽16��Ϊ2��16�㵽0��Ϊ3
	char name[20];
	char department[20];
	int years;
	char skill[80];
}Doctor;

typedef struct Medicine
{
	char name[26];
	char price[10];
	char function[140];
}Medicine;


typedef struct Bought
{
	char name[26];
	char num[3];
	char fee[10];
}Bought;
	

typedef struct Sym
{
	char user1[40];
	char doc1[40];
	char doc2[40];
	char sym1[20];
	char sym2[20];
	char sym3[20];
	char sym4[20];
	char sym5[20];
	char sym6[20];
	char sym7[20];
	char sym8[20];
}Sym;

typedef struct Resu
{
	char res1[40];
	char res2[40];
	char res3[40];
	char res4[40];
	char res5[40];
	char res6[40];
	char res7[40];
	char res8[40];
	char res9[40];
	char res10[40];
	char res11[40];
	char res12[40];
	char res13[40];
	char res14[40];
	char res15[40];
	char res16[40];
}Resu;

//ע����溯��
void Register(int *main_flag);

//�û���Ϣ��ʼ��
int Userinti(User *user1);

//����û����Ƿ��Ѿ����ù�
int Check(char* s,User *user,int num);

//�����溯��
void Interface(int *main_flag);

//ѡҽ������
void Selectdoc(int *main_flag);

//�ж�ҽ���Ƿ�����
int JudgeDoc(int a,int hour,int c);

//ҽ��������
void sort(Doctor *doc,int num,int s);

//����Ա��������
int Adminpass(int *main_flag);

//ҽ����Ϣ��ȡ��ʼ��
int Docinti(Doctor *doctor);

//�ַ��ָ��
char* substr(char dst[],char src[],int start,int len);

//ҽ����Ϣ���
void Docinfo_pic(Doctor *doc,int num,int page,int lastpage);		//���ٽ���ˢ�·�Χ

//�������Ĺ��ܺ���
void Personal(int *main_flag,User *user);

//�ѹ�ҩ�����
void BoughtM(int *main_flag,User *user);

//�ѹ�ҩ����Ϣ���
void MedBou_pic(Bought *bought,int page,int lastpage,int num);	//���ٽ���ˢ�·�Χ

//�ѹ�ҩ����Ϣ��ʼ��
int Bouinti(Bought *bought,User *user);

//�����ʾ����
void Balance(void);

//��ֵ���ܺ���
void Charge(int *main_flag,int n,User *user);

//�޸����빦�ܺ���
void Changepass(int *main_flag,User *user,int n);

//AboutUs���湦��
void AboutUs(int *main_flag);	

//�ж��ַ��Ƿ�ȫΪ����
int JudgeNum(char *s);

//�ж��ַ��Ƿ�Ϊ��ĸ������
int JudgeWord(char *s);

	
//��ҩ����
void BuyM(Medicine *medicine,User *user,int n);



#endif



