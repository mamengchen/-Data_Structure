迭代器：
STL的中心思想在于：将数据容器和算法分开，彼此独立设计，最后再以一粘胶着剂将它们撮合在一起

vector实现;
template <class T, class Alloc = alloc>
class vector {
public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type* iterator;
	typedef value_type& reference;
	typedef size_t 	size_type;
	typedef ptrdift_t defference_type;
	
protected:
	typedef simple_alloc<value_type, Alloc> data_allocator;
	iterator start;
	iterator finish;
	iterator end_of_storage;
	
	void insert_aux(
}