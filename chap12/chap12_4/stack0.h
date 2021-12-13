typedef unsigned long Item;
class Stack
{
private:
	const static int MAX = 10;
	Item * pitems;
	int size;//�������
	int top;//ͷ��λ��
public:
	Stack(int n = MAX);
	Stack(const Stack & st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	void push(const Item & item);
	Item pop();//����ջ����Ϣ
	Stack & operator=(const Stack & st);
};