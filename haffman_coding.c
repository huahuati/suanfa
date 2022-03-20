//哈弗曼树的建立以及哈夫曼编码
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//设计存储结构
#define INFINITY 99999
#define MAXLEN 20
typedef struct {
     int weight;
     int parent, lchild, rchild;
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;

//算法实现
void Select(HuffmanTree* HT, int x, int* s1, int* s2);

void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int* w, int n)
{
    int m, i;
    HuffmanTree p;
    char* cd;
    if (n <= 1)
        return;
    m = 2 * n - 1;    //节点个数
    *HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));  //0号位置不使用
    for (p = *HT + 1, i = 1; i <= n; ++i, ++p, ++w)
    {
        p->weight = *w;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }

    for (; i <= m; ++i)
    {
        p->weight = 0;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }

    for (i = n + 1; i <= m; ++i)
    {
        int s1, s2;   //两个最小的数
        Select(HT, i - 1, &s1, &s2);
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }

    (*HC) = (HuffmanCode)malloc((n + 1) * sizeof(char*));
    cd = (char*)malloc(n * sizeof(char));

    cd[n - 1] = '\0';   //最后一个放'\0'
    for (i = 1; i <= n; ++i)
    {
        int start = n - 1, c, f;
        for (c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent)
        {
            if((*HT)[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        (*HC)[i] = (char*)malloc((n - start) * sizeof(char));
        strcpy((*HC)[i], &cd[start]);
        printf("%s\n", (*HC)[i]);
    }
    free(cd);
}

void Select(HuffmanTree* HT, int x, int* s1, int* s2)
{
     int i = 1, min1 = INFINITY, min2 = INFINITY;
    for (; i <= x; i++)
    {
        if ((*HT)[i].weight < min1 && (*HT)[i].parent == 0)
        {
            min1 = (*HT)[i].weight;
            *s1 = i;
        }
    }

    for (i = 1; i <= x; i++)
    {
        if ((*HT)[i].weight < min2 && (*HT)[i].parent == 0 && i != *s1)
        {
            min1 = (*HT)[i].weight;
            *s2 = i;
        }
    }

}

int main(void)
{
    HuffmanTree ht;
    HuffmanCode hc;
    int n, i, w[MAXLEN];
    char ch[MAXLEN];

    printf("please input the coding chars length: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("输入字符和对应的权值: \n");
        fflush(stdin);
        scanf("%c %d", &ch[i], &w[i]);
    }

    printf("字符: ");
    for (i = 0; i < n; i++)
        printf("%c", ch[i]);

    printf("huffman coding: ");
    HuffmanCoding(&ht, &hc, w, n);

    system("pause");
    return 0;
}
