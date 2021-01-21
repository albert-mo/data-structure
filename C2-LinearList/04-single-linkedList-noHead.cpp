#include <stdio.h>
#include <cstdlib> //malloc、free函数的头文件

// typedef <数据类型> <别名> -- 数据类型重命名
typedef struct LNode //定义单链表节点类型
{
    int data;           // 数据，每个节点存放一个数据元素
    struct LNode *next; //指针，指向下一个节点
} LNode, *LinkList;     //LNode *L(强调是单链表) 等价与 Linklist L(强调是节点),可读性更强

// 初始化一个空的单链表
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}

// 判断单链表是否为空
bool Empty(LinkList L)
{
    return (L == NULL);
}

/* 在第i个位置插入元素e(不带头节点)
最好时间复杂度=O(1)
平均时间复杂度=O(1/2 * n)
最坏时间复杂度=O(n) */
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    if (i == = 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;  //指针p指向当前扫描到的节点
    int j = 1; //当前p指向的是第几个节点
    p = L;     //p指向第一个节点（注意：不是头节点）
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++ ；
    }
    if (p == NULL) //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;  //先将当前指针p.next设为s.next
    p->next = s;    //再将s设为p.next
    return true; //插入成功
}

void test()
{
    LinkList L;
    InitList(L);
}

int main()
{
    test;
    return 0;
}