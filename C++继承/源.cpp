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
//	int _stuid; //ѧ��
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
//	//cout << "person_size: " << sizeof(p); //��������С֤�����ڻ����˽�г�ԱҲ�ᱻ�̳У�ֻ�����������в��ܷ���
//	
//	s.name();
//	s.Print();//���ʵ�������ǲ����˻����protected��Ա���Ա�������̳�
//
//	/*p.Print();
//	s.Print();
//	t.Print();*/
//	return 0;
//}

//
////Car��BMW Car��Benz����is-a�Ĺ�ϵ
//class Car
//{
//protected:
//	string _colour = "��ɫ";
//	string _num = "��ABIT00";
//};
//
//class BMW : public Car
//{
//public:
//	void Drive()
//	{
//		cout << "����-����-��ת-��ת" << endl;
//	}
//};
//
//class Benz : public Car
//{
//public:
//	void Drive()
//	{
//		cout << "����-���-����-����" << endl;
//	}
//};
//
////Tire �� Car1����has-a�Ĺ�ϵ
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
//	string _colour = "��ɫ";
//	string _num = "123456789";
//	Tire _t; //has-a����������ʵ������һ����
//};

/*
class Person
{
protected:
	string _name; //����
	string _sex; //�Ա�
	int _age;    //����
};

class Student : public Person
{
public:
	int _No; //ѧ��
};

void Test()
{
	Student sc;
	// 1.���������Ը�ֵ���������/ָ��/����
	Person pc = sc;
	Person* pp = &sc;
	Person& rp = sc;

	//2.��������ܸ�ֵ�����������
	sc = pc;

	//3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	pp = &sc;
	Student* ps = (Student*)pp;
	ps->_No = 10;
	cout << "Student::_No: "<<ps->_No << endl;

	pp = &pc;
	Student* ps1 = (Student*)pp;//�������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
	//ps1->_No = 20;//�����쳣
	cout << "Person::_No: " << ps1->_No << endl;
}

*/

//�������_num���������ع�ϵ
/*
class Person
{
protected:
	string _name = "С����";
	int _num = 123;
};

class Student : public Person
{
public:
	void Print()
	{
		cout << "student::_name>> " << _name << endl;
		cout << "student::���֤>> " << Person::_num << endl;
		cout << "student::ѧ��>> " << _num << endl;
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
//��Ϊ������Ĳ�ͬ�������ǲ��Ǻ������أ�
//��������ͬ����ͬ����ֵ����������������
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
		cout << "student::(�������캯��)" << endl;
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
	//Ϊʲô�ͷŵ�ʱ�����ͷ�sc2������Ϊ�ֲ���������ջ���
	system("pause");
	return 0;
}
*/

//�̳�����Ԫ����Ԫ��ϵ���ܼ̳У�

//���μ̳�
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