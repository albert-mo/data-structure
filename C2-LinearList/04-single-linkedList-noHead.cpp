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