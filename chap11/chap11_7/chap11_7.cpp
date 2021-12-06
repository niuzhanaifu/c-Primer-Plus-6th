#include"complex0.h"
#include<iostream>
using namespace std;
int main()
{
	Complex a(3,4),c;
	cin >> c;
	cout << "c is"<<c<<endl;
	cout << "complex conjugate is" << ~c ;
	cout << "a is " << a ;
	cout << "a+c is " << a + c ;
	cout << "a-c is " << a - c ;
	cout << "a*c is " << a*c   ;
	cout << "2*c is " << 2 * c ;
	cin.get();
	cin.get();
	return 0;
}