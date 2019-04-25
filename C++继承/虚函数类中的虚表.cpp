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