#define _CRT_SECURE_NO_WARNINGS
#define Row 10
#define Lin 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char Iswin(char arr[Row][Lin], int row, int lin);
void Playermove(char arr[Row][Lin], int row, int lin);
void ComputerMove(char arr[Row][Lin], int row, int lin);
void ShowBoard(char arr[Row][Lin], int row, int lin);