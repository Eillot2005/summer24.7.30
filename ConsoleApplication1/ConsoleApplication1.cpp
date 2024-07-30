//欧拉筛法，素数筛
#include<iostream>
using namespace std;
int prime[50];
int main()
{
	int size = 1;
	prime[0] = 2;
	for (int i = 2; i <= 100; i++)
	{
		cout << "当前数：" << i<<endl;
		cout << "素数有：";
		for (int k = 0; k < size; k++)
		{
			cout << prime[k] << " ";
		}
		cout << endl;
		for (int j = 0; j < size; j++)
		{
			cout << prime[j] * i << " ";
			if (i % prime[j] == 0)
			{
				break;
			}
			if (j == size - 1)
			{
				prime[size++] = i;
			}
		}
		cout << endl;
	}


	cout << "素数有：" << endl;;
	cout << size << "个" << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << prime[i] << " ";
	}
}