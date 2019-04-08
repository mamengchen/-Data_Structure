//#3:any_of
//作用：检测在给定范围中是否存在元素满足给定条件
#include <iostream>
#include <algorithm>
#include <array>

/*模板实现*/
template<class Iterator, class Lambda>
bool any_of(Iterator first, Iterator end, Lambda pred)
{
	while (first != last)
	{
		if (pred(*first))
			return true;
		++first;
	}
	return false;
}

//实例
int main()
{
	std::array<int, 7> foo = { 0,1,-1,3,-3,5,-5 };

	if (std::any_of(foo.begin(), foo.end()
		, [](int i) {return i < 0; }))
		std::cout << "范围内有负元素 \n";
	return 0;
}