#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
    int key;
    int color;   //0 red, 1 black, 2 double black
    struct Node *lchild,*rchild;
}Node;

Node __NIL;
#define NIL (&__NIL)        //__attribute__语法格式为：attribute ( ( attribute-list ) )
__attribute__((constructor))//如果函数被设定为constructor属性，则该函数会在main（）函数执行之前被自动的执行
void init_NIL()
{
    NIL->key = 0;
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    return;
}
Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = 0;
    p->lchild = p->rchild = NIL;
    return p;
}

int has_red_child(Node *root)
{
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root)   //左旋
{
    Node *temp = root->rchild;   //指向根节点
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root)  //右旋
{
    Node *temp = root->lchild;   //指向根节点
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}
Node *inset_maintain(Node *root)   //插入调整
{

    int flag = 0;
    if(!has_red_child(root))   //如果插入节点下面根本就没有红色子孩子，不用调整
        return root;

    if(root->lchild->color == 0 && root->rchild->color == 0)//root的左孩子右孩子都为红色，直接改成红黑黑
    {                                         //这个if就是用来处理插入调整情况一：黑红红改成红黑黑   
                                            //这是一种偷懒的策略，没有判断是否真正的发生了双红的冲突
        //这里也可以使用goto语句
        goto insert_end;    //可以使用goto来替代//的内容，但是不建议使用goto，可以把//的内容分装成一个函数
        // root->color = 0;
        // root->lchild->color = 1;
        // root->rchild->color = 1;
        // return root;
    }

    if(root->lchild->color == 0 && has_red_child(root->lchild))//左孩子是红，右孩子是黑;左孩子的左孩子是红或者左孩子的右孩子是红
        flag = 1;

    if(root->rchild->color == 0 && has_red_child(root->rchild))//右孩子是红，左孩子是黑;右孩子的左孩子是红或者右孩子的右孩子是红
        flag = 2; 

    if(flag == 0)//没有发生冲突，直接return
        return root;    
    if(flag == 1)
    {
        if(root->lchild->rchild->color == 0) //左子树的右子树是红
        {
            root->lchild = left_rotate(root->lchild);   //需要小左旋
        }

        root = right_rotate(root);  //右旋

        // root->color = 0;    //可以红色上浮，也可以红色下沉
        // root->lchild->color = 1;
        // root->rchild->color = 1;  
    }
    else  //falg == 2;
    {
        if(root->rchild->lchild->color == 0) //右子树的左子树是红
        {
            root->rchild = right_rotate(root->rchild);   //需要小右旋
        }

        root = left_rotate(root);  //左旋

        // root->color = 0;    //可以红色上浮，也可以红色下沉
        // root->lchild->color = 1;
        // root->rchild->color = 1;  
    }
insert_end:
    root->color = 0;    //可以红色上浮，也可以红色下沉
    root->lchild->color = 1;
    root->rchild->color = 1;  
    return root;
}
Node *__insert(Node *root, int key)
{
    if(root == NIL)  //要是递归到为空的位置
        return getNewNode(key);
    if(root->key == key)  //节点重复
         return root;  
    if(key < root->key)
    {
        root->lchild = __insert(root->lchild,key);

    }
    else
    {
        root->rchild = __insert(root->rchild,key);
    }
    return inset_maintain(root);
}

Node *insert(Node *root, int key)   //主要是把根节点染成黑色
{
    root = __insert(root, key);
    root->color = 1;   
    return root;
}


Node *predecessor(Node *root)//找到度为二节点的左子树的前驱
{
    Node * temp = root->lchild;
    while(temp->rchild != NIL)
        temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root)
{
    if(root->lchild->color !=2 && root->rchild->color !=2) //都不是双重黑
        return root;
    if(has_red_child(root))   //兄弟节点是红色的情况，需要旋转
    {
        int flag = 0;
        root->color = 0;
        if(root->lchild->color == 0)
        {
            root = right_rotate(root);
            flag = 1;
        }
        else
        {
            root = left_rotate(root);
            flag = 2;
        }
        root->color = 1;
        if(flag == 1)
            root->rchild = erase_maintain(root->rchild);
        else  
            root->lchild = erase_maintain(root->lchild);
        return root;
    } 

    if((root->lchild->color == 2 && !has_red_child(root->rchild)) ||
       (root->rchild->color == 2 && !has_red_child(root->lchild))) //这里处理的是情况一
    {
        
        root->lchild->color -=1;
        root->rchild->color -=1;
        root->color +=1;
        return root;
    }
    if(root->lchild->color == 2) //如果左子树是双重黑，那么一定会进行大左旋
    {
        if(root->rchild->rchild->color != 0)
        {
            root->rchild->color = 0;   //交换颜色
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = 1;
        }
        root = left_rotate(root);
        root->color = root->lchild->color;  //新根节点变成源根节点的颜色

    }
    else   //如果右侧是双重黑，那么一定进行大右旋
    {
        if(root->lchild->lchild->color != 0)
        {
            root->lchild->color = 0;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = 1;
        }
        root = right_rotate(root);
        root->color = root->rchild->color;
    }
    root->lchild->color = root->rchild->color = 1;  //两个子节点强制变成黑色
    return root;
}
Node *__erase(Node *root, int key)
{
    if(root == NIL) return NIL;
    if(key < root->key)
    {
        root->lchild = __erase(root->lchild,key);
    }
    else if(key > root->key)
    {
        root->rchild = __erase(root->rchild,key);
    }
    else//key  == root->key
    {
        if(root->lchild == NIL || root->rchild == NIL)  //删除的是度为零或者度为一的情况
        {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            temp->color += root->color;
            free(root);
            return temp;
        }
        else //删除的是度为二的节点
        {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild,temp->key);
        }
    }

    return erase_maintain(root);
}
Node *erase(Node *root, int key)
{
    root = __erase(root,key);
    root->color = 1;
    return root;
}
void clear(Node *root)  //销毁操作
{
    if(root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}

void print(Node *root)
{
    printf("(%d | %d, %d, %d)\n",root->color,root->key,root->lchild->key,root->rchild->key);  //根节点颜色， 值，左子树值，右子树值 
    return;
}

void output(Node *root)  //采用先序遍历的方式
{
    if(root == NIL) return;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return;
}

int main()
{
    int op,val;
    Node *root = NIL;
    while(~scanf("%d%d",&op,&val))
    {
        switch(op)
        {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root,val); break;
        }
        output(root);
        printf("-------------------\n");
    }
    clear(root);
    exit(0);
}