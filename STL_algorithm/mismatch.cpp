//#13��mismatch
//���ã�����������Χ�е�һ��Ԫ�ز��ȼ۵�λ��
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

/* ģ�� */
template <class Iterator1, class Iterator2>
std::pair<Iterator1, Iterator2>
My_mismatch(Iterator1 first, Iterator1 last, Iterator2 first2)
{
	while ((first != last) && (*first = *first2))
	{
		++first;
		++first2;
	}
	return std::make_pair(first, first2);
}

bool mypredicate(int i, int j)
{
	return (i == j);
}

int main()
{
	std::vector<int> my_vector;
	for (int i = 1; i < 6; i++)
		my_vector.push_back(i * 10);
	int my_ints[] = { 10, 20, 30, 80, 1024 };
	std::pair<std::vector<int>::iterator, int*>my_pair;

	my_pair = std::mismatch(my_vector.begin(), my_vector.end(), my_ints);
	std::cout << "��һ����ȵ�Ԫ�� " << *my_pair.first;
	std::cout << " and " << *my_pair.second << std::endl;

	++my_pair.first;
	++my_pair.second;
	my_pair = std::mismatch(my_pair.first, my_vector.end(), my_pair.second, mypredicate);
	std::cout << "�ڶ�������ȵ�Ԫ�� " << *my_pair.first;
	std::cout << " and " << *my_pair.second << std::endl;
	system("pause");
	return 0;
}