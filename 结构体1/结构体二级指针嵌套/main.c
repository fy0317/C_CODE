#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Teacher
{
	char* name;
	char** students;
}Teacher;
//��ʦ�������ռ�
void allocateSpace(Teacher*** teacherarray)
{
	if (teacherarray == NULL) return;
	//�����ڴ�
	Teacher** tmp = malloc(sizeof(Teacher*) * 3);
	if (tmp != NULL)
	{
		for (int i = 0; i < 3; i++)
		{
			//ÿ����ʦ����ռ�
			tmp[i] = malloc(sizeof(Teacher));	
			if (tmp[i] != NULL)
				tmp[i]->name = malloc(sizeof(char) * 20);	//��ʦ���ַ���ռ�
			if(tmp[i]->name != NULL)						//��ʦ���ָ�ֵ
				sprintf(tmp[i]->name, "Teacher_%d", i + 1);
			tmp[i]->students = malloc(sizeof(char*) * 4);		//ѧ���������ռ�
			if (tmp[i]->students != NULL)
			{
				for (int j = 0; j < 4; j++)
				{
					tmp[i]->students[j] = malloc(sizeof(char) * 20);		//ѧ����������ռ�
					if (tmp[i]->students[j] != NULL)
						sprintf(tmp[i]->students[j], "Teacher_%d_Student_%d", i + 1,j + 1);
				}
			}
		}
	}
	*teacherarray = tmp;
}
void printteacherarry(Teacher** teacherarray)
{
	if (teacherarray == NULL) return;
	for (int i = 0; i < 3; i++)
	{
		//��ʦ����
		printf("%s\n", teacherarray[i]->name);

		//ѧ������
		for (int j = 0; j < 4; j++)
		{
			printf("	%s\n", teacherarray[i]->students[j]);
		}
	}
}
void freeteacherarry(Teacher** teacherarry)
{
	if (teacherarry == NULL) return;
	for (int i = 0; i < 3; i++)
	{
		if (teacherarry[i] != NULL)
		{
			if (teacherarry[i]->name != NULL)
			{
				free(teacherarry[i]->name);
				teacherarry[i]->name = NULL;
				for (int j = 0; j < 4; j++)
				{
					if (teacherarry[i]->students != NULL)
					{
						if (teacherarry[i]->students[j] != NULL)
						{
							free(teacherarry[i]->students[j]);
							teacherarry[i]->students[j] = NULL;
						}
						free(teacherarry[i]->students);
						teacherarry[i]->students = NULL;
					}

				}
			}
			free(teacherarry[i]);
			teacherarry[i] = NULL;
		}
	}
}
void test1()
{
	Teacher** teacherarry = NULL;
	allocateSpace(&teacherarry);	//����ռ�
	printteacherarry(teacherarry);	//��ӡ����
	freeteacherarry(teacherarry);		//�ͷſռ�
	free(teacherarry);
	teacherarry = NULL;
}
int main()
{
	test1();
	return 0;
}