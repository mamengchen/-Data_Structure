#include"±êÍ·.h"
#include <assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void StackInit(Stack * ps)
{
	assert(ps);
	ps->_top = 0;
}

void StackPush(Stack * ps, SDataType data)
{
	assert(ps);
	ps->_array[ps->_top++] = data;
}

void StackPop(Stack * ps)
{
	assert(ps);
	if (StackEmpty(ps))
	{
		return;
	}
	ps->_top--;
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->_top;
}

SDataType StackTop(Stack* ps)
{
	return ps->_array[ps->_top-1];
}
#if 0
void Test()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPop(&s);
	StackPop(&s);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));
}
#endif

#if 0
int IsBracket(char ch)
{
	if (('(' == ch || ')' == ch) ||
		('[' == ch || ']' == ch) ||
		('{' == ch || '}' == ch))
	{
		return 1;
	}
	return 0;
}
void MatchBrackets(const char* str)
{
	int i = 0;
	int size = 0;
	char ch;
	Stack s;
	if (NULL == str)
	{
		return;
	}

	StackInit(&s);
	size = strlen(str);
	for (i = 0; i < size; i++)
	{
		if (IsBracket(str[i]))
		{
			if ('(' == str[i] ||
				'[' == str[i] ||
				'{' == str[i])
			{
				StackPush(&s, str[i]);
			}
			else
			{
				if (StackEmpty(&s))
				{
					printf("ÓÒÀ¨ºÅ±È×óÀ¨ºÅ¶à\n");
					return;
				}
				//¼ì²éµ±Ç°À¨ºÅÊÇ·ñÓëÕ»¶¥À¨ºÅÆ¥Åä
				ch = StackTop(&s);
				if (!(('(' == ch && ')' == str[i]) ||
					('[' == ch && ']' == str[i]) ||
					('{' == ch && '}' == str[i])))
				{
					printf("×óÓÒÀ¨ºÅÆ¥Åä³ö´í\n");
					return;
				}
				StackPop(&s);
			}
		}
	}
	if (StackEmpty(&s))
	{
		printf("À¨ºÅÆ¥ÅäÕýÈ·:>\n");
	}
	else
	{
		printf("À¨ºÅÆ¥Åä³ö´í\n");
	}
	return;
}
int main()
{
	

	char a[] = "(())abc{[(])}";
	char b[] = "(()))abc{[]}";
	char c[] = "(()()abc{[]}";
	char d[] = "(())abc{[]()}";
	
	MatchBrackets(a);
	MatchBrackets(b);
	MatchBrackets(c);
	MatchBrackets(d);
	system("pause");
	return 0;
}
#endif
typedef enum {
	ADD,
	SUB,
	MUL,
	DIV,
	DATA
}OPERATOP;

typedef struct Cell {
	OPERATOP _op;
	int data;
}Cell;

//12 3 4 + * 6 - 8 2 / +
int CalcRPN(Cell* str, int size)
{
	Stack s;
	int i = 0;
	StackInit(&s);
	for (i = 0; i < size; i++)
	{
		if (DATA == str[i]._op)
		{
			StackPush(&s, str[i].data);
		}
		else
		{
			int left = 0, right = 0;
			right = StackTop(&s);
			StackPop(&s);
			left = StackTop(&s);
			StackPop(&s);
			switch (str[i]._op)
			{
			case ADD:
				StackPush(&s, left + right);
				break;
			case SUB:
				StackPush(&s, left - right);
				break;
			case MUL:
				StackPush(&s, left * right);
				break;
			case DIV:
				if (right == 0)
				{
					printf("³ýÊýÎª0·Ç·¨ÁË\n");
					return 0;
				}
				StackPush(&s, left / right);
				break;
			default:
				printf("ÔËËã·ûÒì³£\n");
				break;
			}
		}
	}
	return StackTop(&s);
}


int main()
{
	Cell Rpn[] = { {DATA,12},{DATA,3},{DATA,4},{ADD,0},{MUL,0},
				   {DATA,6},{SUB,0},{DATA,8},{DATA,2},{DIV,0},{ADD,0} };
	printf("Äæ²¨À¼ÊýÎª:>%d\n", CalcRPN(Rpn, sizeof(Rpn) / sizeof(Rpn[0])));
	system("pause");
	return 0;
}