#include"port.h"
using namespace std;
int main()
{
	port p1;
	port p2("Tsingtao", "Beer", 30);
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	port p3 = p2;
	p3.show();
	p3 += 3;
	p3.show();

	vintageport vp1("Harbin", 50, "hb", 1992);
	vp1.show();
	vintageport vp2;
	vp2.show();
	vp1 -= 3;
	vp2 = vp1;
	vp2.show();
	system("pause");
	return 0;
}