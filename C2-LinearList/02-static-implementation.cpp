#include <stdio.h>

#define MaxSize 10 //定义最大长度
typedef struct
{
    int data[MaxSize]; //用静态的“数组存放元素”
    int length;        //顺序表的当前长度
} SqList;              //顺序表的类型定义

/* 初始化顺序表 */
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0;

    L.length = 0;
}

/* 插入元素
最好时间复杂度=O(1)
平均时间复杂度=O(1/2 * n)
最坏时间复杂度=O(n)
 */
bool ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1) //判断i的范围是否有效
        return false;
    if (L.length >= MaxSize) //当前存储空间已满，不能插入
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
bool ListDelete(SqList &L, int i, int &e)
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
int GetElem(SqList L, int i)
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
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

int main()
{
    SqList L;    //声明一个
    InitList(L); //初始化顺序表

    // 此处省略一些代码，插入几个元素

    //尝试“违规”打印整个data数组
    // for (int i = 0; i < MaxSize; i++)
    //     printf("data[%d]=%d\n", i, L.data[i]);

    // return 0;

    // 插入元素
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