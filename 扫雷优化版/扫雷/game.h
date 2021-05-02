#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
<<<<<<< HEAD
#define ROW 9		//ÓÐÐ§ÆåÅÌÐÐÊý
#define COL 9		//ÓÐÐ§ÆåÅÌÁÐÊý
#define ROWS ROW+2	//Êµ¼ÊÆåÅÌÐÐÊý
#define COLS COL+2	//Êµ¼ÊÆåÅÌÁÐÊý	   
#define COUNT 1	//µØÀ×µÄÊýÄ¿
void InitBoard(char board[ROWS][COLS], int row, int col, char c);	//³õÊ¼»¯ÆåÅÌ
void PrintBoard(char board[ROWS][COLS], int row, int col);			//´òÓ¡ÆåÅÌ 
void ArrangeBoard(char board[ROWS][COLS], int row, int col);		//²¼À×
void FindBoard(char board[ROWS][COLS], char ShowBoard[ROWS][COLS],int													 row, int col);			//ÅÅÀ×
=======
#define ROW 9		//æœ‰æ•ˆæ£‹ç›˜è¡Œæ•°
#define COL 9		//æœ‰æ•ˆæ£‹ç›˜åˆ—æ•°
#define ROWS ROW+2	//å®žé™…æ£‹ç›˜è¡Œæ•°
#define COLS COL+2	//å®žé™…æ£‹ç›˜åˆ—æ•°	   
#define COUNT 1	//åœ°é›·çš„æ•°ç›®
void InitBoard(char board[ROWS][COLS], int row, int col, char c);	//åˆå§‹åŒ–æ£‹ç›˜
void PrintBoard(char board[ROWS][COLS], int row, int col);			//æ‰“å°æ£‹ç›˜ 
void ArrangeBoard(char board[ROWS][COLS], int row, int col);		//å¸ƒé›·
void FindBoard(char board[ROWS][COLS], char ShowBoard[ROWS][COLS],int													 row, int col);			//æŽ’é›·
>>>>>>> b8cbb3e7b007ae1b82e23def3b03f1129a1e65ae
