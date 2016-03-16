#include <iostream>
/****************************
��������
��ĳ����Χ�ڵ�����������0-range����������
��buckets��¼�ȸ���С�����ĸ���������output�����е�λ��

********************************/
using namespace std;
void countSort(int a[], int n,int range)
{
    int output[n];             // �洢"����������"����ʱ����
    int i, buckets[range] ;
    for (i = 0; i < range; i++)
        buckets[i ]=0;

    // �����ݳ��ֵĴ����洢��buckets[]��
    for (i = 0; i < n; i++)
        buckets[ a[i] ]++;

    // ����buckets[i]��Ŀ�����ø��ĺ��buckets[i]��ֵ���Ǹ�������output[]�е�λ�á�
    for (i = 1; i < range; i++)
        buckets[i] += buckets[i - 1];

    // �����ݴ洢����ʱ����output[]��
    for (i = n - 1; i >= 0; i--)
    {
        output[buckets[ a[i]] - 1] = a[i];
        buckets[ a[i] ]--;
    }

    // ������õ����ݸ�ֵ��a[]
    for (i = 0; i < n; i++)
        a[i] = output[i];
}

int main()
{
    int i;
    int a[] = {43, 3, 42, 48, 14, 4, 34, 7, 16};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    countSort(a,ilen,50);
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    return 0;
}
