#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

//定义的节点结构体
typedef struct QNode {
	QDataType data;
	struct QNode * next;
} QNode;

//定义的俩条链表
typedef struct Queue {
	struct QNode * front;
	struct QNode * rear;
} Queue;

//初始化
void QueueInit(Queue * pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

//销毁
void QueueDestroy(Queue * pQueue)
{
	QNode * cur = pQueue->front;
	QNode * next;
	for (cur = pQueue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	pQueue->front = pQueue->rear = NULL;
}

//插入(队尾插入)/删除(队头删除)/查看队前数据
static QNode * CreateNode(QDataType data)
{
	QNode * node = (QNode *)malloc(sizeof(QNode));
	assert(node);
	node->data = data;
	node->next = NULL;
	return node;
}

//插入
void QueuePush(Queue * pQueue, QDataType data)
{
	QNode * newNode = CreateNode(data);
	if (pQueue->front == NULL)
	{
		pQueue->front = pQueue->rear = newNode;
		return;
	}
	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

//删除
void QueuePop(Queue *pQueue)
{
	assert(pQueue != NULL);			// 地址需要有效
	assert(pQueue->front != NULL);	// 队列为空，不支持

	QNode *del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);

	// 队列中只有一个结点
	if (pQueue->front == NULL) {
		pQueue->rear = NULL;
	}
}

//查看队首数据
QDataType QueueFront(Queue * pQueue)
{
	assert(pQueue != NULL);
	assert(pQueue->front != NULL);
	return pQueue->front->data;
}

//查看队列是否为空
int QueueEmpty(const Queue * pQueue)
{
	return pQueue->front == NULL;
}

//返回数据个数
int QueueSize(const Queue * pQueue)
{
	int size = 0;
	QNode * cur = pQueue->front;
	for (cur = pQueue->front; cur != NULL; cur = cur->next)
	{
		size++;
	}
	return size;
}