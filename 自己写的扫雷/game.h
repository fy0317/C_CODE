#pragma once
#define ROW 3
#define COL 3	
#define SETCOUNT 5

#define ROWS ROW+2		//Ϊ���ܳɹ������߽�����̣�������Ҫ����������չ�����齫���׺�ɨ��һһ��Ӧ����ʼ��ʱҲһ��Ҫ��չ
#define COLS COL+2		
void Initboard(char board[ROWS][COLS], int rows, int cols,char set);
void Displayboard(char board[ROW][COL], int row, int col);		//��ӡ����ֻ��ӡ�м�����̣�����Ҫ��ӡ���е�
void Setmine(char mine[ROW][COL], int row, int col);
void Findmine(char mine[ROW][COL],char show[ROW][COL], int row, int col);