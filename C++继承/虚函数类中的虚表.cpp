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
	���н����12 << ��Ϊʵ�����Ķ������и��������ָ��vptr1��vptr2
	һ��ָ���γɵĻ����һ��ָ������������*/
	system("pause");
	return 0;
}