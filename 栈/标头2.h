#pragma once
#include<assert.h>

#define COL 6
#define ROW 6

typedef struct Maze {
	int _map[ROW][COL];
}Maze;

typedef struct Position {
	int _x;
	int _y;
}Position;

//��ͼ����--->�����ļ��Ƚ����˼��
//��ά������δ��Σ�
//��δ���һ����̬�Ķ�ά����?
void InitMaze(Maze* m, int map[ROW][COL])
{
	int i = 0;
	int j = 0;
	assert(m);
	for(;)


}