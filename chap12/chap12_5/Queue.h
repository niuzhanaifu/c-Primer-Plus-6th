#include<string>
using namespace std;
class customer
{
private:
	string name;
	int arrive;//����ʱ��
	int processtime;//�ȴ�ʱ��
public:
	void set(int time, string s);//���õ���ʱ��͵ȴ�ʱ���Լ�����
	customer();//���캯��
	int when() const;//��ȡ����ʱ��
	int ptime() const;//��ȡ�ȴ�ʱ��
	string who() const;//��ȡ����
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
	bool dequeue(Item & item);//���У���ͷ������
	void print();//��ӡ����
};