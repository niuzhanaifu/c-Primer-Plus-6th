#include"cow.h"
#include<cstring>
#include<iostream>
using namespace std;
cow::cow()
{
	weight = 0.2;
	name[0] = '\n';
	hobby = new char[1];
	hobby[0] = '\n';
}
cow::cow(const char *nm, const char *ho, double wt)
{
	weight = wt;
	hobby = new char[strlen(ho)];
	for (int i = 0; i < strlen(ho); i++)
	{
		hobby[i] = ho[i];
	}
	for (int i = 0; (i < strlen(nm))&&(i<20); i++)
	{
		name[i] = nm[i];
	}
}
/*cow::~cow()
{
	delete[]hobby;
}*/
void cow::showcow()const
{
	std::cout << "name is:" << name<<endl;
	cout << "hobby is:" << hobby << endl;
	cout << "weight is:" << weight<<endl;
}
cow & cow::operator=(const cow & c)
{
	memset(name, '\0', sizeof(name));
	for (int i = 0; (i < strlen(c.name)) && (i<20); i++)
	{
	name[i] = c.name[i];
	}
	delete[]hobby;
	hobby = new char[strlen(c.hobby)];
	for (int i = 0; i < strlen(c.hobby); i++)
	{
		hobby[i] = c.hobby[i];
	}
	weight = c.weight;
	return *this;
}
cow::cow(const cow& c)
{
	weight = c.weight;
	for (int i = 0; (i < strlen(c.name)) && (i<20); i++)
	{
		name[i] = c.name[i];
	}
	hobby = new char[strlen(c.hobby)];
	std::strcpy(hobby, c.hobby);
}