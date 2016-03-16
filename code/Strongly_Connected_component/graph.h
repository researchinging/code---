#include <iostream>
using namespace std;

#define N 8
#define WHITE 0
#define GRAY 1
#define BLACK 2


//�߽��ṹ
struct Edge
{
	int start;//����ͼ�����
	int end;//����ͼ���յ�
	Edge *next;//ָ��ͬһ��������һ����
	int type;//�ߵ�����
	Edge(int s, int e):start(s),end(e),next(NULL){}
};
//������ṹ
struct Vertex
{
	int id;
	Edge *head;//ָ���Ըö���Ϊ������һ����
	int color;//�������ɫ
	Vertex *p;//ָ���������ĸ����
	int d, f;//��һ�α����ֵ�ʱ��ͽ�������ʱ��
	Vertex(int i):head(NULL),color(WHITE),p(NULL),d(0x7fffffff),id(i){}
};
//ͼ�ṹ
struct Graph
{
	Vertex *V[N+1];//N������
	Graph()
	{
		int i;
		for(i = 1; i <= N; i++)
			V[i] = new Vertex(i);
	}
	~Graph()
	{
		int i;
		for(i = 1; i <= N; i++)
			delete V[i];
	}
};

int time = 0;
bool flag = 0;
int Sort[N+1] = {N};

//�����
void InsertEdge(Graph *G, Edge *E)
{
	//���û����ͬ���ı�
	if(G->V[E->start]->head == NULL)
		G->V[E->start]->head =E;
	//����У����뵽�����У�����˳�����У����ڲ���
	else
	{
		//����Ĳ��룬������
		Edge *e1 = G->V[E->start]->head, *e2 = e1;
		while(e1 && e1->end < E->end)
		{
			e2 = e1;
			e1 = e1->next;
		}
		if(e1 && e1->end == E->end)
			return;
		if(e1 == e2)
		{
			E->next = e1;
			G->V[E->start]->head =E;
		}
		else
		{
			e2->next = E;
			E->next = e1;
		}
	}
}
//ת��
Graph* Reverse(Graph *G)
{
    Graph *ret = new Graph;
    int i;
    //����ͼG�е�ÿһ���ߣ����յ�Ϊ��㣬�����Ϊ�յ㣬���뵽��ͼRET��
    for(i = 1; i <= N; i++)
    {
        Edge *E = G->V[i]->head;
        while(E)
        {
            Edge *e = new Edge(E->end, E->start);
            InsertEdge(ret, e);
            E = E->next;
        }
    }
    return ret;
}
//����ĳ����
void DFS_Visit(Graph *G, Vertex *u)
{
	//�ڵ�һ�η���ʱ���
	if(flag)cout<<char(u->id)<<' ';
	//��u��Ϊ��ɫ
	u->color = GRAY;
	//ʹȫ�ֱ���time��ֵ
	time++;
	//��time����ֵ��¼Ϊ����ʱ��
	u->d = time;
	//����u���ڵ�ÿ������v
	Vertex *v;
	Edge *e = u->head;
	while(e)
	{
		v = G->V[e->end];
		//�������Ϊ��ɫ
		if(v->color == WHITE)
		{
			//�ݹ���ʶ���
			v->p = u;
			DFS_Visit(G, v);
			//����
			e->type = 1;
		}
		else if(v->color == GRAY)
		{
			//�����
			e->type = 2;
		}
		else if(v->color == BLACK)
		{
			//�����
			if(u->d < v->d)
				e->type = 3;
			//�����
			else
				e->type = 4;
		}
		e = e->next;
	}
	//��uΪ�������б߶���̽Ѱ����uΪ��ɫ
	u->color = BLACK;
	//�������ʱ���¼��f[u]��
	time++;
	u->f = time;
	//�ѽ������f�Ӵ�С��˳�򱣴���Sort������,����������
	if(flag == 0)
	{
		Sort[Sort[0]] = u->id;
		Sort[0]--;
	}
}
//�����������
void DFS(Graph *G)
{
	int i;
	//��ÿ�������ʼ��
	for(i = 1; i <= N; i++)
	{
		G->V[i]->id = i;
		G->V[i]->color = WHITE;
		G->V[i]->p = NULL;
	}
	//ʱ�����ʼ��
	time = 0;
	//���μ���V�еĶ��㣬���ְ�ɫ����ʱ������DFS_Visit���ʸö���
	for(i = 1; i <= N; i++)
	{

		int j;
		//��һ����������˳��
		if(flag == 0)
			j = i;
		//�ڶ�������f�Ӵ�С��˳�����˳���ڵ�һ��dfs�α�����Sort������
		else j = Sort[i];
		//���ְ�ɫ����ʱ������DFS_Visit���ʸö���
		if(G->V[j]->color == WHITE)
		{
			DFS_Visit(G, G->V[j]);
			if(flag)cout<<endl;
		}
	}
}
void Strongly_Connected_Component(Graph *G)
{
	//��һ��DFS������ÿ�������f
	DFS(G);
    //ת�ã�����GT
    Graph *G2 = Reverse(G);
	//��һ�ε�DFS�͵ڶ��ε�DFS��ϸ΢��ͬ����flag����
	flag = 1;
	//�ڶ��ε�DFS������f�Ӵ�С��˳��
	DFS(G2);
}

