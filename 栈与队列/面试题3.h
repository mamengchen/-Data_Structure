#pragma once

#include"队列.h"
#include"栈.h"

//利用两个队列实现栈的存储

typedef struct DoubleQNode {
	  Queue  list1;
	  Queue  list2;
}DbQNode;

//初始化
void DbQNodeInit(DbQNode * pSeq)
{
	QueueInit(&(pSeq->list1));
	QueueInit(&(pSeq->list2));
}

//销毁
void DbQNodeDestroy(DbQNode * pSeq)
{
	QueueDestroy(&(pSeq->list1));
	QueueDestroy(&(pSeq->list2));
}

//先判断俩个链表谁是空的，给不是空的压入数据

void PushDbQNode(DbQNode * pSeq, QDataType data)
{
    Queue * pNotEmpty = &(pSeq->list2);
	if (QueueEmpty(pNotEmpty))
	{
		pNotEmpty = &(pSeq->list1);
	}
	QueuePush(pNotEmpty, data);
}


//在你想打印的时候保持一个为空，另一个有元素，增加的数据放在有元素队列的后面
void PopDbQNode(DbQNode *pQS)
{
	// 假设编程
	// 我们程序正确的前提：
	// 1. 一个空、一个非空
	// 2. 两个都是空
	Queue *pEmpty = &(pQS->list1);
	Queue *pNotEmpty = &(pQS->list2);
	if (QueueEmpty(pNotEmpty)) {
		pEmpty = &(pQS->list2);
		pNotEmpty = &(pQS->list1);
	}

	// 从非空队列中 move  size - 1 个元素到 空队列中
	while (QueueSize(pNotEmpty) > 1) {
		QDataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}

	// pNotEmpty 队列里只剩一个数据
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
	printf("存储方式");
	for (int i = 0; i < size; i++)
	{
		PushDbQNode(&stack, num[i]);
		printf("%d ", num[i]);
	}
	printf("\n");
	printf("按照队列方式存储的两个栈序列>");
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
//// 初始化/销毁
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
//	// 假设编程
//	// 我们程序正确的前提：
//	// 1. 一个空、一个非空
//	// 2. 两个都是空
//	Queue *pEmpty = &(pQS->queue_1);
//	Queue *pNotEmpty = &(pQS->queue_2);
//	if (QueueEmpty(pNotEmpty)) {
//		pEmpty = &(pQS->queue_2);
//		pNotEmpty = &(pQS->queue_1);
//	}
//
//	// 从非空队列中 move  size - 1 个元素到 空队列中
//	while (QueueSize(pNotEmpty) > 1) {
//		QDataType data = QueueFront(pNotEmpty);
//		QueuePop(pNotEmpty);
//		QueuePush(pEmpty, data);
//	}
//
//	// pNotEmpty 队列里只剩一个数据
//	QueuePop(pNotEmpty);
//}
//
//QDataType QSTop(QStack *pQS)
//{
//	// 假设编程
//	// 我们程序正确的前提：
//	// 1. 一个空、一个非空
//	// 2. 两个都是空
//	Queue *pEmpty = &(pQS->queue_1);
//	Queue *pNotEmpty = &(pQS->queue_2);
//	if (QueueEmpty(pNotEmpty)) {
//		pEmpty = &(pQS->queue_2);
//		pNotEmpty = &(pQS->queue_1);
//	}
//
//	// 从非空队列中 move  size - 1 个元素到 空队列中
//	while (QueueSize(pNotEmpty) > 1) {
//		QDataType data = QueueFront(pNotEmpty);
//		QueuePop(pNotEmpty);
//		QueuePush(pEmpty, data);
//	}
//
//	// pNotEmpty 队列里只剩一个数据
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
//	QStack	*stack;	// 指针 vs 指针指向的空间	(野指针)
//	QSInit(stack);
//	*/
//
//	QStack	stack;
//	QSInit(&stack);
//
//	for (int i = 0; i < 5; i++) {
//		QSPush(&stack, i);
//		printf("压入了 %d, Top = %d\n", i, QSTop(&stack));
//	}
//
//	for (int i = 0; i < 3; i++) {
//		QSPop(&stack);
//		printf("Top = %d\n", QSTop(&stack));
//	}
//
//	for (int i = 0; i < 2; i++) {
//		QSPush(&stack, i + 10);
//		printf("压入了 %d, Top = %d\n", i + 10, QSTop(&stack));
//	}
//}