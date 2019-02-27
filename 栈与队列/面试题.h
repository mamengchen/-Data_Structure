#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"队列.h"
#include"栈.h"

//实现一个栈，要求实现push(出栈)，Pop(入栈)，Min(返回最小值)的时间复杂度为O（1）


typedef struct Minstack {
	ShedList stackNormal; //保存正常序列的栈
	ShedList stackMin; //保存当前含有最小的栈
} Minstack;

//初始化
void MinstackInit(Minstack * pSeq)
{
	ShedListInit(&(pSeq->stackNormal));
	ShedListInit(&(pSeq->stackMin));
}

//销毁
void MinstackDestroy(Minstack * pSeq)
{
	ShedListDestroy(&(pSeq->stackNormal));
	ShedListDestroy(&(pSeq->stackMin));
}

//增
void PushMinstack(Minstack * pSeq, ShedDataType data)
{
	PushShedList((&(pSeq->stackNormal)), data);
	if (Nodevoid(&(pSeq->stackMin)))
	{
		PushShedList((&(pSeq->stackMin)), data);
		return;
	}

	if (data <= FindShedNode(&(pSeq->stackMin)))
	{
		PushShedList((&(pSeq->stackMin)), data);
	}
	else
	{
		PushShedList(&(pSeq->stackMin), FindShedNode(&(pSeq->stackMin)));
	}
}

//删除
void PopMinstack(Minstack * pSeq)
{
	PopShedList(&(pSeq->stackNormal));
	PopShedList(&(pSeq->stackMin));
}

//查看正常栈的栈顶元素
int MinstackNormal(Minstack * pSeq)
{
	return FindShedNode(&(pSeq->stackNormal));
}

//查看栈中最小元素
int MinstackMin(Minstack * pSeq)
{
	return FindShedNode(&(pSeq->stackMin));
}

void Test()
{
	Minstack stack;
	MinstackInit(&stack);
	ShedDataType number[] = { 5, 2, 4, 7, 1, 6, 8, 9, 3 };
	for (int i = 0; i < sizeof(number) / sizeof(number[0]); i++)
	{
		PushMinstack(&stack, number[i]);
		printf("栈顶元素>%d ,栈中最小元素>%d\n", MinstackNormal(&stack), MinstackMin(&stack));
	}
	printf("\n");
	for (int i = 0; i < sizeof(number) / sizeof(number[0]); i++)
	{
		
		printf("栈顶元素>%d ,栈中最小元素>%d\n", MinstackNormal(&stack), MinstackMin(&stack));
		PopMinstack(&stack);
	}
	
}