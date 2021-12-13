#include<iostream>
#include"stack0.h"
using namespace std;
int main()
{
	Stack a(6);//构造最大容量是6的stack类
	//判断是否为空并输出结果
	cout<<a.isempty()<<endl;
	//向其中压入全部数据
	for (int i = 0; i < 6; i++)
	{
		a.push(2 * i + 1);
	}
	//判断是否是满的并输出结果
	cout << a.isfull() << endl;
	//强行加入数据
	a.push(10);
	//弹出栈顶数据
	cout<<a.pop()<<endl;
	//再次判断是否是满
	cout << a.isfull()<<endl;
	//=重载
	Stack b = a;
	//弹出栈顶数据
	cout << b.pop() << endl;
	system("pause");
	return 0;
}