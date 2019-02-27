#pragma once

#include"����.h"
#include"ջ.h"

//����ջʵ�ֶ���

typedef struct ShedQueue {
	ShedList shed1;
	ShedList shed2;
} ShedQueue;

//��ʼ��
void ShedQueueInit(ShedQueue * pSeq)
{
	ShedListInit(&(pSeq->shed1));
	ShedListInit(&(pSeq->shed2));
}

//��һ��ջ��Ԫ�أ��ڶ�ջ��Ԫ��
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

//�鿴ջ��Ԫ��
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
	printf("�洢���У�\n");
	for (int i = 0; i < sizeof(number) / sizeof(number[0]); i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n����ջʵ�ֶ��еĴ�ӡ���У�\n");
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