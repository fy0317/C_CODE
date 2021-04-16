#pragma once
#define MAX_NAME 20			//������󳤶�
//#define MAX 1000
#define MAX_SEX 5			//�Ա����󳤶�
#define MAX_TEL 12			//�绰����󳤶�
#define MAX_ADDR 30			//��ַ��󳤶�
#define INITIAL_SZ 3		//ͨѶ¼��ʼ�Ĵ�С

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

void InitContact(struct Contact* p);   //��ʼ��ͨѶ¼
void AddContact(struct Contact* p);   //����ͨѶ¼
void Showcontact(const struct Contact* p);  //��ʾͨѶ¼
void DelContact(struct Contact* p);		//ɾ����Ա
void SerContact(const struct Contact* p);   //����ͨѶ¼
void ModContact(struct Contact* p);			//�޸�ͨѶ¼
int FindByNmae(struct Contact* p, char name[MAX_NAME]);  //ͨ�����ֲ���
void CheckCapacity(struct Contact* p);			//���ͨѶ¼��С
void SaveContact(struct Contact *p);			//�����ļ�
void SortContact(struct Contact* p);            //����������
void DesContact(struct Contact* p);				//�ͷŶ���



//��Ϣ�ṹ�壬������������䡢�Ա𡢵绰����ַ
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
};



//ͨѶ¼�ṹ�壬������ŵ���Ϣ����ǰͨѶ¼������ŵ���Ϣ�Լ�ͨѶ¼�洢����
struct Contact
{
	struct PeoInfo* data;   //��Ÿ��˵���Ϣ
	int sz;   //��¼��ǰ����Ԫ�صĸ���
	int capacity;    //��ǰ���洢����
};


//�˵�ѡ��
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