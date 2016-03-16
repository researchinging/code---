/**
 * C++ ����: �����
 *
 * @author skywang
 * @date 2013/11/07
 */

#ifndef _RED_BLACK_TREE_HPP_
#define _RED_BLACK_TREE_HPP_

#include <iomanip>
#include <iostream>
using namespace std;

enum RBTColor{RED, BLACK};

template <class T>
class Interval{
public:T low;
T high;
Interval(T l,T h):low(l),high(h){}
};

template <class T>
class RBTNode{
    public:
        RBTColor color;    // ��ɫ
        T key;            // �ؼ���(��ֵ)
        RBTNode *left;    // ����
        RBTNode *right;    // �Һ���
        RBTNode *parent; // �����
/*****************order-statistic tree**********************************/
        Interval<T>* inter;
        T subtree_max;

        RBTNode(RBTColor c, RBTNode *p, RBTNode *l, RBTNode *r,Interval<T> *i):
            key(i->low),color(c),parent(),left(l),right(r),inter(i),subtree_max(i->high){}
};

template <class T>
class RBTree {
    private:
        RBTNode<T> *mRoot;    // �����

    public:
        RBTree();
        ~RBTree();

        // ǰ�����"�����"
        void preOrder();
        // �������"�����"
        void inOrder();
        // �������"�����"
        void postOrder();
        T Max(T a,T b,T c);
        RBTNode<T>* Inter_search(Interval<T>* i);
        // (�ݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
        RBTNode<T>* search(Interval<T>* i);
        //RBTNode<T>* Inter_remove_search(Interval i);
        // (�ǵݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
        RBTNode<T>* iterativeSearch(T key);

        // ������С��㣺������С���ļ�ֵ��
        T minimum();
        // ��������㣺���������ļ�ֵ��
        T maximum();

        // �ҽ��(x)�ĺ�̽�㡣��������"�����������ֵ���ڸý��"��"��С���"��
        RBTNode<T>* successor(RBTNode<T> *x);
        // �ҽ��(x)��ǰ����㡣��������"�����������ֵС�ڸý��"��"�����"��
        RBTNode<T>* predecessor(RBTNode<T> *x);


        // �����(keyΪ�ڵ��ֵ)���뵽�������
        void Inter_insert(Interval<T>* i);

        // ɾ�����(keyΪ�ڵ��ֵ)
        void Inter_remove(Interval<T> *i);

        // ���ٺ����
        void destroy();

        // ��ӡ�����
        void Inter_print();
    private:
        // ǰ�����"�����"
        void preOrder(RBTNode<T>* tree) const;
        // �������"�����"
        void inOrder(RBTNode<T>* tree) const;
        // �������"�����"
        void postOrder(RBTNode<T>* tree) const;

        RBTNode<T>* Inter_search(RBTNode<T>* tree,Interval<T>* i);
        // (�ݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
        RBTNode<T>* search(RBTNode<T>* x, Interval<T>* i) const;
        void Inter_remove(RBTNode<T>* &root, RBTNode<T> *node);
        RBTNode<T>* OS_remove_search(RBTNode<T>* x, T key) const;
        // (�ǵݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
        RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;

        // ������С��㣺����treeΪ�����ĺ��������С��㡣
        RBTNode<T>* minimum(RBTNode<T>* tree);
        // ��������㣺����treeΪ�����ĺ����������㡣
        RBTNode<T>* maximum(RBTNode<T>* tree);

        // ����
        void Inter_leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
        // ����
        void Inter_rightRotate(RBTNode<T>* &root, RBTNode<T>* y);

        // ���뺯��
        void Inter_insert(RBTNode<T>* &root, RBTNode<T>* node);
        // ������������
        void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
        // ɾ������
        void OS_remove(RBTNode<T>* &root, RBTNode<T> *node);
        // ɾ����������
        void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);

        // ���ٺ����
        void destroy(RBTNode<T>* &tree);

        // ��ӡ�����
        void Inter_print(RBTNode<T>* tree, T key, int direction);
        void updata_onebranch(RBTNode<T> *node);
        void updata_leaf(RBTNode<T> *node);
        void updata_twobranch(RBTNode<T> *node,RBTNode<T> *rep);


#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};

/*
 * ���캯��
 */
