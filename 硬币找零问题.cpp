#include<iostream>
using namespace std;
//money��Ҫ�����Ǯ
//coin���õ�Ӳ��
//Ӳ������
void FindMin(int money,int *coin, int n)
{
	int *coinNum=new int[money+1]();//�洢1...money����������Ҫ��Ӳ�ҵĸ���
	int *coinValue=new int[money+1]();//�������Ӳ�ң��������������ļ���Ӳ��
	coinNum[0]=0;

	for(int i=1;i<=money;i++)
	{
		int minNum=i;//i��ֵǮ����Ҫ����Ӳ�Ҹ���
		int usedMoney=0;//������㣬��ԭ���Ļ�������Ҫ��Ӳ��
		for(int j=0;j<n;j++)
		{
			if(i>=coin[j])//�����Ǯ�������Ӳ�ҵ���ֵ
			{
				if(coinNum[i-coin[j]]+1<=minNum&&(i==coin[j]||coinValue[i-coin[j]]!=0))//����Ӳ�Ҹ���������
				{
					minNum=coinNum[i-coin[j]]+1;//����
					usedMoney=coin[j];//����
				}
			}
		}
		coinNum[i]=minNum;
		coinValue[i]=usedMoney;
	}

	//������
	if(coinValue[money]==0)
		cout<<"�Ҳ�����Ǯ"<<endl;
	else
	{
		cout<<"��Ҫ����Ӳ�Ҹ���Ϊ��"<<coinNum[money]<<endl;
		cout<<"Ӳ�ҷֱ�Ϊ:";
		while(money>0)
		{
			cout<<coinValue[money]<<",";
			money-=coinValue[money];
		}
	}
	delete []coinNum;
	delete []coinValue;
}
int main()
{
	int Money=18;
	int coin[]={1,2,5,9,10};
	FindMin(Money,coin,5);
	return 0;
}
