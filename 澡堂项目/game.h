

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
void chushiqipan(char board[ROW][COL], int row, int col);//��ʼ������
void displayboard(char board[ROW][COL], int row, int col);//��ʾ���ù�ģ
void moveboard(char board[ROW][COL], int row, int col);//ѧ��ϴ��λ��
int IFull(char board[ROW][COL], int  row, int  col);//�ж�����
#endif 