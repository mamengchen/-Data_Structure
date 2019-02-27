#pragma once

#include"����.h"
#include"ջ.h"

//������������ʵ��ջ�Ĵ洢

typedef struct DoubleQNode {
	  Queue  list1;
	  Queue  list2;
}DbQNode;

//��ʼ��
void DbQNodeInit(DbQNode * pSeq)
{
	QueueInit(&(pSeq->list1));
	QueueInit(&(pSeq->list2));
}

//����
void DbQNodeDestroy(DbQNode * pSeq)
{
	QueueDestroy(&(pSeq->list1));
	QueueDestroy(&(pSeq->list2));
}

//���ж���������˭�ǿյģ������ǿյ�ѹ������

void PushDbQNode(DbQNode * pSeq, QDataType data)
{
    Queue * pNotEmpty = &(pSeq->list2);
	if (QueueEmpty(pNotEmpty))
	{
		pNotEmpty = &(pSeq->list1);
	}
	QueuePush(pNotEmpty, data);
}


//�������ӡ��ʱ�򱣳�һ��Ϊ�գ���һ����Ԫ�أ����ӵ����ݷ�����Ԫ�ض��еĺ���
void PopDbQNode(DbQNode *pQS)
{
	// ������
	// ���ǳ�����ȷ��ǰ�᣺
	// 1. һ���ա�һ���ǿ�
	// 2. �������ǿ�
	Queue *pEmpty = &(pQS->list1);
	Queue *pNotEmpty = &(pQS->list2);
	if (QueueEmpty(pNotEmpty)) {
		pEmpty = &(pQS->list2);
		pNotEmpty = &(pQS->list1);
	}

	// �ӷǿն����� move  size - 1 ��Ԫ�ص� �ն�����
	while (QueueSize(pNotEmpty) > 1) {
		QDataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}

	// pNotEmpty ������ֻʣһ������
	QueuePop(pNotEmpty);
}



QDataType PrintTopDbQNode(DbQNode * pSeq)
{
	Queue * pEmpty = &(pSeq->list1);
	Queue * pNotEmpty = &(pSeq->list2);
	if (QueueEmpty(pNotEmpty))
	{
		pEmpty = &(pSeq->list2);
		pNotEmpty = &(pSeq->list1);
	}
	while (QueueSize(pNotEmpty) > 1)
	{
		QDataType data = QueueFront(pNotEmpty);
		QueuePush(pEmpty, data);
		QueuePop(pNotEmpty);
	}
		QDataType r = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		return r;   
}


void Test3()
{
	DbQNode stack;
	DbQNodeInit(&stack);
	QDataType num[] = { 1,2,3,4,5,6,7 };
	QDataType size = sizeof(num) / sizeof(num[0]);
	printf("�洢��ʽ");
	for (int i = 0; i < size; i++)
	{
		PushDbQNode(&stack, num[i]);
		printf("%d ", num[i]);
	}
	printf("\n");
	printf("���ն��з�ʽ�洢������ջ����>");
	for (int i = 0; i < size; i++)
	{
		
		printf("%d ", PrintTopDbQNode(&stack));
	}
}

//typedef struct {
//	Queue	queue_1;
//	Queue	queue_2;
//}	QStack;
//
//// ��ʼ��/����
//void QSInit(QStack *pQS)
//{
//	QueueInit(&(pQS->queue_1));
//	QueueInit(&(pQS->queue_2));
//}
//
//void QSDestroy(QStack *pQS)
//{
//	QueueDestroy(&(pQS->queue_2));
//	QueueDestroy(&(pQS->queue_1));
//}
//
//// Push / Pop / Top
//void QSPush(QStack *pQS, QDataType data)
//{
//	Queue *pNotEmpty = &(pQS->queue_2);
//	if (QueueEmpty(pNotEmpty)) {
//		pNotEmpty = &(pQS->queue_1);
//	}
//
//	QueuePush(pNotEmpty, data);
//}
//
//
//void QSPop(QStack *pQS)
//{
//	// ������
//	// ���ǳ�����ȷ��ǰ�᣺
//	// 1. һ���ա�һ���ǿ�
//	// 2. �������ǿ�
//	Queue *pEmpty = &(pQS->queue_1);
//	Queue *pNotEmpty = &(pQS->queue_2);
//	if (QueueEmpty(pNotEmpty)) {
//		pEmpty = &(pQS->queue_2);
//		pNotEmpty = &(pQS->queue_1);
//	}
//
//	// �ӷǿն����� move  size - 1 ��Ԫ�ص� �ն�����
//	while (QueueSize(pNotEmpty) > 1) {
//		QDataType data = QueueFront(pNotEmpty);
//		QueuePop(pNotEmpty);
//		QueuePush(pEmpty, data);
//	}
//
//	// pNotEmpty ������ֻʣһ������
//	QueuePop(pNotEmpty);
//}
//
//QDataType QSTop(QStack *pQS)
//{
//	// ������
//	// ���ǳ�����ȷ��ǰ�᣺
//	// 1. һ���ա�һ���ǿ�
//	// 2. �������ǿ�
//	Queue *pEmpty = &(pQS->queue_1);
//	Queue *pNotEmpty = &(pQS->queue_2);
//	if (QueueEmpty(pNotEmpty)) {
//		pEmpty = &(pQS->queue_2);
//		pNotEmpty = &(pQS->queue_1);
//	}
//
//	// �ӷǿն����� move  size - 1 ��Ԫ�ص� �ն�����
//	while (QueueSize(pNotEmpty) > 1) {
//		QDataType data = QueueFront(pNotEmpty);
//		QueuePop(pNotEmpty);
//		QueuePush(pEmpty, data);
//	}
//
//	// pNotEmpty ������ֻʣһ������
//	QDataType r = QueueFront(pNotEmpty);
//	QueuePop(pNotEmpty);
//	QueuePush(pEmpty, r);
//
//	return r;
//}
//
//#include <stdio.h>
//
//void Test3()
//{
//	/*
//	QStack	*stack;	// ָ�� vs ָ��ָ��Ŀռ�	(Ұָ��)
//	QSInit(stack);
//	*/
//
//	QStack	stack;
//	QSInit(&stack);
//
//	for (int i = 0; i < 5; i++) {
//		QSPush(&stack, i);
//		printf("ѹ���� %d, Top = %d\n", i, QSTop(&stack));
//	}
//
//	for (int i = 0; i < 3; i++) {
//		QSPop(&stack);
//		printf("Top = %d\n", QSTop(&stack));
//	}
//
//	for (int i = 0; i < 2; i++) {
//		QSPush(&stack, i + 10);
//		printf("ѹ���� %d, Top = %d\n", i + 10, QSTop(&stack));
//	}
//}