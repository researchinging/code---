using namespace std;
template <class T>
class M_Queue
{
private:
    int length;
    int head;
    int tail;
    T   *Q;
public:
    M_Queue(int Q_length);
    bool Enqueue(T x);
    T* Dequeue();
    bool Isempty();
    bool Isfull();
};

template <class T>
M_Queue<T>::M_Queue(int Q_length)
{
    length=Q_length;
    Q=new T[length];
    head=tail=0;
}
template <class T>
bool M_Queue<T>::Isempty()
{
    return (head==tail);
}
template <class T>
bool M_Queue<T>::Isfull()
{
    return (head==(tail+1));
}
template <class T>
bool M_Queue<T>::Enqueue(T x)
{
    if(Isfull()) return 0;
    else{
        Q[tail]=x;
        if(tail==(length-1))    tail=0;
        else    tail=tail+1;
        return 1;
    }
}

template <class T>
T* M_Queue<T>::Dequeue()
{
    if(Isempty())   return NULL;
    else{
        T* x=&Q[head];
        if(head==(length-1))    head=0;
        else    head=head+1;
        return x;
    }
}
