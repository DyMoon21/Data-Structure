#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

/*
typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Queue;

void initQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}


*/
typedef struct
{
    ElemType *data;
    int front;
    int rear;
}Queue;

//初始化
Queue* initQueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); 
    q->front = 0;
    q->rear = 0;
    return q;
}

//判断队列是否为空
int isEmpty(Queue *Q)
{
    if (Q->front == Q->rear)
    {
        printf("空的\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

//出队
ElemType dequeue(Queue *Q)
{
    if (Q->front == Q->rear)
    {
        printf("空的\n");
        return 0;
    }
    ElemType e = Q->data[Q->front];
    Q->front++;
    return e;
}

//队尾满了，调整队列
int queueFull(Queue *Q)
{
    if (Q->front > 0)
    {
        int step = Q->front;
        for (int i = Q->front; i <= Q->rear; ++i)
        {
            Q->data[i - step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 1;
    }
    else
    {
        printf("队列已满\n"); 
        return 0;
    }
}

//入队
int enqueue(Queue *Q, ElemType e)
{
    if (Q->rear >= MAXSIZE)
    {
        if(!queueFull(Q))
        {
            return 0;
        }
    }
    Q->data[Q->rear] = e;
    Q->rear++;
    return 1;
}

//获取队头元素
int getHead(Queue *Q, ElemType *e)
{
    if (Q->front == Q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *e = Q->data[Q->front];
    return 1;
}

int main()
{
    Queue *q = initQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    ElemType e;
    getHead(q, &e);
    printf("%d\n",e);

    return 0;
}