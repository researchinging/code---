//�ο���Skip lists: a probabilistic alternative to balanced trees
#ifndef _SKIPLIST_H_
#define _SKIPLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_L 16 //������

//new_node����һ��Node�ṹ��,ͬʱ���ɰ���n��Node *Ԫ�ص�����
#define new_node(n) ((Node*)malloc(sizeof(Node)+n*sizeof(Node*)))
//����key��value������
typedef int keyType;
typedef int valueType;

//ÿ���ڵ�����ݽṹ
typedef struct node
{
    keyType key;// keyֵ
    valueType value;// valueֵ
    struct node *next[1];// ���ָ�����飬�������� ��ʵ�ֽṹ��ı䳤
} Node;
//����ṹ
typedef struct skip_list
{
    int level;// ������
    Node *head;//ָ��ͷ���
} skip_list;

/*
  �����ڵ�,�ɹ�����Node*����ָ��,���򷵻�NULL
  level �ڵ����
  key   �ڵ�ؼ���
  vlal  �ڵ��ֵ
*/
Node *create_node(int level, keyType key, valueType val);
/*
  ������Ծ���ɹ�����skip_list*����ָ��,���򷵻�NULL
*/
skip_list *create_sl();
/*
����Ԫ�ص�ʱ��Ԫ����ռ�еĲ�����ȫ������㷨,�����������
*/
int randomLevel();
/*
  ����ڵ㣬����ɹ�����true�����򷵻�false
  sl     ����ָ��
  key   �ڵ�ؼ���
  vlal  �ڵ��ֵ
*/
bool insert(skip_list *sl, keyType key, valueType val);
/*
  ɾ���ڵ㣬�ɹ�����true�����򷵻�false
  sl     ����ָ��
  key   �ڵ�ؼ���
*/
bool erase(skip_list *sl, keyType key);
/*
  ���ҽڵ㣬�ɹ�����valueT*���͵�ָ�룬���򷵻�NULL
  sl     ����ָ��
  key   �ڵ�ؼ���
*/
valueType *search(skip_list *sl, keyType key);
/*
����߲㿪ʼ����ӡ
sl ����ָ��
*/
void print_sl(skip_list *sl);
/*
�ͷ���Ծ��
sl ����ָ��
*/
void sl_free(skip_list *sl);

#endif

