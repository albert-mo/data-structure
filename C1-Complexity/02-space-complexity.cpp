#include <iostream>
#include <string>

void loveYou(int n)
{
    int i = 1;     //1
    while (i <= n) //n+1
    {
        i++;                           //n
        printf("I love you %d \n", i); //n
    }
    printf("I love you more than %d \n", n); //1
}

void loveYouRecursion(int n)
{
    int a, b, c;
    if (n > 1)
    {
        loveYouRecursion(n - 1);
    }
    printf("I love you %d\n", n);
}

int main()
{
    // loveYou(3000);
    loveYouRecursion(5);
}

// S(n) = o(1) 算法原地工作--算法所需内存空间为常量
// 空间复杂度：常对幂指阶
// 递归：空间复杂度 = 递归调用的深度