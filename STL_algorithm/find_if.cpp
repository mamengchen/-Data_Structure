//#10��find_if
//���ã����ص�һ��ֵ�������������Ԫ��
#include <iostream>     
#include <algorithm>    
#include <vector>     


/*ģ��*/
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
	std::cout << "��һ�������������ڣ�" << *it << std::endl;
	return 0;
}