/*
1.�麯��������������麯�����丸�ຬ���麯������
����������Ϊ�����һ���麯����vptr��
2.�������������̳в���������vbptr������
�������������麯������ȫ��ͬ��
*/
/*
C++���麯����������Ҫ��Ϊ��ʵ�ֶ�̬���ơ���̬����ָ
�ڼ̳в���У������ָ����Ծ��ж�����̬---����ָ��ĳ��
�������ʱ��ͨ�����ܹ����õ�����ĺ��������Ǹ���ĺ�����
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

/*����һ�������ڶ�̬��������ָ��Ψ���ڳ�������ʱ��
��֪����ָ������������ʲô*/

#if 0

//ʹ��ָ��������

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
	cout << "����ĳ���" << sizeof(b) << endl;
	cout << "�麯��ָ��ĵ�ַ�ǣ�" << vptrAdree << endl;
	cout << *vptrAdree << endl;
	cout << *(vptrAdree + 1) << endl;
	system("pause");
	return 0;
}
/*
���н����8
��һ����ַ
һ������
1000
*/
#endif

#if 0
//�麯��ָ��ָ���麯�����麯�����д洢����һ
//ϵ���麯���ĵ�ַ���麯����ַ���ֵ�˳��������
//�麯������һ�¡����麯��ָ���ֵַ�����Եõ�
//�麯����ĵ�ַ��Ҳ�����麯�����һ���麯����
//��ַ

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
	cout << "��һ���麯���ĵ�ַ��: " << (int*)*(int*)(&b) << endl;
	vfunc();
	cout << "�ڶ����麯���ĵ�ַ��: " << (int*)(*(int*)(&b) + 4) << endl;
	vfunc = (Fun)*(int*)(*(int*)(&b) + 4);
	vfunc();
	system("pause");
	return 0;
}
#endif

#if 0
//����ģ�͸�����
/* ��C++�У����������ݳ�Ա����̬��Ǿ�̬���������Ա����
����̬���Ǿ�̬������*/
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

/* �ڴ�ģ���£�nonstatic���ݳ�Ա������ÿһ�������
�У���static���ݳ�Ա�����������֮�⡣static��nonstatic����
Ҳ�����������֮�⣬������virtual��������ͨ���麯����+��ָ����֧��*/

void testBase(Base& p)
{
	cout << "������ڴ���ʼ��ַ��" << &p << endl;
	cout << "type_info��Ϣ: " << endl;
	fun str = (fun)*((int *)*(int *)(&p));
	cout << typeid(p).name() << endl;

	//��֤���
	cout << "�麯�����һ�������ĵ�ַ: " << ((int *)*(int *)(&p)) << endl;
	str();
	cout << "�麯����ڶ��������ĵ�ַ: " << ((int *)*(int *)(&p) + 1) << endl;
	str = (fun)*((int *)*(int *)(&p) + 1);
	str();
	//����demoע�͵��ǵڶ����麯�����еľ�������������

	//����static�����ĵ�ַ
	p.countI();
	//�ȵ��ú����Բ���һ��ʵ��
	cout << "static����countI()�ĵ�ַ��" << pointer_cast<void*>(&Base::countI) << endl;
	fun str1 = (fun)(pointer_cast<int*>(&Base::countI));
	str1();


	//��֤�Ǿ�̬���ݳ�Ա
	cout << " �Ʋ�nonstatic���ݳ�ԱbaseI�ĵ�ַ: " << (int *)(&p) + 1 << endl;
	cout << "�����Ʋ���ĵ�ַ������õ�ַ��ֵ: " << *((int *)(&p) + 1) << endl;
	p.getI();
	cout << "��static����getI()�ĵ�ַ��" << pointer_cast<int*>(&Base::getI) << endl;
}


int main()
{
	Base b(1000);
	cout << sizeof(b) << endl;
	testBase(b);
	system("pause");
	return 0;
}

/*
1.ͨ��(int*)(&p)ȡ���麯����ĵ�ַ
2.ʹ��tpyeid().name()�鿴��
3.�麯�������Ȱ�����˳��ķ�������У���������print����������ʱdemo()
�����������������
4.���ָ�����һ��λ��Ϊ�Ǿ�̬�����ݳ�Ա
5.��̬��Ա�������Ƿ��뵽����еģ����ǿ��Կ������в�ֵ�Ƚϴ�*/

#endif

//�̳��µ�C++����ģ��
//���̳�

#if 0
typedef void(*Fun)(void);

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
	int ba;
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

public:
	int DeriveI;
};

int main()
{
	Derive d(1024);
	cout << sizeof(d) << endl;
	cout << "[0]Base::vptr";
	cout << "\t��ַ��" << (int *)(&d) << endl;
	//�����е��麯����
	cout << ((int *)*((int *)(&d))) << endl;
	Fun fun1 = (Fun)*((int *)*((int *)(&d)));
	fun1();
	cout << ((int *)*(int *)(&d) + 1) << endl;
	Fun fun2 = (Fun)*((int *)*((int *)(&d)) + 1);
	fun2();
	//���������������
	/*
	Fun fun3 = (Fun)*((int *)*((int *)(&d)) + 2);
	fun3();
	*/
	Fun fun4 = (Fun)*((int *)*((int *)(&d)) + 3);
	fun4();
	cout << "[0]Derive::vptr";
	cout << "\t��ַ: " << (int *)(&d) + 1 << endl;
	//�������е��麯����
	cout << ((int *)*((int*)(&d) + 1)) << endl;
	cout << *((int *)(&d) + 2) << endl;
	Fun fun3 = (Fun)*((int *)*((int *)(&d) + 1));
	fun3();
	cout << "[1]" << "Derive::~Derive" << endl;


	/*
		���н����12 << ��Ϊʵ�����Ķ������и��������ָ��vptr1��vptr2
		һ��ָ���γɵĻ����һ��ָ����������������Ӧ��ָ��ڶ�������ָ��
		����ָ��һ������ɶҲû�еĿռ䣬�����ڵ�һ������е����λ�÷�����������麯��������
	*/
	system("pause");
	return 0;
}
#endif

