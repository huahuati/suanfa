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

	//第二次提交，哈哈哈
	//第三次修改,hh
	//在master中修改并提交
	//zai hot-fixzhong xiugai
	//再次测试在，hot-fix中提交
        //hot-fix再次修改
    s1 = COLOR;
    struct t t1 = {1,{1}};
    f((struct part){1,"dfs",3});
    printf("hello,world\n");
    system("pause");
    return 0;
    //在在在次修改xiba
}

