#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int reduce(long *p, int n);//接口改为，参数形参改为指针
void show(long arr[], int n);
int main()
{
	long a[10] = { 12, 12, 4, 5, 87, 87, 6, 25, 4, 6 };
	int n;
	n=reduce(a, 10);
	show(a, n);
	system("pause");
	return 0;
}
int reduce(long *p, int n)
{
	sort(p, p + n);
	auto q = unique(p, p + n);
	return q-p;
}
void show(long arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << endl;
	}
}
