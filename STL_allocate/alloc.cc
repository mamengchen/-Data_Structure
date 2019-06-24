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