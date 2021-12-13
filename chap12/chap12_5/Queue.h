#include<string>
using namespace std;
class customer
{
private:
	string name;
	int arrive;//到达时间
	int processtime;//等待时间
public:
	void set(int time, string s);//设置到达时间和等待时间以及名字
	customer();//构造函数
	int when() const;//获取到达时间
	int ptime() const;//获取等待时间
	string who() const;//获取名字
};
typedef customer Item;
typedef struct list
{
	Item item;
	list *next;
	list *previous;
}*node;
class Queue
{
	enum {Q_size=10};
private:
	node head;
	node rare;
	int size;
	int qsize;
public:
	Queue(int qs = Q_size);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item & item);
	bool dequeue(Item & item);//出列，从头部出列
	void print();//打印队列
};