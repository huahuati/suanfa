//判断图是否为空
#include<iostream>
#include<cstdlib>
using namespace std;
//存储结构设计（邻接矩阵）
#define INFINITY    (unit32_t)0xffffffff
#define MAX_VALUE_NUM 20
typedef int VRType;
typedef char InfoType;
typedef char VertexType;
typedef enum{DG, DN, UDG, UDN} GraphKind;

typedef struct ArcCell{
    VRType adj;   //无向图 1或 0 表示是否相邻，对于带权图，则为权值类型
    InfoType *info;   //该弧相关信息的指针
}ArcCell, AdjMatrix[MAX_VALUE_NUM][MAX_VALUE_NUM];

typedef struct{
    VertexType vexs[MAX_VALUE_NUM];  //顶点向量
    AdjMatrix arcs;  //邻接矩阵
    int vexnum, arcnum;   //图的当前定点数和弧(边)数
    GraphKind kind;   //图的种类
}MGraph;
//算法---遍历（深度优先遍历）

int LocateVex(MGraph G,VertexType v)
{
    int i;
    for(i = 0; i < G.vexnum; i++)
    {
        if(G.vexs[i] == v)
            return i;
    }
    return -1;
}

bool CreateUDG(MGraph *G)
{
    int IncInfo , i,j,k;
    VertexType v1,v2;
    cout << "请输入无向图顶点数目，边的数目和边的其他信息(若为0，则表示各边不含其他信息): ";
    cin >> G->vexnum >> G->arcnum >> IncInfo;
    cout << endl;
    for(i = 0; i < G->vexnum; i++)
    {
        cout << "请输入顶点的值: ";
        cin >> G->vexs[i];
        cout << endl;
    }
    //邻接矩阵的初始化工作,无向图实对称的
    for(i = 0; i < G->vexnum; i++)
    {
        for(j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }

    for(k = 0; k < G->arcnum; k++)
    {
        cout << "请输入一条边所依附的两个顶点: "<<endl;
        cin >> v1 >> v2;
        cout << endl;
        i = LocateVex(*G,v1);  //行坐标
        j = LocateVex(*G,v2);  //列坐标

        G->arcs[i][j].adj = 1;
        if(IncInfo)
        {
            cout << "请输入边的其他信息: ";
            cin >> G->arcs[i][j].info;
            cout << endl;
        }
        G->arcs[j][i] = G->arcs[i][j];

    }
    G->kind = UDG;
    return true;
}

bool visited[MAX_VALUE_NUM];

void DFS(MGraph G, int v)
{
    int w;
    visited[v] = true;

    for(w = 0; w < G.vexnum; w++)
    {
        if(G.arcs[v][w].adj == 1 && !visited[w])
            DFS(G,w);
    }
}

void JudgeUDGConnectivity(MGraph G)
{
    int v,k,count = 0;
    for(v = 0; v < G.vexnum; v++)
    {
        visited[v] = false;
    }
    for(k = 0; k < G.vexnum; k++)
    {
        if(!visited[k])
        {
            DFS(G,k);
            count++;
        }
    }
    if(count == 1)
        cout << "该图为连通图" <<endl;
    else
        cout << "该图为非连通图" <<endl;
}

int main(void)
{
    MGraph G;
    CreateUDG(&G);
    JudgeUDGConnectivity(G);
    system("pause");
    return 0;
}





