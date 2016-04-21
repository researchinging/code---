#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 100  //��󶥵����
int n, m;       //������������
struct arcnode  //�߽��
{
	int vertex;     //���ͷ������ڵĶ�����
	arcnode * next; //ָ����һ���ڽӵ�
	arcnode() {}
	arcnode(int v):vertex(v),next(NULL) {}
};
struct vernode      //�����㣬Ϊÿһ���ڽӱ�ı�ͷ���
{
	int vex;    //��ǰ������
	arcnode * firarc;   //��ö��������ĵ�һ��������ɵı�
}Ver[maxn];

void Init()  //����ͼ���ڽӱ���Ҫ�ȳ�ʼ��������������
{
	for(int i = 1; i <= n; i++)
	{
		Ver[i].vex = i;
		Ver[i].firarc = NULL;
	}
}
void Insert(int a, int b)   //������aΪ��㣬bΪ�յ㣬��Ȩ�ı�
{
	arcnode * q = new arcnode(b);
	if(Ver[a].firarc == NULL)
		Ver[a].firarc = q;
	else
	{
		arcnode * p = Ver[a].firarc;
		while(p->next != NULL)
			p = p->next;
		p->next = q;
	}
}

#define INF 9999
bool visited[maxn];     //��Ƕ����Ƿ񱻿��죬��ʼֵΪfalse
int parent[maxn];       //parent[]��¼ĳ���ĸ��׽�㣬����������ʼ��Ϊ-1
int d[maxn], time, f[maxn]; //ʱ��time��ʼ��Ϊ0��d[]��¼��һ�α�����ʱ��f[]��¼�������ʱ
int topoSort[maxn];
int cnt;
void dfs(int s)         //��������������ڽӱ�ʵ�֣�����¼ʱ�����Ѱ�����·��
{
	//cout << s << " ";
	visited[s] = true;
	time++;
	d[s] = time;
	arcnode * p = Ver[s].firarc;
	while(p != NULL)
	{
		if(!visited[p->vertex])
		{
			parent[p->vertex] = s;
			dfs(p->vertex);
		}
		p = p->next;
	}
	time++;
	f[s] = time;
	topoSort[cnt++] = s;

}
void dfs_travel()       //�������ж��㣬�ҳ�����������������������ɭ��
{
	for(int i = 1; i <= n; i++)     //��ʼ��
	{
		parent[i] = -1;
		visited[i] = false;
	}
	time = 0;
	for(int i = 1; i <= n; i++)     //����
		if(!visited[i])
			dfs(i);
	//cout << endl;
}
void topological_Sort()
{
	cnt = 0;
	dfs_travel();
	for(int i = cnt-1; i >= 0; i--)
		cout << topoSort[i] << " ";
	cout << endl;
}
int main()
{
	int a, b, w;
	cout << "Enter n and m��";
	cin >> n >> m;
	Init();
	while(m--)     {
		cin >> a >> b;       //������㡢�յ�
		Insert(a, b);        //�������
	}
	topological_Sort();
	return 0;
}