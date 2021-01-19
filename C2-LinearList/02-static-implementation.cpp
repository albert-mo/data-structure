#include <stdio.h>

#define MaxSize 10  //定义最大长度
typedef struct
{
    int data[MaxSize];  //用静态的“数组存放元素”
    int length; //顺序表的当前长度
} SqList;   //顺序表的类型定义

void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0;

    L.length = 0;
}

int main()
{
    SqList L;    //声明一个
    InitList(L); //初始化顺序表

    //尝试“违规”打印整个data数组
    for (int i = 0; i < MaxSize; i++)
        printf("data[%d]=%d\n", i, L.data[i]);

    return 0;
}