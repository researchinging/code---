#include <iostream>
#include <stdlib.h>
using namespace std;
int Partion(int *A,int p,int r)
{
    int x,i,j,temp;
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

int Randomized_Partion(int *A,int p,int r)
{
    int i,temp;
    i=rand()%(r-p+1)+p;
    temp=A[i];
    A[i]=A[r];
    A[r]=temp;
    return Partion(A,p,r);

}

int Randomized_Select(int *A,int p,int r,int i)
{
    int q,k;
    if(p==r)
        return A[p];
    q=Randomized_Partion(A,p,r);
    k=q-p+1;
    if(i==k)
        return A[q];
    else if(i<k)
        return Randomized_Select(A,p,q-1,i);
    else return Randomized_Select(A,q+1,r,i-k);
}


int main()
{
    int j;
    int a[6]={3,6,2,9,1,0};
    j=Randomized_Select(a,0,5,6);
    cout<<"the number is"<<j<<endl;
    /*HeapSort(a,6);
    for(j=0;j<6;j++)
    {
        cout<<b[j]<<"  ";
    }*/
    return 0;
}
