using namespace std;
class Stonewt
{
private:
	const static int Lbs_per_stn = 14;
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	double get_pounds()const{ return pounds; }
	friend ostream & operator<< (ostream & output, const Stonewt& x);//常引用，保证不出错，不修改
	friend istream & operator>> (istream & input, Stonewt& x);//友元函数，也可以用非友元函数实现
};
bool operator<(const Stonewt& x, const Stonewt& y);
bool operator>(const Stonewt& x, const Stonewt& y);

