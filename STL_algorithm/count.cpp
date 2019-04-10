//#4：count
//作用：返回值等价于给定值的元素的个数
#include <iostream>
#include <algorithm>
#include <vector>

//模板实现
template <class InputIterator, class T>
typename iterator_traits<InputIterator>::difference_type
my_count(InputIterator first, InputIterator last, const T& val)
{
	typename iterator_traits<InputIterator>::difference_type ret = 0;
	while (first != last) {
		if (*first == val) ++ret;
		++first;
	}
	return ret;
}
//实例
int main()
{
	int my_ints[] = { 10,20,30,30,20,10,10,20 };
	int my_count = std::count(my_ints, my_ints + 8, 10);
	std::cout << "10出现的个数：" << my_count << std::endl;

	std::vector<int> my_vector(my_ints, my_ints + 8);
	my_count = std::count(my_vector.begin(), my_vector.end(), 20);
	std::cout << "20出现的个数：" << my_count << std::endl;
	system("pause");
	return 0;
}