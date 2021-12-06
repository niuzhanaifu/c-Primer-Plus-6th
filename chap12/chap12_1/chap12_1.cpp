#include<iostream>
#include<string>
#include"cow.h"
using namespace std;
int main()
{
	cow c1;
	cow c2("xiaoming", "play basketball", 60);
	cow c3("lihua", "eat meat and appples", 80);
	c2.showcow();
	c3.showcow();
	//cow c4=c3;
	c3 = c2;
	system("pause");
	return 0;
}