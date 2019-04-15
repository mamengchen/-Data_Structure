//#7��find
//���ã����ص�һ��ֵ�ȼ��ڸ���ֵ��Ԫ��
#include <iostream>
#include <algorithm>
#include <vector>

/*ģ��*/
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
		std::cout << "�ҵ�����������ֵ��" << *p << std::endl;
	else
		std::cout << "û�ҵ�����������ֵ��" << std::endl;

	std::vector<int> my_vector(my_int, my_int + 4);
	std::vector<int>::iterator it;

	it = Find(my_vector.begin(), my_vector.end(), 30);
	if (it != my_vector.end())
		std::cout << "�ҵ�����������ֵ��" << *it << std::endl;
	else
		std::cout << "û�ҵ�����������ֵ��";
	system("pause");
	return 0;
}