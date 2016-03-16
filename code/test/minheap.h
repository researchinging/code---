using namespace std;
#define Parent(i) (i/2)
#define Left(i) (2*i)
#define Right(i) (2*i+1)
#define n_Left(i) (2*i+1)
#define n_Right(i) (2*i+2)
template <class T>
class Minheap
{
private:


    void Min_heapify(int i);
    int Find_key(int i,int key);

public:
    T *heap;
    int heaplen;
    //����һ����С��
    Minheap(T *sample,int start,int length);

    //�ҵ���С�ڵ㣬��ɾ��
    T* Extract_Min();

    //������С��
    void Bulid_min_heap();

    //���ҹؼ�ֵΪkey�Ľڵ�
    T* Find_key(int key);

    T* Find_id(char id);

    //�Զѽ������򣬰��ؼ��ֵݼ�˳��
    void HeapSort();

    //��С�ڵ�x�Ĺؼ��֣���������С��
    void Decrease(T *x,int new_key);

    //��ӡ��С��
    void print();
};

//�����Ǵ�0~n���ƣ�Ҫ�ر�ע���봫�ݽ�����ָ�������ʵ���ϲ�������1-n
template <class T>
Minheap<T>::Minheap(T *sample,int start,int length)
{
    int i;
    heaplen=length;
    heap=new T[heaplen];
    for(i=0;i<heaplen;i++)
    {
        heap[i]=sample[start+i];
    }
}
template <class T>
T* Minheap<T>::Extract_Min()
{
    T temp;
    temp=heap[0];
    heap[0]=heap[heaplen-1];
    heap[heaplen-1]=temp;
    heaplen--;
    return &heap[heaplen];
}

template <class T>
void Minheap<T>::HeapSort()
{
    T temp;
    int i;
    int arraylen=heaplen;
    Bulid_min_heap();

    for(i=arraylen-1;i>=1;i--)
    {
        temp=heap[0];
        heap[0]=heap[i];
        heap[i]=temp;
        heaplen--;
        Min_heapify(0);
    }
    heaplen=arraylen;
}
//��������ٶ�left(i) right(i)������ѵ�����
template <class T>
void Minheap<T>::Min_heapify(int i)
{
    int l,r,min;
    T temp;
    l=Left(i);
    r=Right(i);
    if(l<heaplen&&heap[l]<heap[i])
        min=l;
    else min=i;
    if(r<heaplen&&heap[r]<heap[min])
        min=r;
    if(min!=i)
    {
        temp=heap[i];
        heap[i]=heap[min];
        heap[min]=temp;
        Min_heapify(min);
    }
}

template <class T>
void Minheap<T>::Bulid_min_heap()
{
    int i;
    for(i=heaplen/2;i>=0;i--)
        Min_heapify(i);
}

template <class T>
T* Minheap<T>::Find_key(int key)
{
    int i=Find_key(0,key);
    if(i<0) return NULL;
    else return &heap[i];
}

template <class T>
int Minheap<T>::Find_key(int i,int key)
{
    int m=-1;
    cout<<"i="<<i<<endl;
    if(i>=heaplen||heap[i].key>key) return -1;
    else if(heap[i].key==key) return i;
    else if(m=Find_key(n_Left(i),key)>0) return m;
    else return Find_key(n_Right(i),key);

}
template <class T>
T* Minheap<T>::Find_id(char id)
{
    int i;
    for(i=0;i<heaplen;i++)
        if(heap[i].id==id) return &heap[i];
    if(i==heaplen) return NULL;
}
template <class T>
void Minheap<T>::Decrease(T *x,int new_key)
{

}
template <class T>
void Minheap<T>::print()
{
    int i=1,j,next_row;
    cout<<heap[0].key<<endl;
    while(i<heaplen/2+1)
    {
        next_row=Right(i);
        for(j=i;j<next_row;j++)
        cout<<heap[j].key<<"  ";
        cout<<endl;
        i=next_row;
    }
}
