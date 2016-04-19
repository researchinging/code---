#include<iostream>

using namespace std;

int find(int* root,int a){
	if(root[a]==0) return a;
	else return root[a]=find(root,root[a]);
}

void bind(int* root,int a,int b){
	int root_a,root_b;
	root_a=find(root,a);
	root_b=find(root,b);
	if(root_a!=root_b) root[root_a]=root_b;
}

int main(){

	int N,M;
	int a,b;
	int count=0;
	int* root;
	while(cin>>N){
		
		if(N==0) break;
		root=new int[N+1];
		memset(root,0,sizeof(int)*(N+1));

		cin>>M;
		for(int i=0;i<M;i++){
			cin>>a>>b;
			bind(root,a,b);
		}
		count=0;
		for(int j=1;j<=N;j++)
			if(root[j]==0) count++;
		cout<<count-1<<endl;
		delete []root;
	}
	return 0;
}