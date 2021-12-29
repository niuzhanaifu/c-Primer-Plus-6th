#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<memory>
using namespace std;
struct Review{
	string title;
	int rating;
	double price;
};
bool price_sort(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool price_sort_1(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool abc_sort(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool rate_sort(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool rate_sort_1(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
void ShowReview(vector<shared_ptr<Review>> &p);
void show(const shared_ptr<Review> &p);
bool FillReview(shared_ptr<Review> &p);
int main()
{
	vector<shared_ptr<Review>> books;
	shared_ptr<Review> temp;
	while (FillReview(temp))
	{
		books.push_back(temp);
	}
	if (books.size() > 0)
	{
		cout << "Thank you.You entered the following" << books.size()
			<< "ratings:\n" << "Rating\tbook\n";
	}
	ShowReview(books);
	system("pause");
	return 0;
}
bool FillReview(shared_ptr<Review> &p)
{
	cout << "Enter book title (quit to quit):" << endl;
	p =shared_ptr<Review>(new Review);//智能指针的初始化方法
	getline(cin, p->title);
	if (p->title == "quit")
	{
		return false;
	}
	cout << "Enter book rating (quit to quit):" << endl;
	cin >> p->rating;
	if (!std::cin)
		return false;
	cout << "Enter book price (quit to quit):" << endl;
	cin >> p->price;
	if (!std::cin)
		return false;
	while (cin.get() != '\n')
		continue;
	return true;
}
void ShowReview(vector<shared_ptr<Review>> &p)
{
	vector<shared_ptr<Review>> q(p);
	cout << "sort show:" << endl
		<< "按原始顺序显示(a):" << endl
		<< "字母表顺序显示(b):" << endl
		<< "评级升序显示(c):" << endl
		<< "评级降序显示(d):" << endl
		<< "价格升序显示(e):" << endl
		<< "价格降序显示(f):" << endl
		<< "退出(q)." << endl;
	char c;
	cin >> c;
	while (c != 'q')
	{
		switch (c)
		{
		case 'a':
			for (auto x : q) show(x);
			break;
		case 'b':
			sort(p.begin(), p.end(), abc_sort);
			for (auto x : p) show(x);
			break;
		case 'c':
			sort(p.begin(), p.end(), rate_sort);
			for (auto x : p) show(x);
			break;
		case 'd':
			sort(p.begin(), p.end(), rate_sort_1);
			for (auto x : p) show(x);
			break;
		case 'e':
			sort(p.begin(), p.end(), price_sort);
			for (auto x : p) show(x);
			break;
		case 'f':
			sort(p.begin(), p.end(), price_sort_1);
			for (auto x : p) show(x);
			break;
		}
		cin >> c;
	}
}
void show(const shared_ptr<Review> &p)
{
	cout << "book name:"<<p->title << endl;
	cout << "book rating:"<<p->rating << endl;
	cout << "book price:"<<p->price << endl;
}
bool price_sort(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	return r1->price < r2->price;
}
bool price_sort_1(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	return r1->price > r2->price;
}
bool abc_sort(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	return r1->title < r2->title;
}
bool rate_sort(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	return r1->rating < r2->rating;
}
bool rate_sort_1(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	return r1->rating > r2->rating;
}