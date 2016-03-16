#include <iostream>
#include <queue>
using namespace std;

#define N 6
#define M 10

//边结点结构
struct Edge
{
	int start;//有向图的起点
	int end;//有向图的终点
	Edge *next;//指向同一个起点的下一条边
	int weight;//边的权重
	Edge(int s, int e,int w):start(s),end(e),weight(w),next(NULL){}
};
//顶点结点结构
struct Vertex
{
	int id;
	Edge *head;//指向以该顶点为起点的下一条边
	int degree;
	int d;
	int p;
	Vertex(int i):head(NULL),degree(0),id(i),p(-1){}
};
//图结构
struct Graph
{
	Vertex *V[N+1];//N个顶点
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
//插入边
void InsertEdge(Graph *G, Edge *E)
{
	//如果没有相同起点的边
	if(G->V[E->start]->head == NULL)
		G->V[E->start]->head =E;
	//如果有，加入到链表中，递增顺序排列，便于查重
	else
	{
		//链表的插入，不解释
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
		//插入边的同时，计下每个顶点的入度
		G->V[E->end]->degree++;
	}
}
//拓扑排序
void Topological(Graph *G)
{
	//队列初始化
	while(!Q.empty())
		Q.pop();
	int i;
	//将所有入度为0的点入队列
	for(i = 1; i <= N; i++)
	{
		if(G->V[i]->degree == 0)
			Q.push(i);
	}
	//队列不为空
	while(!Q.empty())
	{
		//队列首元素
		int t = Q.front();
		Q.pop();
		//输出
		cout<<t<<' ';
		Top[++Top[0]] = t;
		//处理以头结点为起点的所有的边
		Edge *e = G->V[t]->head;
		while(e)
		{
			//将边的终点的入度-1
			G->V[e->end]->degree--;
			//若入度减为0，则入队列
			if(G->V[e->end]->degree == 0)
				Q.push(e->end);
			e = e->next;
		}
	}
	cout<<endl;
}
//初始化
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
//松弛技术
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
	//拓扑排序并输出，时间O(V+E)
	Topological(G);
	//初始化O(V)
	Initialize_Single_Source(G, s);
	//对每个顶点进行一次迭代
	for(int i = 1; i <= N; i++)
	{
		cout<<"对第"<<i<<"个点进行松弛后"<<endl;
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
	//构造一个空的图
	Graph *G = new Graph;
	Edge *E;
	//输入边
	int i,weight, start, end;
	for(i = 1; i <= M; i++)
	{
		cin>>start>>end>>weight;
		E = new Edge(start, end,weight);
		InsertEdge(G, E);
	}
	//有向
	int s;
	cin>>s;
	Dag_Shortest_Paths(G, s);
	return 0;
}
