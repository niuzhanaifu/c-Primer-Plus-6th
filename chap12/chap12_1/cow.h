class cow
{
private:
	char name[20];
	char *hobby;
	double weight;
public:
	cow();
	cow(const char *nm, const char *ho, double wt);
	cow(const cow& c);//传递的是常引用，减小系统开支且安全保证不被修改
	~cow(){ delete[]hobby; }
	cow & operator=(const cow & c);
	void showcow() const;
};