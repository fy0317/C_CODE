#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
<<<<<<< HEAD
#define ROW 9		//有效棋盘行数
#define COL 9		//有效棋盘列数
#define ROWS ROW+2	//实际棋盘行数
#define COLS COL+2	//实际棋盘列数	   
#define COUNT 1	//地雷的数目
void InitBoard(char board[ROWS][COLS], int row, int col, char c);	//初始化棋盘
void PrintBoard(char board[ROWS][COLS], int row, int col);			//打印棋盘 
void ArrangeBoard(char board[ROWS][COLS], int row, int col);		//布雷
void FindBoard(char board[ROWS][COLS], char ShowBoard[ROWS][COLS],int													 row, int col);			//排雷
=======
#define ROW 9		//鏈夋晥妫嬬洏琛屾暟
#define COL 9		//鏈夋晥妫嬬洏鍒楁暟
#define ROWS ROW+2	//瀹為檯妫嬬洏琛屾暟
#define COLS COL+2	//瀹為檯妫嬬洏鍒楁暟	   
#define COUNT 1	//鍦伴浄鐨勬暟鐩�
void InitBoard(char board[ROWS][COLS], int row, int col, char c);	//鍒濆鍖栨鐩�
void PrintBoard(char board[ROWS][COLS], int row, int col);			//鎵撳嵃妫嬬洏 
void ArrangeBoard(char board[ROWS][COLS], int row, int col);		//甯冮浄
void FindBoard(char board[ROWS][COLS], char ShowBoard[ROWS][COLS],int													 row, int col);			//鎺掗浄
>>>>>>> b8cbb3e7b007ae1b82e23def3b03f1129a1e65ae
