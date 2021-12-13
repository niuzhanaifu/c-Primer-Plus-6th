#include"Queue.h"
#include<iostream>
#include<time.h>
using namespace std;
const int min_per_hr = 60;
int max_queue=10;//���е���󳤶�
double hour=100;//ģ�����е�Сʱ��
double cycle;
int per_hour;//ƽ��ÿСʱ����Ŀ�������
bool newcustomer(double x);
int main()
{
	//std::srand(time(NULL));
	int p[20] = { 0 };//�ٶ�ģ��20�Σ�
	/*cout << "��������е���󳤶ȣ�";
	cin >> max_queue;
	Queue Q(max_queue);
	cout << "������ģ�����е�Сʱ����";
	cin >> hour;
	cycle = hour*min_per_hr;//�ܹ����еķ�����
	cout << "������ƽ��ÿСʱ����Ŀ���������";
	cin >> per_hour;*/
	Queue Q(max_queue);
	cycle = hour*min_per_hr;//ѭ�����ܷ�����
	int wait_time=0;//��������һ���˵õ�����ĵȺ�ʱ��,��ʼ��Ϊ0
	int server=0;//�ܹ��õ������������
	int reject=0;//���ܾ��Ŷӵ�����
	int customers=0;//�Ŷӵ�������
	int sum_line = 0;//ÿ�����Ŷӵ�������֮��
	int line_wait = 0;//ÿ���˵ĵȴ�ʱ���ܺ�
	Item temp;
	per_hour = 100;//�ٶ�ÿСʱ����Ŀͻ���Ϊ100
	double per_min;//ÿ�����ٷ��ӵ���һ������
	double average_wait_time;
	for (int j = 0; j < 20; j++)//�ⶨ����ģ��20�Σ���ÿ����������һ�������ģ��20���൱��1��
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
	
	//����Ϊ�����ӡ�������������Ϣ
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