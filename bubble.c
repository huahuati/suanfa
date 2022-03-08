#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void bubble(int *p,int n){
    int count = 0;
    _Bool change = true;
    for(int i=n-1;i>0 && change;i--)
    {
        change = false;
        for(int j=0;j<i;j++)
        {
            if(p[j] > p[j+1])
            {
                int temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                change = true;
            }
        }
    count++;
    }
    printf("how much %d\n",count);
    
}
int main(void ){

    int a[] = {1,2,3,4,5,6,7,3,2,1,5,6,7,8,124};

    bubble(a,sizeof(a)/sizeof(a[0]));
    for(int i =0;i<sizeof(a)/sizeof(a[0]);i++)
        printf("%d ",a[i]);
    system("pause");
    return 0;
}