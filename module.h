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
	int t;		//医生值班时间参数
	//0点到8点为1,8点到16点为2，16点到0点为3
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

//注册界面函数
void Register(int *main_flag);

//用户信息初始化
int Userinti(User *user1);

//检查用户名是否已经被用过
int Check(char* s,User *user,int num);

//主界面函数
void Interface(int *main_flag);

//选医生界面
void Selectdoc(int *main_flag);

//判断医生是否在线
int JudgeDoc(int a,int hour,int c);

//医生排序函数
void sort(Doctor *doc,int num,int s);

//管理员密码输入
int Adminpass(int *main_flag);

//医生信息读取初始化
int Docinti(Doctor *doctor);

//字符分割函数
char* substr(char dst[],char src[],int start,int len);

//医生信息输出
void Docinfo_pic(Doctor *doc,int num,int page,int lastpage);		//减少界面刷新范围

//个人中心功能函数
void Personal(int *main_flag,User *user);

//已购药物界面
void BoughtM(int *main_flag,User *user);

//已购药物信息输出
void MedBou_pic(Bought *bought,int page,int lastpage,int num);	//减少界面刷新范围

//已购药物信息初始化
int Bouinti(Bought *bought,User *user);

//余额显示窗口
void Balance(void);

//充值功能函数
void Charge(int *main_flag,int n,User *user);

//修改密码功能函数
void Changepass(int *main_flag,User *user,int n);

//AboutUs界面功能
void AboutUs(int *main_flag);	

//判断字符是否全为数字
int JudgeNum(char *s);

//判断字符是否都为字母或数字
int JudgeWord(char *s);

	
//购药函数
void BuyM(Medicine *medicine,User *user,int n);



#endif



