//某人有8 角的邮票5 张，1 元的邮票4 张，
//1 元8 角的邮票6 张，用这些邮票中的一张或若干张可以得到多少中不同的邮资？

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int eight_num;
	int ten_num;
	vector<int> count;
	for (eight_num = 0; eight_num < 11; eight_num++)
	{
		for (ten_num = 0; ten_num < 10; ten_num++)
		{
			if ((eight_num - ten_num) >= 6 || (ten_num - eight_num) >= 5)
			{
				break;
			}
			vector<int>::iterator p;
			for (p = count.begin(); p != count.end(); p++)
			{
				if (*p == (10 * ten_num + 8 * eight_num))
				{
					break;
				}
			}
			count.push_back(10 * ten_num + 8 * eight_num);
		}
	}
	cout << count.size() << endl;
	system("pause");
	return 0;
}