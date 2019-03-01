#pragma once

typedef int SDataType;

#define MAX_SIZE 10

typedef struct Stack
{
	SDataType _array[MAX_SIZE];
	int _top;   //���ջ����ջ��Ԫ�ظ�����
}Stack;

void StackInit(Stack * ps);   //��ʼ��ջ��Ԫ��
void StackPush(Stack * ps, SDataType data);    //����ջ��Ԫ��
void StackPop(Stack * ps);      //ɾ��ջ��Ԫ��
SDataType StackTop(Stack * ps);    //�鿴ջ��Ԫ��
int StackSize(Stack * ps);       //����ջ��Ԫ�ظ���
int StackEmpty(Stack * ps);      //�鿴ջ�Ƿ�Ϊ��