#define MAX_NAME 20
#define MAX 1000
#define MAX_SEX 5
#define MAX_TEL 12
#define MAX_ADDR 30
#include<stdio.h>
#include<string.h>

void InitContact(struct Contact* p);   //初始化通讯录
void AddContact(struct Contact* p);   //增加通讯录
void Showcontact(const struct Contact* p);  //显示通讯录
void DelContact(struct Contact* p);		//删除成员
void SerContact(const struct Contact* p);   //查找通讯录
void ModContact(struct Contact* p);			//修改通讯录
int FindByNmae(struct contact* p, char name[MAX_NAME]);  //通过名字查找
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
};
struct Contact
{
	struct PeoInfo data[MAX];   //存放1000个人的信息
	int sz;   //记录当前已有元素的个数
};
enum Option
{
	EXIT,		//0
	ADD,		//1
	DEL,		//2
	SEARCH,		//3
	MODIFY,		//4
	SHOW,		//5
	SORT,		//6
};