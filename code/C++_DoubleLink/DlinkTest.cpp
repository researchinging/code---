#include <iostream>
#include "DoubleLink.h"
using namespace std;

// ˫���������int����
void int_test()
{
    int iarr[4] = {10, 20, 30, 40};

    cout << "\n----int_test----" << endl;
    // ����˫������
    DoubleLink<int>* pdlink = new DoubleLink<int>();

    pdlink->insert(0, 20);        // �� 20 ���뵽��һ��λ��
    pdlink->append_last(10);    // �� 10 ׷�ӵ�����ĩβ
    pdlink->insert_first(30);    // �� 30 ���뵽��һ��λ��

    // ˫�������Ƿ�Ϊ��
    cout << "is_empty()=" << pdlink->is_empty() <<endl;
    // ˫������Ĵ�С
    cout << "size()=" << pdlink->size() <<endl;

    // ��ӡ˫�������е�ȫ������
    int sz = pdlink->size();
    for (int i=0; i<sz; i++)
        cout << "pdlink("<<i<<")=" << pdlink->get(i) <<endl;
}

void string_test()
{
    string sarr[4] = {"ten", "twenty", "thirty", "forty"};

    cout << "\n----string_test----" << endl;
    // ����˫������
    DoubleLink<string>* pdlink = new DoubleLink<string>();

    pdlink->insert(0, sarr[1]);        // �� sarr�е�2��Ԫ�� ���뵽��һ��λ��
    pdlink->append_last(sarr[0]);    // �� sarr�е�1��Ԫ��  ׷�ӵ�����ĩβ
    pdlink->insert_first(sarr[2]);    // �� sarr�е�3��Ԫ��  ���뵽��һ��λ��

    // ˫�������Ƿ�Ϊ��
    cout << "is_empty()=" << pdlink->is_empty() <<endl;
    // ˫������Ĵ�С
    cout << "size()=" << pdlink->size() <<endl;

    // ��ӡ˫�������е�ȫ������
    int sz = pdlink->size();
    for (int i=0; i<sz; i++)
        cout << "pdlink("<<i<<")=" << pdlink->get(i) <<endl;
}

struct stu
{
    int id;
    char name[20];
};

static stu arr_stu[] =
{
    {10, "sky"},
    {20, "jody"},
    {30, "vic"},
    {40, "dan"},
};
#define ARR_STU_SIZE ( (sizeof(arr_stu)) / (sizeof(arr_stu[0])) )

void object_test()
{
    cout << "\n----object_test----" << endl;
    // ����˫������
    DoubleLink<stu>* pdlink = new DoubleLink<stu>();

    pdlink->insert(0, arr_stu[1]);        // �� arr_stu�е�2��Ԫ�� ���뵽��һ��λ��
    pdlink->append_last(arr_stu[0]);    // �� arr_stu�е�1��Ԫ��  ׷�ӵ�����ĩβ
    pdlink->insert_first(arr_stu[2]);    // �� arr_stu�е�3��Ԫ��  ���뵽��һ��λ��

    // ˫�������Ƿ�Ϊ��
    cout << "is_empty()=" << pdlink->is_empty() <<endl;
    // ˫������Ĵ�С
    cout << "size()=" << pdlink->size() <<endl;

    // ��ӡ˫�������е�ȫ������
    int sz = pdlink->size();
    struct stu p;
    for (int i=0; i<sz; i++)
    {
        p = pdlink->get(i);
        cout << "pdlink("<<i<<")=[" << p.id << ", " << p.name <<"]" <<endl;
    }
}


int main()
{
    int_test();        // ��ʾ��˫�����������int���ݡ���
    string_test();    // ��ʾ��˫������������ַ������ݡ���
    object_test();    // ��ʾ��˫��������������󡱡�

    return 0;
}
