#pragma once


#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>


typedef int ShedDataType;

#define MAX_SIZE (100)

typedef struct ShedList {
	ShedDataType array[MAX_SIZE];
	ShedDataType top;     //栈顶
} ShedList;

//初始化
void ShedListInit(ShedList * pSeq)
{
	pSeq->top = 0;
}
//销毁
void ShedListDestroy(ShedList * pSeq)
{
	pSeq->top = 0;
}

//尾增
void PushShedList(ShedList * pSeq, ShedDataType data)
{
	pSeq->array[pSeq->top++] = data;
}

//尾删
void PopShedList(ShedList * pSeq)
{
	assert(pSeq != NULL);
	pSeq->top--;
}

//查看栈顶的数据
int FindShedNode(ShedList * pSeq)
{
	return pSeq->array[pSeq->top - 1];
}

//栈中有多少数据
int MachNode(ShedList * pSeq)
{
	return pSeq->top;
}

//满了
int NodeFull(ShedList *pSeq)
{
	return pSeq->top > MAX_SIZE;
}

//空了
int Nodevoid(ShedList * pSeq)
{

	return pSeq->top <= 0;
}