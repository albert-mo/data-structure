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

/* 后插入操作：在p节点之后插入元素e
时间复杂度=O(1) */
bool insertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) //内存分配失败
        return false;
    s->data = e; //用节点s保存数据元素e
    s->next = p->next;
    p->next = s; //将几点s连到p之后
    return true;
}

/* 前插操作：在p节点前插入元素e
时间复杂度=O(1)
 */
bool insertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) //内存分配失败
        return false;
    s->next = p->next;
    p->next = s;       //s连到p之后
    s->data = p->data; //交换数据域
    p->data = e;
    return true;
}

/* 按位序删除，带头节点
最坏时间复杂度=O(n)
平均时间复杂度=O(n)
最好时间复杂度=O(1)
 */
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p;                      //指针p指向当前扫描到的节点
    int j = 0;                     //当前p指向的是第几个节点
    p = L;                         //L指向头节点，头节点是第0个节点（不存数据）
    while (p != NULL && j < i - 1) //循环找到第i-1个节点
    {
        p = p->next;
        j++;
    }
    if (p == NULL) //i值不合法
        return false;
    if (p->next == NULL) //第i-1个节点之后已无其他节点
        return false;
    LNode *q = p->next; //令q指向被删除节点
    e = q->data;        //用e返回被删除元素的值
    p->next = q->next;  //将*q节点从链中断开
    free(q);            //释放节点的存储空间
    return true;        //删除成功
}

/* 删除指定节点 p
时间复杂度=O(1)
如果p是最后一个节点，需要从头遍历找到p节点的上一个节点
时间复杂度O=(n)
 */
bool DeleteNode(LNode *p)
{
    if (p == NULL) //i值不合法
        return false;
    LNode *q = p->next; //令q指向*p的后继节点
    p->data = q->data;  //和后继节点交换数据域
    p->next = q->next;  //将*q节点从链中断开
    free(q);            //释放后继节点的存储空间
    return true;
}

/* 按位查找，返回第i个元素（带头节点）
平均数据复杂度=O(n) */
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p;                  //指针p指向当前扫描到的节点
    int j = 0;                 //当前p指向的是第几个节点
    p = L;                     //L指向头节点，头节点是第0个节点(不存数据)
    while (p != NULL && j < i) //循环找到第i个节点
    {
        p = p->next;
        j++;
    }
    return p; //如果i大于单链表长度，返回NULL
}

/* 按值查找，找到元素域==e的节点
时间复杂度=O(n)
 */
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    //从第1个节点开始查找数据域为e的节点
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p; //找到后返回该指针，否则返回NULL
}

/* 求表的长度
时间复杂度=O(n) */
int Length(LinkList L)
{
    int len = 0; //统计表长
    LNode *p = L;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
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