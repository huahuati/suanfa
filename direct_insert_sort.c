#include<stdio.h>
#include<stdlib.h>

//直接插入排序
int main(void)
{
    //数组的0号位置用来作为标兵
    int a[] = {0,6,5,1,2,4,5,7,9,42,5,7,8,1};
    int j;
    for(int i = 2;i < sizeof(a)/sizeof(a[0]); i++)
    {
        if(a[i] < a[i-1])
        {
            a[0] = a[i];
            a[i] = a[i-1];
            for(j = i - 2; a[0] < a[j];--j)
                a[j+1] = a[j];
            a[j+1] = a[0];
        }
    }
    for(int i = 1;i<sizeof(a)/sizeof(a[0]);i++)
    {
        printf("%d ",a[i]);
    }
    system("pause");
    return 0;
}