#include<stdio.h>
#include<stdlib.h>

#define MAXN 510   //�����������㣩���� 

typedef int VertexType; //�����������û��Զ���
typedef int EdgeType; //���ϵ�Ȩֵ�������û��Զ���

typedef struct EdgeNode{ //�߱���
    int adjvex;  //�ڽӵ��򣬴洢�ö����Ӧ���±�
//    EdgeType weight; //Ȩֵ�����ڷ���ͼ���Բ���Ҫ 
    struct EdgeNode *next; //����ָ����һ���ڽӵ� 
} EdgeNode;

typedef struct VertexNode{ //�������
    VertexType data; //�����򣬴洢������Ϣ
    int in;   //�洢������ȵ����� 
    EdgeNode *firstEdge; //�߱�ͷָ��
} VertexNode;

void CreateGraph(VertexNode *GL, int n, int m);//�Ѷ���ͱ���Ϣ���뵽��ʾͼ���ڽӱ��� 
int InsertStack(int vec[], int x, int n);//�۰����,�ݼ����� 
void TopoLogicalSort_DFS(VertexNode *GL, int n);

int main()
{
    int i, m, n;
    VertexNode GL[MAXN];
    
    while(scanf("%d%d", &n, &m) != EOF)
    {   
        CreateGraph(GL, n, m);//�Ѷ���ͱ���Ϣ���뵽��ʾͼ���ڽӱ��� 
        TopoLogicalSort_DFS(GL, n);
    }
     
    return 0;
}

void CreateGraph(VertexNode *GL, int n, int m)//�Ѷ���ͱ���Ϣ���뵽��ʾͼ���ڽӱ��� 
{
    int i, u, v;
    EdgeNode *e;

    for (i=1; i<=n; i++)//��ʼ��ͼ 
    {
        GL[i].data = i;
        GL[i].in = 0;
        GL[i].firstEdge = NULL;
    }
    
    for (i=0; i<m; i++)
    {
        e = (EdgeNode*)malloc(sizeof(EdgeNode)); //����ͷ�巨����߱��� 
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

int InsertStack(int vec[], int x, int n)//�۰����,�ݼ����� 
{
    int low = 0, high = n - 1, mid, j;

    while(low <= high) //�۰���Ҳ���λ��
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
    //���в������
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
    int topo[MAXN], Stack[MAXN];//����ջ�������ȶ��У� 
    
    for (i=1; i<=n; i++)//�����Ϊ0�Ķ��㰴��Ŵ�С������ջ
    {
        if (GL[i].in == 0)
        {
             top = InsertStack(Stack, i, top); 
        }
    }
       
    while (top > 0)//�����������������ȡ�������� 
    {
        u = Stack[--top];
        topo[count++] = u;
        
        for (e=GL[u].firstEdge; e!=NULL; e=e->next)//��u���ڽӵ���ȼ�1���������Ϊ0�Ķ�����ջ 
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