#include<stdio.h>
#include<stdlib.h>

int no_recursion(int a[],int begin ,int end, int target)
{
    while(begin < end)
    {
        int middle = ( begin + end ) / 2;
        if(a[middle] == target)
            return middle;
        if(a[middle] < target)
            begin = middle + 1;
        else
            end = middle - 1;
    }
    if(a[begin] == target)
        return begin;
    return -1;


}
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int begin = 0;
    int end = sizeof(a)/sizeof(a[0]) - 1;
    int target = 10;
    int result = no_recursion(a,begin,end,target);
    printf("the position is %d: ",result);
    system("pause");
    return 0;
}