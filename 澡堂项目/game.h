

#ifndef _GAME_H_  
#define _GAME_H_  

#include <stdio.h>  
#include <windows.h>  
#include <stdlib.h>   
#include <string.h> 
#include <time.h>  
#define ROW 10 
#define COL 10 

void game();
void chushiqipan(char board[ROW][COL], int row, int col);//初始化澡堂
void displayboard(char board[ROW][COL], int row, int col);//显示澡堂规模
void moveboard(char board[ROW][COL], int row, int col);//学生洗澡位置
int IFull(char board[ROW][COL], int  row, int  col);//判断满了
#endif 