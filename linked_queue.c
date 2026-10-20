#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct QueueNode
{
    ElemType data;
    struct QueueNode *next;
}QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
}Queue;

Queue* initQueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

//判断队列是否为空
int isEmpty(Queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//入队
void equeue(Queue *q, ElemType e)
{
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

//出队
int dequeue(Queue *q, ElemType *e)
{
    QueueNode *node = q->front->next;
    *e = node->data;
    q->front->next = node->next;
    if (q->rear == node)
    {
        q->rear = q->front;
    }
    free(node);
    return 1;
}

//获取队头元素
ElemType getFront(Queue *q)
{
    if (isEmpty(q))
    {
        printf("空的\n");
        return 0;
    }
    return q->front->next->data;
}

int main()
{
    Queue *q = initQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    ElemType e;
    dequeue(q, &e);
    printf("出队%d\n", e);
    dequeue(q, &e);
    printf("出队%d\n", e);
    printf("%d\n", getFront(q));
    return 0;
}