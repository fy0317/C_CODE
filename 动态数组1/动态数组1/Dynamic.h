#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INITCAP  5		//��ʼ����
typedef struct Dynamic
{
	void** pArr;			//ά����̬���ٵ����飨ÿ��Ԫ����void*�����������Խ����������͵�����
	int size;			//���鵱ǰ��С
	int capacity;		//��������
}Dynamic;

Dynamic* InitArr(int x);		//��ʼ������
void Check(Dynamic* arr);			//�����������
void Insert(Dynamic* arr, void* data, int pos);		//��������
void Print(Dynamic* arr, void (*PrintData)(void*));		//��ӡ����
void DeleteByPos(Dynamic* arr, int pos);			//����λ��ɾ������
void DeleteByData(Dynamic* arr, void* data, int (*Compare)(void* p1,void* p2));		//��������ɾ������
void DestroyArr(Dynamic* arr);		//��������