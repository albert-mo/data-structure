#include <iostream>
#include <string>

void loveYou(int n)
{
    int i = 1;  //1
    while (i <= n)  //n+1
    {
        i++;    //n
        printf("I love you %d \n", i);  //n
    }
    printf("I love you more than %d \n", n);    //1
}

int main()
{
    loveYou(3000);
}

// T(3000) = 1 + 3001 + 3000 + 3000 +1
// T(n) = 1 + n + 1 + 2n + 1 = 3n+3
// 时间复杂度：常对幂指阶
// 结论1：顺序执行的代码只会影响常数项，可以忽略
// 结论2：只需挑选循环中的一个基本操作分析它的执行次数与n的关系即可
// 结论3：如果有多层嵌套循环，只需关注最深层循环循环了几次