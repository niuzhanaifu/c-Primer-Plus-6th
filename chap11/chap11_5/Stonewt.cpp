#include<iostream>
#include"stonewt.h"
Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}
Stonewt::Stonewt(int stn = 0, double lbs = 0.0) :stone(stn), pds_left(lbs)
{
	pounds = stn*Lbs_per_stn + lbs;
}
Stonewt::Stonewt()
{
	stone=pounds=pds_left=0;
}
Stonewt::~Stonewt()
{
}
ostream & operator<< (ostream & output, const Stonewt& x)
{
	output <<"stone:"<< x.stone<<endl;
	output << "pounds:" << x.pounds<<endl;
	return output;
}
istream & operator>> (istream & input, Stonewt& x)
{
	cout << "请输入stone(整形):";
	input >> x.stone;
	cout << endl;
	cout << "请输入pounds:";
	input >> x.pounds;
	return input;
}
bool operator<(const Stonewt& x, const Stonewt& y)
{
	if (x.get_pounds() <= y.get_pounds())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator>(const Stonewt& x, const Stonewt& y)
{
	return (x.get_pounds() > y.get_pounds()) ? true : false;
}