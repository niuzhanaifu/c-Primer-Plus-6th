#include<iostream>
#include"stonewt.h"
using namespace std;
void f(int *p);
int main()
{
	/*Stonewt a(1,5.2),c(2,3.1);
	cout << (a < c);
	cout << (a > c);*/
	int p[4] = { 0, 1, 2, 3 };
	f(p);
	cin.get();
	cin.get();
	return 0;
}
void f(int *p)
{
	for (int i = 0; i < 4; i++)
	{
		cout << *(p + i) << " " << *p + i << " " << *p + 2 * i << endl;
	}
}