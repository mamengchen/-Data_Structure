//#12：for_each
//作用：对范围中的每个元素调用指定函数
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector


/*模拟*/
template <class Iterator, class Function>
Function For_each(Iterator first, Iterator last, Function pred)
{
	while (first != last)
	{
		pred(*first);
		++first;
	}
	return pred;
}



void my_function(int i)
{
	std::cout << ' ' << i;
}

struct my_class {
	void operator()(int i)
	{
		std::cout << ' ' << i;
	}
}myobject;

int main()
{
	std::vector<int> my_vector;
	my_vector.push_back(10);
	my_vector.push_back(20);
	my_vector.push_back(30);

	std::cout << "my_vector contains：";
	for_each(my_vector.begin(), my_vector.end(), my_function);
	std::cout << std::endl;

	std::cout << "my_vector contains：";
	for_each(my_vector.begin(), my_vector.end(), myobject);
	std::cout << std::endl;
	return 0;
}