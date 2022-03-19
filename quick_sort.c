#include<stdio.h>
#include<stdlib.h>

void quick_sort(int a[],int start,int end)
{
    if(start >= end)
        return ;

    int left = start,right = end;
    int mid = (a[(start + end) / 2]);   //以数组的中心点为比较
    while(left <= right)
    {
        while(left <= right && a[left] < mid)
        {
                left++;
        }
        while(left <= right && a[right] > mid)
        {
                right--;
        }
        if(left <= right)
        {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            left++;
            right--;
        }
    }

    quick_sort(a,start,right);
    quick_sort(a,left,end);

    
}
int main(void)
{

    int a[] = {1,23,4,5,6,234,1,312,4,6,3453,1,31,4,6,7,8,3};
    quick_sort(a,0,sizeof(a)/sizeof(a[0]) - 1);

    for(int i = 0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        printf("%d ",a[i]);
    }
    system("pause");
    return 0;
}