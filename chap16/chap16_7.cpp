#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
void show(const vector<int> &tmp);
bool judge(int s);
vector<int> Lotto(int sum, int num);
vector<int> winner;
int main()
{ 
	int m, n;
	cin >> m >> n;
	winner = Lotto(m, n);
	show(winner);
	system("pause");
	return 0;
}
vector<int> Lotto(int sum, int num)
{
	int number;
	while (num)
	{
		number = rand() % sum;
		if (judge(number))
		{
			winner.push_back(number);
			--num;
		}
	}
	return winner;
}
void show(const vector<int> &tmp)
{
	cout << "选中的号码是:";
	for (int i = 0; i < tmp.size(); i++)
		cout << tmp[i] << " ";
}
bool judge(int s)
{
	for (int i = 0; i < winner.size(); i++)
	{
		if (s == winner[i])
			return false;
	}
	return true;
}