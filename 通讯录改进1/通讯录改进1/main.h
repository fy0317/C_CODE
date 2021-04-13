#define MAX_NAME 20
//#define MAX 1000
#define MAX_SEX 5
#define MAX_TEL 12
#define MAX_ADDR 30
#define INITIAL_SZ 3
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void InitContact(struct Contact* p);   //��ʼ��ͨѶ¼
void AddContact(struct Contact* p);   //����ͨѶ¼
void Showcontact(const struct Contact* p);  //��ʾͨѶ¼
void DelContact(struct Contact* p);		//ɾ����Ա
void SerContact(const struct Contact* p);   //����ͨѶ¼
void ModContact(struct Contact* p);			//�޸�ͨѶ¼
int FindByNmae(struct contact* p, char name[MAX_NAME]);  //ͨ�����ֲ���
void CheckCapacity(struct contact* p);
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
	struct PeoInfo* data;   //���1000���˵���Ϣ
	int sz;   //��¼��ǰ����Ԫ�صĸ���
	int capacity;
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