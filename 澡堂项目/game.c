#include"game.h"

void chushiqipan(char board[ROW][COL], int row, int col)//��ʼ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)//��ʾ���ù�ģ
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void moveboard(char board[ROW][COL], int row, int col)//ѧ��ϴ��λ��
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("ϴ�跿������������:");
		scanf("%d %d", &i, &j);
		if (((i >= 1) && (i <= row + 1)) && ((j >= 1) && (j <= col + 1)))
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = 'X';
				break;
			}
			else
			{
				printf("�ط���ռ�ù�");
			}
		}
		else
		{
			printf("�������");
		}
	}
}




int IFull(char board[ROW][COL], int  row, int  col)////�ж���������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}