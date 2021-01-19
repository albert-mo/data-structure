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

int main()
{
    SeqList L;
    InitList(L);
    //...往顺序表插入几个元素
    IncreaseSize(L, 5);
    printf("length of L:%d\n", L.MaxSize);
    return 0;
}