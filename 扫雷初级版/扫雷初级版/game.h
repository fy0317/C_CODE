#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9		//��Ч��������
#define COL 9		//��Ч��������
#define ROWS ROW+2	//ʵ����������
#define COLS COL+2	//ʵ����������	
#define COUNT 10	//���׵���Ŀ
void InitBoard(char board[ROWS][COLS], int row, int col, char c);	//��ʼ������
void PrintBoard(char board[ROWS][COLS], int row, int col);			//��ӡ���� 
void ArrangeBoard(char board[ROWS][COLS], int row, int col);		//����
void FindBoard(char board[ROWS][COLS], char ShowBoard[ROWS][COLS], int row, int col);			//����