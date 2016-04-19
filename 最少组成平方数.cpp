#include<iostream>
#include<string>
#include<vector>

using namespace std;


int perfect_squares(int n){
	int *dp=new int[n+1];
	dp[1]=1;

	for(int i=2;i<=n;i++){
		int min_num=INT_MAX;
		for(int j=1;j*j<=i;j++){
			if(j*j==i) {min_num=1;break;}
			min_num=min(min_num,dp[i-j*j]+1);
		}
		dp[i]=min_num;
	}
	return dp[n];

}


int main(){

	cout<<perfect_squares(12)<<endl;
	return 0;
}