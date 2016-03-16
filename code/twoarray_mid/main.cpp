//9.3-8
/*********************************
���⣺�����������������λ��

�㷨�������£�

Step1���ֱ���������������ֵmidA��midB���Ƚ�midA��midB�Ĵ�С

Step2�����midA=midB����ô���ֵ�����⣨nA+nB�������е���λ��

Step3�����midA < midB��A[1..Na] -> A[a+1..Na]��B[1..Nb] -> B[1..b]���ݹ�ض������µ���������λ����

Step4�����midA > midB��A[1..Na] -> A[1..a]��B[1..Nb] -> B[b+1..Nb]���ݹ�ض������µ���������λ����

Step5������Step1-Step4�еĵݹ������ֱ����������ʣ�µ�Ԫ��һ��������4����ֱ�Ӷ���4��Ԫ������λ����


*************************************/
#include <iostream>
#include<stdlib.h>
using namespace std;

void Print(int *A, int s, int e)
{
	int i;
	for(i = s; i <= e; i++)
		cout<<A[i]<<' ';
	cout<<endl;
}
//��������ʱ���ѡ��
//�Ѿ����ֺܶ���ˣ�������
int Partition(int *A, int p, int r)
{
	int x = A[r], i = p-1, j;
	for(j = p; j < r; j++)
	{
		if(A[j] <= x)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r]);
	return i+1;
}
int Select(int *A, int p, int r, int i);
//��ÿһ���start��end���в������򣬲�������ֵ
//��������ܼ򵥣�������
int Insert(int *A, int start, int end, int k)
{
	int i, j;
	for(i = 2; i <= end; i++)
	{
		int t = A[i];
		for(j = i; j >= start; j--)
		{
			if(j == start)
				A[j] = t;
			else if(A[j-1] > t)
				A[j] = A[j-1];
			else
			{
				A[j] = t;
				break;
			}
		}
	}
	return A[start+k-1];
}
//�������е��㷨���ҵ���ֵ����ֵ
int Find(int *A, int p, int r)
{
	int i, j = 0;
	int start, end, len = r - p + 1;
	int *B = new int[len/5+1];
	//ÿ5��Ԫ��һ�飬����Ϊstart��end����ÿһ����в������򣬲�������ֵ
	for(i = 1; i <= len; i++)
	{
		if(i % 5 == 1)
			start = i+p-1;
		if(i % 5 == 0 || i == len)
		{
			j++;
			end = i+p-1;
			//��ÿһ���start��end���в������򣬲�������ֵ,��������һ�飬����Ԫ�ظ�����������5
			int ret = Insert(A, start, end, (end-start)/2+1);
			//��ÿһ�����ֵ�������γ�һ���µ�����
			B[j] = ret;
		}
	}
	//����������Եݹ����Select()�ķ�ʽѰ����ֵ
	int ret = Select(B, 1, j, (j+1)/2);
	//delete []B;
	return ret;
}
//��fΪ��Ԫ�Ļ���
int Partition2(int *A, int p, int r, int f)
{
	int i;
	//�ҵ�f��λ�ò�������A[r]����
	for(i = p; i < r; i++)
	{
		if(A[i] == f)
		{
			swap(A[i], A[r]);
			break;
		}
	}
	return Partition(A, p, r);
}
//Ѱ������A[p..r]�еĵ�i���Ԫ�أ�i�Ǵ�1��ʼ���������Ǵ�p��ʼ
int Select(int *A, int p, int r, int i)
{
	//���������ֻ��һ��Ԫ�أ���ֱ�ӷ���
	if(p == r)
		return A[p];
	//�������е��㷨���ҵ���ֵ����ֵ
	int f = Find(A, p, r);
	//�������ֵΪ��Ԫ�Ļ��֣�������ֵ����������A[1..len]��λ��
	//��Ϊ��Ԫ�������е�ĳ��Ԫ�أ����ֺ��������ģ�A[p..q-1] <= f < A[q+1..r]
	int q = Partition2(A, p, r, f);
	//ת��Ϊ��ֵ��������A[p..r]�е�λ��
	int k = q - p + 1;
	//����Ѱ�ҵ�Ԫ����Ƚ�
	if(i == k)
		return A[q];
	else if(i < k)
		return Select(A, p, q-1, i);
	else
		//�����Ԫ�������е�ĳ��Ԫ�أ�����һ��Ҫ����д
		return Select(A, q+1, r, i-k);
		//���������Ԫ���������еĸ�ĳ��Ԫ�أ�����һ��Ҫ�ĳ�Select(A, q, r, i-k+1)
}
int SelectMid(int *A, int start, int end)
{
	return Select(A, start, end, (end-start+1)/2+1);
}
//����abcd�еڶ�С�������Ѿ�a<b,c<d
int GetRet(int a, int b, int c, int d)
{
	if(a < c)
	{
		if(c < b)
			return min(b, d);
		return c;
	}
	else
	{
		if(a < d)
			return min(b, d);
		return a;
	}
}
//�㷨����
int solve(int *A, int *B, int n)
{
	int ret;
	int startA = 1, startB = 1, endA = n, endB = n;
	while(1)
	{
		if(endA == startA)
			return max(A[startA], B[startB]);
		//���ֻʣ��4��Ԫ�أ�����4��Ԫ���е�2С��Ԫ��
		if(endA - startA == 1)
		{
			ret = GetRet(A[startA], A[endA], B[startB], B[endB]);
			break;
		}
		//�ֱ����A��B�е���ֵ�����ﴦ��������A��B���������
		//���A��B���Ѿ�����ģ�ֻ��mid=A[(start+end)/2]�Ϳ��������ֵ
		int midA = SelectMid(A, startA, endA);
		int midB = SelectMid(B, startB, endB);
//		cout<<midA<<' '<<midB<<endl;
//		Print(A, startA, endA);
//		Print(B, startB, endB);
		//SELECT�㷨�������ֵĹ��̣����Կ���ֱ�ӽ�ȥ����Ҫһ��
		//ȥ������A��ǰһ�������B�ĺ�һ�룬ע�Ᵽ֤ȥ����AB������Ԫ�ظ������
		if(midA == midB)
		{
			ret = midA;
			break;
		}
		//ȥ��A��ǰ�������B�ĺ�룬ע��غ����������Ԫ�����
		else if(midA < midB)
		{
			startA = startA + (endA - startA + 1) / 2;
			endB = endB - (endB - startB + 1) / 2;
		}
		//ȥ��B��ǰ�������A�ĺ�룬ע��غ����������Ԫ�����
		else
		{
			endA = endA - (endA-startA + 1) / 2;
			startB = startB + (endB - startB + 1) / 2;
		}
//		Print(A, startA, endA);
//		Print(B, startB, endB);
	}
	return ret;
}
//�����㷨����
int main()
{
	int n, i;
	while(cin>>n)
	{
		int *A = new int[n+1];
		int *B = new int[n+1];
		//�����������
		for(i = 1; i <= n; i++)
		{
			A[i] = rand() % 100;
			B[i] = rand() % 100;
		}
		//��ӡ���ɵ�����
		Print(A, 1, n);
		Print(B, 1, n);
		//�㷨����
		int ret = solve(A, B, n);
		//������
		cout<<ret<<endl;
		delete A;
		delete B;
	}
	return 0;
}
