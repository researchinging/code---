#include<stdio.h>
#include<stdlib.h>

#define MAXN 502   //最大顶点数量 

int map[MAXN][MAXN] = {0};

void TopoLogicalSort(int n);

int main()
{
    int i, j, m, n, u, v;

    while(scanf("%d%d", &n, &m) != EOF)
    {   
        for (i=0; i<MAXN; i++)
            for (j=0; j<MAXN; j++)
                map[i][j] = 0;
        
        for (i=0; i<m; i++)        
        {
            scanf("%d%d", &u, &v);
            if (map[u][v] == 0)    //数据可能会重复
            {
                map[u][v] = 1;
                map[0][v]++; //存储顶点v的入度 
            }
        }
        
        TopoLogicalSort(n);
    }
     
    return 0;
}

void TopoLogicalSort(int n)
{
    int i, j, top;
    int topo[MAXN] = {0};
    
    for (top=0; top<n; top++)//总共有n个顶点，搜索n次 
    {
        for (i=1; i<=n; i++)//寻找入度为0的序号最小的顶点 
        {
            if (map[0][i] == 0)
            {
                map[0][i] = -1;
                break;
            }
        }
        topo[top] = i;
        for (j=1; j<=n; j++) //弧尾i对应弧头j入度减1 
        {
            if (map[i][j] == 1)
                map[0][j]--;
        }
    }
    
    for (i=0; i<top-1; i++)
    {
        printf("%d ", topo[i]);
    }
    printf("%d\n", topo[top-1]);
}