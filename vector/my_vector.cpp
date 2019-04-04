#include <iostream>
#include <algorithm>
#include <string>
#include <assert.h>
using namespace std;

namespace mmc
{
	template<class T>
	class My_vector
	{
	public:
		//vector�ĵ�������һ��ԭ��ָ��
		typedef T* Iterator;
		typedef const T* const_Iterator;

		Iterator my_begin() { return _start; }
		Iterator my_end() { return _finish; }

		const_Iterator my_cbegin() const { return _start; }
		const_Iterator my_cend() const { return _finish; }

		size_t my_size() const { return _finish - _start; }
		size_t my_capacity() const { return _endOfStorage - _start; }

		My_vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		My_vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(n);
			while (n--)
			{
				PushBack(value);
			}
		}

		//�������ʹ��Iterator�����������ᵼ�³�ʼ���ĵ���������[first, last]ֻ����
		//vector�ĵ�������������������������������������[first, last]���������������ĵ���������.
		template<class Input_Iterator>
		My_vector(Input_Iterator first, Input_Iterator last)
		{
			Reserve(last - first);
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}

		My_vector(const My_vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(v.my_capacity());
			Iterator it = my_begin();
			const_Iterator cit = v.my_cbegin();
			while (cit != v.my_cend())
			{
				*it++ = *cit++;
			}
			_finish = _start + v.my_size();
			_endOfStorage = _start + v.my_capacity();
		}

		My_vector<T>& operator= (My_vector<T> v)
		{
			my_swap(v);
			return *this;
		}

		~My_vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		void my_swap(My_vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		void PushBack(const T& x)
		{
			Insert(my_end(), x);
		}

		void PopBack()
		{
			Iterator end = my_end();
			end--;
			Erase(end);
		}

		void Resize(size_t n, const T& value = T())
		{
			//1.���nС�ڵ�ǰ��size,�����ݸ�����С��N
			if (n <= my_size())
			{
				_finish = _start + n;
				return;
			}

			//2.�ռ䲻��������
			if (n > my_capacity())
			{
				Reserve(n);
			}

			//3.��size����n
			Iterator it = _finish;
			Iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}

		void Reserve(size_t n)
		{
			if (n > my_capacity())
			{
				size_t size = my_size();
				T* tmp = new T[n];

				if (_start)
				{
					for (size_t i = 0; i < size; ++i)
					{
						tmp[i] = _start[i];
					}
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}

		void Print()
		{
			Iterator begin = my_begin();
			Iterator end = my_end();
			for (; begin != end; begin++)
			{
				cout << *begin << " ";
			}
			cout << endl;
		}

		Iterator Insert(Iterator pos, const T& x)
		{
			assert(pos <= _finish);
			int count = 0;
			Iterator begin = my_begin();
			while (begin++ != pos)
			{
				count++;
			}


			//�ռ䲻���Ƚ�������
			if (_finish == _endOfStorage)
			{
				size_t newCapacity = my_capacity() == 0 ? 1 : my_capacity() * 2;

				Reserve(newCapacity);
				//������������ݣ��������pos
				pos = _start + count;
			}

			Iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;
			return pos;
		}

		Iterator Erase(Iterator pos)
		{
			//�ƶ����ݽ���ɾ��
			Iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

		Iterator Find(const T& x)
		{
			Iterator begin = my_begin();
			Iterator end = my_end();
			for (; begin != end; begin++)
			{
				if (*begin == x)
				{
					break;
				}
			}
			return begin;
		}

	private:
		Iterator _start;	//ָ�����ݿ�Ŀ�ʼ
		Iterator _finish;	//ָ����Ч���ݵ�β
		Iterator _endOfStorage;	//ָ��洢������β
	};
}


int main()
{
	mmc::My_vector<int> num;
	mmc::My_vector<int> num1(3, 10);
	mmc::My_vector<int> num2(num1.my_begin(), num1.my_end());
	mmc::My_vector<int> num3(num2);
	num1.Print();
	num2.Print();
	num3.Print();

	int testInts[] = { 13, 23, 77, 87, 45 };
	mmc::My_vector<int> num4(testInts, testInts + sizeof(testInts) / sizeof(int));
	num4.PopBack();
	num4.PushBack(100);


	mmc::My_vector<int>::Iterator it = num4.my_begin();
	num4.Insert(it, 10);
	num4.Print();


	return 0;
}