#include"classic.h"
#include<iostream>
using namespace std;
classic::classic()
{
	cd();
	name = new char[1];
	name[0] = '\0';
}
classic::classic(char *s1, char *s2, char *s3, int x, double y) :cd(s2, s3, x, y)
{
	name = new char[strlen(s1) + 1];
	strcpy(name, s1);
}
void classic::Report() const
{
	cout << "name:"<< name<<endl;
	cd::Report();
}
classic & classic::operator=(const classic & c)
{
	if (this == &c)
	{
		return *this;
	}
	cd::operator=(c);
	delete[]name;
	name = new char[strlen(c.name) + 1];
	strcpy(name, c.name);
}
classic::~classic()
{
	delete[]name;
}