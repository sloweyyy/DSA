#include<iostream>
using namespace std;
int TongSoChan(int);
int main()
{
	int k;
	cout << "nhap so k:";
	cin >> k;
	int kq = TongSoChan(k);
	cout << "Ket qua la:" << kq;
	return 1;
}
int TongSoChan(int n)
{
	n = abs(n);
	if (n <= 9)
		return 0;
	{
		if (n % 2 != 0)
			return 0;
		return n;
	}
	int s = TongSoChan(n / 10);
	int dv = n % 10;
	if (dv % 2 == 0)
		return s + dv;
	return s;
}
