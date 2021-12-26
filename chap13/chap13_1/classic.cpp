#include"classic.h"
#include<iostream>
using namespace std;
classic::classic()
{
	cd();
	name[0] = '\0';
}
classic::classic(char *s1, char *s2, char *s3, int x, double y) :cd(s2, s3, x, y)
{
	strcpy(name, s1);
}
void classic::Report() const
{
	cout << "name:"<< name<<endl;
	cd::Report();
}