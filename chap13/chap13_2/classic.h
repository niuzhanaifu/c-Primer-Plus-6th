#include"cd.h"
class classic:public cd
{
private:
	char *name;
public:
	classic();
	classic(char *s1, char *s2, char *s3, int x, double y);
	void Report() const;
	classic & operator=(const classic & c);
	~classic();
};