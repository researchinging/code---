
#include<iostream>
#include"minheap.h"
using namespace std;

class Node
{
    int key;
};

void create_nodearr(Node *node,int *key,int length)
{
    for(i=0;i<length;i++)
        node[i].key=key[i];
}
int main()
{
    Node *p=new Node[7];
    int key[7]={3,6,1,8,5,32,23};
    create_nodearr(p,key,7);
    Minheap *mheap<Node>=new Node(p,0,7);
    return 0;
}
