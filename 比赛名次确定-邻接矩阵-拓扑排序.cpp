#include<stdio.h>
#include<stdlib.h>

#define MAXN 502   //��󶥵����� 

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
            if (map[u][v] == 0)    //���ݿ��ܻ��ظ�
            {
                map[u][v] = 1;
                map[0][v]++; //�洢����v����� 
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
    
    for (top=0; top<n; top++)//�ܹ���n�����㣬����n�� 
    {
        for (i=1; i<=n; i++)//Ѱ�����Ϊ0�������С�Ķ��� 
        {
            if (map[0][i] == 0)
            {
                map[0][i] = -1;
                break;
            }
        }
        topo[top] = i;
        for (j=1; j<=n; j++) //��βi��Ӧ��ͷj��ȼ�1 
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