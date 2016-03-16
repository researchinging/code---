#include <iostream>
#include <algorithm>
#include "UnionFindSet.h"
using namespace std;

#define N 14
#define M 9
//��
struct Edge
{
	int start;//���
	int end;//�յ�
	int len;//����
};
//��������
bool cmp(Edge a, Edge b)
{
	return a.len < b.len;
}
Edge e[N+1];
//Kruskal�㷨
void Mst_Kruskal()
{
    int i;
	//ʹ�ò��ཻ�������ݽṹΪÿ�����㴴��һ������
	UFS ufs(M);
	//���ݿ�Ȩֵ�ķǵݼ�����
	sort(e+1, e+N+1, cmp);
	//���ÿ����
	for(i = 1; i <= N; i++)
	{
		int u = e[i].start, v = e[i].end, l = e[i].len;
		//�˵�u,v�Ƿ�����ͬһ����������γ�һ����·�������
		//��������ͬһ����
		if(ufs.Find_Set(u) != ufs.Find_Set(v))
		{
			//�ѱ߼��뵽������
			cout<<u<<' '<<v<<' '<<l<<endl;
			//���������Ķ�����кϲ�
			ufs.Union(u, v);
		}
	}
}
/*
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 9 2
3 6 4
4 5 9
4 6 14
5 6 10
6 7 2
7 9 6
7 8 1
8 9 7
*/
int main()
{
	int i;
	for(i = 1; i <= N; i++)
		cin>>e[i].start>>e[i].end>>e[i].len;
	cout<<"MST:"<<endl;
	Mst_Kruskal();
	return 0;
}
