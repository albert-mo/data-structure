#include <stdio.h>
#include <cstdlib> //malloc、free函数的头文件

// typedef <数据类型> <别名> -- 数据类型重命名
typedef struct LNode //定义循环单链表结点类型
{
    int data;           // 数据，每个结点存放一个数据元素
    struct LNode *next; //指针，指向下一个结点
} LNode, *LinkList;     //LNode *L(强调是循环单链表) 等价与 Linklist L(强调是结点),可读性更强

// 初始化一个循环单链表(带头结点)
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //分配一个头结点
    if (L == NULL)                      //内存不足，分配失败
        return false;
    L->next == L; //头结点指针指向头结点 从尾部找到头结点，时间复杂度=O(1)
    return true;
}

// 判断循环单链表是否为空
bool Empty(LinkList L)
{
    return (L->next == L);
}

//判断结点p是否是循环单链表的表尾结点
bool isTail(LinkList L, LNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}

/* 在第i个位置插入元素e(带头结点)
最好时间复杂度=O(1)
平均时间复杂度=O(1/2 * n)
最坏时间复杂度=O(n) */
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    LNode *p;                      //指针p指向当前扫描到的结点
    int j = 0;                     //当前p指向的是第几个结点
    p = L;                         //L指向头结点，头结点是0个结点（不存放数据）
    while (p != NULL && j < i - 1) //循环找到第i-1个结点
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; //将结点s连到p之后
    return true; //插入成功
}

/* 后插入操作：在p结点之后插入元素e
时间复杂度=O(1) */
bool insertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) //内存分配失败
        return false;
    s->data = e; //用结点s保存数据元素e
    s->next = p->next;
    p->next = s; //将几点s连到p之后
    return true;
}

/* 前插操作：在p结点前插入元素e
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

/* 按位序删除，带头结点
最坏时间复杂度=O(n)
平均时间复杂度=O(n)
最好时间复杂度=O(1)
 */
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p;                      //指针p指向当前扫描到的结点
    int j = 0;                     //当前p指向的是第几个结点
    p = L;                         //L指向头结点，头结点是第0个结点（不存数据）
    while (p != NULL && j < i - 1) //循环找到第i-1个结点
    {
        p = p->next;
        j++;
    }
    if (p == NULL) //i值不合法
        return false;
    if (p->next == NULL) //第i-1个结点之后已无其他结点
        return false;
    LNode *q = p->next; //令q指向被删除结点
    e = q->data;        //用e返回被删除元素的值
    p->next = q->next;  //将*q结点从链中断开
    free(q);            //释放结点的存储空间
    return true;        //删除成功
}

/* 删除指定结点 p
时间复杂度=O(1)
如果p是最后一个结点，需要从头遍历找到p结点的上一个结点
时间复杂度O=(n)
 */
bool DeleteNode(LNode *p)
{
    if (p == NULL) //i值不合法
        return false;
    LNode *q = p->next; //令q指向*p的后继结点
    p->data = q->data;  //和后继结点交换数据域
    p->next = q->next;  //将*q结点从链中断开
    free(q);            //释放后继结点的存储空间
    return true;
}

/* 按位查找，返回第i个元素（带头结点）
平均数据复杂度=O(n) */
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p;                  //指针p指向当前扫描到的结点
    int j = 0;                 //当前p指向的是第几个结点
    p = L;                     //L指向头结点，头结点是第0个结点(不存数据)
    while (p != NULL && j < i) //循环找到第i个结点
    {
        p = p->next;
        j++;
    }
    return p; //如果i大于循环单链表长度，返回NULL
}

/* 按值查找，找到元素域==e的结点
时间复杂度=O(n)
 */
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    //从第1个结点开始查找数据域为e的结点
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

/* 尾插法建立循环单链表
时间复杂度=O(n) */
LinkList List_TailInsert(LinkList &L)
{                                        //正向建立循环单链表
    int x;                               // 设ElemType为整形
    L = (LinkList)malloc(sizeof(LNode)); //建立头结点
    LNode *s, *r = L;                    //r为表尾指针
    scanf("%d", &x);                     //输入结点的值
    while (x != 9999)                    //输入9999表示结束
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s; //r指向新的表尾结点
        scanf("%d", &x);
    }
    r->next = NULL; //表尾结点指针置空
    return L;
}

/* 头插法建立循环单链表
时间复杂度=O(n) */
LinkList LIst_HeadInsert(LinkList &L) //逆向建立循环单链表
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //创建头结点
    L->next = NULL;                      //初始为空链表
    scanf("%d", &x);                     //输入结点的值
    while (x != 9999)                    //输入9999表示结束
    {
        s = (LinkList)malloc(sizeof(LNode)); //创建新结点
        s->data = x;
        s->next = L->next;
        L->next = s; //将新结点插入表中，L为头指针
        scanf("%d", &x);
    }
    return L;
}

// 测试初始化
void test()
{
    LinkList L;  //声明一个指向循环单链表的指针
    InitList(L); //初始化一个循环单链表
}

int main()
{
    test;
    return 0;
}