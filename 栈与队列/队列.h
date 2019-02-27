#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

//����Ľڵ�ṹ��
typedef struct QNode {
	QDataType data;
	struct QNode * next;
} QNode;

//�������������
typedef struct Queue {
	struct QNode * front;
	struct QNode * rear;
} Queue;

//��ʼ��
void QueueInit(Queue * pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

//����
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

//����(��β����)/ɾ��(��ͷɾ��)/�鿴��ǰ����
static QNode * CreateNode(QDataType data)
{
	QNode * node = (QNode *)malloc(sizeof(QNode));
	assert(node);
	node->data = data;
	node->next = NULL;
	return node;
}

//����
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

//ɾ��
void QueuePop(Queue *pQueue)
{
	assert(pQueue != NULL);			// ��ַ��Ҫ��Ч
	assert(pQueue->front != NULL);	// ����Ϊ�գ���֧��

	QNode *del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);

	// ������ֻ��һ�����
	if (pQueue->front == NULL) {
		pQueue->rear = NULL;
	}
}

//�鿴��������
QDataType QueueFront(Queue * pQueue)
{
	assert(pQueue != NULL);
	assert(pQueue->front != NULL);
	return pQueue->front->data;
}

//�鿴�����Ƿ�Ϊ��
int QueueEmpty(const Queue * pQueue)
{
	return pQueue->front == NULL;
}

//�������ݸ���
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