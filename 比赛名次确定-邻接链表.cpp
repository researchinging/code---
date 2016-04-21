#include<stdio.h>
#include<stdlib.h>

#define MAXN 510   //最大变量（顶点）数量 

typedef int VertexType; //顶点类型由用户自定义
typedef int EdgeType; //边上的权值类型由用户自定义

typedef struct EdgeNode{ //边表结点
    int adjvex;  //邻接点域，存储该顶点对应的下标
//    EdgeType weight; //权值，对于非网图可以不需要 
    struct EdgeNode *next; //链域，指向下一个邻接点 
} EdgeNode;

typedef struct VertexNode{ //顶点表结点
    VertexType data; //顶点域，存储顶点信息
    int in;   //存储顶点入度的数量 
    EdgeNode *firstEdge; //边表头指针
} VertexNode;

void CreateGraph(VertexNode *GL, int n, int m);//把顶点和边信息读入到表示图的邻接表中 
int InsertStack(int vec[], int x, int n);//折半插入,递减排序 
void TopoLogicalSort_DFS(VertexNode *GL, int n);

int main()
{
    int i, m, n;
    VertexNode GL[MAXN];
    
    while(scanf("%d%d", &n, &m) != EOF)
    {   
        CreateGraph(GL, n, m);//把顶点和边信息读入到表示图的邻接表中 
        TopoLogicalSort_DFS(GL, n);
    }
     
    return 0;
}

void CreateGraph(VertexNode *GL, int n, int m)//把顶点和边信息读入到表示图的邻接表中 
{
    int i, u, v;
    EdgeNode *e;

    for (i=1; i<=n; i++)//初始化图 
    {
        GL[i].data = i;
        GL[i].in = 0;
        GL[i].firstEdge = NULL;
    }
    
    for (i=0; i<m; i++)
    {
        e = (EdgeNode*)malloc(sizeof(EdgeNode)); //采用头插法插入边表结点 
        if (!e)
        {
            puts("Error"); 
            exit(1);
        }
        
        scanf("%d%d", &u, &v);
        e->next = GL[u].firstEdge;
        GL[u].firstEdge = e;
        e->adjvex = v;
        GL[v].in++;
    }
} 

int InsertStack(int vec[], int x, int n)//折半插入,递减排序 
{
    int low = 0, high = n - 1, mid, j;

    while(low <= high) //折半查找插入位置
    {
        mid = (low + high)/2;
        if(vec[mid] < x)
        {
            high = mid -1;
        }
        else
        {
            low = mid + 1;
        }
    }
    //进行插入操作
    for(j=++n; j>low; j--)
    {
        vec[j] = vec[j-1];
    }
    vec[low] = x;
    
    return n;
}

void TopoLogicalSort_DFS(VertexNode *GL, int n)
{
    int i, u, v, top = 0;
    int count = 0;
    EdgeNode *e;
    int topo[MAXN], Stack[MAXN];//有序栈（或优先队列） 
    
    for (i=1; i<=n; i++)//将入度为0的顶点按序号大小逆序入栈
    {
        if (GL[i].in == 0)
        {
             top = InsertStack(Stack, i, top); 
        }
    }
       
    while (top > 0)//采用深度优先搜索获取拓扑序列 
    {
        u = Stack[--top];
        topo[count++] = u;
        
        for (e=GL[u].firstEdge; e!=NULL; e=e->next)//将u的邻接点入度减1，并将入度为0的顶点入栈 
        {
            v = e->adjvex;
            if (--GL[v].in == 0)
            {
                top = InsertStack(Stack, v, top);
            }
        }
    }
    
    for (i=0; i<count-1; i++)
    {
        printf("%d ", topo[i]);
    }
    printf("%d\n", topo[count-1]);
}