/*
1.虚函数表解析。含有虚函数或其父类含有虚函数的类
编译器都会为其添加一个虚函数表，vptr。
2.虚基类表解析。虚继承产生虚基类表（vbptr），虚
基类表的内容与虚函数表完全不同，
*/
/*
C++中虚函数的作用主要是为了实现多态机制。多态：是指
在继承层次中，父类的指针可以具有多种形态---当它指向某个
子类对象时，通过它能够调用到子类的函数，而非父类的函数。
*/
#include <iostream>
using namespace std;

#if 0
class Base {
public:
	virtual void print(void) {
		cout << "Base::print" << endl;
	}
};

class Drive1 : public Base {
public:
	virtual void print(void) {
		cout << "Drive1::print" << endl;
	}
};
class Drive2 : public Base {
public:
	virtual void print(void) {
		cout << "Drive2::print" << endl;
	}
};

int main()
{
	Base* ptr1 = new Base;
	Base* ptr2 = new Drive1;
	Base* ptr3 = new Drive2;

	ptr1->print();
	ptr2->print();
	ptr3->print();
	system("pause");
	return 0;
}
#endif

/*这是一种运行期多态，即父类指针唯有在程序运行时才
能知道所指的真正类型是什么*/

#if 0

//使用指针访问虚表

class Base
{
public:
	Base(int i) :
		baseI(i)
	{}

	virtual void print(void)
	{
		cout << "Base::print()" << endl;
	}

	virtual void setI()
	{
		cout << "Base::setI()" << endl;
	}

	virtual ~Base()
	{}

private:
	int baseI;
};



int main()
{
	Base b(1000);
	int * vptrAdree = (int *)(&b);
	cout << "基类的长度" << sizeof(b) << endl;
	cout << "虚函数指针的地址是：" << vptrAdree << endl;
	cout << *vptrAdree << endl;
	cout << *(vptrAdree + 1) << endl;
	system("pause");
	return 0;
}
/*
运行结果：8
和一个地址
一串数字
1000
*/
#endif

#if 0
//虚函数指针指向虚函数表，虚函数表中存储的是一
//系列虚函数的地址，虚函数地址出现的顺序与类中
//虚函数次序一致。对虚函数指针地址值，可以得到
//虚函数表的地址，也即是虚函数表第一个虚函数的
//地址

typedef void(*Fun)(void);

class Base
{
public:
	Base(int i) :
		baseI(i)
	{}

	virtual int print(void)
	{
		cout << "Base::print()" << endl;
		return 0;
	}

	virtual int setI()
	{
		cout << "Base::setI()" << endl;
		return 0;
	}

	virtual ~Base()
	{}

private:
	int baseI;
};

int main()
{
	Base b(1000);
	Fun vfunc = (Fun)*((int*)*(int*)(&b));
	cout << "第一个虚函数的地址是: " << (int*)*(int*)(&b) << endl;
	vfunc();
	cout << "第二个虚函数的地址是: " << (int*)(*(int*)(&b) + 4) << endl;
	vfunc = (Fun)*(int*)(*(int*)(&b) + 4);
	vfunc();
	system("pause");
	return 0;
}
#endif