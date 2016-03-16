/**
 * C++ ����: ���������
 *
 * @author skywang
 * @date 2013/11/07
 */

#include <iostream>
#include "RBTree.h"
using namespace std;

int main()
{
    int a[]= {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int check_insert=1;    // "����"�����ļ�⿪��(0���رգ�1����)
    int check_remove=1;    // "ɾ��"�����ļ�⿪��(0���رգ�1����)
    int i;
    int ilen = (sizeof(a)) / (sizeof(a[0])) ;
    RBTree<int>* tree=new RBTree<int>();

    cout << "== ԭʼ����: ";
    for(i=0; i<ilen; i++)
        cout << a[i] <<" ";
    cout << endl;

    for(i=0; i<ilen; i++)
    {
        tree->OS_insert(a[i]);
        // ����check_insert=1,����"��Ӻ���"
        if(check_insert)
        {
            cout << "== ��ӽڵ�: " << a[i] << endl;
            cout << "== ������ϸ��Ϣ: " << endl;
            tree->OS_print();
            cout << endl;
        }

    }

    cout << "== ǰ�����: ";
    tree->preOrder();

    cout << "\n== �������: ";
    tree->inOrder();

    cout << "\n== �������: ";
    tree->postOrder();
    cout << endl;

    cout << "== ��Сֵ: " << tree->minimum() << endl;
    cout << "== ���ֵ: " << tree->maximum() << endl;
    cout << "== ������ϸ��Ϣ: " << endl;
    tree->OS_print();
    cout << "=======select==========" << endl;
    i=tree->OS_select(1);
    cout<<"the "<<5<<"th number is"<<i<<endl;
    // ����check_remove=1,����"ɾ������"
    if(check_remove)
    {
        for(i=0; i<ilen; i++)
        {
            tree->OS_remove(a[i]);

            cout << "== ɾ���ڵ�: " << a[i] << endl;
            cout << "== ������ϸ��Ϣ: " << endl;
            tree->OS_print();
            cout << endl;
        }
    }

    // ���ٺ����
    tree->destroy();

    return 0;
}
