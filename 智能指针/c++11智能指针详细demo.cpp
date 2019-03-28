#include <iostream>
#include <vector>
#include<thread>
#include <mutex>
#include <memory>
using namespace std;

//智能指针原理：
//1.RAII特性
//2.重载operator*和operator->,具有像指针一样的行为
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
//C++98提供的std::auto_ptr
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
	//auto_ptr的问题：当对象拷贝或者赋值后，前面的对象就是悬空的
	ap->_year = 2018;

	return 0;
}
*/

//auto_ptr的实现原理：管理权转移的思想。
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
//	//一旦发生拷贝，就将ap中资源转移到当前对象中，然后另ap与其所管理资源断开联系
//	//这样就解决了一块空间被多个对象使用而造成程序崩溃
//	Auto_ptr(Auto_ptr<T>& ap)
//		:_ptr(ap._ptr)
//	{
//		ap._ptr = nullptr;
//	}
//
//	Auto_ptr operator=(Auto_ptr<T>& ap)
//	{
//		//检测是否为自己给自己赋值
//		if (this != &ap)
//		{
//			//释放当前对象资源
//			if (_ptr)
//				delete _ptr;
//
//			//转移ap中资源到当前对象中
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


//C++11中不让拷贝和赋值的智能指针unique_ptr
//int main()
//{
//	unique_ptr<Date> up(new Date);
//	unique_ptr<Date> copy(up);
//	return 0;
//}

//unique_ptr的实现原理：简单粗暴的防拷贝
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
//	//C++98防拷贝的方式：只声明不实现+声明成私有
//	UniquePtr(UniquePtr<T> const&);
//	UniquePtr & operator=(UniquePtr<T> const&);
//
//	//C++11防拷贝的方式：delete
//	UniquePtr(UniquePtr<T> const &) = delete;
//	UniquePtr & operator=(UniquePtr<T> const &) = delete;
//private:
//	T* _ptr;
//};


/*
//C++11中开始提供更靠谱的并且支持拷贝的shared_ptr
int main()
{
	//shared_ptr通过引用计数支持智能指针对象的拷贝
	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> copy(sp);

	cout << "ref count:" << sp.use_count() << endl;
	cout << "ref count:" << copy.use_count() << endl;
	return 0;
}

*/
//shared_ptr的原理：是通过引用计数的方式来实现多个shared_ptr对象之间共享资源。
//1.shared_ptr在其内部，给每个资源都维护了着一份计数，用来记录该份资源被几个对象共享。
//2.在对象被销毁时（也就是析构函数调用），就说明自己不使用该资源了，对象的引用计数减一。
//3.如果引用计数是0，就说明自己是最后一个使用该资源的对象，必须释放该资源；
//4.如果不是0，就说明除了自己还有其他对象在使用该份资源，不能释放该资源，否则其他对象就成野指针了。

//template<class T>
//class Share_ptr
//{
//public:
//	Share_ptr(T* ptr = nullptr)
//		:_ptr(ptr)
//		,_pRefCount(new int(1))
//		,_pMutex(new mutex)
//	{
//		//如果是一个空指针对象，则引用计数给0
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
//		//如果是一个空指针对象，则不加引用计数，否则才加引用计数
//		if (_ptr)
//			AddRefCount();
//	}
//
//	Share_ptr<T>& operator=(const Share_ptr<T>& sp)
//	{
//		if (_ptr != sp._ptr)
//		{
//			//释放管理的旧资源
//			Release();
//
//			//共享管理新对象的资源，并增加引用计数
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
//		//加锁或者使用加1的原子操作
//		_pMutex->lock();
//		++(*_pRefCount);
//		_pMutex->unlock();
//		return *_pRefCount;
//	}
//
//	int SubRefCount()
//	{
//		//加锁或者使用减1的原子操作
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
//		//引用计数减1，如果减到0，则释放资源
//		if (_ptr && SubRefCount() == 0)
//		{
//			delete _ptr;
//			delete _pRefCount;
//		}
//	}
//private:
//	int* _pRefCount; //引用计数
//	T* _ptr;		 //指向管理资源的指针
//	mutex* _pMutex;	 //互斥锁
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
//std::shared_ptr的线程安全问题
//1.智能指针对象中引用计数是多个智能指针对象共享的，两个线程中智能指针的引用计数同时++或--，这 个操作不是原子的，引用计数原来是1，
//++了两次，可能还是2.这样引用计数就错乱了。会导致资源未 释放或者程序崩溃的问题。所以只能指针中引用计数++、--是需要加锁的，也就是说引用计数的操作是 线程安全的。
//
//2.智能指针管理的对象存放在堆上，两个线程中同时去访问，会导致线程安全问题

/*
循环引用
1.node1和node2两个智能指针对象指向两个节点，引用计数变成1，我们不需要手动delete.
2.node1的_next指向node2, node2的_prev指向node1,引用计数变成2.
3.node1和node2析构，引用计数减到1，但是_next还指向下一个节点。但是_prev还指向上一个节点。
4.也就是说_next析构了，node2就释放了。
5.也就是说_prev析构了，node1就释放了。
6.但是_next属于node的成员，node1释放了，_next才会析构，而node1由_prev管理，_prev属于node2成员，所以这就叫循环引用，谁也不会释放。
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


//如果不是new出来的对象如何通过智能指针管理呢？其实shared_ptr设计了一个删除器来解决这个问题 
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