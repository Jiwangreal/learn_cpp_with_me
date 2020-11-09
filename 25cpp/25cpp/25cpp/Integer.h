#ifndef _INTEGER_H_
#define _INTEGER_H_

class Integer
{
public:
	Integer(int n);
	~Integer();

	Integer& operator++();
	//friend Integer& operator++(Integer& i);

	Integer operator++(int n);
	//friend Integer operator++(Integer& i, int n);

	operator int();//没有参数，就是将自身转换为int型

	void Display() const;
private:
	int n_;
};

#endif // _INTEGER_H_