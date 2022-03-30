#include<stdio.h>
#include<stdlib.h>

//一：递归的定义：函数结构什么样的参数，返回什么样的值，代表什么样的意思
int fibonacci(int n)
{
    //三：递归的出口
    if( n <= 2)
    return n - 1;

    //二：递归的拆解
    return fibonacci(n - 1) + fibonacci( n - 2);
}

int main(void)
{

    int result = fibonacci(6);
    printf("%d ",result);
    system("pause");
    return 0;
}