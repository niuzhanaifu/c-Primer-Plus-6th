#include<iostream>
using namespace std;
class port
{
private:
	char *brand;
	char style[20];
	int bottles;
public:
	port(const char *br = "none", const char * st = "none", int b = 0);
	port(const port &p);
	virtual ~port();
	port & operator=(const port &b);
	port & operator+=(int b);
	port & operator-=(int b);
	int bottlecount()const;
	virtual void show()const;
	friend ostream & operator<<(ostream & out, const port & b);
};
class vintageport :public port
{
private:
	char * nickname;
	int year;
public:
	vintageport();
	vintageport(const char *br, int b, const char *nm, int y);
	vintageport(const vintageport &vp);
	~vintageport();
	vintageport & operator=(const vintageport & vp);
	void show() const;
	friend ostream & operator<<(ostream & out, const vintageport & vp);
};