#pragma once

typedef int SDataType;

#define MAX_SIZE 10

typedef struct Stack
{
	SDataType _array[MAX_SIZE];
	int _top;   //标记栈顶（栈中元素个数）
}Stack;

void StackInit(Stack * ps);   //初始化栈中元素
void StackPush(Stack * ps, SDataType data);    //插入栈中元素
void StackPop(Stack * ps);      //删除栈中元素
SDataType StackTop(Stack * ps);    //查看栈顶元素
int StackSize(Stack * ps);       //计算栈中元素个数
int StackEmpty(Stack * ps);      //查看栈是否为空