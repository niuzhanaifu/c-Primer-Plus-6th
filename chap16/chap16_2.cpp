#include<iostream>
#include<string>
using namespace std;
bool judge(const string & s1);
int main()
{
	string s1;
	getline(cin, s1);
	if (judge(s1))
	{
		cout << "是一个回文";
	}
	else
	{
		cout << "不是一个回文";
	}
	cout << endl;
	system("pause");
	return 0;
}
bool judge(const string & s1)
{
	int i = s1.length()-1,j=0;
	while (j < i)
	{
		if (s1[j] != s1[i])
		{
			return false;
		}
		++j; --i;
	}
	return true;
}