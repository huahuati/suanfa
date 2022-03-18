#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
//设计存储结构
typedef char TElemType;
typedef struct PTNode{
    TElemType data;
    int parent;
}PTNode;

typedef struct 
{
    PTNode nodes[MAXSIZE];
    int r,n;
}PTree;

//创建树（从1号空间开始）
void CreateTree(PTree * p)
{
    int m = 0;
    printf("input tree nodes: \n");
    scanf("%d",&m);
    fflush(stdin);
    p->n = m;
    printf("input node the value and the parent(root parent are zero)s: \n");
    for(int i = 1;i <= p->n; ++i)  //从数组一号位置开始，抛弃0号位置
    {
        printf("node%d: ",i);
        scanf("%c%d",&p->nodes[i].data,&p->nodes[i].parent);
        fflush(stdin);
        if(0 == p->nodes[i].parent)
        {
            p->r = i;
        }
    }

}

//求树的深度

int DepthTree(PTree p)
{
    int max = 0, temp = 0, f = 0;
    for(int i = 1; i<=p.n; i++)
    {
        temp = 0;
        f = i;
        while(f > 0)
        {
            temp ++;
            f = p.nodes[f].parent;
        }
        if(temp > max)
            max = temp;
    }
    return max;
}
//main验证和使用
int main(void)
{
    PTree pt;
    CreateTree(&pt);
    printf("tree depth %d",DepthTree(pt));
    system("pause");
    return 0;
}