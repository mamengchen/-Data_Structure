//#10：find_if
//作用：返回第一个值满足给定条件的元素
#include <iostream>     
#include <algorithm>    
#include <vector>     


/*模板*/
template <class Iterator, class Function>
Iterator Find_if(Iterator first, Iterator last, Function pred)
{
	while (first != last)
	{
		if (pred(*first))
			return first;
	}
	return last;
}

bool IsOdd(int i)
{
	return ((i % 2) == 1);
}

int main()
{
	std::vector<int> my_vector;
	my_vector.push_back(10);
	my_vector.push_back(25);
	my_vector.push_back(40);
	my_vector.push_back(55);

	std::vector<int>::iterator it = std::find_if(my_vector.begin(), my_vector.end(), IsOdd);
	std::cout << "第一次满足条件的在：" << *it << std::endl;
	return 0;
}