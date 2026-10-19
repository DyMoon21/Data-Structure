#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int top; 
}Stack;

//初始化
void initStack(Stack *s)
{
    s->top = -1;
}

//判断栈是否为空
int isEmpty(Stack *s)
{
    if(s->top = -1)
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
int push(Stack *s,ElemType e)
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

int main()
{
    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    ElemType e;
    pop(&s,&e);
    printf("%d\n", e);
    getTop(&s,&e);
    printf("%d\n", e);

    return 0;
}

