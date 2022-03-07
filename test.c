#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef char TElemType;
//设计二叉链表存储结构
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, *rchild;
}BiTNode,*BiTree;
//创建二叉树（基于遍历的思想)
void CreateBiTree(BiTree* T) {
	TElemType ch;
	printf("IN PUT CHARS:");
	scanf("%c", &ch);
	fflush(stdin);
	if (ch == ' ')
		*T = NULL;
	else
	{
		if (*T = (BiTree)malloc(sizeof(BiTNode)))
		{
			(*T)->data = ch;
			CreateBiTree(&(*T)->lchild);
			CreateBiTree(&(*T)->rchild);
		}
	}
}
//遍历，先序遍历，中序遍历，后序遍历 

void Traverse(BiTree T) {

	if (T)
	{
		printf("%c", T->data);
		Traverse(T->lchild);
		Traverse(T->rchild);
	}
}

//求二叉树的深度
int BT_Depth(BiTree T){
    int l ,r;
    if(T == NULL)
    {
        return 0;
    }
    else{
        l = BT_Depth(T->lchild);
        r = BT_Depth(T->rchild);
        if(l >=r)
            return l+1;
        else 
            return r+1;
    }
}

//二叉树的销毁
void DestoryBiTree(BiTree *T){

    if(*T)
    {
        if((*T)->lchild)
            DestoryBiTree(&(*T)->lchild);
        if((*T)->rchild)
            DestoryBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
}

int main(void) {

	BiTree mt;
	CreateBiTree(&mt);
	printf("THE RESULT: \n");
	Traverse(mt);
    printf("the depth:%d\n",BT_Depth(mt));
    printf("destory the BiTree\n");
    DestoryBiTree(&mt);
    system("pause");
	return 0;
}
