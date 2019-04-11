//利用虚函数求解
class A;
A* array[2];

class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};

class B : public A {
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return array[!!n]->Sum(n - 1) + n;
	}
};

int Sum_Solution(int n)
{
	A a;
	B b;
	array[0] = &a;
	array[1] = &b;

	int value = array[1]->Sum(n);
	return value;
}

//函数指针求解

typedef unsigned  int(*fun)(unsigned int);
unsigned int Solution2_Teminator(unsigned int n)
{
	return 0;
}
unsigned int Sum_Soluntin2(unsigned int n)
{
	static fun f[2] = { Solution2_Teminator, Sum_Soluntin2 };
	return n + f[!!n](n - 1);
}