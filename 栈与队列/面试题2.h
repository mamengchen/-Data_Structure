#pragma once

#include"队列.h"
#include"栈.h"

//两个栈实现队列

typedef struct ShedQueue {
	ShedList shed1;
	ShedList shed2;
} ShedQueue;

//初始化
void ShedQueueInit(ShedQueue * pSeq)
{
	ShedListInit(&(pSeq->shed1));
	ShedListInit(&(pSeq->shed2));
}

//第一个栈进元素，第二栈出元素
void PushDoudleShed(ShedQueue * pSeq, ShedDataType data)
{
	PushShedList(&(pSeq->shed1), data);
}


void PopDoudleShed(ShedQueue * pSeq)
{
	ShedList * p1 = &(pSeq->shed1);
	ShedList * p2 = &(pSeq->shed2);
	if (Nodevoid(p2))
	{
		while (!Nodevoid(p1))
		{
				PushShedList(p2, FindShedNode(p1));
				PopShedList(p1);
		}
	}
	
}

//查看栈顶元素
int TopDoudleShed(ShedQueue * pSeq)
{
	int r = FindShedNode(&(pSeq->shed2));
	PopShedList(&(pSeq->shed2));
	return r;
}

void Test1()
{
	ShedQueue stack;
	ShedQueueInit(&stack);

	ShedDataType number[] = { 1,2,3,4,5,6,7,8,9 };
	printf("存储序列；\n");
	for (int i = 0; i < sizeof(number) / sizeof(number[0]); i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n两个栈实现队列的打印序列；\n");
	for (int i = 0; i < sizeof(number) / sizeof(number[0]); i++)
	{
		PushDoudleShed(&stack, number[i]);
	}
	PopDoudleShed(&stack);
	for (int i = 0; i < sizeof(number) / sizeof(number[0]); i++)
	{
		printf("%d ", TopDoudleShed(&stack));
	}
}