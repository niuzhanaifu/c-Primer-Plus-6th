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
	friend ostream & operator<< (ostream & output, const Stonewt& x);//�����ã���֤���������޸�
	friend istream & operator>> (istream & input, Stonewt& x);//��Ԫ������Ҳ�����÷���Ԫ����ʵ��
};
bool operator<(const Stonewt& x, const Stonewt& y);
bool operator>(const Stonewt& x, const Stonewt& y);

