#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"����.h"
#include"ջ.h"

//ʵ��һ��ջ��Ҫ��ʵ��push(��ջ)��Pop(��ջ)��Min(������Сֵ)��ʱ�临�Ӷ�ΪO��1��


typedef struct Minstack {
	ShedList stackNormal; //�����������е�ջ
	ShedList stackMin; //���浱ǰ������С��ջ
} Minstack;

//��ʼ��
void MinstackInit(Minstack * pSeq)
{
	ShedListInit(&(pSeq->stackNormal));
	ShedListInit(&(pSeq->stackMin));
}

//����
void MinstackDestroy(Minstack * pSeq)
{
	ShedListDestroy(&(pSeq->stackNormal));
	ShedListDestroy(&(pSeq->stackMin));
}

//��
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

//ɾ��
void PopMinstack(Minstack * pSeq)
{
	PopShedList(&(pSeq->stackNormal));
	PopShedList(&(pSeq->stackMin));
}

//�鿴����ջ��ջ��Ԫ��
int MinstackNormal(Minstack * pSeq)
{
	return FindShedNode(&(pSeq->stackNormal));
}

//�鿴ջ����СԪ��
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
		printf("ջ��Ԫ��>%d ,ջ����СԪ��>%d\n", MinstackNormal(&stack), MinstackMin(&stack));
	}
	printf("\n");
	for (int i = 0; i < sizeof(number) / sizeof(number[0]); i++)
	{
		
		printf("ջ��Ԫ��>%d ,ջ����СԪ��>%d\n", MinstackNormal(&stack), MinstackMin(&stack));
		PopMinstack(&stack);
	}
	
}