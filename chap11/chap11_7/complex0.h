#include<iostream>
using namespace std;
class Complex
{
private:
	double i, j;
public:
	Complex(double a = 0, double b = 0) :i(a), j(b){}
	double get_i()const { return i; }
	double get_j()const { return j; }
	void set_i(const double &a){ i = a; }
	void set_j(const double &b){ j = b; }
};
const Complex operator+(const Complex& a, const Complex& b);//返回类型为常量。
Complex operator-(const Complex& a, const Complex& b);
Complex operator*(const Complex& a, const Complex& b);
Complex operator*(const double& a, const Complex& b);
Complex operator~(const Complex& b);
ostream & operator<<(ostream &output, const Complex& x);//非友元函数的实现，借助自定义的get函数。
istream & operator>>(istream &input, Complex& x);
const Complex operator+(const Complex& a, const Complex& b)
{
	Complex result;
	result.set_i(a.get_i() + b.get_i());
	result.set_j(a.get_j() + b.get_j());
	return result;
}
Complex operator-(const Complex& a, const Complex& b)
{
	Complex result;
	result.set_i(a.get_i() - b.get_i());
	result.set_j(a.get_j() - b.get_j());
	return result;
}
Complex operator*(const Complex& a, const Complex& b)
{
	Complex result;
	result.set_i((a.get_i() * b.get_i()) - (a.get_j() * b.get_j()));
	result.set_j((a.get_i() * b.get_j())+  (a.get_j() * b.get_i()));
	return result;
}
Complex operator*(const double& a, const Complex& b)
{
	Complex result;
	result.set_i(a*b.get_i());
	result.set_j(a*b.get_j());
	return result;
}
Complex operator~(const Complex& b)
{
	Complex result;
	result.set_i(b.get_i());
	result.set_j((-1)*b.get_j());
	return result;
}
ostream & operator<<(ostream &output, const Complex& x)
{
	output << "("<<x.get_i() << "," << x.get_j() << "j" << ")"<<endl;
	return output;
}
istream & operator>>(istream &input, Complex& x)
{
	double a, b;
	cout << "real:";
	input >> a;
	cout << "imaginary:";
	input >> b;
	x.set_i(a); x.set_j(b);
	return input;
}