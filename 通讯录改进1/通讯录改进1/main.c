#define _CRT_SECURE_NO_WARNINGS
#include"main.h"
void menu()
{
	printf("*****************************************\n");
	printf("********    1.Add        2.Del    ********\n");
	printf("********    3.Search     4.Modify ********\n");
	printf("********    5.Show       6.Sort   ********\n");
	printf("********    0.exit                ********\n");
	printf("*****************************************\n");
	printf("*****************************************\n");
	printf("*****************************************\n");

}
int main()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			printf("��������Ҫɾ����Ԫ��:\n");
			int n = 0;
			scanf("%d", &n);
			DelContact(&con, n);
			break;
		case SEARCH:
			SerContact(&con);
			break;
		case MODIFY:
			ModContact(&con);
			break;
		case SHOW:
			Showcontact(&con);
			break;
		case SORT:
			//SortContact(&con);
			break;
		case EXIT:
			DesContact(&con);
			printf("�˳�����\n");
			break;
		default:
			printf("���������������\n");
			break;
		}

	} while (input);
}