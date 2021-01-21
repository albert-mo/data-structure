#include <stdio.h>
#include <cstdlib> //malloc、free函数的头文件

#define InitSize 10 //顺序表的初始长度
typedef struct
{
    int *data;   //指示动态分配数组的指针
    int MaxSize; //顺序表的最大容量
    int length;  //顺序表的当前长度
} SeqList;       //顺序表的类型定义

// 动态申请和释放内存空间
// C -- malloc、free函数
//      L.data = (ElemType *)malloc(sizeof(ElemType)*InitSize);
// C++ -- new、delete关键字

/* 顺序表的特点：
1.随机访问，即可以在O(1)时间内找到第i个元素。
2.存储密度高，每个节点只存储数据元素
3.拓展容量不方便（即使采用动态分配的方式实现，拓展长度的时间复杂度也比较高）
4.插入、删除操作不方便，需要移动大量元素
 */

void InitList(SeqList &L)
{
    // 用malloc函数申请一片连续的存储空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    free(p);
}

/* 插入元素
最好时间复杂度=O(1)
平均时间复杂度=O(1/2 * n)
最坏时间复杂度=O(n)
 */
bool ListInsert(SeqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1) //判断i的范围是否有效
        return false;
    if (L.length >= L.MaxSize) //当前存储空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j--) //将第i个元素及之后的元素后移
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

/* 删除元素 
最好时间复杂度=O(1)
平均时间复杂度=O(1/2 * n)
最坏时间复杂度=O(n)
*/
bool ListDelete(SeqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

/* 按位查找
时间复杂度=O(1)
 */
int GetElem(SeqList L, int i)
{

    if (i < 1 || i > L.length)
        return -1;
    return L.data[i - 1];
}

/* 按值查找
在顺序表L中查找第一个元素值等于e的元素，并返回其位序
最好时间复杂度=O(1)
平均时间复杂度=O(1/2 * n)
最坏时间复杂度=O(n)
 */
int LocateElem(SeqList L, int e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

int main()
{
    SeqList L;
    InitList(L);

    IncreaseSize(L, 5);
    printf("length of L:%d\n", L.MaxSize);

    //...往顺序表插入几个元素
    for (int i = 0; i < 5; i++)
    {
        ListInsert(L, 1, i);
    }

    int e = -1;
    if (ListDelete(L, 3, e))
        printf("已删除第三个元素，删除元素值为=%d\n", e);
    else
        printf("位序i不合法，删除失败\n");

    return 0;
}