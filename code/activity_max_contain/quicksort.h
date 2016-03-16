#include<stdlib.h>
using namespace std;
template <class T>
int Partion(T *A,int p,int r)
{
    T x,temp;
    int i,j;
    x=A[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
        i++;
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        }
    }
    temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}

template <class T>
int Randomized_Partion(T *A,int p,int r)
{
    int i;
    T temp;
    i=rand()%(r-p+1)+p;
    temp=A[i];
    A[i]=A[r];
    A[r]=temp;
    return Partion<T>(A,p,r);

}
template <class T>
T Randomized_Select(T *A,int p,int r,int i)
{
    int q,k;
    if(p==r)
        return A[p];
    q=Randomized_Partion<T>(A,p,r);
    k=q-p+1;
    if(i==k)
        return A[q];
    else if(i<k)
        return Randomized_Select<T>(A,p,q-1,i);
    else return Randomized_Select<T>(A,q+1,r,i-k);
}

template <class T>
void QuickSort(T *A,int p,int r)
{
    int q;
    if(p<r)
    {
        q=Randomized_Partion<T>(A,p,r);
        QuickSort<T>(A,p,q-1);
        QuickSort<T>(A,q+1,r);
    }
}

