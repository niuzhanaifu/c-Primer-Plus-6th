#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include <cstdlib> 
#include <ctime>
const int number=100000;
using namespace std;
int main()
{
	vector<int> vi0(number);
	vector<int> vi(number);
	list<int> li;
	for (int i = 0; i < number; i++)
	{
		vi0[i] = rand();
		li.push_back(vi0[i]);
		vi[i] = vi0[i];
	}
	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	cout <<"������������ʱ:"<< (double)(end - start) / CLOCKS_PER_SEC << endl;
	clock_t start1 = clock();
	li.sort();
	clock_t end1 = clock();
	cout << "list�б��Ŷ�ʱ��:"<<(double)(end1 - start1) / CLOCKS_PER_SEC << endl;
	li.clear();
	for (int i = 0; i < number; i++)
	{
		li.push_back(vi0[i]);
	}
	clock_t start2 = clock();
	list<int>::iterator p = li.begin();
	for (int i = 0; i < number; i++)
	{
		vi[i] = *(p++);
	}
	sort(vi.begin(), vi.end());
	p = li.begin();
	for (int i = 0; i < number; i++)
	{
		*p = vi[i];
		p++;
	}
	clock_t end2 = clock();
	cout << "��list���Ƶ�vector�����ٸ��ƻ�list��ʱ��:"<<(double)(end2 - start2) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}