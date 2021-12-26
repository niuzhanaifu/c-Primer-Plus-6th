#include"cd.h"
#include<iostream>
using namespace std;
cd::cd(char *s1, char *s2, int n, double x) :selections(n), playtime(x)
{
	strcpy(performers, s1);
	strcpy(label, s2);
}
cd::cd():selections(1), playtime(1)
{
	performers[0] = '\0';
	label[0] = '\0';
}
cd::cd(const cd & d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
cd & cd::operator=(const cd & d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
void cd::Report() const
{
	cout <<"performers:"<< performers << endl;
	cout <<"label:"<< label << endl;
	cout << "selections:" << selections << endl;
	cout <<"playtime:"<< playtime << endl<<endl;
}
void cd::set_select(int x){ selections=x; }
int cd::get_selectios()const{ return selections; }
void cd::set_playtime(double x){ playtime = x; }
void cd::set_label(char *s){ strcpy(label, s); }
void cd::set_performers(char *s){ strcpy(performers, s); }
void cd::show_lable()const { cout << label; }
cd::~cd(){}