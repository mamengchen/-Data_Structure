//ĳ����8 �ǵ���Ʊ5 �ţ�1 Ԫ����Ʊ4 �ţ�
//1 Ԫ8 �ǵ���Ʊ6 �ţ�����Щ��Ʊ�е�һ�Ż������ſ��Եõ������в�ͬ�����ʣ�

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