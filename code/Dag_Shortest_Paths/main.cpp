#include <iostream>
#include <queue>
using namespace std;

#define N 6
#define M 10

//�߽��ṹ
struct Edge
{
	int start;//����ͼ�����
	int end;//����ͼ���յ�
	Edge *next;//ָ��ͬһ��������һ����
	int weight;//�ߵ�Ȩ��
	Edge(int s, int e,int w):start(s),end(e),weight(w),next(NULL){}
};
//������ṹ
struct Vertex
{
	int id;
	Edge *head;//ָ���Ըö���Ϊ������һ����
	int degree;
	int d;
	int p;
	Vertex(int i):head(NULL),degree(0),id(i),p(-1){}
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

queue<int> Q;
int time = 0, Top[N+1] = {0};

void Print(Graph *G)
{
	int i;
	cout<<"d:";
	for(i = 1; i <= N; i++)
		cout<<G->V[i]->d<<' ';
	cout<<endl;
	cout<<"p:";
	for(i = 1; i <= N; i++)
		cout<<G->V[i]->p<<' ';
	cout<<endl;
}
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
		//����ߵ�ͬʱ������ÿ����������
		G->V[E->end]->degree++;
	}
}
//��������
void Topological(Graph *G)
{
	//���г�ʼ��
	while(!Q.empty())
		Q.pop();
	int i;
	//���������Ϊ0�ĵ������
	for(i = 1; i <= N; i++)
	{
		if(G->V[i]->degree == 0)
			Q.push(i);
	}
	//���в�Ϊ��
	while(!Q.empty())
	{
		//������Ԫ��
		int t = Q.front();
		Q.pop();
		//���
		cout<<t<<' ';
		Top[++Top[0]] = t;
		//������ͷ���Ϊ�������еı�
		Edge *e = G->V[t]->head;
		while(e)
		{
			//���ߵ��յ�����-1
			G->V[e->end]->degree--;
			//����ȼ�Ϊ0���������
			if(G->V[e->end]->degree == 0)
				Q.push(e->end);
			e = e->next;
		}
	}
	cout<<endl;
}
//��ʼ��
void Initialize_Single_Source(Graph *G, int s)
{
	int i;
	for(i = 1; i <= N; i++)
	{
		G->V[i]->d = 0x7fffffff;
		G->V[i]->p = -1;
	}
	G->V[s]->d = 0;
}
//�ɳڼ���
void Relax(Vertex* u, Vertex* v, int w)
{
	if(u->d != 0x7fffffff && v->d > u->d + w)
	{
		v->d = u->d + w;
		v->p = u->id;
	}
}
void Dag_Shortest_Paths(Graph *G, int s)
{
	//�������������ʱ��O(V+E)
	Topological(G);
	//��ʼ��O(V)
	Initialize_Single_Source(G, s);
	//��ÿ���������һ�ε���
	for(int i = 1; i <= N; i++)
	{
		cout<<"�Ե�"<<i<<"��������ɳں�"<<endl;
		Vertex *u = G->V[Top[i]];
		Edge *e = u->head;
		while(e)
		{
			Relax(u,G->V[e->end], e->weight);
			e = e->next;
		}
		Print(G);
	}
}
/*
1 2 5
2 3 2
3 4 7
4 5 -1
5 6 -2
1 3 3
2 4 6
3 5 4
3 6 2
4 6 1
*/
int main()
{
	//����һ���յ�ͼ
	Graph *G = new Graph;
	Edge *E;
	//�����
	int i,weight, start, end;
	for(i = 1; i <= M; i++)
	{
		cin>>start>>end>>weight;
		E = new Edge(start, end,weight);
		InsertEdge(G, E);
	}
	//����
	int s;
	cin>>s;
	Dag_Shortest_Paths(G, s);
	return 0;
}
