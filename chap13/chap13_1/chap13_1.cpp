#include"classic.h"
#include<iostream>
using namespace std;
void Bravo(const cd & disk);
int main()
{
	cd c1("Beatles", "Capitol", 14, 35.5);
	classic c2 = classic("Piano Sonata in B flat,Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	cd *pcd = &c1;
	cout << "using object directly:\n";
	c1.Report();
	c2.Report();
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();
	cout << "Calling a function with a cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << "Testing assignment:";
	classic copy;
	copy = c2;
	copy.Report();
	system("pause");
	return 0;
}
void Bravo(const cd & disk)
{
	disk.Report();
}