#include<iostream>
using namespace std;
int extend_gcd(int a, int b, int& x, int& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int temp = extend_gcd(b, a % b, x, y);
		int t = y;
		y = x - (a / b) * y;
		x = t;
		return temp;
	}
}
int main()
{
	int a, b;
	int x, y;
	int c;
	cin >> a >> b;
	int g = extend_gcd(a, b, x, y);
	cout << "最大公约数是：" << g << endl;
	cout << "请输入c的值：";
	cin >> c;
	if (c % g == 0)
		cout << "有解";
	cout << "x:" << x << endl << "y:" << y << endl;
	x += b / g;
	y -= a / g;
	cout << "最小x正整数解(=gcd(a,b),与c无关)" << endl << "x:" << x << endl << "y:" << y << endl;
	if (c % g != 0)
		cout << "同余式无解";
	else
	{
		cout << "同余式" << endl;
		x *= c / g;
		y *= c / g;
		for (int i = 0; i < g; i++)
		{
			cout << (x + b / g * i) % b << endl << (y + b / g * i) % b;
		}
	}
}