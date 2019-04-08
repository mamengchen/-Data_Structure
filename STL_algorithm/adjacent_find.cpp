//#2:adjacent_find
//作用：查找两个相邻(adjacent)的等价(Indentical)元素
#include <iostream>
#include <algorithm>
#include <vector>

/*模拟实现*/
template<class Iterator>
Iterator my_adjacent_find(Iterator first, Iterator last)
{
	if (first != last)
	{
		Iterator next = first;
		++next;
		while (next != last)
		{
			if (*first == *next)
				return first;
			++first;
			++next;
		}
	}
	return last;
}

//实例
bool myfunction(int first, int second)
{
	return (first == second);
}

int main()
{
	int my_int[] = { 5,20,5,30,30,20,10,10,20 };
	std::vector<int> my_vector(my_int, my_int + 8);
	std::vector<int>::iterator it;

	//使用默认比较
	it = std::adjacent_find(my_vector.begin(), my_vector.end());
	if (it != my_vector.end())
		std::cout << "第一对重复的元素是：" << *it << std::endl;

	it = std::adjacent_find(++it, my_vector.end(), myfunction);
	if (it != my_vector.end())
		std::cout << "第二对重复的元素是：" << *it << std::endl;
	return 0;
}
