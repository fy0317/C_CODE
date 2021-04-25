#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Teacher
{
	char* name;
	char** students;
}Teacher;
//老师数组分配空间
void allocateSpace(Teacher*** teacherarray)
{
	if (teacherarray == NULL) return;
	//分配内存
	Teacher** tmp = malloc(sizeof(Teacher*) * 3);
	if (tmp != NULL)
	{
		for (int i = 0; i < 3; i++)
		{
			//每个老师分配空间
			tmp[i] = malloc(sizeof(Teacher));	
			if (tmp[i] != NULL)
				tmp[i]->name = malloc(sizeof(char) * 20);	//老师名字分配空间
			if(tmp[i]->name != NULL)						//老师名字赋值
				sprintf(tmp[i]->name, "Teacher_%d", i + 1);
			tmp[i]->students = malloc(sizeof(char*) * 4);		//学生数组分配空间
			if (tmp[i]->students != NULL)
			{
				for (int j = 0; j < 4; j++)
				{
					tmp[i]->students[j] = malloc(sizeof(char) * 20);		//学生姓名分配空间
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
		//老师姓名
		printf("%s\n", teacherarray[i]->name);

		//学生姓名
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
	allocateSpace(&teacherarry);	//分配空间
	printteacherarry(teacherarry);	//打印数据
	freeteacherarry(teacherarry);		//释放空间
	free(teacherarry);
	teacherarry = NULL;
}
int main()
{
	test1();
	return 0;
}