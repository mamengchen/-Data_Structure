#include <iostream>
#include <string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name: " << _name << endl;
//		cout << "age: " << _age << endl;
//	}
//private:
//	int a = 10;
//protected:
//	string _name = "peter";
//	int _age = 10;
//};
//
//class student : public Person
//{
//public:
//	void name()
//	{
//		string s = "Lihua";
//		_name.swap(s);
//	}
//protected:
//	int _stuid; //学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid;
//};
//
//int main()
//{
//	Person p;
//	student s;
//	Teacher t;
//	//cout << "student_size: " << sizeof(s) << endl;
//	//cout << "person_size: " << sizeof(p); //这两个大小证明了在基类的私有成员也会被继承，只是在派生类中不能访问
//	
//	s.name();
//	s.Print();//这个实例中我们测试了基类的protected成员可以被派生类继承
//
//	/*p.Print();
//	s.Print();
//	t.Print();*/
//	return 0;
//}

//
////Car和BMW Car和Benz构成is-a的关系
//class Car
//{
//protected:
//	string _colour = "白色";
//	string _num = "陕ABIT00";
//};
//
//class BMW : public Car
//{
//public:
//	void Drive()
//	{
//		cout << "开车-操作-左转-右转" << endl;
//	}
//};
//
//class Benz : public Car
//{
//public:
//	void Drive()
//	{
//		cout << "好坐-舒服-开心-安逸" << endl;
//	}
//};
//
////Tire 和 Car1构成has-a的关系
//class Tire
//{
//protected:
//	string _brand = "LaBoom";
//	size_t _size = 18;
//};
//
//class Car1
//{
//protected:
//	string _colour = "白色";
//	string _num = "123456789";
//	Tire _t; //has-a就是在类中实例化另一个类
//};

/*
class Person
{
protected:
	string _name; //姓名
	string _sex; //性别
	int _age;    //年龄
};

class Student : public Person
{
public:
	int _No; //学号
};

void Test()
{
	Student sc;
	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pc = sc;
	Person* pp = &sc;
	Person& rp = sc;

	//2.基类对象不能赋值给派生类对象
	sc = pc;

	//3.基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sc;
	Student* ps = (Student*)pp;
	ps->_No = 10;
	cout << "Student::_No: "<<ps->_No << endl;

	pp = &pc;
	Student* ps1 = (Student*)pp;//这种情况转换时虽然可以，但是会存在越界访问的问题
	//ps1->_No = 20;//触发异常
	cout << "Person::_No: " << ps1->_No << endl;
}

*/

//这里就是_num构成了隐藏关系
/*
class Person
{
protected:
	string _name = "小李子";
	int _num = 123;
};

class Student : public Person
{
public:
	void Print()
	{
		cout << "student::_name>> " << _name << endl;
		cout << "student::身份证>> " << Person::_num << endl;
		cout << "student::学号>> " << _num << endl;
 	}
protected:
	int _num = 999;
};

int main()
{
	//Test();
	Student sc;
	sc.Print();
	return 0;
}
*/


/*
//因为作用域的不同所以他们不是函数重载，
//但是他们同名，同返回值，所以它们是隐藏
class A
{
public:
	void fun()
	{
		cout << "A::func()" << endl;
	}
};

class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "fun(int i)->" << i << endl;
	}
};

void Test()
{
	B b;
	b.fun();
}

int main()
{
	Test();
	return 0;
}
*/


/*
class Person
{
public:
	Person( const char* c = "mmc", int y = 20, int n = 123)
		:_name(c),_year(y),_num(n)
	{
		cout << "Person::Person" << endl;
	}

	Person(const Person& p)
		:_name(p._name)
		,_year(p._year)
		,_num(p._num)
	{
		cout << "Person::(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << _name << endl;
	}
public:
	string _name;
	int _year;
	int _num;
};

class Student : public Person
{
public:
	Student(const char* s = "zhangsan", int _year = 20, int _num = 123, int snow = 10000)
		:_snow(snow),
		Person(s, _year, _num)
	{
		cout << "Student::Student" << endl;
	}

	Student(const Student& s)
		:Person(s)
		,_snow(s._snow)
	{
		cout << "student::(拷贝构造函数)" << endl;
	}

	Student& operator=(const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator=(s);
			_snow = s._snow;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()"  << _snow << endl;
	}
protected:
	int _snow;
};

int main()
{
	Student sc("lisi", 12, 1, 1);
	Student sc1(sc);
	Student sc2("wawu", 21, 2, 12);
	//为什么释放的时候先释放sc2，是因为局部变量按照栈存放
	system("pause");
	return 0;
}
*/

//继承与友元，友元关系不能继承，

//菱形继承
//class Person
//{
//public:
//	string _name;
//};
//
//class Student : public Person
//{
//protected:
//	int _num;
//};
//
//class Teacher : public Person
//{
//protected:
//	int _id;
//};
//
//class As : public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};
//
//void Test()
//{
//	As a;
//}