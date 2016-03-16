#include <iostream>
#include <queue>
using namespace std;

#define N 10

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
	int degree;
	Vertex(int i):head(NULL),degree(0),id(i){}
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
		cout<<char(t+'l')<<' ';
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

int main()
{
	//����һ���յ�ͼ
	Graph *G = new Graph;
	Edge *E;
	//�����
	int i;
	char start, end;
	for(i = 1; i <= 14; i++)
	{
		cin>>start>>end;
		E = new Edge(start-'p', end-'p');
		InsertEdge(G, E);
		//����ͼ��Ҫ��������
//		E = new Edge(end, start);
//		InsertEdge(G, E);
	}
	//�����������
	Topological(G);
	return 0;
}
