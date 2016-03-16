#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>


/**********************************************
ȫ���ϣ ��ϣ�����������
����m  ��������k

˼·:��kת����m������,����������

1.k = <k0, k1, k2,...kr>      0<r<=m-1  ����:k���ϳ���m,ȡ���ٳ�(����ת����)

2.����һ������a = <a0, a1, a2,...ar>   ����Ĵ�(0,1,2,...m-1)��ѡȡԪ�ط��䵽a�����и�Ԫ��

3.a�������k���������result mod m��Ϊ����Ĳ���

**********************************************/
int* transform(int num, int length);    //��������ؼ���num��ת��Ϊlength������
int* hash_fuction(int length);          //����һ��m���������
int  hash_full(int *num, int* vector, int length);  //�ɹ�ϣȫ��õ���Ӧ�Ĳ�

int main(int argc, char *argv[])
{
	int a[10] = {12,22,35,47,59,69,76,85,90,10};
	int hash[17] = {0};
	int i, m;

	int* num_vector;
	int* vector;

	/*������ϣ*/
	vector = hash_fuction(17);
	for ( i = 0; i < 10; i++)
	{
		num_vector = transform(a[i], 17);
		m = hash_full(num_vector, vector, 17);
		while (hash[m])
		      m =(m+1)%17;
		hash[m] = a[i];
		free(num_vector);
	}

	/*��ϣ����*/
	for ( i = 0; i < 10; i++)
	{
		num_vector = transform(a[i], 17);
		m = hash_full(num_vector, vector, 17);
		while (hash[m] != a[i])
		{
			printf("collision��\n");
			m = (m+1)%17;
		}
		printf("%d is in hash[%d]\n", a[i], m);
	}
	free(vector);

	return 0;
}

int* transform(int num, int length)
{
	int* num_vector;
	int  i;
	num_vector = (int*)malloc(sizeof(int)*length);
	memset(num_vector, 0, sizeof(int)*length);

	for ( i = 0; i < length && num; i++)
	{
		num_vector[i] = num%length;
		num = num/length;
	}

	return num_vector;
}

int* hash_fuction(int length)
{
	struct timeval t;
	int* vector;
	int i;

	gettimeofday(&t, NULL);
	srand(t.tv_usec);

	vector = (int*)malloc(sizeof(int)*length);
	for ( i = 0; i < length; i++)
		vector[i] = rand()%length;

	return vector;
}

int hash_full(int* num, int* vector, int length)
{
	int i;
	int slot = 0;

	for ( i = 0; i < length; i++)
	{
		slot += num[i] + vector[i];
	}

	return slot%length;
}