template <class T>
RBTree<T>::RBTree():mRoot(NULL)
{
    mRoot = NULL;
}

/*
 * ��������
 */
template <class T>
RBTree<T>::~RBTree()
{
    destroy();
}
template <class T>
T RBTree<T>::Max(T a,T b,T c)
{
    if(a>b)
        return (a>c)?a:c;
    else return (b>c)?b:c;
}

template <class T>
RBTNode<T>* RBTree<T>::Inter_search(RBTNode<T>* tree,Interval<T>* i)
{
    while(tree!=NULL&&(tree->inter->high<i->low||i->high<tree->inter->low))
        if(tree->left!=NULL&&tree->left->subtree_max>=i->low)
            tree=tree->left;
        else tree=tree->right;
    return tree;
}
template <class T>
RBTNode<T>* RBTree<T>::Inter_search(Interval<T>* i)
{
    Inter_search(mRoot,i);
}
/*
 * ǰ�����"�����"
 */
template <class T>
void RBTree<T>::preOrder(RBTNode<T>* tree) const
{
    if(tree != NULL)
    {
        cout<< tree->key << " " ;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void RBTree<T>::preOrder()
{
    preOrder(mRoot);
}

/*
 * �������"�����"
 */
template <class T>
void RBTree<T>::inOrder(RBTNode<T>* tree) const
{
    if(tree != NULL)
    {
        inOrder(tree->left);
        cout<< tree->key << " " ;
        inOrder(tree->right);
    }
}

template <class T>
void RBTree<T>::inOrder()
{
    inOrder(mRoot);
}

/*
 * �������"�����"
 */
template <class T>
void RBTree<T>::postOrder(RBTNode<T>* tree) const
{
    if(tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<< tree->key << " " ;
    }
}

template <class T>
void RBTree<T>::postOrder()
{
    postOrder(mRoot);
}

/*
 * (�ݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
 */
template <class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, Interval<T>* i) const
{
    if (x==NULL || (x->inter->high==i->high&&x->key==i->low))
        return x;

    if (i->low < x->key)
        return search(x->left, i);
    else
        return search(x->right, i);
}

template <class T>
RBTNode<T>* RBTree<T>::search(Interval<T>* i)
{
    search(mRoot,i);
}



/*
 * (�ǵݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
 */
template <class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const
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
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
    iterativeSearch(mRoot, key);
}

/*
 * ������С��㣺����treeΪ�����ĺ��������С��㡣
 */
template <class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

