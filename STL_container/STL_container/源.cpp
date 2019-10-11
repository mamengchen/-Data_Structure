
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>


using namespace std;

namespace mmc {
//	class String {
//	private:
//		char* _str;
//		int _size;
//		int _capacity;
//	public:
//		typedef char* iterator;
//	public:
//		String(const char* str = "") {
//			if (nullptr == str) {
//				assert(false);
//				return;
//			}
//
//			_size = strlen(str);
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		String(const String& s) {
//			_str = new char[s._capacity + 1];
//			_capacity = s._capacity;
//			_size = s._size;
//			strcpy(_str, s._str);
//		}
//
//		String operator=(const String& s) {
//			if (this != &s) {
//				char* pstr = new char[s._capacity];
//				strcpy(pstr, s._str);
//
//				_size = s._size;
//				_capacity = s._capacity;
//				_str = pstr;
//			}
//			return *this;
//		}
//
//		~String()
//		{
//			if (_str) {
//				delete[]_str;
//				_str = nullptr;
//			}
//		}
//
//		iterator begin() {
//			return _str;
//		}
//
//		iterator end() {
//			return _str + _size;
//		}
//
//		void PushBack(char c) {
//			if (_size == _capacity) {
//				addcapacity(_capacity * 2);
//			}
//			_str[_size++] = c;
//			_str[_size] = '\0';
//		}
//
//		void PushBack(int c) {
//			if (_size == _capacity) {
//				addcapacity(_capacity * 2);
//			}
//			_str[_size++] = c - '0';
//			_str[_size] = '\0';
//		}
//
//		void PushBack(String& c) {
//			if (_size + c._size >= _capacity) {
//				addcapacity(_capacity * 2 + c._size);
//			}
//			for (int i = 0; i < c._size; i++) {
//				_str[_size++] = c._str[i];
//			}
//			_str[_size] = '\0';
//		}
//
//		void PushBack(const char* c) {
//			String ss(c);
//			PushBack(ss);
//		}
//
//		void Append(int n, char c) {
//			for (int i = 0; i < n; i++) {
//				PushBack(c);
//			}
//		}
//
//		void PopBack() {
//			_str[--_size] = '\0';
//		}
//
//		void erase(int start, int end) {
//			int size = end - start;
//			for (int i = end; i < _size; i++) {
//				_str[start++] = _str[i];
//			}
//			_str[_size - size] = '\0';
//		}
//
//		void insert(int seat, char c) {
//			if (_size == _capacity) {
//				addcapacity(2 * _capacity);
//			}
//			for (int i = seat; i < _size; i++) {
//				_str[i] = _str[i - 1];
//			}
//			_str[seat - 1] = c;
//			++_size;
//			_str[_size] = '\0';
//		}
//
//		void insert(int seat, const char* c) {
//			int csize = strlen(c);
//			if (_size + csize >= _capacity) {
//				addcapacity(_capacity * 2 + csize);
//			}
//
//			for (int i = _size - 1; i >= seat; i--) {
//				_str[i + csize] = _str[i];
//			}
//
//			for (int i = 0; i < csize; i++) {
//				_str[seat++] = c[i];
//			}
//			
//			_size += csize;
//			_str[_size] = '\0';
//		}
//		
//		template <typename T>
//		String& operator+=(T c) {
//			PushBack(c);
//			return *this;
//		}
//
//		void clear() {
//			_size = 0;
//			_str[_size] = '\0';
//		}
//
//		void Swap(String& s) {
//			swap(_str, s._str);
//			swap(_size, s._size);
//			swap(_capacity, s._capacity);
//		}
//
//		const char* C_Str() const {
//			return _str;
//		}
//		
//		////////////////////////////////////////////////////////////////
//
//		size_t Size() const {
//			return _size;
//		}
//
//		size_t Capacity() const {
//			return _capacity;
//		}
//
//		bool Empty()const {
//			return 0 == _size;
//		}
//
//		//////////////////////////////////////////////////////////////
//		char& operator[](size_t index) {
//			assert(index < _size);
//			return _str[index];
//		}
//
//		const char& operator[](size_t index) const {
//			assert(index < _size);
//			return _str[index];
//		}
//
//		bool operator>(String& s) {
//			int ret = 0;
//			char* pstr = _str;
//			char* bstr = s._str;
//			while (!(ret = *pstr - *bstr) && *bstr) {
//				++pstr, ++bstr;
//			}
//			return ret > 0 ? true : false;
//		}
//		bool operator<(String& s) {
//			return _str > s._str ? false : true;
//		}
//		bool operator==(String& s) {
//			if (!(strcmp(_str, s._str))) {
//				return true;
//			}
//			return false;
//		}
//		bool operator!=(String& s) {
//			return _str == s._str ? false : true;
//		}
//		bool operator>=(String& s) {
//			if (_str > s._str || _str == s._str) {
//				return true;
//			}
//			return false;
//		}
//
//		bool operator<=(String& s) {
//			if (!(_str > s._str)) {
//				return true;
//			}
//			return false;
//		}
//
//		size_t Find(char c) const {
//			for (int i = 0; i < _size; i++) {
//				if (c == _str[i]) {
//					return i;
//				}
//			}
//			return -1;
//		}
//
//		size_t Find(const char* c, size_t pos = -1) const {
//			for (int i = 0; i < _size; i++) {
//				if (_str[i] == *c) {
//					const char* pstr = c;
//					pos = i;
//					while (*pstr) {
//						if (*pstr != _str[i]) {
//							i = pos;
//							pos = -1;
//						}
//						i = (i + 1) % _size;
//						pstr++;
//					}
//				}
//			}
//			return pos;
//		}
//
//		String* SubStr(size_t pos, size_t n) {
//			String* str = new String;
//			for (int i = 0; i < n; i++) {
//				str->PushBack(_str[(pos + i) % _size]);
//			}
//			return str;
//		}
//
//		
//	private:
//		
//		friend ostream& operator<<(ostream& _cout, const mmc::String& s) {
//			_cout << s._str;
//			return _cout;
//		}
//
//		int two_data_judge(char l, char r) {
//			return l - r;
//		}
//
//		void addcapacity(int newcapacity) {
//			if (newcapacity > _capacity) {
//				char* pstr = new char[newcapacity + 1];
//				strcpy(pstr, _str);
//
//				delete[]_str;
//				_capacity = newcapacity;
//				_str = pstr;
//			}
//		}


	/*template<class T>
	class Vector {
	public:
		typedef T* Iterator;
		typedef const T* ConstIterator;

		Iterator Begin() { return _start; }
		Iterator End() { return _finish; }

		ConstIterator CBegin() const { return _start; }
		ConstIterator CEnd() const { return _finish; }

		size_t Size() { return _finish - _start; }
		size_t Capacity() const { return _endOfStorage - _start; }

		Vector() :_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)
		{}

		Vector(int n, const T& value = T())
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)
		{
			addcapactiy(n);
			while (n--) {
				PushBack(value);
			}
		}

		template<class InputIterator>
		Vector(InputIterator first, InputIterator last) {
			addcapactiy(last - first);
			while (first != last) {
				PushBack(*first);
				first++;
			}
		}

		Vector(const Vector<T>& vec) 
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)
		{
			addcapactiy(vec.Capacity());
			for (int i = 0; i < vec.Size(); i++) {
				_start[i] = vec[i];
			}
		}

		Vector<T>& operator= (Vector<T> v) {
			Swap(v);
			return *this;
		}

		Vector<T>& operator+= (Vector<T> v) {
			if (this->Size() + v.Size() > this->Capacity()) {
				addcapactiy(this->Size() + v.Capacity());
			}
			while (v._start != v._finish) {
				_finish++ = v._start++;
			}
		}

		~Vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		Iterator insert(Iterator pos, const T& value) {
			assert(pos <= _finish);
			int ipos = pos - _start;
			if (_finish == _endOfStorage) {
				size_t size = Size();
				size_t newcapacity = Capacity() == 0 ? 1 : newcapacity * 2;
				addcapactiy(newcapacity);
				pos = _start + ipos;
			}
			Iterator end = _finish - 1;
			while (end != pos) {
				*(end + 1) = *end;
				end--;
			}
			*pos = value;
			++_finish;
			return pos;
		}

		Iterator Erase(Iterator pos) {
			Iterator begin = pos + 1;
			while (begin != End()) {
				*(begin - 1) = *begin;
				begin++;
			}
			--_finish;
			return pos;
		}

		T& operator[](size_t pos) {
			return _start[pos];
		}

		void PushBack(const T& value) {
			insert(End(), value);
		}

		void PopBack() {
			Erase(End());
		}

	private:
		void Swap(Vector<T>& v) {
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		void addcapactiy(size_t n) {
			if (n > Capacity()) {
				size_t size = Size();
				T* tmp = new T[n];

				if (_start) {
					for (size_t i = 0; i < size; i++) {
						tmp[i] = _start[i];
					}
				}

				delete[] _start;

				_start = tmp;
				_finish = size + tmp;
				_endOfStorage = _start + n;
			}
		}

		Iterator _start;
		Iterator _finish;
		Iterator _endOfStorage;
	};
	
	*/

	template <class T>
	struct ListNode {
		ListNode(const T& val = T()) 
			:_pPre(nullptr)
			,_pNext(nullptr)
			,_val(val)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};

	template <class T, class ref, class ptr>
	class ListIterator {
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, ref, ptr> myiter;
	public:
		ListIterator(PNode pnode = nullptr)
			:_pnode(pnode)
		{}

		ListIterator(const myiter& val) 
			:_pnode(val._pnode)
		{}

		T& operator*() {
			return _pnode->_val;
		}

		T* operator->() {
			return &(operator*());
		}

		myiter& operator++() {
			_pnode = _pnode->_pNext;
			return *this;
		}

		myiter& operator++(int) {
			myiter temp(*this);
			_pnode = _pnode->_pNext;
			return temp;
		}

		myiter& operator--() {
			_pnode = _pnode->_pPre;
			return *this;
		}

		myiter& operator--(int) {
			myiter temp(*this);
			_pnode = _pnode->_pPre;
			return temp;
		}

		bool operator!=(const myiter& mval) {
			return _pnode->_val != mval._pnode->_val;
		}

		bool operator==(const myiter& mval) {
			return (!(operator!=(mval)));
		}

		PNode _pnode;
	};


	template<class T, class ref, class ptr, class iterator>
	class ListReverseIterator {
		typedef ListReverseIterator<T, ref, ptr, iterator> Rmyiter;
	public:
		ListReverseIterator(const iterator& it) 
			:_it(it)
		{}

		ListReverseIterator(const Rmyiter& val)
			:_it(val._it)
		{}

		ref operator*() {
			return *(_it);
		}

		ptr operator->() {
			return &operator*();
		}

		Rmyiter& operator++() {
			--_it;
			return *this;
		}

		Rmyiter& operator++(int) {
			iterator it(_it);
			--_it;
			return it;
		}

		Rmyiter& operator--() {
			++_it;
			return *this;
		}

		Rmyiter& operator--(int) {
			iterator it(_it);
			++_it;
			return it;
		}

		bool operator!=(const Rmyiter& val) {
			return _it != val._it;
		}

		bool operator==(const Rmyiter& val) {
			return _it == val._it;
		}

		iterator _it;
	};
	class mylist {

	};
};
//}
//
//int main() {
//	mmc::String ss;
//	mmc::String s("hallo world");
//	ss += "hhhhh";
//	ss.insert(2, "mmc");
//	if (ss > s) {
//		cout << "ss ´óÓÚ s" << endl;
//	}
//	int i = s.Find("al");
//	cout << s[1] << endl;
//	mmc::String* sss = s.SubStr(2, 3);
//	cout << s << endl;
//	return 0;
//}
//
