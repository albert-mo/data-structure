#include <stdio.h>

// InitList(&L):初始化表。构造一个空的线性表L，分配内存空间。
// DestroyList(&L):销毁操作。销毁线性表，并释放线性表L所占用的内存空间

// ListInsert(&L,i,e):插入操作。在表L中的第i个位置上插入指定元素e。
// ListDelete(&L,i,&e):删除操作。删除表L中第i个位置的元素，并用e返回删除元素的值。

// LocateElem(L,e):按值查找操作。在表L中查找具有给定关键字值的元素。
// GetElem(L,i):按位查找操作。获取表L中第i个位置的元素的值。

// Length(L):求表长。返回线性表L的长度，即L中数据元素的个数。
// PrintList(L):输出操作。按前后顺序输出线性表L的所有元素值。
// Empty(L):判空操作。若L表为空，则返回true，否则返回false。

// 1.Tips：对数据的操作 -- 创销，增删改查
// 2.C语言函数的定义 -- <返回值类型> 函数名(<参数1类型> 参数1,<参数2类型> 参数2, ......)
// 3.实际开发中，可以根据实际需求定义其他的基本操作
// 4.函数名和参数的形式、命名都可改变（参考：严蔚敏版《数据结构》）
// 5.什么时候需要传入引用“&” -- 对参数的修改结果需要“带回来”

void test(int x)
{
    x = 1024;
    printf("test函数内部 x=%d\n", x);
}

void test_call(int &x)
{
    x = 1024;
    printf("test函数内部 x=%d\n", x);
}

int main()
{
    int x = 1;
    printf("调用test前： x=%d\n", x);
    test(x);
    printf("调用test后： x=%d\n", x);
    printf("调用test_call前： x=%d\n", x);
    test_call(x);
    printf("调用test_call后： x=%d\n", x);
    printf("int长度：%d\n",sizeof(int));
}