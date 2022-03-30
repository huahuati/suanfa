#include<stdio.h>
#include<stdlib.h>


//找到第一个出现target的位置
int no_recursion(int a[],int begin ,int end, int target)
{
    while(begin + 1 < end)
    {
        int middle = ( begin + end ) / 2;
        if(a[middle] == target)
            end = middle;
        else if(a[middle] < target)
            begin = middle + 1;
        else
            end = middle - 1;
    }
    if(a[begin] == target)
        return begin;
    if(a[end] == target)
        return end;
    return -1;


}
int main()
{
    int a[] = {1,2,2,4,5,6,7,7}; 
    int begin = 0;
    int end = sizeof(a)/sizeof(a[0]) - 1;
    int target = 7;   //target 表示要寻找的目标数
    int result = no_recursion(a,begin,end,target);
    printf("the position is %d: ",result);
    system("pause");
    return 0;
}