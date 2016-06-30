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
			if(j<weight[i]) dp[i][j]=dp[i-1][j];//这件货物不装包
			else dp[i][j]=max(dp[i-1][j-weight[i]]+val[i],dp[i-1][j]);//装包价值和不装包价值对比

	}
	

	system("pause");
	return 0;
}
