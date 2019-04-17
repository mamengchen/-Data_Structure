//#9��find_first_of
//���ã����ҷ�Χ A �е�һ���뷶Χ B ����һԪ�صȼ۵�Ԫ�ص�λ��
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype> //ʹ�����е�tolower�������ַ�ת��Сд�ַ�

/*ģ��*/
template<class Iterator, class ForIterator>
Iterator Find_first_of(Iterator first1, Iterator last1,
	ForIterator first2, ForIterator last2)
{
	while (first1 != last1)
	{
		for (ForIterator it = first2; it != last2; it++)
		{
			if (*it = *first1)
				return first1;
		}
		++first1;
	}
	return last1;
}



bool comp_case_insensitive(char c1, char c2)
{
	return (std::tolower(c1) == std::tolower(c2));
}

int main()
{
	int my_char[] = { 'a', 'b', 'c', 'A', 'B','C' };
	std::vector<char> haystack(my_char, my_char + 6);
	std::vector<char>::iterator it;

	int needle[] = { 'A', 'B', 'C' };
	it = find_first_of(haystack.begin(), haystack.end(), needle, needle + 3);

	if (it != haystack.end())
		std::cout << "��һ�ν��Ϊ��" << *it << std::endl;

	it = find_first_of(haystack.begin(), haystack.end(),
		needle, needle + 3, comp_case_insensitive);

	if (it != haystack.end())
		std::cout << "��һ�γ��ֵĽ����" << *it << std::endl;
	return 0;
}