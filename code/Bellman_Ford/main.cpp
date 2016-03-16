/**
Bellman-Ford�㷨�ĵ����ɳڲ�����ʵ���Ͼ��ǰ��������s�Ĳ�Σ��������������·�����Ĺ��̡�
�ڶ�ÿ���߽��е�1���ɳڵ�ʱ�������˴�s�������������Ϊ1����Щ��֦��
Ҳ����˵���ҵ�����s������1������������Щ��������·����
��ÿ���߽��е�2���ɳڵ�ʱ�������˵�2��ε���֦������˵�ҵ��˾���2������������Щ��������·��������
��Ϊ���·�����ֻ����|v|-1 ���ߣ����ԣ�ֻ��Ҫѭ��|v|-1 �Ρ�

*/
#include <iostream>
using namespace std;

#define N 5   //��
#define M 10  //��
//�߽��ṹ
struct Edge
{
    int start;//����ͼ�����
    int end;//����ͼ���յ�
	int value;
};
//��������
struct Vertex
{
	int d;//���Դ��ľ���
	int p;//�����·�����еĸ����
};
Vertex V[N+1];//���㼯��
Edge E[M+1];//�߼���
//��ʼ��
void Initialize_Single_Source(int s)
{
	int i;
	for(i = 1; i <= N; i++)
	{
		V[i].d = 0x7fffffff;
		V[i].p = -1;
	}
	V[s].d = 0;
}
//�ɳڼ���
void Relax(int u, int v, int w)
{
	if(V[u].d != 0x7fffffff && V[v].d > V[u].d + w)
	{
		V[v].d = V[u].d + w;
		V[v].p = u;
	}
}
//���ÿ�����������
void Print()
{
	int i;
	for(i = 1; i <= N; i++)
		cout<<V[i].d<<' ';
	cout<<endl;
	for(i = 1; i <= N; i++)
		cout<<V[i].p<<' ';
	cout<<endl;
}
//Bellman_Ford�㷨
bool Bellman_Ford(int s)
{
	int i, j;
	//��ʼ��
	Initialize_Single_Source(s);
	//��ͼ�ı߽���|V|-1�����
	for (i = 1; i < N; i++)
	{
		cout<<"��"<<i<<"�֣�"<<endl;
		//���ζ�ÿ���߽����ɳڲ���
		for(j = 1; j <= M; j++)
		{
			Relax(E[j].start, E[j].end, E[j].value);
		}
		//���ÿһ���ɳں�Ľ��
		Print();
	}
	//�Ը�Ȩ��·���м��
	for(j = 1; j <= M; j++)
	{
		if(V[E[j].end].d > V[E[j].start].d + E[j].value)
			return false;
	}
	return true;
}
/*
2 3 5
2 5 8
2 4 -4
3 2 -2
5 3 -3
5 4 9
4 3 7
4 1 2
1 2 6
1 5 7
*/
int main()
{
	int i;
	//�����
	for(i = 1; i <= M; i++)
		cin>>E[i].start>>E[i].end>>E[i].value;
	//Bellman_Ford�㷨
	Bellman_Ford(1);
	return 0;
}
