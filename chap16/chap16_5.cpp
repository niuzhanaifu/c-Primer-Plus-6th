#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
template<typename T>
int reduce(T arr[], int n);
template<typename T>
void show(T arr[], int n);
int main()
{
	long a[10] = { 12, 12, 4, 5, 87, 87, 6, 25, 4, 6 };
	string s[5] = { "hello", "boys", "hello", "girls", "and" };
	int n;
	n = reduce(a, 10);
	show(a, n);
	n = reduce(s, 5);
	show(s, n);
	system("pause");
	return 0;
}
template<typename T>
int reduce(T arr[], int n)
{
	sort(arr, arr + n);
	auto p = unique(arr, arr + n);
	return p - arr;
}
template<typename T>
void show(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << *(arr + i) << endl;
	}
}