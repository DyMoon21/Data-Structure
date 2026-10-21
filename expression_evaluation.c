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

char expr[] = "82/2+56*-";

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

int eval(Stack *s)
{
	char symbol;
	int op1, op2;
	int index = 0;
	contentType token;
	token = getToken(&symbol, &index);
	ElemType result;
	while(token != EOS)
	{
		if (token == NUM)
		{
			push(s, symbol - '0');//'8'-'0'
		}
		else
		{
			pop(s, &op2);
			pop(s, &op1);
			
			switch(token)
			{
				case ADD:
					push(s, op1 + op2);
					break;
				case SUB:
					push(s, op1 - op2);
					break;
				case MUL:
					push(s, op1 * op2);
					break;
				case DIV:
					push(s, op1 / op2);
					break;
				case MOD:
					push(s, op1 % op2);
					break;
				default:
					break;
			}
		}
		token = getToken(&symbol, &index);
	}
	pop(s, &result);
	printf("%d\n", result);
	return 1;
}


int main(int argc, char const *argv[])
{
	Stack *s = initStack();
	
	eval(s);
	
	return 0;
}



