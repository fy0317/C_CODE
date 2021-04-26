#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void func(int a,int b)
{
	printf("hello world\n");
}

//ͨ�����庯�����ͣ���������ָ��
void test1()
{
	typedef void (Func)(int , int );
	Func* pfun = func;
	pfun(1, 2);
}
//ͨ�����庯��ָ�����ͣ���������ָ��
void test2()
{
	typedef void (*Func)(int , int );
	Func pfun = func;
	pfun(1, 2);
}
//ֱ�Ӵ�������ָ��
void test3()
{
	void (*pfun)(int, int) = func;
	pfun(1, 2);
}

void fun1()
{
	printf("fun1�ĵ���\n");
}
void fun2()
{
	printf("fun2�ĵ���\n");
}void fun3()
{
	printf("fun3�ĵ���\n");
}
//����ָ������
void test4()
{
	void (*Pfun[3])() = { fun1,fun2,fun3 };
	for (int i = 0; i < 3; i++)
	{
		Pfun[i]();
	}

}

//�ص���������������������ָ����Ϊ�����Ĳ������ǻص�����
void myPrint(void* num, void (*fun)(void*))		//��ӡ�������͵�����,num�Ǵ�ӡ�����ݣ�fun�Ǻ���ָ��
{
	fun(num);					//ͨ������ָ����ú���fun
}
void PrintInt(void* num)		//��ӡ����
{
	int* p = (int*)num;
	printf("%d\n", *p);
}
void PrintDouble(void* num)		//��ӡ˫������
{
	double* p = (double*)num;
	printf("%f\n", *p);
}
struct Person {
	char name[20];
	int age;
};
void PrintPerson(void* num)		//��ӡ�ṹ��
{
	struct Person* p = (struct Person*)num;
	printf("����:%s  ����:%d\n", p->name, p->age);
}
//��ӡ������������
void test5()
{
	int a = 10;
	myPrint(&a, PrintInt);
	double b = 3.14;
	myPrint(&b, PrintDouble);
	struct Person p1 = { "����",20 };
	myPrint(&p1, PrintPerson);
}


//��ӡ������������
void printArr(void* arr,int sizeofele,int len,void (*p)(void*))
{
	for (int i = 0; i < len; i++)
	{
		char* tmp = arr;
		tmp = tmp + sizeofele * i;			//�ҵ���i��Ԫ�ص��׵�ַ
		p(tmp);
	}
}
void test6()
{
	int arr[] = { 1,2,3,4,5 };
	printArr(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), PrintInt);		//��ӡ��������
	double arr1[] = { 1.1, 2.3, 3.4, 5.5 };
	printArr(arr1, sizeof(arr1[0]), sizeof(arr1) / sizeof(arr1[0]), PrintDouble);	//��ӡ˫��������
	struct Person person[] =
	{
		{"����",20},
		{"����",21},
		{"����",22},
		{"aaa",23},
		{"bbb",24},
	};
	printArr(person, sizeof(person[0]), sizeof(person) / sizeof(person[0]), PrintPerson);	//��ӡPerson����


}
int cmpPerson(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;
	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
		return 1;
	else return 0;

}
int FindEle(void* arr, int eleSize, int len, void* data, int (*cmp)(void*, void*))
{
	for (int i = 0; i < len; i++)			//��������
	{
		char* eleAdrr = (char*)arr + eleSize * i;		//�ҵ���i��Ԫ�صĵ�ַ
		int ret = cmp(data, eleAdrr);			//����Ҫ����Ԫ���������е�i��Ԫ�رȽϣ���ȷ���1�����򷵻�0
		if (ret) return 1;					//�ҵ��ˣ�����1
	}
	return 0;				//ѭ��������˵��û�ҵ�������0
}
void test7()
{
	struct Person person[] =
	{
		{"����",20},
		{"����",21},
		{"����",22},
		{"aaa",23},
		{"bbb",24},
	};
	int len = sizeof(person) / sizeof(struct Person);		//���鳤��
	struct Person data = { "����",220 };			//��Ҫ���ҵ�Ԫ��
	int ret = FindEle(person, sizeof(person[0]), len, &data, cmpPerson);
	if (ret) printf("�ҵ���\n");
	else printf("û�ҵ�\n");
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();		//��ӡ�������͵�����
	test7();		//���������е�Ԫ��
	return 0;
}