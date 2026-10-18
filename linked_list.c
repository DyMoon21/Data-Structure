#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct node {
    ElemType data;
    struct node *next;
}Node;

//初始化链表
Node* initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//初始化节点（带节点数据域参数）
Node* initListWithElem(ElemType e)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    return node;
}

//头插法
int insertHead(Node* L, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

//遍历
void listNode(Node* L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//获取尾部结点
Node* get_tail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

//尾插法
Node* insertTail(Node *tail, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

//尾插法（节点）
Node* insertTailWithNode(Node *tail, Node *node)
{
    tail->next = node;
    node->next = NULL;
    return node;
}

//指定位置插入
int insertNode(Node *L, int pos, ElemType e)
{
    //用来保存插入位置的前驱结点
    Node *p = L;
    int i = 0;

    //遍历链表找到插入位置的前驱节点
    while (i < pos-1)
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            return 0;
        }
    }

    //要插入的新节点
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

//删除节点
int deleteNode(Node *L, int pos)
{
    //要删除节点的前驱
    Node *p = L;
    int i = 0;
    //遍历链表，找到要删除节点的前驱
    while(i < pos-1)
    {
        p = p->next;
        i++;
        if(p == NULL)
        {
            return 0;
        }
    }

    if(p->next == NULL)
    {
        printf("要删除的位置错误\n");
        return 0;
    }
    //q指向要删除的节点
    Node *q = p->next;
    //让要删除节点的前驱指向要删除节点的后继
    p->next = q->next;
    //释放要删除节点的内存空间
    free(q);
    return 1;
}

//获取链表长度
int listLength(Node *L)
{
    Node *p = L;
    int len = 0;
    while(p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//释放链表
void freeList(Node *L)
{
    Node *p = L->next;
    Node *q;

    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

//查找倒数第k个节点
int findNodeFS(Node *L, int k)
{
    Node *fast = L->next;
    Node *slow = L->next;

    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("倒数第%d个节点值为；%d", k, slow->data);
    return 1;
}

//查找两个节点共同后缀的起始位置
Node* findIntersectionNode(Node *headA,Node *headB)
{
    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }

    Node *p = headA;
    int lenA = 0;
    int lenB = 0;

    //遍历链表A，获取链表A的长度
    while(p != NULL)
    {
        p = p->next;
        lenA++;
    }

    //遍历链表B，获取链表B的长度
    p = headB;
    while(p != NULL)
    {
        p = p->next;
        lenB++;
    }

    Node *m;//快指针
    Node *n;//慢指针
    int step;//两个单词之间数量的差值，可以用于快指针先走的步数
    if(lenA > lenB)
    {
        step = lenA - lenB;
        m = headA;
        n = headB;
    }
    else
    {
        step = lenB - lenA;
        m = headB;
        n = headA;
    }
    //让快指针先走step步
    for (int i = 0; i < step; i++)
    {
        m = m->next;
    }
    //快慢指针同步走。直到指向同一个节点退出循环
    while(m != n)
    {
        m = m->next;
        n = n->next;
    }
    return m;
}

//删除绝对值相同的节点
void removeNode(Node *L, int n)
{
    Node *p = L;
    int index;//作为数组下标使用
    int *q = (int*)malloc(sizeof(int)*(n+1));

    //遍历数组，初始化为0
    for(int i = 0; i < n+1; i++)
    {
        *(q + i) = 0;
    }

    while(p->next != NULL)
    {
        //abs获取绝对值
        index = abs(p->next->data);
        if(*(q+index) == 0)
        {
            *(q + index) = 1;
            p = p->next;
        }
        else
        {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
}

//反转链表
Node* reverseList(Node* head)
{
    Node *first = NULL;
    Node *second = head->next;
    Node *third;

    while(second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    Node *hd = initList();
    hd->next = first;

    return hd;
}

//删除中间节点
int delMiddleNode(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *q = slow->next;
    slow->next = q->next;
    free(q);
    return 1;
}

int main()
{
    Node *list = initList();

    Node *tail = get_tail(list);

    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    tail = insertTail(tail, 7);
    listNode(list);
    delMiddleNode(list);
    listNode(list);
    return 0;
}