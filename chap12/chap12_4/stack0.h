typedef unsigned long Item;
class Stack
{
private:
	const static int MAX = 10;
	Item * pitems;
	int size;//最大容量
	int top;//头部位置
public:
	Stack(int n = MAX);
	Stack(const Stack & st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	void push(const Item & item);
	Item pop();//弹出栈顶信息
	Stack & operator=(const Stack & st);
};