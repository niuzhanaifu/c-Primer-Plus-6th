#include"Queue.h"
#include<cstdlib>
#include<iostream>
using namespace std;
customer::customer() :arrive(0), processtime(0){}
int customer::ptime()const{ return processtime; }
int customer::when()const{ return arrive; }
string customer::who()const{ return name; }
void customer::set(int time, string s){ arrive = time; processtime = std::rand() % 3 + 1; name=s; }
Queue::Queue(int qs){ size = 0; qsize = qs; head = NULL; }
bool Queue::isempty()const{ return (size == 0) ? true : false; }
bool Queue::isfull()const{ return (size == qsize) ? true : false; }
int Queue::queuecount()const{ return size; }
bool Queue::enqueue(const Item & item)
{
	if (isfull())
	{
		return false;
	}
	else
	{
		if (head == NULL)
		{
			head = new list;
			head->item = item;
			head->next = NULL;
			rare = head;
			++size;
		}
		else
		{
			rare->next = new list;
			rare->next->item = item;
			rare = rare->next;
			rare->next = NULL;
			++size;
		}
		return true;
	}
}
bool Queue::dequeue(Item & item)
{
	if (isempty())
	{
		return false;
	}
	else
	{
		item = head->item;
		node temp = head;
		head = head->next;
		delete temp;
		--size;
	}
}
void Queue::print()
{
	cout << "共有" << size << "个客户在队列中："<<endl;
	node temp = head;
	while (temp != NULL)
	{
		cout << "name:"<<temp->item.who()<< endl;
		cout << "arrive time:" << temp->item.when() << endl;
		cout << "process time:" << temp->item.ptime() << endl;
		temp = temp->next;
	}
}
Queue::~Queue()
{
	node temp = head;
	while (temp != NULL)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}