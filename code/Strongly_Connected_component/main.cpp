#include <iostream>
#include"graph.h"
using namespace std;


int main()
{
    //����һ���յ�ͼ
    Graph *G = new Graph;
	Edge *E;
    //�����
    int i;
    int start, end;
    for(i = 1; i <= 14; i++)
    {
        cin>>start>>end;
        E = new Edge(start, end);
        InsertEdge(G, E);
        //����ͼ��Ҫ��������
//      E = new Edge(end, start);
//      InsertEdge(G, E);
    }
	//����ǿ��ͨ����
	Strongly_Connected_Component(G);
    return 0;
}
