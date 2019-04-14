//#5��count_if
//���ã�����ֵ�������������Ԫ�صĸ���
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*ģ��*/
template <class Iterator, class Function>
int Count_if(Iterator first, Iterator end, Function pred)
{
	int ret = 0;
	while (first != end)
	{
		if (pred(*first))
			++ret;
		++first;
	}
	return ret;
}

bool IsOdd(int i)
{
	return ((i % 2) == 1);
}

int main()
{
	vector<int> my_vector;
	for (int i = 1; i < 10; i++)
		my_vector.push_back(i);
	int my_count = Count_if(my_vector.begin(), my_vector.end(), IsOdd);
	cout << "vector�������ĸ�����" << my_count << endl;
	system("pause");
	return 0;
}