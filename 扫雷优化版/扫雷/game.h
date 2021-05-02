#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9		//有效棋盘行数
#define COL 9		//有效棋盘列数
#define ROWS ROW+2	//实际棋盘行数
#define COLS COL+2	//实际棋盘列数	   
#define COUNT 1	//地雷的数目
void InitBoard(char board[ROWS][COLS], int row, int col, char c);	//初始化棋盘
void PrintBoard(char board[ROWS][COLS], int row, int col);			//打印棋盘 
void ArrangeBoard(char board[ROWS][COLS], int row, int col);		//布雷
void FindBoard(char board[ROWS][COLS], char ShowBoard[ROWS][COLS],int													 row, int col);			//排雷
