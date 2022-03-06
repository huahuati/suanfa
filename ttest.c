#include<stdio.h>
#include<stdlib.h>
 struct part {
    int number;
    char name[20];
    int on_head;
};

void f(struct part part1)
{
    struct part part2 = part1;
} 

struct t{

    char c;
    struct {int x;};
};
enum suit {COLOR,SO};
enum suit s1;
int main(void)
{

    s1 = COLOR;
    struct t t1 = {1,{1}};
    f((struct part){1,"dfs",3});
    printf("hello,world\n");
    system("pause");
    return 0;
}