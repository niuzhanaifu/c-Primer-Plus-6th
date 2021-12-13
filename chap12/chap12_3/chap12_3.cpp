#include<iostream>
#include"stock20.h"
const int STKS = 4;
int main()
{
	Stock stocks[5] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boff Objects", 200, 2.0),
		Stock("Monolith Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.45)
	};
	Stock a("Boffo Objects", 12, 20);
	cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
	{
		cout<<stocks[st];
	}
	const Stock *top = stocks;
	for (st = 1; st < STKS; st++)
	{
		top = &top->topval(stocks[st]);
	}
	cout << "most valable holding::\n";
	cout << *top;
	system("pause");
	return 0;
}
