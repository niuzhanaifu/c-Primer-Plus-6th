#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
void read(ifstream &in, vector<string> &vec);
void playgame(const vector<string> &vec);
int number;
int main()
{
	ifstream fin;
	vector<string> vec;
	read(fin, vec);
	playgame(vec);
	system("pause");
	return 0;
}
void playgame(const vector<string> &vec)
{
	string target = vec[rand() % number];
	cout << target << endl;
	int length = target.length();
	string learn(length, '-');
	char guess;
	string badguess;
	int position;
	while ((learn != target)&&(length!=0))
	{
		cout << "请输入你的猜测字符:" << endl;
		cin >> guess;
		position = target.find(guess);
		if (position == string::npos)
		{
			cout << "猜错了" << endl;
			--length;
		}
		else
		{
			learn[position] = guess;
			while ((position=target.find(guess, ++position)) != string::npos)
			{
				learn[position] = guess;
			}
			cout << "猜对了:" << endl;
		}
		cout << "你猜测的是:" << learn << endl;
		cout << "你还有" << length << "次机会" << endl;
	}
	if (learn == target)
	{
		cout << "恭喜你，完全猜对了"<<endl;
		cout << "答案是：" << target;
	}
	else
	{
		cout << "很遗憾，次数用完，你猜错了:";
	}
	cout << endl;
}
void read(ifstream &in, vector<string> &vec)
{
	in.open("D:\\VS2013learning\\C++primer\\chap13\\words.txt");
	string s;
	while (getline(in, s))
	{
		vec.push_back(s);
		++number;
	}
	if (in.is_open())
		in.close();
}