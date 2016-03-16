/**
 * C++ ����: ���������
 *
 * @author skywang
 * @date 2013/11/07
 */

#include <iostream>
#include "BSTree.h"
using namespace std;

static int arr[]= {1,5,4,3,2,6};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i, ilen;
    BSTree<int>* tree=new BSTree<int>();

    cout << "== �������: ";
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        cout << arr[i] <<" ";
        tree->insert(arr[i]);
    }

    cout << "\n== ǰ�����: ";
    tree->preOrder();

    cout << "\n== �������: ";
    tree->inOrder();

    cout << "\n== �������: ";
    tree->postOrder();
    cout << endl;

    cout << "== ��Сֵ: " << tree->minimum() << endl;
    cout << "== ���ֵ: " << tree->maximum() << endl;
    cout << "== ������ϸ��Ϣ: " << endl;
    tree->print();

    cout << "\n== ɾ�����ڵ�: " << arr[1];
    tree->remove2(arr[1]);

    cout << "\n== �������: ";
    tree->inOrder();
    cout << endl;

    // ���ٶ�����
    tree->destroy();

    return 0;
}
