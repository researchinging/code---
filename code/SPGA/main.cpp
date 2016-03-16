#include <iostream>
#include <queue>
#include<string.h>
using namespace std;


bool *IN_queue;
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
	Vertex **V;//N������
	int num_v;
	Graph(int n)
	{
		int i;
		num_v=n;
		V=new Vertex*[n+1];
		for(i = 1; i <= n; i++)
			V[i] = new Vertex(i);
	}
	~Graph()
	{
		int i;
		for(i = 1; i <= num_v; i++)
			delete V[i];
	}
};

queue<int> Q;
int time = 0, *Top;


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
	for(i = 1; i <= G->num_v; i++)
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
	for(i = 1; i <= G->num_v; i++)
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
	for(int i = 1; i <= G->num_v; i++)
	{
		cout<<"�Ե�"<<i<<"��������ɳں�"<<endl;
		Vertex *u = G->V[Top[i]];
		Edge *e = u->head;
		while(e!=NULL)
		{
			Relax(u,G->V[e->end], e->weight);
			e = e->next;
		}
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

void SPFA(Graph *G,int s)
{
    int old_weight;
    Initialize_Single_Source(G, s);
    while(!Q.empty())
        Q.pop();
    Q.push(s);
    cout<<"SPGA begin"<<endl;
    IN_queue[s]=true;
    while(!Q.empty())
	{
		//������Ԫ��
		int t = Q.front();
		Q.pop();
		Edge *e = G->V[t]->head;
		Vertex *u = G->V[t];
		while(NULL!=e)
        {
            old_weight=G->V[e->end]->d;
            Relax(u,G->V[e->end], e->weight);
            if(old_weight!=G->V[e->end]->d&&IN_queue[e->end]==false)
            {
                Q.push(e->end);
                IN_queue[e->end]=true;
            }
            e=e->next;
        }
	}
}

void Print(Graph *G)
{
	int i;
	cout<<"d:";
	for(i = 1; i <= G->num_v; i++)
		cout<<G->V[i]->d<<' ';
	cout<<endl;
	cout<<"p:";
	for(i = 1; i <= G->num_v; i++)
		cout<<G->V[i]->p<<' ';
	cout<<endl;
}
int main()
{
	//����һ���յ�ͼ
	int n,m;
	cout<<"input vertex number and edge number:"<<endl;
	cin>>n>>m;
	IN_queue=new bool[n+1];
	memset(IN_queue,0,sizeof(bool)*(n+1));
	Top=new int[n+1];
	Top[0]=0;
	Graph *G = new Graph(n);
	Edge *E;
	//�����
	cout<<"input edge eg:123  vertex1---->vertex2----weight=3"<<endl;
	int i,weight, start, end;
	for(i = 1; i <= m; i++)
	{
		cin>>start>>end>>weight;
		E = new Edge(start, end,weight);
		InsertEdge(G, E);
	}
	cout<<"input source"<<endl;
	//����
	int s;
	cin>>s;
	//Dag_Shortest_Paths(G, s);
	SPFA(G,1);
	cout<<"SPGA finish"<<endl;
	Print(G);
	return 0;
}
