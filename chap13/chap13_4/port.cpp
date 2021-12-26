#include"port.h"
port::port(const char *br, const char * st, int b) :bottles(b)
{
	strcpy(style, st);
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
}
port::port(const port &p)
{
	strcpy(style, p.style);
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	bottles = p.bottles;
}
port::~port(){ delete[]brand; }
port & port::operator=(const port &b)
{
	if (this == &b)
	{
		return *this;
	}
	delete[]brand;
	strcpy(style, b.style);
	brand = new char[strlen(b.brand) + 1];
	strcpy(brand, b.brand);
	bottles = b.bottles;
	return *this;
}
port & port::operator+=(int b)
{
	bottles += b;
	return *this;
}
port & port::operator-=(int b)
{
	bottles -= b;
	return *this;
}
int port::bottlecount()const
{
	return bottles;
}
void port::show()const
{
	cout << "Brand:" << brand;
	cout << endl << "Kind:" << style << endl;
	cout << "Bottles:" << bottles << endl;
}
ostream & operator<<(ostream & out, const port & b)
{
	out << b.brand << " " << b.style << " " << b.bottles;
	return out;
}
vintageport::vintageport() :port("none","none",0)
{
	nickname = new char[1];
	nickname[0] = '\0';//注意不要越界
}
vintageport::vintageport(const char *br, int b, const char *nm, int y) :port(br, "vintage", b), year(y)
{
	nickname = new char[strlen(nm) + 1];
	strcpy(nickname, nm);
}
vintageport::vintageport(const vintageport &vp) : port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}
vintageport:: ~vintageport()
{
	delete []nickname;
}
vintageport & vintageport:: operator=(const vintageport & vp)
{
	if (this == &vp)
	{
		return *this;
	}
	port::operator=(vp);
	delete[] nickname;
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
    return *this;
}
void vintageport::show() const
{
	cout << "nickname:" << nickname<<endl;
	cout << "year:" << year << endl;
	port::show();
}
ostream & operator<<(ostream & out, const vintageport & vp)
{
	out << vp.nickname << "," << vp.year << (const port &)vp;//注意写法
	return out;
}