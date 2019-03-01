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

//地图数据--->保存文件比较灵活思考
//二维数组如何传参？
//如何创建一个动态的二维数组?
void InitMaze(Maze* m, int map[ROW][COL])
{
	int i = 0;
	int j = 0;
	assert(m);
	for(;)


}