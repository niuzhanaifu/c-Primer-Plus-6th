#include<iostream>
#include"stack0.h"
using namespace std;
int main()
{
	Stack a(6);//�������������6��stack��
	//�ж��Ƿ�Ϊ�ղ�������
	cout<<a.isempty()<<endl;
	//������ѹ��ȫ������
	for (int i = 0; i < 6; i++)
	{
		a.push(2 * i + 1);
	}
	//�ж��Ƿ������Ĳ�������
	cout << a.isfull() << endl;
	//ǿ�м�������
	a.push(10);
	//����ջ������
	cout<<a.pop()<<endl;
	//�ٴ��ж��Ƿ�����
	cout << a.isfull()<<endl;
	//=����
	Stack b = a;
	//����ջ������
	cout << b.pop() << endl;
	system("pause");
	return 0;
}