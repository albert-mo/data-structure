#include <stdio.h>
#include <cstdlib> //malloc、free函数的头文件

// typedef <数据类型> <别名> -- 数据类型重命名
typedef struct DNode //定义双链表结点类型
{
    int data;                   // 数据，每个结点存放一个数据元素
    struct DNode *prior, *next; // 前驱和后继指针
} DNode, *DLinkList;            //DNode *L(强调是双链表) 等价与 DLinklist L(强调是结点),可读性更强

//初始化双链表
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode)); //分配一个头结点
    if (L == NULL)                      //内存不足，分配失败
        return false;
    L->prior = NULL; //头结点的prior永远指向NULL
    L->next = NULL;  //头结点之后暂时还没有节点
    return true;
}

//在p结点之后插入s节点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL) //非法参数
        return false;
    s->next = p->next;      //将结点*s插入到结点p之后
    if (p->next != NULL)    //p没有后继结点即不需要设置其前驱结点
        p->next->prior = s; //将p后继节点的前驱节点设置为s
    s->prior = p;
    p->next = s;
}

// 删除p结点之后的结点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next; //找到p的后继结点q
    if (q == NULL)      //p没有后继
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q); //释放结点空间
    return true;
}

void testDLinkList()
{
    //初始化双链表
    DLinkList L;
    InitDLinkList(L);
}

int main()
{
    testDLinkList;
    return 0;
}