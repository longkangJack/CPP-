#include<iostream>

using namespace std;

int main()
{
	//首先创建四个变量将这几个数表示出来
	int A = 0, B = 0, B1 = 0, B2 = 0, C = 0, a, b, c, d;
	a = A - B;
	b = B - C;
	c = A + B;
	d = B + C;
	//给这四个变量进行输值；
	cin >> a >> b >> c >> d;
	if (-30 <= a <= 30 && -30 <= b <= 30 && -30 <= c <= 30 && -30 <= d <= 30)
	{
		//这里有个细节，就是B1，B2，因为A，C算出来就算有一个解，但是B不止一个，所以判断一下，B才能正确
		A = (a + c) / 2;
		C = (d - b) / 2;
		B1 = (c - a) / 2;
		B2 = (b + d) / 2;
		if (B1 != B2)
		{
			cout << "No" << endl;
		}
		cout << A << " " << B1 << " " << C;
	}
	return 0;
}
