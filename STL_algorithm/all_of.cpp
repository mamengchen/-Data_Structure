#include <iostream>
#include <algorithm>
#include <array>

//#1:all_of
//作用：检查在给定范围中是否所有元素
//		都满足给定的条件

/*模拟实现*/
template<class Iterator, class Lambda>
bool my_All_of(Iterator first, Iterator last, Lambda pred)
{
	while (first != last)
	{
		if (!pred(*first))
			return false;
		++first;
	}
	return true;
}

//实例：

int main()
{
	std::array<int, 6> foo = { 3,5,7,9,11,13 };
	if (my_All_of(foo.begin(), foo.end(),
		[](int i) {return i % 2; }))
		std::cout << "这个数组里面全是奇数" << std::endl;
	return 0;
}