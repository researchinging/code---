#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	int max_num;int max_weight;

	vector<int> weight;
	vector<int> val;
	vector<vector<int> > dp(max_num+1,vector<int>(max_weight+1,0));

	for(int i=0;i<=max_num;i++){
		for(int j=0;j<=max_weight;j++){
			if(i==0||j==0) dp[i][j]=0;			
			else dp[i][j]=max(dp[i-1][j-weight[i]]+val[i],dp[i-1][j]);

	}
	

	system("pause");
	return 0;
}