template <class T>
T RBTree<T>::minimum()
{
    RBTNode<T> *p = minimum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/*
 * ��������㣺����treeΪ�����ĺ����������㡣
 */
template <class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T>
T RBTree<T>::maximum()
{
    RBTNode<T> *p = maximum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/*
 * �ҽ��(x)�ĺ�̽�㡣��������"�����������ֵ���ڸý��"��"��С���"��
 */
template <class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T> *x)
{
    // ���x�����Һ��ӣ���"x�ĺ�̽��"Ϊ "�����Һ���Ϊ������������С���"��
    if (x->right != NULL)
        return minimum(x->right);

    // ���xû���Һ��ӡ���x���������ֿ��ܣ�
    // (01) x��"һ������"����"x�ĺ�̽��"Ϊ "���ĸ����"��
    // (02) x��"һ���Һ���"�������"x����͵ĸ���㣬���Ҹø����Ҫ��������"���ҵ������"��͵ĸ����"����"x�ĺ�̽��"��
    RBTNode<T>* y = x->parent;
    while ((y!=NULL) && (x==y->right))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
 * �ҽ��(x)��ǰ����㡣��������"�����������ֵС�ڸý��"��"�����"��
 */
template <class T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T> *x)
{
    // ���x�������ӣ���"x��ǰ�����"Ϊ "��������Ϊ���������������"��
    if (x->left != NULL)
        return maximum(x->left);

    // ���xû�����ӡ���x���������ֿ��ܣ�
    // (01) x��"һ���Һ���"����"x��ǰ�����"Ϊ "���ĸ����"��
    // (01) x��"һ������"�������"x����͵ĸ���㣬���Ҹø����Ҫ�����Һ���"���ҵ������"��͵ĸ����"����"x��ǰ�����"��
    RBTNode<T>* y = x->parent;
    while ((y!=NULL) && (x==y->left))
    {
        x = y;
        y = y->parent;
    }

    return y;
}



/*
 * �Ժ�����Ľڵ�(x)��������ת
 *
 * ����ʾ��ͼ(�Խڵ�x��������)��
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(����)-->           / \                #
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */
template <class T>
void RBTree<T>::Inter_leftRotate(RBTNode<T>* &root, RBTNode<T>* x)
{
    // ����x���Һ���Ϊy
    RBTNode<T> *y = x->right;

    // �� ��y�����ӡ� ��Ϊ ��x���Һ��ӡ���
    // ���y�����ӷǿգ��� ��x�� ��Ϊ ��y�����ӵĸ��ס�
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    // �� ��x�ĸ��ס� ��Ϊ ��y�ĸ��ס�
    y->parent = x->parent;

    if (x->parent == NULL)
    {
        root = y;            // ��� ��x�ĸ��ס� �ǿսڵ㣬��y��Ϊ���ڵ�
    }
    else
    {
        if (x->parent->left == x)
            x->parent->left = y;    // ��� x�������ڵ�����ӣ���y��Ϊ��x�ĸ��ڵ�����ӡ�
        else
            x->parent->right = y;    // ��� x�������ڵ�����ӣ���y��Ϊ��x�ĸ��ڵ�����ӡ�
    }

    // �� ��x�� ��Ϊ ��y�����ӡ�
    y->left = x;
    // �� ��x�ĸ��ڵ㡱 ��Ϊ ��y��
    x->parent = y;
    y->subtree_max=x->subtree_max;
    if(x->left==NULL||x->right==NULL)
    {
        if(x->left==NULL&&x->right!=NULL)
            x->subtree_max=(x->inter->high>x->right->subtree_max)?x->inter->high:x->right->subtree_max;
        else if(x->left!=NULL&&x->right==NULL)
            x->subtree_max=(x->inter->high>x->left->subtree_max)?x->inter->high:x->left->subtree_max;
        else x->subtree_max=x->inter->high;
    }
    else    x->subtree_max=Max(x->inter->high,x->left->subtree_max,x->right->subtree_max);

}

/*
 * �Ժ�����Ľڵ�(y)��������ת
 *
 * ����ʾ��ͼ(�Խڵ�y��������)��
 *            py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(����)-->            /  \                     #
 *        x   ry                           lx   y
 *       / \                                   / \                   #
 *      lx  rx                                rx  ry
 *
 */
template <class T>
void RBTree<T>::Inter_rightRotate(RBTNode<T>* &root, RBTNode<T>* y)
{
    // ����x�ǵ�ǰ�ڵ�����ӡ�
    RBTNode<T> *x = y->left;

    // �� ��x���Һ��ӡ� ��Ϊ ��y�����ӡ���
    // ���"x���Һ���"��Ϊ�յĻ����� ��y�� ��Ϊ ��x���Һ��ӵĸ��ס�
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    // �� ��y�ĸ��ס� ��Ϊ ��x�ĸ��ס�
    x->parent = y->parent;

    if (y->parent == NULL)
    {
        root = x;            // ��� ��y�ĸ��ס� �ǿսڵ㣬��x��Ϊ���ڵ�
    }
    else
    {
        if (y == y->parent->right)
            y->parent->right = x;    // ��� y�������ڵ���Һ��ӣ���x��Ϊ��y�ĸ��ڵ���Һ��ӡ�
        else
            y->parent->left = x;    // (y�������ڵ������) ��x��Ϊ��x�ĸ��ڵ�����ӡ�
    }

    // �� ��y�� ��Ϊ ��x���Һ��ӡ�
    x->right = y;

    // �� ��y�ĸ��ڵ㡱 ��Ϊ ��x��
    y->parent = x;
    x->subtree_max=y->subtree_max;
    if(y->left==NULL||y->right==NULL)
    {
        if(y->left==NULL&&y->right!=NULL)
            y->subtree_max=(y->inter->high>y->right->subtree_max)?y->inter->high:y->right->subtree_max;
        else if(y->left!=NULL&&y->right==NULL)
            y->subtree_max=(y->inter->high>y->left->subtree_max)?y->inter->high:y->left->subtree_max;
        else y->subtree_max=y->inter->high;
    }
    else    y->subtree_max=Max(y->inter->high,y->left->subtree_max,y->right->subtree_max);

}

/*
 * �����������������
 *
 * ���������в���ڵ�֮��(ʧȥƽ��)���ٵ��øú�����
 * Ŀ���ǽ������������һ�ź������
 *
 * ����˵����
 *     root ������ĸ�
 *     node ����Ľ��        // ��Ӧ���㷨���ۡ��е�z
 */
template <class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
    RBTNode<T> *parent, *gparent;

    // �������ڵ���ڣ����Ҹ��ڵ����ɫ�Ǻ�ɫ��
    while ((parent = rb_parent(node)) && rb_is_red(parent))
    {
        gparent = rb_parent(parent);

        //�������ڵ㡱�ǡ��游�ڵ�����ӡ�
        if (parent == gparent->left)
        {
            // Case 1����������ڵ��Ǻ�ɫ
            {
                RBTNode<T> *uncle = gparent->right;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }

            // Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ����Һ���
            if (parent->right == node)
            {
                RBTNode<T> *tmp;
                Inter_leftRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            // Case 3�����������Ǻ�ɫ���ҵ�ǰ�ڵ������ӡ�
            rb_set_black(parent);
            rb_set_red(gparent);
            Inter_rightRotate(root, gparent);
        }
        else//����z�ĸ��ڵ㡱�ǡ�z���游�ڵ���Һ��ӡ�
        {
            // Case 1����������ڵ��Ǻ�ɫ
            {
                RBTNode<T> *uncle = gparent->left;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }

            // Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ�������
            if (parent->left == node)
            {
                RBTNode<T> *tmp;
                Inter_rightRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            // Case 3�����������Ǻ�ɫ���ҵ�ǰ�ڵ����Һ��ӡ�
            rb_set_black(parent);
            rb_set_red(gparent);
            Inter_leftRotate(root, gparent);
        }
    }

    // �����ڵ���Ϊ��ɫ
    rb_set_black(root);
}

/*
 * �������뵽�������
 *
 * ����˵����
 *     root ������ĸ����
 *     node ����Ľ��        // ��Ӧ���㷨���ۡ��е�node
 */
template <class T>
void RBTree<T>::Inter_insert(RBTNode<T>* &root, RBTNode<T>* node)
{
    RBTNode<T> *y = NULL;
    RBTNode<T> *x = root;

    // 1. �����������һ�Ŷ�������������ڵ���ӵ�����������С�
    while (x != NULL)
    {
        y = x;
        if(y->subtree_max<node->subtree_max) y->subtree_max=node->subtree_max;
        if (node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;
    if (y!=NULL)
    {
        if (node->key < y->key)
            y->left = node;
        else
            y->right = node;
    }
    else
        root = node;



    // 2. ���ýڵ����ɫΪ��ɫ
    node->color = RED;

    // 3. ������������Ϊһ�Ŷ��������
    insertFixUp(root, node);
}

/*
 * �����(keyΪ�ڵ��ֵ)���뵽�������
 *
 * ����˵����
 *     tree ������ĸ����
 *     key ������ļ�ֵ
 */
template <class T>
void RBTree<T>::Inter_insert(Interval<T>* i)
{
    RBTNode<T> *z=NULL;

    // ����½����ʧ�ܣ��򷵻ء�
    if ((z=new RBTNode<T>(BLACK,NULL,NULL,NULL,i)) == NULL)
        return ;

    Inter_insert(mRoot, z);
}

/*
 * �����ɾ����������
 *
 * �ڴӺ������ɾ������ڵ�֮��(�����ʧȥƽ��)���ٵ��øú�����
 * Ŀ���ǽ������������һ�ź������
 *
 * ����˵����
 *     root ������ĸ�
 *     node �������Ľڵ�
 */
template <class T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent)
{
    RBTNode<T> *other;

    while ((!node || rb_is_black(node)) && node != root)
    {
        if (parent->left == node)
        {
            other = parent->right;
            if (rb_is_red(other))
            {
                // Case 1: x���ֵ�w�Ǻ�ɫ��
                rb_set_black(other);
                rb_set_red(parent);
                Inter_leftRotate(root, parent);
                other = parent->right;
            }
            if ((!other->left || rb_is_black(other->left)) &&
                (!other->right || rb_is_black(other->right)))
            {
                // Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��
                rb_set_red(other);
                node = parent;
                parent = rb_parent(node);
            }
            else
            {
                if (!other->right || rb_is_black(other->right))
                {
                    // Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��
                    rb_set_black(other->left);
                    rb_set_red(other);
                    Inter_rightRotate(root, other);
                    other = parent->right;
                }
                // Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->right);
                Inter_leftRotate(root, parent);
                node = root;
                break;
            }
        }
        else
        {
            other = parent->left;
            if (rb_is_red(other))
            {
                // Case 1: x���ֵ�w�Ǻ�ɫ��
                rb_set_black(other);
                rb_set_red(parent);
                Inter_rightRotate(root, parent);
                other = parent->left;
            }
            if ((!other->left || rb_is_black(other->left)) &&
                (!other->right || rb_is_black(other->right)))
            {
                // Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��
                rb_set_red(other);
                node = parent;
                parent = rb_parent(node);
            }
            else
            {
                if (!other->left || rb_is_black(other->left))
                {
                    // Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��
                    rb_set_black(other->right);
                    rb_set_red(other);
                    Inter_leftRotate(root, other);
                    other = parent->left;
                }
                // Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->left);
                Inter_rightRotate(root, parent);
                node = root;
                break;
            }
        }
    }
    if (node)
        rb_set_black(node);
}

/*
 * ɾ�����(node)�������ر�ɾ���Ľ��
 *
 * ����˵����
 *     root ������ĸ����
 *     node ɾ���Ľ��
 */
template <class T>
void RBTree<T>::Inter_remove(RBTNode<T>* &root, RBTNode<T> *node)
{
    RBTNode<T> *child, *parent,*delete_p;
    RBTColor color;

    // ��ɾ���ڵ��"���Һ��Ӷ���Ϊ��"�������
    if ( (node->left!=NULL) && (node->right!=NULL) )
    {
        // ��ɾ�ڵ�ĺ�̽ڵ㡣(��Ϊ"ȡ���ڵ�")
        // ������ȡ��"��ɾ�ڵ�"��λ�ã�Ȼ���ٽ�"��ɾ�ڵ�"ȥ����
        RBTNode<T> *replace = node;

        // ��ȡ��̽ڵ�
        replace = replace->right;
        while (replace->left != NULL)
            replace = replace->left;

        updata_leaf(replace);

        // "node�ڵ�"���Ǹ��ڵ�(ֻ�и��ڵ㲻���ڸ��ڵ�)
        if (rb_parent(node))
        {
            if (rb_parent(node)->left == node)
                rb_parent(node)->left = replace;
            else
                rb_parent(node)->right = replace;
        }
        else
            // "node�ڵ�"�Ǹ��ڵ㣬���¸��ڵ㡣
            root = replace;

        // child��"ȡ���ڵ�"���Һ��ӣ�Ҳ����Ҫ"�����Ľڵ�"��
        // "ȡ���ڵ�"�϶����������ӣ���Ϊ����һ����̽ڵ㡣
        child = replace->right;
        parent = rb_parent(replace);
        // ����"ȡ���ڵ�"����ɫ
        color = rb_color(replace);

        // "��ɾ���ڵ�"��"���ĺ�̽ڵ�ĸ��ڵ�"
        if (parent == node)
        {
            parent = replace;
        }
        else
        {
            // child��Ϊ��
            if (child)
                rb_set_parent(child, parent);
            parent->left = child;

            replace->right = node->right;
            rb_set_parent(node->right, replace);
        }

        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;

        updata_twobranch(node,replace);

        if (color == BLACK)
            removeFixUp(root, child, parent);

        delete node;
        return ;
    }

    if( (node->left==NULL) && (node->right==NULL) ) updata_leaf(node);
    else updata_onebranch(node);

    if (node->left !=NULL)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    // ����"ȡ���ڵ�"����ɫ
    color = node->color;

    if (child)
        child->parent = parent;

    // "node�ڵ�"���Ǹ��ڵ�
    if (parent)
    {
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }
    else
        root = child;

    if (color == BLACK)
        removeFixUp(root, child, parent);
    delete node;
}
template <class T>
void RBTree<T>::updata_twobranch(RBTNode<T> *node,RBTNode<T> *rep)
{
    RBTNode<T> *parent,*child,*brother;
    T bigger_branch=(node->left->subtree_max>node->right->subtree_max)?node->left->subtree_max:node->right->subtree_max;
    cout<<" in updata_twobranch"<<endl;
    if(node->inter->high>bigger_branch)
    {
        rep->subtree_max=bigger_branch;
        parent=rep;

        while(parent->parent!=NULL&&parent->parent->subtree_max==node->inter->high)
        {
            child=parent;
            parent=parent->parent;
            brother=(child==parent->left)?parent->right:parent->left;
            if(brother==NULL)
            {
                parent->subtree_max=(child->subtree_max>parent->inter->high)?child->subtree_max:child->subtree_max;
            }
            else{parent->subtree_max=Max(child->subtree_max,parent->inter->high,brother->subtree_max);}
        }
    }

}
template <class T>
void RBTree<T>::updata_leaf(RBTNode<T> *node)
{

    RBTNode<T> *parent,*child,*brother;
    parent=node->parent;
    if(parent->subtree_max==node->subtree_max)
        parent->subtree_max=parent->inter->high;
    cout<<" in updata_leaf"<<endl;
    while(parent->parent!=NULL&&parent->parent->subtree_max==node->subtree_max)
        {
            child=parent;
            parent=parent->parent;
            brother=(child==parent->left)?parent->right:parent->left;
            if(brother==NULL)
            {
                parent->subtree_max=(child->subtree_max>parent->inter->high)?child->subtree_max:child->subtree_max;
            }
            else{parent->subtree_max=Max(child->subtree_max,parent->inter->high,brother->subtree_max);}
        }
}
template <class T>
void RBTree<T>::updata_onebranch(RBTNode<T> *node)
{
    RBTNode<T> *parent,*child,*brother;
    parent=node->parent;
    cout<<" in updata_onebranch"<<endl;
    if(parent->subtree_max==node->subtree_max)
    {
        brother=(node==parent->left)?parent->right:parent->left;
        child=(node->left==NULL)?node->right:node->left;
        if(brother==NULL)
        {
            parent->subtree_max=(child->subtree_max>parent->inter->high)?child->subtree_max:child->subtree_max;
        }
        else{parent->subtree_max=Max(child->subtree_max,parent->inter->high,brother->subtree_max);}
        while(parent->parent!=NULL&&parent->parent->subtree_max==node->subtree_max)
        {
            child=parent;
            parent=parent->parent;
            brother=(child==parent->left)?parent->right:parent->left;
            if(brother==NULL)
            {
                parent->subtree_max=(child->subtree_max>parent->inter->high)?child->subtree_max:child->subtree_max;
            }
            else{parent->subtree_max=Max(child->subtree_max,parent->inter->high,brother->subtree_max);}
        }
    }
}
/*
 * ɾ��������м�ֵΪkey�Ľڵ�
 *
 * ����˵����
 *     tree ������ĸ����
 */
template <class T>
void RBTree<T>::Inter_remove(Interval<T> *i)
{
    RBTNode<T> *node;

    // ����key��Ӧ�Ľڵ�(node)���ҵ��Ļ���ɾ���ýڵ�
    if ((node = search(mRoot, i)) != NULL)
        Inter_remove(mRoot, node);
}

/*
 * ���ٺ����
 */
template <class T>
void RBTree<T>::destroy(RBTNode<T>* &tree)
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
void RBTree<T>::destroy()
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
void RBTree<T>::Inter_print(RBTNode<T>* tree, T key, int direction)
{
    if(tree != NULL)
    {
        if(direction==0)    // tree�Ǹ��ڵ�
            cout << setw(2) << "["<<tree->key<<","<<tree->inter->high<<"]  " << "(B) is root" << "  subtree_max is"<<tree->subtree_max<< endl;
        else                // tree�Ƿ�֧�ڵ�
            cout << setw(2) <<  "["<<tree->key<<","<<tree->inter->high<<"]  "<<  (rb_is_red(tree)?"(R)":"(B)") << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << "  subtree_max is"<<tree->subtree_max<< endl;

        Inter_print(tree->left, tree->key, -1);
        Inter_print(tree->right,tree->key,  1);
    }
}

template <class T>
void RBTree<T>::Inter_print()
{
    if (mRoot != NULL)
        Inter_print(mRoot, mRoot->key, 0);
}

#endif


