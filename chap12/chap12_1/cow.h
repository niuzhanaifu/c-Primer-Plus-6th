class cow
{
private:
	char name[20];
	char *hobby;
	double weight;
public:
	cow();
	cow(const char *nm, const char *ho, double wt);
	cow(const cow& c);//���ݵ��ǳ����ã���Сϵͳ��֧�Ұ�ȫ��֤�����޸�
	~cow(){ delete[]hobby; }
	cow & operator=(const cow & c);
	void showcow() const;
};