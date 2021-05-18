#include <stdio.h>
#include <cstdlib> //malloc��free������ͷ�ļ�

// typedef <��������> <����> -- ��������������
typedef struct LNode //���嵥����������
{
    int data;           // ���ݣ�ÿ�������һ������Ԫ��
    struct LNode *next; //ָ�룬ָ����һ�����
} LNode, *LinkList;     //LNode *L(ǿ���ǵ�����) �ȼ��� Linklist L(ǿ���ǽ��),�ɶ��Ը�ǿ

// ��ʼ��һ���յĵ�����(��ͷ���)
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //����һ��ͷ���
    if (L == NULL)                      //�ڴ治�㣬����ʧ��
        return false;
    L->next == NULL;
    return true;
}

// �жϵ������Ƿ�Ϊ��
bool Empty(LinkList L)
{
    return (L->next == NULL);
}

/* �ڵ�i��λ�ò���Ԫ��e(��ͷ���)
���ʱ�临�Ӷ�=O(1)
ƽ��ʱ�临�Ӷ�=O(1/2 * n)
�ʱ�临�Ӷ�=O(n) */
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    LNode *p;                      //ָ��pָ��ǰɨ�赽�Ľ��
    int j = 0;                     //��ǰpָ����ǵڼ������
    p = L;                         //Lָ��ͷ��㣬ͷ�����0����㣨��������ݣ�
    while (p != NULL && j < i - 1) //ѭ���ҵ���i-1�����
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; //�����s����p֮��
    return true; //����ɹ�
}

/* ������������p���֮�����Ԫ��e
ʱ�临�Ӷ�=O(1) */
bool insertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) //�ڴ����ʧ��
        return false;
    s->data = e; //�ý��s��������Ԫ��e
    s->next = p->next;
    p->next = s; //������s����p֮��
    return true;
}

/* ǰ���������p���ǰ����Ԫ��e
ʱ�临�Ӷ�=O(1)
 */
bool insertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) //�ڴ����ʧ��
        return false;
    s->next = p->next;
    p->next = s;       //s����p֮��
    s->data = p->data; //����������
    p->data = e;
    return true;
}

/* ��λ��ɾ������ͷ���
�ʱ�临�Ӷ�=O(n)
ƽ��ʱ�临�Ӷ�=O(n)
���ʱ�临�Ӷ�=O(1)
 */
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p;                      //ָ��pָ��ǰɨ�赽�Ľ��
    int j = 0;                     //��ǰpָ����ǵڼ������
    p = L;                         //Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
    while (p != NULL && j < i - 1) //ѭ���ҵ���i-1�����
    {
        p = p->next;
        j++;
    }
    if (p == NULL) //iֵ���Ϸ�
        return false;
    if (p->next == NULL) //��i-1�����֮�������������
        return false;
    LNode *q = p->next; //��qָ��ɾ�����
    e = q->data;        //��e���ر�ɾ��Ԫ�ص�ֵ
    p->next = q->next;  //��*q�������жϿ�
    free(q);            //�ͷŽ��Ĵ洢�ռ�
    return true;        //ɾ���ɹ�
}

/* ɾ��ָ����� p
ʱ�临�Ӷ�=O(1)
���p�����һ����㣬��Ҫ��ͷ�����ҵ�p������һ�����
ʱ�临�Ӷ�O=(n)
 */
bool DeleteNode(LNode *p)
{
    if (p == NULL) //iֵ���Ϸ�
        return false;
    LNode *q = p->next; //��qָ��*p�ĺ�̽��
    p->data = q->data;  //�ͺ�̽�㽻��������
    p->next = q->next;  //��*q�������жϿ�
    free(q);            //�ͷź�̽��Ĵ洢�ռ�
    return true;
}

/* ��λ���ң����ص�i��Ԫ�أ���ͷ��㣩
ƽ�����ݸ��Ӷ�=O(n) */
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p;                  //ָ��pָ��ǰɨ�赽�Ľ��
    int j = 0;                 //��ǰpָ����ǵڼ������
    p = L;                     //Lָ��ͷ��㣬ͷ����ǵ�0�����(��������)
    while (p != NULL && j < i) //ѭ���ҵ���i�����
    {
        p = p->next;
        j++;
    }
    return p; //���i���ڵ������ȣ�����NULL
}

/* ��ֵ���ң��ҵ�Ԫ����==e�Ľ��
ʱ�临�Ӷ�=O(n)
 */
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    //�ӵ�1����㿪ʼ����������Ϊe�Ľ��,��������=e���Ƴ�ѭ��
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p; //�ҵ��󷵻ظ�ָ�룬���򷵻�NULL
}

/* ���ĳ���
ʱ�临�Ӷ�=O(n) */
int Length(LinkList L)
{
    int len = 0; //ͳ�Ʊ�
    LNode *p = L;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

/* β�巨����������
ʱ�临�Ӷ�=O(n) */
LinkList List_TailInsert(LinkList &L)
{                                        //������������
    int x;                               // ��ElemTypeΪ����
    L = (LinkList)malloc(sizeof(LNode)); //����ͷ���
    LNode *s, *r = L;                    //rΪ��βָ��
    scanf("%d", &x);                     //�������ֵ
    while (x != 9999)                    //����9999��ʾ����
    {
        // printf("%d\n", x)
        // s���������ڴ�ռ�
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s; //rָ���µı�β���
        scanf("%d", &x);
    }
    r->next = NULL; //��β���ָ���ÿ�
    return L;
}

/* ͷ�巨����������
ʱ�临�Ӷ�=O(n) */
LinkList List_HeadInsert(LinkList &L) //������������
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //����ͷ���
    L->next = NULL;                      //��ʼΪ������
    scanf("%d", &x);                     //�������ֵ
    while (x != 9999)                    //����9999��ʾ����
    {
        s = (LinkList)malloc(sizeof(LNode)); //�����½��
        s->data = x;
        s->next = L->next;
        L->next = s; //���½�������У�LΪͷָ��
        scanf("%d", &x);
    }
    return L;
}

// ���Գ�ʼ��
void test()
{
    LinkList L;  //����һ��ָ�������ָ��
    InitList(L); //��ʼ��һ��������
    // List_TailInsert(L);
    List_HeadInsert(L);
    int j = 1;
    while (L != NULL)
    {
        printf("�ڵ�%d:%d\n", j, L->next->data);
        L = L->next;
        j++;
    }
}

int main()
{
    // ��Ҫ����()�ſ�������
    test();
    return 0;
}