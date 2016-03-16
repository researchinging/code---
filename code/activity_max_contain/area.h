using namespace std;
class area{
public:
    float start;
    float finish;
    area *next;

    bool operator<=(const area & b)const
	{
		return finish <= b.finish;
	}
	bool operator>(const area & b)const
	{
		return finish > b.finish;
	}

};
class Activity_col{
    private:
        int length;
        area *max_contain_p;
    public:
        area *A;
        Activity_col(int length_A){length=length_A;}
        void init_col();
        void print();
        void print_max_contain();
        void Max_con();
    private:
        void recursive_activity_selector(int k,int n);

};
void Activity_col::print_max_contain()
{
    area *B;
    for(B=A->next;B!=max_contain_p;B=B->next)
        cout<<"["<<B->start<<"  "<<B->finish<<"]"<<"   ";
    cout<<"["<<B->start<<"  "<<B->finish<<"]"<<"   "<<endl;

}
void Activity_col::Max_con()
{
    max_contain_p=A;
    recursive_activity_selector(0,length);
}
void Activity_col::recursive_activity_selector(int k,int n)
{
    int m=k+1;
    while(m<=n&&(A[m].start<A[k].finish))
        m=m+1;
    if(m<=n)
    {
        max_contain_p->next=&A[m];
        max_contain_p=&A[m];
        cout<<"in recursive_activity_selector"<<"["<<A[m].start<<"  "<<A[m].finish<<"]"<<"   "<<endl;
        recursive_activity_selector(m,n);
    }
}
void Activity_col::init_col()
{
    int i;
    A=new area[length+1];
    A[0].start =0;
    A[0].finish =0;
    for(i = 1; i<=length; i++)
	{
		A[i].start = rand() % 100;
		A[i].finish = rand() % 100;
		if(A[i].start > A[i].finish)
			swap(A[i].start, A[i].finish);
	}
}
void Activity_col::print()
{
    int i;
    for(i = 1; i<=length; i++)
	{
		cout<<"["<<A[i].start<<"  "<<A[i].finish<<"]"<<"   ";
	}
	cout<<endl;
}