/* ���ؼ̳� */
//���̳��У�һ��̳У�,�������չ������麯�����ڶ�̳��У����ຬ�ж��
//������Ӷ���
//1.������麯�������������ĵ�һ��������麯�����С�
//2.��ѧʱ�����л����print()�������������print()��������.
//3.�ڴ沼���У����ఴ��������˳�����С�

#if 1
class Base
{
public:
	Base(int i) : baseI(i) {}

	int getI() {
		cout << "Base::getI()" << endl;
		return baseI;
	}

	static void countI()
	{
		cout << "Base::countI()--static" << endl;
	}

	virtual void print() {
		cout << "Base::print()" << endl;
	}

	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
private:
	int baseI;
	static int baseS;
};

class Base_2
{
public:
	Base_2(int i) : base2I(i) {}

	int getI()
	{
		cout << "Base_2::getI()" << endl;
		return base2I;
	}

	virtual void print()
	{
		cout << "Base_2::print()" << endl;
	}

	virtual void demo2()
	{
		cout << "Base_2::demo()" << endl;
	}

	virtual ~Base_2()
	{
		cout << "Base_2::~Base_2()" << endl;
	}
private:
	int base2I;
	int base2S = 1000;
};

class Driver : public Base, public  Base_2
{
public:
	Driver(int d) : Base(1000),
		Base_2(2000),
		my_Driver(d)
	{}

	virtual void print()
	{
		cout << "Driver::print()" << endl;
	}

	virtual void demo()
	{
		cout << "Driver::demo()" << endl;
	}
private:
	int my_Driver;
};

typedef void(*Fun)();

int main()
{
	Base a(1);
	Base_2 b(2);
	Driver d(1024);
	cout << "��һ������Ĵ�С��" << sizeof(a) << endl;
	cout << "��һ������Ĵ�С��" << sizeof(b) << endl;
	cout << "��������Ĵ�С��" << sizeof(d) << endl;
	/* �ӵ�һ���͵ڶ�������֪����̬�Ĳ���ռ��һ����Ĵ�С
	���һ��Ϊһ�����ָ��vptr��һ�����ݳ�Ա��*/
	//��һ��������еĺ���
	cout << "[0]Base::vptr";
	cout << "\t��ַ: " << (int *)(&d) << endl;
	cout << "[0][1]:" << (int *)*((int *)(&d)) << endl;
	Fun fun1 = (Fun)*((int *)*((int *)(&d)));
	fun1();
	cout << "[0][2]:" << (int *)*(int *)(&d) + 1 << endl;
	Fun fun2 = (Fun)*((int *)*(int *)(&d) + 1);
	//fun2(); //���������޷�ͨ����ַ����

	cout << "[0][3]:" << (int *)*(int *)(&d) + 2 << endl;
	Fun fun3 = (Fun)*((int *)*(int *)(&d) + 2);
	fun3(); //���ò���Խ�����
	cout << "[0][4]:" << (int *)*(int *)(&d) + 3 << endl;
	Fun fun7 = (Fun)*((int *)*(int *)(&d) + 3);
	fun7(); //���ò���Խ�����

	/*
	(int *)(&d) + 1:�����ַ����ŵ�һ�������˽�г�Ա
	*/

	//�ڶ������λ��
	cout << "[1]Base_2::vptr";
	cout << "\t��ַ: " << (int *)(&d) + 2 << endl;
	cout << "[1][1]:" << (int *)*((int *)(&d) + 2) << endl;
	Fun fun4 = (Fun)*(int *)*((int *)(&d) + 2);
	fun4();
	cout << "[1][2]:" << (int *)*((int *)(&d) + 2) + 1 << endl;
	Fun fun5 = (Fun)*((int *)*((int *)(&d) + 2) + 1);
	fun5();
	cout << "[1][3]:" << (int *)*((int *)(&d) + 2) + 2 << endl;
	Fun fun6 = (Fun)*((int *)*((int *)(&d) + 2) + 2);
	//���������޷�ͨ����ַ����
	//fun6();
	/*cout << "[1][4]:" << (int *)*((int *)(&d) + 2) + 3 << endl;
	Fun fun7 = (Fun)*((int *)*((int *)(&d) + 2) + 3);
	fun7();*/

	/* (int *)(&d) + 2  �� ���ǵڶ������ຯ���ĵ�һ����Ա����*/
	/* (int *)(&d) + 3  �� ���ǵڶ������ຯ���ĵڶ�����Ա����*/

	//���������λ��
	cout << "[2]Driver::vptr";
	cout << "\t��ַ: " << (int *)(&d) + 4 << endl;
	cout << "[2][1]:" << (int *)*((int *)(&d) + 4) << endl;
	Fun fun8 = (Fun)*((int *)*((int *)(&d) + 4));
	fun8();
	return 0;
}
#endif