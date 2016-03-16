#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct node
{
	int start;
	int end;
	bool operator<(const node & b)const
	{
		return start < b.start;
	}
	bool operator==(const node & b)const
	{
		return (end >= b .start) && (start <= b.end);
	}
	bool operator>(const node & b)const
	{
		return start > b.start;
	}
	bool operator>=(const node & b)const
	{
		return (start < b.end)&&(start>b.start)&&(end>b.end);
	}
	bool operator<=(const node & b)const
	{
		return (start < b.start)&&(end>b.start)&&(end<b.end);
	}
};

//���ֽ����0 -> aС����Ԫ��a+1 -> b-1������Ԫ��b -> length_A������Ԫ
struct divid
{
	int a;
	int b;
};

node A[11];
int length_A = 10;

//�����ֽ����������ʾ
void Print(divid d)
{
	int i = 1;
	if(d.a > 0)
	{
		for(i = 1; i <= d.a; i++)
			cout<<'('<<A[i].start<<','<<A[i].end<<") ";
		cout<<endl;
		i = d.a + 1;
	}
	if(d.b > 0)
	{
		for(; i < d.b; i++)
			cout<<'('<<A[i].start<<','<<A[i].end<<") ";
		cout<<endl;
		i = d.b;
	}
	if(i <= length_A)
	{
		for(; i <= length_A; i++)
			cout<<'('<<A[i].start<<','<<A[i].end<<") ";
		cout<<endl;
	}
	cout<<endl;
}
void my_Print(divid d,int p,int r)
{
	int i = 1;
	if(d.a > 0)
	{
		for(i = p; i <= d.a; i++)
			cout<<'('<<A[i].start<<','<<A[i].end<<") ";
		cout<<endl;
		i = d.a + 1;
	}
	if(d.b > 0)
	{
		for(; i <= r; i++)
			cout<<'('<<A[i].start<<','<<A[i].end<<") ";
		cout<<endl;
		i = d.b;
	}
	if(i <= length_A)
	{
		cout<<"element is one only";
		cout<<endl;
	}
	cout<<endl;
}
//����
void Exchange(node &a, node &b)
{
	node temp;
	temp = a;
	a = b;
	b = temp;
}
//�������ص�
divid Partition(node *A, int p, int r)
{
	//��ȡ����һ��Ԫ��Ϊ��Ԫ
	node x = A[r];
	int i = p-1, j = r+1, k = p,kk;
	while(k <=r && k < j)
	{
        cout<<"when i="<<i<<"  " <<"j="<<j<<"  "<<"k="<<k<<"  "<<"A[k]=["<<A[k].start<<","<<A[k].end<<"]"<<endl;
        cout<<"before element is "<<x.start<<"---"<<x.end<<endl;
        for(kk=p; kk <= r; kk++)
			cout<<'('<<A[kk].start<<','<<A[kk].end<<") ";
		cout<<endl;

		//���С����Ԫ��������ǰ��
		if(A[k] < x)
		{
			i++;
			Exchange(A[i], A[k]);
			k++;
			cout<<"go into < "<<endl;
		}
	/*	else if(A[k] <= x)
		{
		    x.end=A[k].end;
			i++;
			Exchange(A[i], A[k]);
			k++;

			cout<<"go into <= "<<endl;
		}*/
		//������ڣ�����������
		else if(A[k] > x)
		{
			j--;
			Exchange(A[j], A[k]);
			//���ﲻ��k++����Ϊ����������Ԫ��Ҳ���ܴ�����Ԫ
			cout<<"go into > "<<endl;
		}
/*		else if(A[k] >= x)
		{
		    x.start=A[k].start;
			j--;
			Exchange(A[j], A[k]);
            cout<<"go into >= "<<endl;
		}*/
			//�����ȣ�������������Ҫ��ȡ������
        else{
			x.end = min(x.end,A[k].end);
			x.start =max(A[k].start,x.start);
			k++;
			cout<<"go into == "<<endl;
		}
        cout<<"after element is "<<x.start<<"---"<<x.end<<endl;
        for(kk=p; kk <= r; kk++)
			cout<<'('<<A[kk].start<<','<<A[kk].end<<") ";
		cout<<endl;
	}
	//���ػ��ֽ��
	divid ret = {i, j};
	if(ret.a < p)ret.a = -1;
	if(ret.b > r)ret.b = -1;
	cout<<"when p="<<p<<"  " <<"r="<<r<<endl;
    cout<<"main element is "<<x.start<<"---"<<x.end<<endl;
	my_Print(ret,p,r);
	return ret;
}

void QuickSort(node *A, int p, int r)
{
    int i;
	if(p >= r)
		return;
	//�����黮��Ϊ����
	divid q = Partition(A, p, r);
	//������ڵ�һ�Σ��Ե�һ������
	if(q.a > 0)
		QuickSort(A, p, q.a);
	//������ڵ����Σ��Ե���������
	if(q.b > 0)
		QuickSort(A, q.b, r);
}

int main()
{
	int i, n;
	//init data by random
	for(i = 1; i <= length_A; i++)
	{
		A[i].start = rand() % 100;
		A[i].end = rand() % 100;
		if(A[i].start > A[i].end)
			swap(A[i].start, A[i].end);
	}
	divid d = {-1, -1};
	for(i = 1; i <= length_A; i++)
	{
	    cout<<'('<<A[i].start<<','<<A[i].end<<") ";
	}
	cout<<endl;
	//Print(d);
	cout<<"***********************"<<endl;
	//sort
	QuickSort(A, 1, length_A);
	for(i=1; i <= length_A; i++)
			cout<<'('<<A[i].start<<','<<A[i].end<<") ";
    cout<<endl;
	return 0;
}
