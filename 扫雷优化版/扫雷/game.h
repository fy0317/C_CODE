#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
<<<<<<< HEAD
#define ROW 9		//��Ч��������
#define COL 9		//��Ч��������
#define ROWS ROW+2	//ʵ����������
#define COLS COL+2	//ʵ����������	   
#define COUNT 1	//���׵���Ŀ
void InitBoard(char board[ROWS][COLS], int row, int col, char c);	//��ʼ������
void PrintBoard(char board[ROWS][COLS], int row, int col);			//��ӡ���� 
void ArrangeBoard(char board[ROWS][COLS], int row, int col);		//����
void FindBoard(char board[ROWS][COLS], char ShowBoard[ROWS][COLS],int													 row, int col);			//����
=======
#define ROW 9		//有效棋盘行数
#define COL 9		//有效棋盘列数
#define ROWS ROW+2	//实际棋盘行数
#define COLS COL+2	//实际棋盘列数	   
#define COUNT 1	//地雷的数目
void InitBoard(char board[ROWS][COLS], int row, int col, char c);	//初始化棋盘
void PrintBoard(char board[ROWS][COLS], int row, int col);			//打印棋盘 
void ArrangeBoard(char board[ROWS][COLS], int row, int col);		//布雷
void FindBoard(char board[ROWS][COLS], char ShowBoard[ROWS][COLS],int													 row, int col);			//排雷
>>>>>>> b8cbb3e7b007ae1b82e23def3b03f1129a1e65ae
