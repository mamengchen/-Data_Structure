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
		}
	}
}
