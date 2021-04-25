#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>

//д�ļ�
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
//���ļ�
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

//��ʽ����ʽ��д�ļ�
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
//Ӣ�۽ṹ��
struct Hero {
	char name[40];
	int age;
};

//�ƶ����
void test4()
{
	//д�ļ�
	FILE* f_write = fopen("test3.txt", "w");
	if (f_write == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	struct Hero heros[4] =
	{
		{"��ɪ",19},
		{"槼�",20},
		{"����",21},
		{"�����",1000},
	};
	for (int i = 0; i < 4; i++)
	{
		fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
	}
	fclose(f_write);

	//���ļ�
	struct Hero tmp;
	FILE* f_read = fopen("test3.txt", "r");
	if (f_read == NULL)
	{
		perror("�ļ���ʧ��");
		//printf("%s",strerror(errno));
		return;
	}
	//fseek(f_read, sizeof(struct Hero) * 2, SEEK_SET);			//SEEK_SET����ͷ���ƶ����
	fseek(f_read, -(int)sizeof(struct Hero) * 2, SEEK_END);		//SEEK_END,���ļ�β������    fseek�ڶ���������long���ͣ�sizeof����ֵ���޷�����
	rewind(f_read);												//���������
	fread(&tmp, sizeof(struct Hero), 1, f_read);
	printf("%s  %d", tmp.name, tmp.age);
	fclose(f_read);
}

void test5()
{
	FILE* file = fopen("test0.txt", "r");
	if (file == NULL)
	{
		perror("�ļ���ʧ��");
		return;
	}
	char ch;
	while (!feof(file))
	{
		ch = fgetc(file);
		if (feof(file)) break;			//��ѭ���ж���EOF��Ȼ���ٽ���ѭ���������жϣ����ͺ���,���Ҫ��һ���ж�
		putchar(ch);
	}
}
struct Person
{
	char* name;					//����ṹ���еı��������ڶ����ϣ���Ҫ�ѵ�ַ������ļ��У��´ζ�ȡ�ļ�ʱ�������ַ��ָ������ݿ����Ѿ�����
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