#include"stack0.h"
#include<iostream>
using namespace std;
Stack::Stack(int n) :top(-1), size(n)
{
	if (n <= 0)
	{
		cout << "初始化失败，n要求大于0" << endl;
		pitems = new Item[1];
		size = 0;
	}
	else if (n > MAX)
	{
		pitems = new Item[MAX];
		size = MAX;
	}
	else
	{
		pitems = new Item[n];
	}
}
Stack::Stack(const Stack & st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[st.size];
	for (int i = 0; i < size; i++)
	{
		pitems[i] = st.pitems[i];
	}
}
Stack::~Stack(){ delete[]pitems; }
bool Stack::isempty() const
{
	return (top == -1) ? true : false;
}
bool Stack::isfull() const
{
	return (top == (size-1)) ? true : false;
}
void Stack::push(const Item & item)
{
	if (isfull())
	{
		cout << "容量已满，压入失败" << endl;
	}
	else
	{
		top++;
		*(pitems + top) = item;
	}
}
Item Stack::pop()
{
		Item temp = pitems[top];
		top--;
		return temp;
}
Stack& Stack::operator=(const Stack & st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[st.size];
	for (int i = 0; i < size; i++)
	{
		pitems[i] = st.pitems[i];
	}
	return *this;
}