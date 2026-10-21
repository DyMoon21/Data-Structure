#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct 
{
	ElemType *data;
	int top;
	
}Stack;

typedef enum
{
	LEFT_PARE, RIGHT_PARE,
	ADD, SUB, MUL, DIV, MOD,
	EOS, NUM
} contentType;

char expr[] = "x/(i-j)*y";

//初始化
Stack* initStack()
{
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	s->top = -1;
	return s;
}

//判断栈是否为空
int isEmpty(Stack *s)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

//进栈/压栈
int push(Stack *s, ElemType e)
{

	if (s->top >= MAXSIZE - 1)
	{
		printf("满了\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}

//出栈
int pop(Stack *s, ElemType *e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}

//获取栈顶元素
int getTop(Stack *s, ElemType *e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}

contentType getToken(char *symbol, int *index)
{
	*symbol = expr[*index];
	*index = *index + 1;
	switch(*symbol)
	{
		case '(':
			return LEFT_PARE;
		case ')':
			return RIGHT_PARE;
		case '+':
			return ADD;
		case '-':
			return SUB;
		case '*':
			return MUL;
		case '/':
			return DIV;
		case '%':
			return MOD;
		case '\0':
			return EOS;
		default:
			return NUM;

	}
}

int print_token(contentType token)
{
	switch(token)
	{
		case ADD:
			printf("+");
			break;
		case SUB:
			printf("-");
			break;
		case MUL:
			printf("*");
			break;
		case DIV:
			printf("/");
			break;
		case MOD:
			printf("%%");
			break;
		default:
			return 0;
	}
	return 1;
}

void postfix(Stack *s)
{
	int in_stack[] = {0, 19, 12, 12, 13, 13, 13, 0};
	int out_stack[] = {20, 19, 12, 12, 13, 13, 13, 0};
	contentType token;
	int index = 0;
	s->top = 0;
	s->data[0] = EOS;
	char symbol;
	ElemType e;

	token = getToken(&symbol, &index);
	while(token != EOS)
	{
		if (token == NUM)
		{
			printf("%c", symbol);
		}
		else if (token == RIGHT_PARE)
		{
			while(s->data[s->top] != LEFT_PARE)
			{
				pop(s, &e);
				print_token(e);
			}
			pop(s, &e);
		}
		else
		{
			while(in_stack[s->data[s->top]] >= out_stack[token])
			{
				pop(s, &e);
				print_token(e);
			}
			push(s, token);
		}
		token = getToken(&symbol, &index);
	}

	pop(s, &e);
	token = e;
	while(token != EOS)
	{
		print_token(token);
		pop(s, &e);
		token = e;
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	Stack *s = initStack();
	printf("%s\n", expr);
	postfix(s);
	return 0;
}



