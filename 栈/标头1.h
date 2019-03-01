#pragma once
#include<assert.h>
#include<stdlib.h>
//����ջ

typedef int QDataType;

typedef struct QNode {
	QDataType data;
	struct QNode* next;
}QNode;

typedef struct Queue {
	QNode* front;
	QNode* rear;
}Queue;

//��ʼ��
void QueueInit(Queue* pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

//����
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

//���ݺ���
static QNode * CreateNode(QDataType data)
{
	QNode* node = (QNode *)malloc(sizeof(QNode));
	assert(node);
	node->data = data;
	node->next = NULL;
	return node;
}

//���루��β���룩
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

//ɾ������ͷɾ����
void QueuePop(Queue* pQueue)
{
	assert(pQueue != NULL);
	//��ַ��Ҫ��Ч
	assert(pQueue->front != NULL);
	//����Ϊ�վͲ���Ҫ����ɾ��
	QNode* del = pQueue->front;
	pQueue->front =
}
//�鿴��������