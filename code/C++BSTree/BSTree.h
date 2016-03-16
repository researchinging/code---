/**
 * C++ ����: ���������
 *
 * @author skywang
 * @date 2013/11/07
 */

#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_

#include <iomanip>
#include <iostream>
using namespace std;

template <class T>
class BSTNode{
    public:
        T key;            // �ؼ���(��ֵ)
        BSTNode *left;    // ����
        BSTNode *right;    // �Һ���
        BSTNode *parent;// �����

        BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r):
            key(value),parent(),left(l),right(r) {}
};

template <class T>
class BSTree {
    private:
        BSTNode<T> *mRoot;    // �����

    public:
        BSTree();
        ~BSTree();

        // ǰ�����"������"
        void preOrder();
        // �������"������"
        void inOrder();
        // �������"������"
        void postOrder();

        // (�ݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�
        BSTNode<T>* search(T key);
        // (�ǵݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�
        BSTNode<T>* iterativeSearch(T key);

        // ������С��㣺������С���ļ�ֵ��
        T minimum();
        // ��������㣺���������ļ�ֵ��
        T maximum();

        // �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
        BSTNode<T>* successor(BSTNode<T> *x);
        // �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"��
        BSTNode<T>* predecessor(BSTNode<T> *x);

        // �����(keyΪ�ڵ��ֵ)���뵽��������
        void insert(T key);

        // ɾ�����(keyΪ�ڵ��ֵ)
        void remove(T key);
        void remove2(T key);

        // ���ٶ�����
        void destroy();

        // ��ӡ������
        void print();
    private:
        // ǰ�����"������"
        void preOrder(BSTNode<T>* tree) const;
        // �������"������"
        void inOrder(BSTNode<T>* tree) const;
        // �������"������"
        void postOrder(BSTNode<T>* tree) const;

        // (�ݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
        BSTNode<T>* search(BSTNode<T>* x, T key) const;
        // (�ǵݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
        BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const;

        // ������С��㣺����treeΪ�����Ķ���������С��㡣
        BSTNode<T>* minimum(BSTNode<T>* tree);
        // ��������㣺����treeΪ�����Ķ�����������㡣
        BSTNode<T>* maximum(BSTNode<T>* tree);

        // �����(z)���뵽������(tree)��
        void insert(BSTNode<T>* &tree, BSTNode<T>* z);

        // ɾ��������(tree)�еĽ��(z)�������ر�ɾ���Ľ��
        BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *z);
        BSTNode<T>* remove2(BSTNode<T>* &tree, BSTNode<T> *z);
        // ���ٶ�����
        void destroy(BSTNode<T>* &tree);

        // ��ӡ������
        void print(BSTNode<T>* tree, T key, int direction);
};

/*
 * ���캯��
 */
template <class T>
BSTree<T>::BSTree():mRoot(NULL)
{
}

/*
 * ��������
 */
template <class T>
BSTree<T>::~BSTree()
{
    destroy();
}

/*
 * ǰ�����"������"
 */
