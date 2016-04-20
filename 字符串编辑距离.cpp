#include<string>
#include<iostream>


using namespace std;


int minValue(int a, int b, int c)
{
    int t = a <= b ? a:b;
    return t <= c ? t:c;
}

int calculateStringDistance(string strA, string strB)
{
    int lenA = (int)strA.length()+1;
    int lenB = (int)strB.length()+1;

    int **c = new int*[lenA];
    for(int i = 0; i < lenA; i++)
        c[i] = new int[lenB];

    for(int i = 0; i < lenA; i++) c[i][0] = i;
    for(int j = 0; j < lenB; j++) c[0][j] = j;
    c[0][0] = 0;
    for(int i = 1; i < lenA; i++)
    {
        for(int j = 1; j < lenB; j++)
        {
            if(strB[j-1] == strA[i-1])
                c[i][j] = c[i-1][j-1];
            else
                c[i][j] = minValue(c[i][j-1], c[i-1][j], c[i-1][j-1]) + 1;
        }
    }

    int ret =  c[lenA-1][lenB-1];

    for(int i = 0; i < lenA; i++)
        delete [] c[i];
    delete []c;

    return ret;
}

int main(){

	int res=calculateStringDistance("heool", "hool");
	cout<<res<<endl;
	return 0;
}