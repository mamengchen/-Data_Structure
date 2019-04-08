//#3:any_of
//���ã�����ڸ�����Χ���Ƿ����Ԫ�������������
#include <iostream>
#include <algorithm>
#include <array>

/*ģ��ʵ��*/
template<class Iterator, class Lambda>
bool any_of(Iterator first, Iterator end, Lambda pred)
{
	while (first != last)
	{
		if (pred(*first))
			return true;
		++first;
	}
	return false;
}

//ʵ��
int main()
{
	std::array<int, 7> foo = { 0,1,-1,3,-3,5,-5 };

	if (std::any_of(foo.begin(), foo.end()
		, [](int i) {return i < 0; }))
		std::cout << "��Χ���и�Ԫ�� \n";
	return 0;
}