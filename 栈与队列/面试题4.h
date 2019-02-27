#pragma once

#include"队列.h"

typedef struct {
	int * array;
	int top1;
	int top2;
	int capacity;
} TStack;

//初始化
void TStackInit(TStack *pTS)
{
	pTS->capacity = 10;
	pTS->
}