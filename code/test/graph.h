#include <iostream>
#include <limits.h>
using namespace std;

enum colour{
    WHITE,
    GRAY,
    BLACK
};


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
class Vertex
{
public:
	char id;
	int key;
	Edge *head;
    int d;
	Vertex *p;

	//�ж��Ƿ��ڶ���
	bool In_queue;


    bool operator<(const Vertex & b)const
	{
		return key < b.key;
	}

};
//ͼ�ṹ
class Graph
{
public:
	Vertex *V;//N������
	int num_v;
    Graph();
    Graph(int **matrix,int n){
        int i,j;
        num_v=n;
        V=new Vertex[num_v+1];
        for(i=1;i<=num_v;i++)
        {
            V[i].id='a'+i-1;
            V[i].key=INT_MAX;
            V[i].p=NULL;
            V[i].In_queue=1;
            V[i].head=NULL;
        }
        cout<<"go into matrix"<<endl;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(matrix[i][j]!=0) InsertEdge(new Edge(i,j));
    }
private:
	//�����
	void InsertEdge(Edge *E);



};
Graph::Graph()
{
    char fir_v,con='[';
    int i,start;
    cout<<"first Vertex id is(eg:a or i):";
    cin>>fir_v;
    cout<<"the number of Vertex:";
    cin>>num_v;
    V=new Vertex[num_v+1];
    for(i=1;i<=num_v;i++)
    {
        V[i].id=fir_v+i-1;
        V[i].key=INT_MAX;
        V[i].p=NULL;
        V[i].In_queue=1;
    }
    cout<<"Now input the edge id connected with the first char"<<endl;
    cout<<"if none input ';'"<<endl;
    for(i=0;i<num_v;i++)
    {
        start=i+1;
        cout<<"connected with "<<char(fir_v+i)<<":";
        cin>>con;
        while(con!=';')
        {
            cin>>con;
            InsertEdge(new Edge(start,(con-'a'+1)));
        }
        con='[';
    }
}

//�����
void Graph::InsertEdge(Edge *E)
{
    	//���û����ͬ���ı�
	if(V[E->start].head == NULL)
		V[E->start].head =E;
	//����У����뵽�����У�����˳�����У����ڲ���
	else
	{
		//����Ĳ��룬������
		Edge *e1 = V[E->start].head, *e2 = e1;
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
			V[E->start].head =E;
		}
		else
		{
			e2->next = E;
			E->next = e1;
		}
	}
}


