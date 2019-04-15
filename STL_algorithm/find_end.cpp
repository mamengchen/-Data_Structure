//#8��find_end
//���ã����ҷ�ΧA���뷶ΧB�ȼ۵��ӷ�Χ�����ֵ�λ��
//���ǲ�����ȡ����һ���ּ�ǰ��һ���ֿ�����ȵ�
#include <iostream>
#include <algorithm>
#include <vector>

/*ģ��*/
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
		std::cout << "��my_int�г���needle1����λ�ã�" << (it - haystack.begin()) << std::endl;
	int needle2[] = { 4,5,1 };
	it = std::find_end(haystack.begin(), haystack.end(), needle2, needle2 + 3, myfunction);
	if (it != haystack.end())
		std::cout << "needle2�������ڣ�" << (it - haystack.begin()) << std::endl;
	system("pause");
	return 0;
}