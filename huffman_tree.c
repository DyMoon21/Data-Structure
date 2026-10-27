#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100  // 最大节点数（足够用）
// 哈夫曼树节点结构体
typedef struct {
    int weight;   // 权值（例如成绩占比）
    int parent;   // 父节点下标
    int lchild;   // 左孩子下标
    int rchild;   // 右孩子下标
} HTNode;

typedef HTNode HuffmanTree[MAX_N];

// 在 HT[0...n-1] 中选出两个无父节点的最小权值节点，其下标存入 s1 和 s2
void selectTwoMin(HuffmanTree HT, int n, int *s1, int *s2) {
    int i;
    *s1 = *s2 = -1;
    for (i = 0; i < n; ++i) {
        if (HT[i].parent == -1) { // 只选还未被合并的节点
            if (*s1 == -1 || HT[i].weight < HT[*s1].weight) {
                *s2 = *s1;
                *s1 = i;
            } else if (*s2 == -1 || HT[i].weight < HT[*s2].weight) {
                *s2 = i;
            }
        }
    }
}

// 创建哈夫曼树
void createHuffmanTree(HuffmanTree HT, int weights[], int n) {
    int i;
    int m = 2 * n - 1;  // 总共需要 2n-1 个节点
    // 初始化所有节点
    for (i = 0; i < m; ++i) {
        HT[i].weight = (i < n) ? weights[i] : 0;  // 前 n 个为叶子节点，其它初始化为 0
        HT[i].parent = -1;
        HT[i].lchild = -1;
        HT[i].rchild = -1;
    }

    // 构造内部节点
    for (i = n; i < m; ++i) {
        int s1, s2;
        selectTwoMin(HT, i, &s1, &s2);  // 找两个最小权值的节点

        // 创建新节点 i，合并 s1 和 s2
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[s1].parent = i;
        HT[s2].parent = i;
    }
}

// 打印哈夫曼树结构（便于查看）
void printHuffmanTree(HuffmanTree HT, int n) {
    int i;
    int total = 2 * n - 1;
    printf("索引  权值  双亲  左子  右子\n");
    for (i = 0; i < total; ++i) {
        printf("%3d  %4d  %4d  %4d  %4d\n",
               i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
    }
}

int main() {
    // 根据案例设置权值：不及格、及格、中等、良好、优秀
    int weights[] = {5, 15, 40, 30, 10};
    int n = sizeof(weights) / sizeof(weights[0]);
    HuffmanTree HT;
    createHuffmanTree(HT, weights, n);  // 构建哈夫曼树
    printHuffmanTree(HT, n);            // 输出节点信息

    return 0;
}
