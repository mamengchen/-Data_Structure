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
#include <string>
#include <algorithm>
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

#if 0
//对象模型概述：
/* 在C++中，有两种数据成员：静态与非静态。三种类成员函数
：静态、非静态和虚拟*/
template<typename dst_type, typename src_type>
dst_type pointer_cast(src_type src)
{
	return *static_cast<dst_type*>(static_cast<void*>(&src));
}


typedef void(*fun)(void);

class Base
{
public:
	Base(int i) : baseI(i)
	{
		cout << "Base::Base" << endl;
	}

	int getI()
	{
		cout << "Base::getI()" << endl;
		return baseI;
	}

	static void countI()
	{
		cout << "static Base::countI()" << endl;
	}

	virtual void print()
	{
		cout << "virtual Base::print()" << endl;
	}

	virtual void demo()
	{
		cout << "virtual Base::demo()" << endl;
	}

	virtual ~Base()
	{
		cout << "virtual Base::~Base()" << endl;
	}
private:
	int baseI;
	static int baseS;
};

int Base::baseS = 1200;

/* 在此模型下，nonstatic数据成员被置于每一个类对象
中，而static数据成员被置于类对象之外。static与nonstatic函数
也都放在类对象之外，而对于virtual函数，则通过虚函数表+虚指针来支持*/

void testBase(Base& p)
{
	cout << "对象的内存起始地址：" << &p << endl;
	cout << "type_info信息: " << endl;
	fun str = (fun)*((int *)*(int *)(&p));
	cout << typeid(p).name() << endl;

	//验证虚表
	cout << "虚函数表第一个函数的地址: " << ((int *)*(int *)(&p)) << endl;
	str();
	cout << "虚函数表第二个函数的地址: " << ((int *)*(int *)(&p) + 1) << endl;
	str = (fun)*((int *)*(int *)(&p) + 1);
	str();
	//当把demo注释掉是第二个虚函数表中的就是析构函数。

	//输入static函数的地址
	p.countI();
	//先调用函数以产生一个实例
	cout << "static函数countI()的地址：" << pointer_cast<void*>(&Base::countI) << endl;
	fun str1 = (fun)(pointer_cast<int*>(&Base::countI));
	str1();


	//验证非静态数据成员
	cout << " 推测nonstatic数据成员baseI的地址: " << (int *)(&p) + 1 << endl;
	cout << "根据推测出的地址，输出该地址的值: " << *((int *)(&p) + 1) << endl;
	p.getI();
	cout << "非static函数getI()的地址：" << pointer_cast<int*>(&Base::getI) << endl;
}


int main()
{
	Base b(1000);
	testBase(b);
	system("pause");
	return 0;
}

/*
1.通过(int*)(&p)取得虚函数表的地址
2.使用tpyeid().name()查看类
3.虚函数表按照先按声明顺序的放入虚表中，所以先是print函数，下来时demo()
最后是虚析构函数。
4.虚表指针的下一个位置为非静态的数据成员
5.静态成员函数不是放入到虚表中的，我们可以看见其中差值比较大*/

#endif

//继承下的C++对象模型
//单继承
class Base
{
public:
	Base(int i) : baseI(i)
	{
		cout << "Base::Base" << endl;
	}

	int getI()
	{
		cout << "Base::getI()" << endl;
		return baseI;
	}

	static void countI()
	{
		cout << "static Base::countI()" << endl;
	}

	virtual void print()
	{
		cout << "virtual Base::print()" << endl;
	}

	virtual void demo()
	{
		cout << "virtual Base::demo()" << endl;
	}

	virtual ~Base()
	{
		cout << "virtual Base::~Base()" << endl;
	}
private:
	int baseI;
	static int baseS;
};

class Derive : public Base
{
public:
	Derive(int d) : Base(1000),
		DeriveI(d)
	{
		cout << "Derive::Derived()" << endl;
	}

	virtual void print()
	{
		cout << "Derive::print()" << endl;
	}

	virtual void demo2()
	{
		cout << "Derive::demo2()" << endl;
	}

	virtual ~Derive()
	{
		cout << "Derive::~Derive()" << endl;
	}

private:
	int DeriveI;
};

int main()
{
	Derive d(1024);
	cout << sizeof(d) << endl;
	/*
	运行结果：12 << 因为实例化的对象中有个两个虚标指针vptr1，vptr2
	一个指向形成的基类表，一个指向派生类的虚表*/
	system("pause");
	return 0;
}