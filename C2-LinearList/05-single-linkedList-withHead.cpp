#include <stdio.h>
#include <cstdlib> //malloc、free函数的头文件

// typedef <数据类型> <别名> -- 数据类型重命名
typedef struct LNode //定义单链表节点类型
{
    int data;           // 数据，每个节点存放一个数据元素
    struct LNode *next; //指针，指向下一个节点
} LNode, *LinkList;     //LNode *L(强调是单链表) 等价与 Linklist L(强调是节点),可读性更强

// 初始化一个空的单链表(带头节点)
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //分配一个头节点
    if (L == NULL)                      //内存不足，分配失败
        return false;
    L->next == NULL;
    return true;
}

// 判断单链表是否为空
bool Empty(LinkList L)
{
    return (L->next == NULL);
}

/* 在第i个位置插入元素e(带头节点)
最好时间复杂度=O(1)
平均时间复杂度=O(1/2 * n)
最坏时间复杂度=O(n) */
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    LNode *p;                      //指针p指向当前扫描到的节点
    int j = 0;                     //当前p指向的是第几个节点
    p = L;                         //L指向头节点，头节点是0个节点（不存放数据）
    while (p != NULL && j < i - 1) //循环找到第i-1个节点
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; //将节点s连到p之后
    return true; //插入成功
}

// 测试初始化
void test()
{
    LinkList L;  //声明一个指向单链表的指针
    InitList(L); //初始化一个单链表
}

int main()
{
    test;
    return 0;
}