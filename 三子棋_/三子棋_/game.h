#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3


void InitBoard(char arr[ROW][COL], int row, int col);			//初始化棋盘
void PrintBoard(char arr[ROW][COL], int row, int col);			//打印棋盘	
void PlayerMove(char arr[ROW][COL], int row, int col);		//玩家下棋
void CopMove(char arr[ROW][COL], int row, int col);		//电脑下棋
char IsWin(char arr[ROW][COL], int row, int col);		//判断结果
