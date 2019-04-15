//#7：find
//作用：返回第一个值等价于给定值的元素
#include <iostream>
#include <algorithm>
#include <vector>

/*模板*/
template <class Iterator, class T>
Iterator Find(Iterator first, Iterator last, const T& val)
{
	while (first != last)
	{
		if (*first == val)
			return first;
		++first;
	}
	return last;
}


int main()
{
	int my_int[] = { 10,20,30,40 };
	int *p;
	p = std::find(my_int, my_int + 4, 30);
	if (p != my_int + 4)
		std::cout << "找到符合条件的值：" << *p << std::endl;
	else
		std::cout << "没找到符合条件的值：" << std::endl;

	std::vector<int> my_vector(my_int, my_int + 4);
	std::vector<int>::iterator it;

	it = Find(my_vector.begin(), my_vector.end(), 30);
	if (it != my_vector.end())
		std::cout << "找到符合条件的值：" << *it << std::endl;
	else
		std::cout << "没找到符合条件的值：";
	system("pause");
	return 0;
}