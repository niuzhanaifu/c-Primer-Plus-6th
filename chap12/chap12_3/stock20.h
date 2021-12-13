#include<iostream>
#include<string>
using namespace std;
class Stock
{
private:
	char *company;
	int shares;
	double share_val;
	double total_val;
	void set_tot(){ total_val = shares*share_val; }
public:
	Stock();
	Stock(const char *s, int n = 0, double pr = 0.0);
	~Stock();
	void buy(int num, double pr);
	void sell(int num, double pr);
	void update(double pr);
	const Stock & topval(const Stock & s) const;
	friend ostream & operator<<(ostream & output,const Stock & x);
};
