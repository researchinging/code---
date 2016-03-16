//�������򣬸��ݽڵ�����ʱ��Ӵ�С����
#include <iostream>
using namespace std;

#define N 14
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
//����ĳ����
void DFS_Visit(Graph *G, Vertex *u)
{
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
	//��������ʱ��f���
	cout<<(char)(u->id + 'l')<<' ';
	u->f = time;
}
//�����������
void DFS(Graph *G)
{
	int i;
	//��ÿ�������ʼ��
	for(i = 1; i <= N; i++)
	{
		G->V[i]->color = WHITE;
		G->V[i]->p = NULL;
	}
	//ʱ�����ʼ��
	time = 0;
	//���μ���V�еĶ��㣬���ְ�ɫ����ʱ������DFS_Visit���ʸö���
	for(i = 1; i <= N; i++)
	{
		if(G->V[i]->color == WHITE)
			DFS_Visit(G, G->V[i]);
	}
}
//���
void Print(Graph *G)
{
	int i;
	//����ÿ������
	for(i = 1; i <= N; i++)
	{
		cout<<i<<':';
		//�����iΪ���ıߵ��յ�
		Edge *e = G->V[i]->head;
		while(e)
		{
			cout<<e->end<<' ';
			e = e->next;
		}
		cout<<endl;
	}
	cout<<endl;
}
/*
m r
m q
m x
n q
n u
n o
q t
o s
o v
o r
r u
r y
u t
p z
p o
s r
v w
v x
y v
w z
*/
int main()
{
	//����һ���յ�ͼ
	Graph *G = new Graph;
	Edge *E;
	Print(G);
	//�����
	int i;
	char start, end;
	for(i = 1; i <= 20; i++)
	{
		cin>>start>>end;
		E = new Edge(start-'l', end-'l');
		InsertEdge(G, E);
		//����ͼ��Ҫ��������
//		E = new Edge(end, start);
//		InsertEdge(G, E);
	}
	Print(G);
	//������������������������
	DFS(G);
	return 0;
}
