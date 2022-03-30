#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int a[], int begin, int end, int target);

int main(void)
{
    int a[] = {1,2,3,4,5,6,7};

    int target = 2;
    int result = BinarySearch(a, 0, sizeof(a)/sizeof(a[0]) - 1, target);
    printf("the position of target: %d \n",result);
    system("pause");
    return 0; 
}

int BinarySearch(int a[], int begin, int end, int target)
{
    if(begin > end)
        return -1;
    
    int middle = (begin + end) / 2;
    if( a[middle] == target)
        return middle;
    if( a[middle] < target)
        return BinarySearch(a, middle + 1, end, target);
    else
        return BinarySearch(a, begin, middle - 1, target);
}