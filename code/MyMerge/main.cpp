#include <iostream>
using namespace std;

template <class T>
void MyMerge(T *A,int p,int q,int r)
{
    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    T *L=new T[n1+2];
    T *R=new T[n2+2];

    for(i=1;i<=n1;i++)
        L[i]=A[p+i-1];
    for(i=1;i<=n2;i++)
        R[i]=A[q+i];
    L[n1+1]=-1;
    R[n2+1]=-1;

    i=1;j=1;
    for(k=p;k<=r;k++){

            if(R[j]==-1) {
                A[k]=L[i++];
                continue;
            }
            else if(L[i]==-1) {
                A[k]=R[j++];
                continue;
            }

        if(L[i]<R[j])   A[k]=L[i++];
        else    A[k]=R[j++];


    }

    delete[] L;
    delete[] R;
}

template <class T>
void MyMerge_Sort(T *A,int p,int r)
{
    int q;
    if(p<r){
        q=(p+r)/2;
        MyMerge_Sort<T>(A,p,q);
        MyMerge_Sort<T>(A,q+1,r);
        MyMerge<T>(A,p,q,r);
       // output_arr(A);
    }
}

int main()
{
 float a[100];
 int n,i;
 cout<<"the array length is:";
 cin>>n;
 cout<<endl<<"input the data:";
 for ( i=1;i<=n;i++)
  cin>>a[i];
 MyMerge_Sort(a,1,n);
    for ( i=1;i<=n;i++)
   cout<<a[i]<<' ';
   cout<<endl;


   return 0;
}