template <class T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const
{
    if(tree != NULL)
    {
        cout<< tree->key << " " ;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void BSTree<T>::preOrder()
{
    preOrder(mRoot);
}

/*
 * �������"������"
 */
template <class T>
void BSTree<T>::inOrder(BSTNode<T>* tree) const
{
    if(tree != NULL)
    {
        inOrder(tree->left);
        cout<< tree->key << " " ;
        inOrder(tree->right);
    }
}

template <class T>
void BSTree<T>::inOrder()
{
    inOrder(mRoot);
}

/*
 * �������"������"
 */
template <class T>
void BSTree<T>::postOrder(BSTNode<T>* tree) const
{
    if(tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<< tree->key << " " ;
    }
}

template <class T>
void BSTree<T>::postOrder()
{
    postOrder(mRoot);
}

/*
 * (�ݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
 */
template <class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T>* x, T key) const
{
    if (x==NULL || x->key==key)
        return x;

    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <class T>
BSTNode<T>* BSTree<T>::search(T key)
{
    search(mRoot, key);
}

/*
 * (�ǵݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
 */
template <class T>
BSTNode<T>* BSTree<T>::iterativeSearch(BSTNode<T>* x, T key) const
{
    while ((x!=NULL) && (x->key!=key))
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}

template <class T>
BSTNode<T>* BSTree<T>::iterativeSearch(T key)
{
    iterativeSearch(mRoot, key);
}

/*
 * ������С��㣺����treeΪ�����Ķ���������С��㡣
 */
template <class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

template <class T>
T BSTree<T>::minimum()
{
    BSTNode<T> *p = minimum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/*
 * ��������㣺����treeΪ�����Ķ�����������㡣
 */
template <class T>
BSTNode<T>* BSTree<T>::maximum(BSTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T>
T BSTree<T>::maximum()
{
    BSTNode<T> *p = maximum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/*
 * �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
 */
template <class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *x)
{
    // ���x�����Һ��ӣ���"x�ĺ�̽��"Ϊ "�����Һ���Ϊ������������С���"��
    if (x->right != NULL)
        return minimum(x->right);

    // ���xû���Һ��ӡ���x���������ֿ��ܣ�
    // (01) x��"һ������"����"x�ĺ�̽��"Ϊ "���ĸ����"��
    // (02) x��"һ���Һ���"�������"x����͵ĸ���㣬���Ҹø����Ҫ��������"���ҵ������"��͵ĸ����"����"x�ĺ�̽��"��
    BSTNode<T>* y = x->parent;
    while ((y!=NULL) && (x==y->right))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
 * �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"��
 */
template <class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *x)
{
    // ���x�������ӣ���"x��ǰ�����"Ϊ "��������Ϊ���������������"��
    if (x->left != NULL)
        return maximum(x->left);

    // ���xû�����ӡ���x���������ֿ��ܣ�
    // (01) x��"һ���Һ���"����"x��ǰ�����"Ϊ "���ĸ����"��
    // (01) x��"һ������"�������"x����͵ĸ���㣬���Ҹø����Ҫ�����Һ���"���ҵ������"��͵ĸ����"����"x��ǰ�����"��
    BSTNode<T>* y = x->parent;
    while ((y!=NULL) && (x==y->left))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
 * �������뵽��������
 *
 * ����˵����
 *     tree �������ĸ����
 *     z ����Ľ��
 */
template <class T>
void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T>* z)
{
    BSTNode<T> *y = NULL;
    BSTNode<T> *x = tree;

    // ����z�Ĳ���λ��
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y==NULL)
        tree = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

/*
 * �����(keyΪ�ڵ��ֵ)���뵽��������
 *
 * ����˵����
 *     tree �������ĸ����
 *     key ������ļ�ֵ
 */
template <class T>
void BSTree<T>::insert(T key)
{
    BSTNode<T> *z=NULL;

    // ����½����ʧ�ܣ��򷵻ء�
    if ((z=new BSTNode<T>(key,NULL,NULL,NULL)) == NULL)
        return ;

    insert(mRoot, z);
}

/*
 * ɾ�����(z)�������ر�ɾ���Ľ��
 *
 * ����˵����
 *     tree �������ĸ����
 *     z ɾ���Ľ��
 */
 template <class T>
BSTNode<T>* BSTree<T>::remove2(BSTNode<T>* &tree, BSTNode<T> *z)
{

    BSTNode<T> *y=NULL;

    if(z->parent==NULL) z=mRoot;

    if ((z->left == NULL)|| (z->right == NULL) ) {
        if (z->left == NULL){
            (z->parent->left==z)?z->parent->left=z->right:z->parent->right=z->right;
            z->right->parent=z->parent;
        }
        else {
            (z->parent->left==z)?z->parent->left=z->left:z->parent->right=z->left;
            z->left->parent=z->parent;
        }

    }
    else {
        y=successor(z);
        z->key=y->key;
        (y->parent->left==y)?y->parent->left=NULL:y->parent->right=NULL;
        return y;
    }
    return z;

}
template <class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* &tree, BSTNode<T> *z)
{
    BSTNode<T> *x=NULL;
    BSTNode<T> *y=NULL;

    if ((z->left == NULL) || (z->right == NULL) )   //��    1.�����ɾ���ڵ��������һ���ڵ㣬������Ľڵ��������
        y = z;                                      //      ���ڵ��λ��ȷ����λ��
    else
        y = successor(z);                           //�������ɾ���ڵ����������ڵ㣬�ҵ���ɾ���ڵ��ǰ�̽��
                                                    //��ǰ�̽��������ýڵ�

    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;

    if (x != NULL)
        x->parent = y->parent;

    if (y->parent == NULL)
        tree = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if (y != z)
        z->key = y->key;

    return y;
}

/*
 * ɾ�����(z)�������ر�ɾ���Ľ��
 *
 * ����˵����
 *     tree �������ĸ����
 *     z ɾ���Ľ��
 */
template <class T>
void BSTree<T>::remove(T key)
{
    BSTNode<T> *z, *node;

    if ((z = search(mRoot, key)) != NULL)
        if ( (node = remove(mRoot, z)) != NULL)
            delete node;
}


template <class T>
void BSTree<T>::remove2(T key)
{
    BSTNode<T> *z, *node;

    if ((z = search(mRoot, key)) != NULL)
        if ( (node = remove2(mRoot, z)) != NULL)
            delete node;
}
/*
 * ���ٶ�����
 */
template <class T>
void BSTree<T>::destroy(BSTNode<T>* &tree)
{
    if (tree==NULL)
        return ;

    if (tree->left != NULL)
        return destroy(tree->left);
    if (tree->right != NULL)
        return destroy(tree->right);

    delete tree;
    tree=NULL;
}

template <class T>
void BSTree<T>::destroy()
{
    destroy(mRoot);
}

/*
 * ��ӡ"���������"
 *
 * key        -- �ڵ�ļ�ֵ
 * direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
 *               -1����ʾ�ýڵ������ĸ���������;
 *                1����ʾ�ýڵ������ĸ������Һ��ӡ�
 */
template <class T>
void BSTree<T>::print(BSTNode<T>* tree, T key, int direction)
{
    if(tree != NULL)
    {
        if(direction==0)    // tree�Ǹ��ڵ�
            cout << setw(2) << tree->key << " is root" << endl;
        else                // tree�Ƿ�֧�ڵ�
            cout << setw(2) << tree->key << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << endl;

        print(tree->left, tree->key, -1);
        print(tree->right,tree->key,  1);
    }
}

template <class T>
void BSTree<T>::print()
{
    if (mRoot != NULL)
        print(mRoot, mRoot->key, 0);
}

#endif
