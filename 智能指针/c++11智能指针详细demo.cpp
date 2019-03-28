#include <iostream>
#include <vector>
#include<thread>
#include <mutex>
#include <memory>
using namespace std;

//����ָ��ԭ��
//1.RAII����
//2.����operator*��operator->,������ָ��һ������Ϊ
/*
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

struct Date
{
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year),
		_month(month),
		_day(day)
	{}
	int _year;
	int _month;
	int _day;
};
*/

//int main()
//{
//	SmartPtr<int> sp1(new int);
//	*sp1 = 10;
//	cout << *sp1 << endl;
//	SmartPtr<Date> sparray(new Date);
//	sparray->_year = 2018;
//	sparray->_month = 1;
//	sparray->_day = 1;
//}

/*
//C++98�ṩ��std::auto_ptr
class Date
{
public:
	Date() {
		cout << "Date::Date()" << endl;
	}

	~Date()
	{
		cout << "Date::~Date()" << endl;
	}

	int _year;
	int _month;
	int _day;
};

int main()
{
	auto_ptr<Date> ap(new Date);
	auto_ptr<Date> copy(ap);
	//auto_ptr�����⣺�����󿽱����߸�ֵ��ǰ��Ķ���������յ�
	ap->_year = 2018;

	return 0;
}
*/

//auto_ptr��ʵ��ԭ������Ȩת�Ƶ�˼�롣
class Date
{
public:
	Date() {
		cout << "Date::Date()" << endl;
	}

	~Date()
	{
		cout << "Date::~Date()" << endl;
	}

	int _year;
	int _month;
	int _day;
};


//template<class T>
//class Auto_ptr {
//public:
//	Auto_ptr(T* ptr = NULL)
//		:_ptr(ptr)
//	{}
//	
//	~Auto_ptr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//	//һ�������������ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap������������Դ�Ͽ���ϵ
//	//�����ͽ����һ��ռ䱻�������ʹ�ö���ɳ������
//	Auto_ptr(Auto_ptr<T>& ap)
//		:_ptr(ap._ptr)
//	{
//		ap._ptr = nullptr;
//	}
//
//	Auto_ptr operator=(Auto_ptr<T>& ap)
//	{
//		//����Ƿ�Ϊ�Լ����Լ���ֵ
//		if (this != &ap)
//		{
//			//�ͷŵ�ǰ������Դ
//			if (_ptr)
//				delete _ptr;
//
//			//ת��ap����Դ����ǰ������
//			_ptr = ap._ptr;
//			ap._ptr = NULL;
//		}
//		return *this;
//	}
//
//	T& operator*()
//	{
//		return  *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//};
//
//int main()
//{
//	Auto_ptr<Date> ap(new Date);
//	Auto_ptr<Date> copy(ap);
//	ap->_year = 2018;
//
//	return 0;
//}


//C++11�в��ÿ����͸�ֵ������ָ��unique_ptr
//int main()
//{
//	unique_ptr<Date> up(new Date);
//	unique_ptr<Date> copy(up);
//	return 0;
//}

//unique_ptr��ʵ��ԭ���򵥴ֱ��ķ�����
//template<class T>
//class UniquePtr {
//public:
//	UniquePtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//
//	~UniquePtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T*operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	//C++98�������ķ�ʽ��ֻ������ʵ��+������˽��
//	UniquePtr(UniquePtr<T> const&);
//	UniquePtr & operator=(UniquePtr<T> const&);
//
//	//C++11�������ķ�ʽ��delete
//	UniquePtr(UniquePtr<T> const &) = delete;
//	UniquePtr & operator=(UniquePtr<T> const &) = delete;
//private:
//	T* _ptr;
//};


/*
//C++11�п�ʼ�ṩ�����׵Ĳ���֧�ֿ�����shared_ptr
int main()
{
	//shared_ptrͨ�����ü���֧������ָ�����Ŀ���
	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> copy(sp);

	cout << "ref count:" << sp.use_count() << endl;
	cout << "ref count:" << copy.use_count() << endl;
	return 0;
}

*/
//shared_ptr��ԭ����ͨ�����ü����ķ�ʽ��ʵ�ֶ��shared_ptr����֮�乲����Դ��
//1.shared_ptr�����ڲ�����ÿ����Դ��ά������һ�ݼ�����������¼�÷���Դ������������
//2.�ڶ�������ʱ��Ҳ���������������ã�����˵���Լ���ʹ�ø���Դ�ˣ���������ü�����һ��
//3.������ü�����0����˵���Լ������һ��ʹ�ø���Դ�Ķ��󣬱����ͷŸ���Դ��
//4.�������0����˵�������Լ���������������ʹ�ø÷���Դ�������ͷŸ���Դ��������������ͳ�Ұָ���ˡ�

