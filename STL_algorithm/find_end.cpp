//#8：find_end
//作用：查找范围A中与范围B等价的子范围最后出现的位置
//但是不包括取后面一部分加前面一部分可以相等的
#include <iostream>
#include <algorithm>
#include <vector>

/*模板*/
template <class Iterator_first, class Iterator_second>
Iterator_first Find_end(Iterator_first begin, Iterator_first end,
	Iterator_second begin2, Iterator_second end2)
{
	if (begin2 == end2)
		return end;
	Iterator_first ret = end;
	while (begin != end)
	{
		Iterator_first it1 = begin;
		Iterator_second it2 = begin2;
		while (*it1 == *it2)
		{
			++it1;
			++it2;
			if (it2 == end2) {
				ret = begin;
				break;
			}
			if (it1 == end) {
				return ret;
			}
		}
		++begin;
	}
	return ret;
}

bool myfunction(int i, int j)
{
	return (i == j);
}

int main()
{
	int my_int[] = { 3, 2, 3, 4, 5, 1,2,3,1,2 };
	std::vector<int> haystack(my_int, my_int + 10);
	int needle1[] = { 1,2,3 };

	std::vector<int>::iterator it;
	it = std::find_end(haystack.begin(), haystack.end(), needle1, needle1 + 3);
	//it = Find_end(haystack.begin(), haystack.end(), needle1, needle1 + 3);
	if (it != haystack.end())
		std::cout << "在my_int中出项needle1最后的位置：" << (it - haystack.begin()) << std::endl;
	int needle2[] = { 4,5,1 };
	it = std::find_end(haystack.begin(), haystack.end(), needle2, needle2 + 3, myfunction);
	if (it != haystack.end())
		std::cout << "needle2最后出项在：" << (it - haystack.begin()) << std::endl;
	system("pause");
	return 0;
}