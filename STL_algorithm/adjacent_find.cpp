//#2:adjacent_find
//���ã�������������(adjacent)�ĵȼ�(Indentical)Ԫ��
#include <iostream>
#include <algorithm>
#include <vector>

/*ģ��ʵ��*/
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

//ʵ��
bool myfunction(int first, int second)
{
	return (first == second);
}

int main()
{
	int my_int[] = { 5,20,5,30,30,20,10,10,20 };
	std::vector<int> my_vector(my_int, my_int + 8);
	std::vector<int>::iterator it;

	//ʹ��Ĭ�ϱȽ�
	it = std::adjacent_find(my_vector.begin(), my_vector.end());
	if (it != my_vector.end())
		std::cout << "��һ���ظ���Ԫ���ǣ�" << *it << std::endl;

	it = std::adjacent_find(++it, my_vector.end(), myfunction);
	if (it != my_vector.end())
		std::cout << "�ڶ����ظ���Ԫ���ǣ�" << *it << std::endl;
	return 0;
}
