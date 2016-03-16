#include <iostream>
#include <stack>
using namespace std;

/**
 * C++ ����: STL �Դ��ġ�ջ��(stack)��ʾ����
 *
 * @author skywang
 * @date 2013/11/07
 */
int main ()
{
    int tmp=0;
    stack<int> istack;

    // ��10, 20, 30 ��������ջ��
    istack.push(10);
    istack.push(20);
    istack.push(30);

    // ����ջ��Ԫ�ء���ֵ��tmp����ɾ����ջ��Ԫ�ء�
    istack.pop();

    // ֻ����ջ������ֵ��tmp����ɾ����Ԫ��.
    tmp = istack.top();

    istack.push(40);

    while (!istack.empty())
    {
        tmp = istack.top();
        istack.pop();
        cout<<tmp<<endl;
    }

    return 0;
}
