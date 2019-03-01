#pragma once
#include<assert.h>
#include<stdlib.h>
//链表栈

typedef int QDataType;

typedef struct QNode {
	QDataType data;
	struct QNode* next;
}QNode;

typedef struct Queue {
	QNode* front;
	QNode* rear;
}Queue;

//初始化
void QueueInit(Queue* pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

//销毁
void QueueDestroy(Queue* pQueue)
{
	QNode* cur,* next;
	for (cur = pQueue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	pQueue->front = pQueue->rear = NULL;
}

//扩容函数
static QNode * CreateNode(QDataType data)
{
	QNode* node = (QNode *)malloc(sizeof(QNode));
	assert(node);
	node->data = data;
	node->next = NULL;
	return node;
}

//插入（队尾插入）
void QueuePush(Queue* pQueue, QDataType data)
{
	QNode* newNode = CreateNode(data);
	if (pQueue->front == NULL) {
		pQueue->front = pQueue->rear = newNode;
		return;
	}
	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

//删除（队头删除）
void QueuePop(Queue* pQueue)
{
	assert(pQueue != NULL);
	//地址需要有效
	assert(pQueue->front != NULL);
	//队列为空就不需要进行删除
	QNode* del = pQueue->front;
	pQueue->front =
}
//查看队首数据