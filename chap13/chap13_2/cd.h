class cd
{
private:
	char *performers;
	char *label;
	int selections;//number of selections
	double playtime;//playing time in minutes
public:
	cd(char *s1, char *s2, int n, double x);
	cd(const cd & d);
	cd();
	void set_select(int x);
	void set_playtime(double x);
	void set_performers(char *s);
	void set_label(char *s);
	virtual ~cd();
	virtual void Report() const;
	int get_selectios() const;
	void show_lable()const;
	cd & operator=(const cd & d);
};