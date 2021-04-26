#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void func(int a,int b)
{
	printf("hello world\n");
}

//通过定义函数类型，创建函数指针
void test1()
{
	typedef void (Func)(int , int );
	Func* pfun = func;
	pfun(1, 2);
}
//通过定义函数指针类型，创建函数指针
void test2()
{
	typedef void (*Func)(int , int );
	Func pfun = func;
	pfun(1, 2);
}
//直接创建函数指针
void test3()
{
	void (*pfun)(int, int) = func;
	pfun(1, 2);
}

void fun1()
{
	printf("fun1的调用\n");
}
void fun2()
{
	printf("fun2的调用\n");
}void fun3()
{
	printf("fun3的调用\n");
}
//函数指针数组
void test4()
{
	void (*Pfun[3])() = { fun1,fun2,fun3 };
	for (int i = 0; i < 3; i++)
	{
		Pfun[i]();
	}

}

//回调函数——————函数指针作为函数的参数就是回调函数
void myPrint(void* num, void (*fun)(void*))		//打印任意类型的数据,num是打印的数据，fun是函数指针
{
	fun(num);					//通过函数指针调用函数fun
}
void PrintInt(void* num)		//打印整型
{
	int* p = (int*)num;
	printf("%d\n", *p);
}
void PrintDouble(void* num)		//打印双精度型
{
	double* p = (double*)num;
	printf("%f\n", *p);
}
struct Person {
	char name[20];
	int age;
};
void PrintPerson(void* num)		//打印结构体
{
	struct Person* p = (struct Person*)num;
	printf("姓名:%s  年龄:%d\n", p->name, p->age);
}
//打印所有类型数据
void test5()
{
	int a = 10;
	myPrint(&a, PrintInt);
	double b = 3.14;
	myPrint(&b, PrintDouble);
	struct Person p1 = { "张三",20 };
	myPrint(&p1, PrintPerson);
}


//打印所有类型数组
void printArr(void* arr,int sizeofele,int len,void (*p)(void*))
{
	for (int i = 0; i < len; i++)
	{
		char* tmp = arr;
		tmp = tmp + sizeofele * i;			//找到第i个元素的首地址
		p(tmp);
	}
}
void test6()
{
	int arr[] = { 1,2,3,4,5 };
	printArr(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), PrintInt);		//打印整型数组
	double arr1[] = { 1.1, 2.3, 3.4, 5.5 };
	printArr(arr1, sizeof(arr1[0]), sizeof(arr1) / sizeof(arr1[0]), PrintDouble);	//打印双精度数组
	struct Person person[] =
	{
		{"张三",20},
		{"李四",21},
		{"王五",22},
		{"aaa",23},
		{"bbb",24},
	};
	printArr(person, sizeof(person[0]), sizeof(person) / sizeof(person[0]), PrintPerson);	//打印Person数组


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
	for (int i = 0; i < len; i++)			//遍历数组
	{
		char* eleAdrr = (char*)arr + eleSize * i;		//找到第i个元素的地址
		int ret = cmp(data, eleAdrr);			//将需要查找元素与数组中第i个元素比较，相等返回1，否则返回0
		if (ret) return 1;					//找到了，返回1
	}
	return 0;				//循环结束，说明没找到，返回0
}
void test7()
{
	struct Person person[] =
	{
		{"张三",20},
		{"李四",21},
		{"王五",22},
		{"aaa",23},
		{"bbb",24},
	};
	int len = sizeof(person) / sizeof(struct Person);		//数组长度
	struct Person data = { "王五",220 };			//需要查找的元素
	int ret = FindEle(person, sizeof(person[0]), len, &data, cmpPerson);
	if (ret) printf("找到了\n");
	else printf("没找到\n");
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();		//打印所有类型的数组
	test7();		//查找数组中的元素
	return 0;
}