#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>

//写文件
void test1()
{
	FILE* f_write = fopen("./test1.txt", "w");
	if (f_write == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	char buf[] = "hello world";
	for (int i = 0; i < strlen(buf); i++)
	{
		fputc(buf[i], f_write);
	}
	fclose(f_write);
}
//读文件
void test2()
{
	FILE* f_read = fopen("./test1.txt","r");
	if (f_read == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	char c = 0;
	while ((c = fgetc(f_read) )!= EOF)
	{
		putchar(c);
	}
	printf("%c", fgetc(f_read));
	fclose(f_read);
}

//格式化方式读写文件
void test3()
{
	FILE* f_write = fopen("test3.txt", "w");
	if (f_write == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	fprintf(f_write, "hello,world!%d", 12345);
	fclose(f_write);
	FILE* f_read = fopen("test3.txt", "r");
	if (f_read == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	char arr[20];
	fscanf(f_read, "%s", arr);
	printf("%s", arr);
	fclose(f_read);

}
//英雄结构体
struct Hero {
	char name[40];
	int age;
};

//移动光标
void test4()
{
	//写文件
	FILE* f_write = fopen("test3.txt", "w");
	if (f_write == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	struct Hero heros[4] =
	{
		{"亚瑟",19},
		{"妲己",20},
		{"赵云",21},
		{"孙悟空",1000},
	};
	for (int i = 0; i < 4; i++)
	{
		fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
	}
	fclose(f_write);

	//读文件
	struct Hero tmp;
	FILE* f_read = fopen("test3.txt", "r");
	if (f_read == NULL)
	{
		perror("文件打开失败");
		//printf("%s",strerror(errno));
		return;
	}
	//fseek(f_read, sizeof(struct Hero) * 2, SEEK_SET);			//SEEK_SET，从头部移动光标
	fseek(f_read, -(int)sizeof(struct Hero) * 2, SEEK_END);		//SEEK_END,从文件尾部查找    fseek第二个参数是long类型，sizeof返回值是无符号型
	rewind(f_read);												//将光标置首
	fread(&tmp, sizeof(struct Hero), 1, f_read);
	printf("%s  %d", tmp.name, tmp.age);
	fclose(f_read);
}

void test5()
{
	FILE* file = fopen("test0.txt", "r");
	if (file == NULL)
	{
		perror("文件打开失败");
		return;
	}
	char ch;
	while (!feof(file))
	{
		ch = fgetc(file);
		if (feof(file)) break;			//在循环中读到EOF，然后再进行循环的条件判断，有滞后性,因此要加一个判断
		putchar(ch);
	}
}
struct Person
{
	char* name;					//如果结构体中的变量创建在堆区上，不要把地址存放在文件中，下次读取文件时，这个地址所指向的内容可能已经变了
	int age;
};
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}