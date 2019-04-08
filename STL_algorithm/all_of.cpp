#include <iostream>
#include <algorithm>
#include <array>

//#1:all_of
//���ã�����ڸ�����Χ���Ƿ�����Ԫ��
//		���������������

/*ģ��ʵ��*/
template<class Iterator, class Lambda>
bool my_All_of(Iterator first, Iterator last, Lambda pred)
{
	while (first != last)
	{
		if (!pred(*first))
			return false;
		++first;
	}
	return true;
}

//ʵ����

int main()
{
	std::array<int, 6> foo = { 3,5,7,9,11,13 };
	if (my_All_of(foo.begin(), foo.end(),
		[](int i) {return i % 2; }))
		std::cout << "�����������ȫ������" << std::endl;
	return 0;
}