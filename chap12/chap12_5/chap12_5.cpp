#include"Queue.h"
#include<iostream>
#include<time.h>
using namespace std;
const int min_per_hr = 60;
int max_queue=10;//队列的最大长度
double hour=100;//模拟运行的小时数
double cycle;
int per_hour;//平均每小时到达的客人数量
bool newcustomer(double x);
int main()
{
	//std::srand(time(NULL));
	int p[20] = { 0 };//假定模拟20次，
	/*cout << "请输入队列的最大长度：";
	cin >> max_queue;
	Queue Q(max_queue);
	cout << "请输入模拟运行的小时数：";
	cin >> hour;
	cycle = hour*min_per_hr;//总共运行的分钟数
	cout << "请输入平均每小时到达的客人数量：";
	cin >> per_hour;*/
	Queue Q(max_queue);
	cycle = hour*min_per_hr;//循环的总分钟数
	int wait_time=0;//队伍中下一个人得到服务的等候时间,初始化为0
	int server=0;//总共得到服务的总人数
	int reject=0;//被拒绝排队的人数
	int customers=0;//排队的总人数
	int sum_line = 0;//每分钟排队的总人数之和
	int line_wait = 0;//每个人的等待时间总和
	Item temp;
	per_hour = 100;//假定每小时到达的客户数为100
	double per_min;//每隔多少分钟到达一个客人
	double average_wait_time;
	for (int j = 0; j < 20; j++)//拟定反复模拟20次，但每次由于种子一样，因此模拟20次相当于1次
	{
		while (1)
		{
			per_min = min_per_hr / per_hour;
			for (int i = 0; i < cycle; i++)
			{
				if (newcustomer(per_min))
				{
					if (Q.isfull())
					{
						reject++;
					}
					else
					{
						temp.set(i, "people");
						Q.enqueue(temp);
						customers++;
					}
				}
				if (wait_time <= 0 && !Q.isempty())
				{
					Q.dequeue(temp);
					wait_time = temp.ptime();
					line_wait = line_wait + (i - temp.when());
					++server;
				}
				if (wait_time > 0)
				{
					--wait_time;
					sum_line = sum_line + Q.queuecount();
				}
			}
			average_wait_time = (double)line_wait / server;
			if (average_wait_time > 1)
			{
				per_hour--;
			}
			else
			{
				p[j] = per_hour;
				break;
			}
		}
	}
	for (int j = 0; j < 20; j++)
	{
		cout << p[j] << endl;
	}
	
	//以下为程序打印结果，输出相关信息
	/*if (customers > 0)
	{
		cout << "customers acceped:" << customers << endl;
		cout << "customers served:" << server<<endl;
		cout << "rejected:" << reject << endl;
		cout << "average queue size:";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cycle << endl;
		cout << "average wait time:"
			<< (double)line_wait / server << "minutes\n";
	}
	else
	{
		cout << "No customers"<<endl;
	}
	cout << "Done!";*/
	cin.get();
	cin.get();
	return 0;
}
bool newcustomer(double x)
{
	return (rand()*x / RAND_MAX < 1);
}