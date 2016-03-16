#include <iostream>
#include<stdlib.h>
#include"area_quicksort.h"
#include"area.h"
using namespace std;

void recursive_activity_selector(area *A,int k,int n)
{
    int m=k+1;
    while(m<=n&&(A[m].start<A[k].finish))
        m=m+1;
    if(m<=n)
        return recursive_activity_selector(A,m,n);
}
int main()
{
    area num;
    Activity_col ac(8);
    ac.init_col();
    ac.print();

    QuickSort<area>(ac.A,1,8);
    ac.print();
    /*
    num=Randomized_Select<area>(ac.A,1,8,5);
    ac.print();
    cout<<"["<<num.start<<"  "<<num.finish<<"]"<<"   "<<endl;
*/
    ac.Max_con();
    ac.print_max_contain();
    return 0;
}
