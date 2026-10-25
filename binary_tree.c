#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;

typedef TreeNode* BiTree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

void createTree(BiTree *T)
{
    ElemType ch;
    ch = str[idx++];
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);
    }
}

//前序遍历
void preOrder(BiTree T)
{
    if (T == NULL)
    {
        return;
    }

    printf("%c ",T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

//中序遍历
void inOrder(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    inOrder(T->lchild);
    printf("%c ", T->data);
    inOrder(T->rchild);
}

//后序遍历
void postOrder(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c ", T->data);
}

int main()
{
    BiTree T;
    createTree(&T);

    preOrder(T);
    printf("\n");

    inOrder(T);
    printf("\n");

    postOrder(T);
    printf("\n");

    return 0;
}

