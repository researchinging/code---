#include <iostream>
#include "ArrayStack.h"
using namespace std;

int main()
{
    int tmp=0;
    ArrayStack<int> *astack = new ArrayStack<int>();

    cout<<"main"<<endl;

    // ��10, 20, 30 ��������ջ��
  //  cout<<"main2"<<endl;
    astack->push(10);
  //  cout<<"main3"<<endl;
    astack->push(20);
    astack->push(30);

    // ����ջ��Ԫ�ء���ֵ��tmp����ɾ����ջ��Ԫ�ء�
    tmp = astack->pop();
    cout<<"tmp="<<tmp<<endl;

    // ֻ����ջ������ֵ��tmp����ɾ����Ԫ��.
    tmp = astack->peek();

    astack->push(40);

    while (!astack->isEmpty())
    {
        tmp = astack->pop();
        cout<<tmp<<endl;
    }

    return 0;
}
