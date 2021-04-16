#pragma once
#define MAX_NAME 20			//名字最大长度
//#define MAX 1000
#define MAX_SEX 5			//性别的最大长度
#define MAX_TEL 12			//电话的最大长度
#define MAX_ADDR 30			//地址最大长度
#define INITIAL_SZ 3		//通讯录初始的大小

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

void InitContact(struct Contact* p);   //初始化通讯录
void AddContact(struct Contact* p);   //增加通讯录
void Showcontact(const struct Contact* p);  //显示通讯录
void DelContact(struct Contact* p);		//删除成员
void SerContact(const struct Contact* p);   //查找通讯录
void ModContact(struct Contact* p);			//修改通讯录
int FindByNmae(struct Contact* p, char name[MAX_NAME]);  //通过名字查找
void CheckCapacity(struct Contact* p);			//检查通讯录大小
void SaveContact(struct Contact *p);			//保存文件
void SortContact(struct Contact* p);            //用名字排序
void DesContact(struct Contact* p);				//释放堆区



//信息结构体，存放姓名、年龄、性别、电话、地址
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
};



//通讯录结构体，包含存放的信息，当前通讯录中所存放的信息以及通讯录存储能力
struct Contact
{
	struct PeoInfo* data;   //存放个人的信息
	int sz;   //记录当前已有元素的个数
	int capacity;    //当前最大存储容量
};


//菜单选项
enum Option
{
	EXIT,		//0
	ADD,		//1
	DEL,		//2
	SEARCH,		//3
	MODIFY,		//4
	SHOW,		//5
	SORT,		//6
	SAVE		//7
};