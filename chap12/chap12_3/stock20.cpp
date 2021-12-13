#include"stock20.h"
#include<iomanip>
#include<string>
Stock::Stock()
{
	shares = 0;
	share_val = 0.0;
	company = new char[1];
	company[0] = '\n';
	set_tot();
}
Stock::Stock(const char *s, int n , double pr )
{
	shares = n;
	share_val = pr;
	company = new char[strlen(s)+1];
	strcpy(company,s);
	set_tot();
}
Stock::~Stock(){ delete[]company; }
void Stock::buy(int num, double pr)
{
	shares += num;
	update(pr);
}
void Stock::sell(int num, double pr)
{
	shares -= num;
	update(pr);
}
void Stock::update(double pr)
{
	share_val = pr;
	set_tot();
}
const Stock & Stock::topval(const Stock & s) const
{
	if (total_val > s.total_val)
	{
		return *this;
	}
	else
	{
		return s;
	}
}
ostream & operator<<(ostream & output, const Stock & x)//使用引用，避免复制和内存泄露
{
	output <<fixed<< setprecision(3);
	output << "Company: " << x.company;
	output << " Shares: " << x.shares<< endl;
	output << " Share Price: $" << x.share_val;
	output << " Total worth: $" << x.total_val << endl;
	return output;
}