//template<class T>
//class Share_ptr
//{
//public:
//	Share_ptr(T* ptr = nullptr)
//		:_ptr(ptr)
//		,_pRefCount(new int(1))
//		,_pMutex(new mutex)
//	{
//		//�����һ����ָ����������ü�����0
//		if (_ptr == nullptr)
//			*_pRefCount = 0;
//	}
//		
//	~Share_ptr()
//	{
//		Release();
//	}
//
//	Share_ptr(const Share_ptr<T>& sp)
//		:_ptr(sp._ptr)
//		, _pRefCount(sp._pRefCount)
//		, _pMutex(sp._pMutex)
//	{
//		//�����һ����ָ������򲻼����ü���������ż����ü���
//		if (_ptr)
//			AddRefCount();
//	}
//
//	Share_ptr<T>& operator=(const Share_ptr<T>& sp)
//	{
//		if (_ptr != sp._ptr)
//		{
//			//�ͷŹ���ľ���Դ
//			Release();
//
//			//��������¶������Դ�����������ü���
//			_ptr = sp._ptr;
//			_pRefCount = sp._pRefCount;
//			_pMutex = sp._pMutex;
//
//			if (_ptr)
//				AddRefCount();
//		}
//		return *this;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	int UseCount()
//	{
//		return *_pRefCount;
//	}
//
//	T* Get()
//	{
//		return _ptr;
//	}
//	int AddRefCount()
//	{
//		//��������ʹ�ü�1��ԭ�Ӳ���
//		_pMutex->lock();
//		++(*_pRefCount);
//		_pMutex->unlock();
//		return *_pRefCount;
//	}
//
//	int SubRefCount()
//	{
//		//��������ʹ�ü�1��ԭ�Ӳ���
//		_pMutex->lock();
//		--(*_pRefCount);
//		_pMutex->unlock();
//
//		return *_pRefCount;
//	}
//
//private:
//	void Release()
//	{
//		//���ü�����1���������0�����ͷ���Դ
//		if (_ptr && SubRefCount() == 0)
//		{
//			delete _ptr;
//			delete _pRefCount;
//		}
//	}
//private:
//	int* _pRefCount; //���ü���
//	T* _ptr;		 //ָ�������Դ��ָ��
//	mutex* _pMutex;	 //������
//};
//
//int main()
//{
//	Share_ptr<int> sp1(new int(10));
//	Share_ptr<int> sp2(sp1);
//	*sp2 = 20;
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//
//	Share_ptr<int> sp3(new int(10));
//	sp2 = sp3;    
//	cout << sp1.UseCount() << endl;    
//	cout << sp2.UseCount() << endl;    
//	cout << sp3.UseCount() << endl;
//
//	sp1 = sp3;    
//	cout << sp1.UseCount() << endl;    
//	cout << sp2.UseCount() << endl;    
//	cout << sp3.UseCount() << endl;
//
//	return 0;
//}
//std::shared_ptr���̰߳�ȫ����
//1.����ָ����������ü����Ƕ������ָ�������ģ������߳�������ָ������ü���ͬʱ++��--���� ����������ԭ�ӵģ����ü���ԭ����1��
//++�����Σ����ܻ���2.�������ü����ʹ����ˡ��ᵼ����Դδ �ͷŻ��߳�����������⡣����ֻ��ָ�������ü���++��--����Ҫ�����ģ�Ҳ����˵���ü����Ĳ����� �̰߳�ȫ�ġ�
//
//2.����ָ�����Ķ������ڶ��ϣ������߳���ͬʱȥ���ʣ��ᵼ���̰߳�ȫ����

/*
ѭ������
1.node1��node2��������ָ�����ָ�������ڵ㣬���ü������1�����ǲ���Ҫ�ֶ�delete.
2.node1��_nextָ��node2, node2��_prevָ��node1,���ü������2.
3.node1��node2���������ü�������1������_next��ָ����һ���ڵ㡣����_prev��ָ����һ���ڵ㡣
4.Ҳ����˵_next�����ˣ�node2���ͷ��ˡ�
5.Ҳ����˵_prev�����ˣ�node1���ͷ��ˡ�
6.����_next����node�ĳ�Ա��node1�ͷ��ˣ�_next�Ż���������node1��_prev����_prev����node2��Ա��������ͽ�ѭ�����ã�˭Ҳ�����ͷš�
*/

//struct ListNode {
//	int _data;    
//	weak_ptr<ListNode> _prev;    
//	weak_ptr<ListNode> _next;
//
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//
//	~ListNode() 
//	{ 
//		cout << "~ListNode()" << endl; 
//	}
//};
//
//
//void test()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	shared_ptr<int>* ps = new shared_ptr<int>(new int);
//	node1->_next = node2;
//	node2->_prev = node1;
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//}
//
//int main() {
//	test();
//	return 0;
//}


//�������new�����Ķ������ͨ������ָ������أ���ʵshared_ptr�����һ��ɾ���������������� 
template<class T>
struct FreeFunc {
	void operator()(T* ptr)
	{
		cout << "free: " << ptr << endl;
	}
};

template<class T>
struct DeleteArrayFunc {
	void operator()(T* ptr)
	{
		cout << "delete[]" << ptr << endl;
		delete[] ptr;
	}
};

void text()
{
	FreeFunc<int> freeFunc;
	shared_ptr<int> sp1((int*)malloc(4), freeFunc);

	DeleteArrayFunc<int> deleteArrayFunc;
	shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);
}
int main()
{
	text();
	return 0;
}