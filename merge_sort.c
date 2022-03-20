#include<stdio.h>
#include<stdlib.h>

//该算法采用经典的分治
//分治法将问题 “分”成一些小的问题然后递归求解，“治”将分的阶段得到的各个答案“修补”在一起。
void sort(int a[],int begin,int end,int b[]);
void merge(int a[],int begin,int end,int b[]);
int main(void)
{
    int a[] = {1,3,77,22,3,123,1,2,44,12,4,4,1};

    int b[13] = {0};

    sort(a, 0, sizeof(a)/sizeof(a[0]) - 1,b);

    for(int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
    {
        printf("%d ",a[i]);
    }
    system("pause");
    return 0;
}

void sort(int a[], int begin, int end, int b[])
{
        if(begin >= end)   //递归终止条件可别忘记了
            return ;
        sort(a, begin, (begin + end) / 2, b);
        sort(a, (begin + end) / 2  + 1, end, b);
        merge(a, begin, end , b);
}

void merge(int a[], int begin, int end, int b[])
{
    int middle = (begin + end) / 2;
    int LeftIndex = begin;
    int RightIndex = middle + 1;
    int Index = LeftIndex;

    while(LeftIndex <= middle && RightIndex <= end)
    {
        if(a[LeftIndex] < a[RightIndex])
        {
            b[Index++] = a[LeftIndex++];  
        }
        else
        {
            b[Index++] = a[RightIndex++];
        }
    }
    while(LeftIndex <= middle)   //当RightIndex后面的所有数都比LeftIndex小的时候
    {
        b[Index++] = a[LeftIndex++];
    }

    while(RightIndex <= end)     //当RightIndex后面的数都大于 LeftIndex的时候
    {
        b[Index++] = a[RightIndex++];
    }

    for(int i = begin; i<= end; i++)
    {
        a[i] = b[i];             //小的部分排好序之后记得赋值给a
    }
}