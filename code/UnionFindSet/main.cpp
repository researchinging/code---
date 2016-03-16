
/*
UnionFindSet.h
���鼯���ǵݹ鷽������·��ѹ���������0��ʼ
*/
#include <iostream>
using namespace std;

#define MAXN 30005

class UFS
{
public:
	int n;
	int p[MAXN+1];//���ϸ����
	int rank[MAXN+1];  //�����е�ĸ���
public:
	UFS(int size = MAXN);
	void clear();
	int Find_Set(int x);
	//a����b�У������ִ�С
	void Union(int x, int y);
	void Make_Set(int x);
	void Link(int x, int y);
};
UFS::UFS(int size):n(size)
{
	//�����0��ʼ
	for(int i = 0; i <= n; i++)
		Make_Set(i);
}
void UFS::Make_Set(int x)
{
	p[x] = x;
	rank[x] = 0;
}
void UFS::clear()
{
	for(int i = 0; i <= n; i++)
		Make_Set(i);
}
int UFS::Find_Set(int x)
{
	if(x != p[x])
		p[x] = Find_Set(p[x]);
	return p[x];
}
void UFS::Union(int x, int y)
{
	Link(Find_Set(x), Find_Set(y));
}
void UFS::Link(int x, int y)
{
	if(rank[x] > rank[y])
		p[y] = x;
	else
	{
		p[x] = y;
		if(rank[x] == rank[y])
			rank[y]++;
	}
}
