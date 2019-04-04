////vector迭代器失效问题
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//int main()
//{
//	int a[] = { 1, 2, 3, 4, };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	
//	//使用find查找3所在位置的iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//
//	//删除pos位置的数据，导致pos迭代器失效。
//	v.erase(pos);
//	cout << *pos << endl;  //此处会导致非法访问
//
//	//在pos位置插入数据，导致pos迭代器失效。
//	//insert会导致迭代器失效，是因为insert可能会导致增容，
//	//增容后pos还指向原来的空间，而原来的空间已经释放了。
//	pos = find(v.begin(), v.end(), 3);
//	v.insert(pos, 30);
//	cout << *pos << endl; //此处会导致非法访问
//
//	return 0;
//
//
//	system("pause");
//	return 0;
//}

//常见的迭代器失效的场景
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
			++it;
		}

		//以上程序要改成下面这样，erase会返回删除位置的下一个位置
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				v.erase(it);
			}
			++it;
		}

		//以上程序要改成下这样，erase会返回删除位置的下一个位置
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else {
				++it;
			}
		}
	}
	return 0;
}