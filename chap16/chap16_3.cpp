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
		cout << "��������Ĳ²��ַ�:" << endl;
		cin >> guess;
		position = target.find(guess);
		if (position == string::npos)
		{
			cout << "�´���" << endl;
			--length;
		}
		else
		{
			learn[position] = guess;
			while ((position=target.find(guess, ++position)) != string::npos)
			{
				learn[position] = guess;
			}
			cout << "�¶���:" << endl;
		}
		cout << "��²����:" << learn << endl;
		cout << "�㻹��" << length << "�λ���" << endl;
	}
	if (learn == target)
	{
		cout << "��ϲ�㣬��ȫ�¶���"<<endl;
		cout << "���ǣ�" << target;
	}
	else
	{
		cout << "���ź����������꣬��´���:";
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