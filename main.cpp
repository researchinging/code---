#include <iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;
class edge{
public:
    int next_index;
    edge *next;
    edge(int index):next_index(index),next(NULL){}
};
class Node{
public:
    int index;
    int weight;
    edge *linked_edge;
    bool operator<(Node &a) const{
        return weight<a.weight;
    }

};


class comparision{
public:
	bool operator()(Node* &a,Node* &b) const{
		return a->weight<b->weight;
	}

};

Node* init_Node(int num,vector<int> &weight){
Node* nodes=(Node*)malloc(sizeof(Node)*(num+1));
for(int i=1;i<=num;i++){
    nodes[i].index=i;
    nodes[i].weight=weight[i-1];
    nodes[i].linked_edge=NULL;
}
return nodes;
}

void add_edge(Node* nodes,int start,int end){
    edge* e=new edge(end);
    edge* pre=NULL;
    edge* curr=nodes[start].linked_edge;
    int key=nodes[end].weight;

    while(curr!=NULL&&nodes[curr->next_index].weight>key){
    pre=curr;
    curr=curr->next;
    }
    if(pre==NULL){
    edge* tmp=curr;
    nodes[start].linked_edge=e;
    e->next=tmp;
    }
    else{
    pre->next=e;
    e->next=curr;
    }

}

void add_bioedge(Node* nodes,int start,int end){

        add_edge(nodes,start,end);
        add_edge(nodes,end,start);
}

void  dfs(vector<vector<int> > &dyna,Node* nodes,int start,int parent,int M){
	int next;
	for(edge* e=nodes[start].linked_edge;e;e=e->next){
		next=e->next_index;
		if(next!=parent){
			dfs(dyna,nodes,next,start,M);
			for(int i=M;i>1;i--)
				for(int j=1;j<i;j++)
					dyna[start][i]=max(dyna[start][i],dyna[start][i-j]+dyna[next][j]);
		}
	}	
}


void BFS(int M,Node* nodes){
    priority_queue<Node*,vector<Node*>,comparision> BFS_q;
    BFS_q.push(&nodes[1]);
    int print_count=M;
    int max_sum=0;
    while(!BFS_q.empty()){
        Node* top_node=BFS_q.top();
        BFS_q.pop();
		max_sum+=top_node->weight;
        print_count--;
        edge *e=top_node->linked_edge;
        while(e!=NULL){
            BFS_q.push(&nodes[e->next_index]);
            e=e->next;
        }
        if(print_count==0) break;
    }

	cout<<max_sum<<endl;

}


int main()
{
    int N,M;
    while(cin>>N>>M){
	
	vector<vector<int> > dyna(N+1,vector<int>(M+1,0));

    vector<int> weight;

    int w;
    for(int i=1;i<=N;i++){
      cin>>w;
      weight.push_back(w);
	  dyna[i][1]=w;
    }


    Node* nodes=init_Node(N,weight);
    int s,e;
    for(int j=3;j<=N+1;j++){
        cin>>s>>e;
        add_bioedge(nodes,s,e);
    }

	
	dfs(dyna,nodes,1,0,M);
	int res=dyna[1][M];
	cout<<res<<endl;
	free(nodes);
	}
    return 0;
}
