#include <iostream>
#include<stdlib.h>
using namespace std;

#define Max_weight 10
#define Num_item 4


void Dynamic_0_1_Kanpsack(int *value,int *weight,int **c)
{
    int i,w;
    for(i=0;i<=Max_weight;i++)  c[0][i]=0;
    for(i=1;i<=Num_item;i++)
    {
        c[i][0]=0;
        for(w=1;w<=Max_weight;w++)
        {
            if(weight[i]<=w)
            {
                if(value[i]+c[i-1][w-weight[i]]>c[i-1][w])
                    c[i][w]=value[i]+c[i-1][w-weight[i]];
                else
                    c[i][w]=c[i-1][w];
            }
            else    c[i][w]=c[i-1][w];
        }
    }
}
int main()
{
    int i,j;
    int *value=new int[Num_item];
    int *weight=new int[Num_item];
    int **c  = (int **) malloc(sizeof(int *) * (Num_item+1));
    for (j=0;j<=Num_item;j++){
    c[j] = (int *) malloc(sizeof(int) * (Max_weight+1));
    }

    for(j=1;j<=Num_item;j++)
    {
        value[j]=rand()%100;
        weight[j]=rand()%50;
    }

    Dynamic_0_1_Kanpsack(value,weight,c);
    for(i=0;i<=Num_item;i++)
    {
        for(j=0;j<=Max_weight;j++)
            cout<<c[i][j]<<"  ";
        cout<<endl;
    }



    return 0;
}
