#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef int ElemType;

typedef struct
{
    ElemType *data;
    int front;
    int rear;
}Queue;

Queue* initQueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); 
    q->front = 0;
    q->rear = MAXSIZE - 1;
    return q;
}

int equeue(Queue *Q, ElemType e)
{
    Q->rear = (Q->rear + 1) % MAXSIZE;
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        printf("满了\n");
        return 0;
    }
    Q->data[Q->rear] = e;
    return 1;
}

//出队
int dequeue(Queue *Q, ElemType *e)
{
    if (Q->front == Q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}