#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string temps;
void assert(vector<string> & s);
void show(const vector<string> & s);
int main()
{
	vector<string> s1, s2, s3;
	cout << "������Mat����������������exit�������룺" << endl;
	assert(s1);
	cout << "������Pat����������������exit�������룺"<<endl;
	assert(s2);
	s3.insert(s3.end(), s1.begin(), s1.end());//�ϲ�s1
	s3.insert(s3.end(), s2.begin(), s2.end());//�ϲ�s1,s2
	sort(s3.begin(), s3.end());
	vector<string>::iterator tmp;
	tmp = unique(s3.begin(), s3.end());//ȥ���ظ���,����ֵ���ظ�����׵�ַ
	s3.erase(tmp, s3.end());//����ɾ���ظ���
	cout << "��ȥ���ظ��������к��������ӡ��" << endl;
	show(s3);
	system("pause");
	return 0;
}
void assert(vector<string> & s)
{
	cin >> temps;
	while (temps != "exit")
	{
		s.push_back(temps);
		cin >> temps;
	}
	sort(s.begin(), s.end());
}
void show(const vector<string> & s)
{
	vector<string>::const_iterator p;
	for (p = s.begin(); p != s.end(); p++)
	{
		cout << *p << endl;
	}
}