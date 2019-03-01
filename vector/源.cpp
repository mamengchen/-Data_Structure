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
	std::vector<int> v3(10); //int()	�������ͣ�ȱʡֵ��0
	std::vector<Date> v4(10);	//Date()�Զ������ͣ�����T����ȱʡ�Ĺ��캯��
	
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
	//resize�ı�vector�Ŀռ䣬Ԫ�ظ����������������С�����ǿ��ٵĿռ䲻�ᱻ�ͷ�
	//reserve�ı�vector�Ŀռ��С������ı�Ԫ�صĸ�����С�Ļ�ɶ�¶���������Ļ�����
}

#endif

#if 0
int main() {
	vector<int> v{ 1,2,3,4 };
	vector<int>::iterator it = v.begin();//����Ա����ĵ�����
	*it *= 2;
	for (int i = 0; i < 5; ++i) {
		v.push_back(i);
	}
	*it *= 2;//���������ʧЧ�ˣ����Ƿ����˱��ͷŵĿռ䡣
}
#endif

namespace bit {
	template<class T>
	class vector {
	public:
		typedef T* iterator;	//vector�ĵ�����
		//begin()					end()
		//��һ��Ԫ�ص�λ��			���һ��Ԫ�ص���һ��λ��


		/*
		rbegin()		rend()
		end()			begin()
		*/


		/*
		3.����	
		size()
		capacity()
		empty()
		resize(newSize, val = T());
			T---->��������	T()----->0
			T---->�Զ�������	T����������ȱʡ���캯��
		reserve(newCapacity)
			һ���������ݣ����ܱȽϲ�(vector)
		*/


		/*
		4.����
		operator[]�������----assert����
		at----->�׳��쳣
		front,	back
		*/

		/*
		5.�޸�
		push_back
		pop_back
		insert(pos,data)
		vector�в���Ԫ�أ�vector��������ʧЧ��
			(��Ҫ���ײ�ռ��Ƿ�ı䣬һ�����ݾͻ����µĿռ�)
		erase(pos)---->������ʧЧ
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

		//[first��last����ʾһ�������Ŀռ�
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