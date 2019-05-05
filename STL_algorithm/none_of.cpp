//#14：none_of 
//作用：检测在给定范围中是否不存在元素给定的条件

#include <iostream>
#include <algorithm>
#include <array>

/* 模板 */
template <class Iterator, class Function>
bool my_none_of(Iterator first, Iterator last, Function pred)
{
	while (first != last)
	{
		if (pred(*first))
			return false;
		++first;
	}
	return true;
}

int main()
{
	std::array<int, 8> foo = { 1,2,4,8,16,32,64,128 };
	if (std::none_of(foo.begin(), foo.end(), [](int i) {return i < 0; }))
		std::cout << "有不符合";
	return 0;
}