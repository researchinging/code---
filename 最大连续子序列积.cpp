#include<stdlib.h>
#include<algorithm>

using namespace std;
/*分析：假设数组为a[]，直接利用动归来求解，考虑到可能存在负数的情况，我们用Max[i]来表示以a[i]结尾的最大连续子序列的乘积值，用Min[i]表示以a[i]结尾的最小的连续子序列的乘积值，那么状态转移方程为：
        Max[i]=max{a[i], Max[i-1]*a[i], Min[i-1]*a[i]};
 
       Min[i]=min{a[i], Max[i-1]*a[i], Min[i-1]*a[i]};
 
初始状态为Max[1]=Min[1]=a[1]。代码如下：
 





 
给定一个整数数组，有正有负数，0，正数组成,数组下标从1算起
 
求最大连续子序列乘积，并输出这个序列，如果最大子序列乘积为负数，那么就输出-1
 
用Max[i]表示以a[i]结尾乘积最大的连续子序列
 
用Min[i]表示以a[i]结尾乘积最小的连续子序列  因为有复数，所以保存这个是必须的
 
*/
 
void longest_multiple(int *a,int n){
 int *Min=new int[n+1]();
 int *Max=new int[n+1]();
 int *p=new int[n+1]();
 //初始化
 for(int i=0;i<=n;i++){
  p[i]=-1;
 }
 Min[1]=a[1];
 Max[1]=a[1];
 int max_val=Max[1];
 for(int i=2;i<=n;i++){
  Max[i]=max(Max[i-1]*a[i],Min[i-1]*a[i],a[i]);
  Min[i]=min(Max[i-1]*a[i],Min[i-1]*a[i],a[i]);
  if(max_val<Max[i])
   max_val=Max[i];
 }
 if(max_val<0)
  printf("%d",-1);
 else
  printf("%d",max_val);
//内存释放
 delete [] Max;
 delete [] Min;
}