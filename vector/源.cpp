#include<iostream>
#include<vector>
#include<string>
using namespace std;

#if 0
class Date {
public:
	Date(int year = 1900,int month = 1, int day = 1)
		:_year(year),
		_month(month),
		_day(day)
	{}
	friend ostream& operator<<(ostream& _cout, const Date& s) {
		_cout << s._year << "-" << s._month << "-" << s._day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};

template<class T>{
	void PrintVector(const vector<T>& v) {
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;
	}
}
void TestVector() {
	std::vector<int> vl;
	std::vector<int> v2(10, 5);
	std::vector<int> v3(10); //int()	内置类型，缺省值：0
	std::vector<Date> v4(10);	//Date()自定义类型：调用T（）缺省的构造函数
	
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v5(array, array + sizeof(array) / sizeof(array[0]));

	string str("hallo");
	vector<char> v6(str.begin(), str.end());
	vector<char> v7(v6);

}
#endif

#if 0
#include<algorithm>

int main() {
	cout << typeid(vector<int>::iterator).name() << endl;
	vector<int> v{ 2,4,6,1,3,8,5,9,0 ,7 };
	sort(v.begin(), v.end());
	return 0;
}

#endif

#if 0
int main() {
	vector<int> v{ 1 ,2 ,3 ,4 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	//resize改变vector的空间，元素个数可以扩大可以缩小，但是开辟的空间不会被释放
	//reserve改变vector的空间大小，不会改变元素的个数，小的话啥事都不做，大的话扩容
}

#endif

#if 0
int main() {
	vector<int> v{ 1,2,3,4 };
	vector<int>::iterator it = v.begin();//程序员定义的迭代器
	*it *= 2;
	for (int i = 0; i < 5; ++i) {
		v.push_back(i);
	}
	*it *= 2;//这个迭代器失效了，就是访问了被释放的空间。
}
#endif

namespace bit {
	template<class T>
	class vector {
	public:
		typedef T* iterator;	//vector的迭代器
		//begin()					end()
		//第一个元素的位置			最后一个元素的下一个位置


		/*
		rbegin()		rend()
		end()			begin()
		*/


		/*
		3.容量	
		size()
		capacity()
		empty()
		resize(newSize, val = T());
			T---->内置类型	T()----->0
			T---->自定义类型	T的类必须包含缺省构造函数
		reserve(newCapacity)
			一旦遇到增容：性能比较差(vector)
		*/


		/*
		4.访问
		operator[]随机访问----assert断言
		at----->抛出异常
		front,	back
		*/

		/*
		5.修改
		push_back
		pop_back
		insert(pos,data)
		vector中插入元素：vector迭代器都失效了
			(主要看底层空间是否改变，一般增容就会找新的空间)
		erase(pos)---->迭代器失效
		*/












		vector()
			:_start(nullptr),
			_last(nullptr),
			_endOfStorage(nullptr)
		{}

		vector(size_t n, const T& data = T()) 
		:_start(new T[n]),
		_last(_start+n),
		_endOfStorage(_last)
		{
			for (size_t i = 0; i < n; ++i) {
				_start[i] = data;
			}
		}

		//[first，last）表示一段连续的空间
		vector(T* first, T* last) {
			size_t size = last - first;
			_start = new T[size];

			for (size_t i = 0; i < size; ++i) {
				_start[i] = first[i];
			}

			_last = _start + size;
			_endOfStorage = _last;
		}

		~vector()
		{
			if (_start) {
				delete[] _start;
				_start = _last = _endOfStorage = nullptr;
			}
		}

		vector<T>& operator=(const vector<T> v);

		iterator begin() {
			return _start;
		}

		iterator end() {
			return _last;
		}
	private:
		iterator _start;
		iterator _last;				//size
		iterator _endOfStorage;		//capacity
	};

}
int main() {
	return 0;
}