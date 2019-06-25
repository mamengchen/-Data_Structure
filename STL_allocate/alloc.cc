enum {__ALIGN = 8};		//小型区块的上调边界
enum {__MAX_BYTES = 128};	//小区块的上限
enum {__NFREELISTS = __MAX_BYTES/_ALIGN} //free_lists个数

template <bool threads, int inst>
class __default_alloc_template{
	private:
	//将bytes上调至8的倍数
	static size_t ROUND_UP(size_t bytes)
	{
		return (((bytes) + __ALIGN - 1) & ~(__ALIGN - 1))
	}
};
当它发现free list中没有可用区块了时，就调用refill()，准备为free list重新填充空间。新
的空间将取自内存池(经由chunk_alloc()完成)。一会分配大约20个新的结点
template <bool threads, int inst>
void* __default_alloc_template<threads, inst>::refill(size_t n)
{
	int nobjs = 20;
	char* chunk = chunk_alloc(n, nobjs);
	obj * volatile * my_free_list;
	obj * result;
	obj * current_obj, * next_obj;
	int i;
	if (1 == nobjs) return (chunk);
	my_free_list = free_list + FREELIST_INDEX(n)
	//以下在chunk空间内建立free list
	result = (obj *)chunk;
	*my_free_list = next_obj = (obj *)(chunk + n);
	//以下将free list指向新配置的各节点连接起来
	for (i = 1;;i++)
	{
		//第0个将返回给客户
		current_obj = next_obj;
		next_obj = (obj *)((char *)next_obj + n);
		if (nobjs - 1 == i)
		{
			//如果这个结点是最后一个结点则它下一个结点为NULL
			current_obj->free_list_link = 0;
			break;
		}
		else
		{
			current_obj->free_list_link = next_obj;
		}
	}
	return result;
}

内存空间配置（内存池）
从内存池中取空间给free list使用，是chunk_alloc（）的工作:
参数nobjs是通过引用来调用的
template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::chunk_alloc(size_t size, int& nobjs)
{
	char* result;
	size_t total_bytes = size * nobjs;
	size_t bytes_left = end_free - start_free; //内存池剩余空间
	
	if (bytes_left >= total_bytes)
	{
		result = start_free;
		start_free += total_bytes;
		return (result);
	}
	else if (bytes_left >= size)
	{
		//内存池剩余空间不能完全满足需求量，但是可以开辟出一个以上的区块
		nobjs = bytes_left/size;
		total_bytes = size * nobjs;
		result = start_free;
		start_free += total_bytes;
		return(result);
	}
	else
	{
		//内存池剩下的残余连一块区域都无法提供ROUND_UP(128)
		size_t bytes_to_get = 2*total_bytes + ROUND_UP(heap_size >> 4);
		if (bytes_left > 0)
		{
			//把这些残余的内存利用起来
			//首先先配给适当的free list
			obj * volatile * my_free_list = free_list + FREELIST_INDEX(bytes_left);
			//调整free list，将内存池中的残余空间编入
			((obj *)start_free)->free_list_link = *my_free_list;
			*my_free_list = (obj *)start_free;
		}
		
		//配置heap空间，用来补充内存池
		start_free = (char *)malloc(bytes_to_get);
		if (0 == start_free)
		{
			//堆空间不足，申请失败
			int i;
			obj * volatile * my_free_list, *p;
			//不能取配置较小的区块，这个在多进程机器上容易导致灾难，所以找相对较大的
			for (i = size; i <= __MAX_BYTES; i += __ALIGN)
			{
				my_free_list = free_list + FREELIST_INDEX(i);
				p = *my_free_list;
				if (0 != p)
				{
					//free_list内尚有没用区块
					//调整free list以释出未用区块
					*my_free_list = p->free_list_link;
					start_free = (char *)p;
					end_free = start_free + i;
					return (chunk_alloc(size, nobjs));
				}
			}
			end_free = 0;
			start_free = (char *)malloc_alloc::allocate(bytes_to_get);
		}
		heap_size += bytes_to_get;
		end_free = start_free + bytes_to_get;
		return (chunk_alloc(size, nobjs));
	}
}

总结：当我们使用二级空间配置器时候，如果内存池里面有足够内存，你就划分出一大块，再把着
一大块分成20小块，其中第一小块交给用户,剩下的19块放入free_list中，如果内存池中的内存不够
20块的量但是你要申请多余1块的还是足够的，那么他改变你的nobjs参数，在按上面的配置，如果
不足一块啦，它就去malloc申请，如果malloc申请失败，他就去找你的free_list看有没有未使用的区块
提供给你现在应急使用，如果free_list中也没有未使用的，他就交给一级空间适配器，如果一级空间
适配器失败它会报异常。

内存基本处理工具
1.构造函数construct()和2.析构函数destroy()
uninitialized_copy:
使我们能够将内存的配置与对象的构造行为分离开来。
因为容器的全区间构造函数是以两步骤完成的：
1.配置内存块，足以包含范围内的所有元素。
2.使用 uninitialized_copy(), 在该内存区块上构造元素。
uninitialized_fill:
void uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& x);
如果[first, last)范围内的每个迭代器都指向未初始化的内存，那么这个函数fill会在该范围内
产生x的辅助品

uninitialized_fill_n:
1.迭代器first指向欲初始化空间的起始处
2.n 表示欲初始化空间的大小
3.x 表示初值。
template <class ForwardIterator, class Size, class T>
inline ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n, const T& x)
{
	return __uninitialized_fill_n(first, n, x,value_type(first));
}
首先萃取出first的值类型(value_type)，判断该类型是否为POD类型
如果是则：采取最有效率的初值填写手法，
template <class ForwardIterator, class Size, class T, class T1>
inline ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n, const T& x, T1*)
{
	typedef typename __type_traits<T1>::is_POD_type is_POD;
	return __uninitialized_fill_n_aux(first, n, x, is_POD());
}

如果是no—POD类别采取最保险的做法：
