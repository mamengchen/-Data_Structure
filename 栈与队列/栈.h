#pragma once


#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>


typedef int ShedDataType;

#define MAX_SIZE (100)

typedef struct ShedList {
	ShedDataType array[MAX_SIZE];
	ShedDataType top;     //ջ��
} ShedList;

//��ʼ��
void ShedListInit(ShedList * pSeq)
{
	pSeq->top = 0;
}
//����
void ShedListDestroy(ShedList * pSeq)
{
	pSeq->top = 0;
}

//β��
void PushShedList(ShedList * pSeq, ShedDataType data)
{
	pSeq->array[pSeq->top++] = data;
}

//βɾ
void PopShedList(ShedList * pSeq)
{
	assert(pSeq != NULL);
	pSeq->top--;
}

//�鿴ջ��������
int FindShedNode(ShedList * pSeq)
{
	return pSeq->array[pSeq->top - 1];
}

//ջ���ж�������
int MachNode(ShedList * pSeq)
{
	return pSeq->top;
}

//����
int NodeFull(ShedList *pSeq)
{
	return pSeq->top > MAX_SIZE;
}

//����
int Nodevoid(ShedList * pSeq)
{

	return pSeq->top <= 0;
}