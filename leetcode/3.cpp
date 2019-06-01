//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序
//。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		bool pd = false;
		int i = 0;
		int array_size = array.size();
		while (i < array_size)
		{
			if (target > array[i][array[i].size() - 1])
			{
				i++;
			}
			else {
				int size = array[i].size();
				for (int j = 0; j < size; j++)
				{
					if (target == array[i][j])
					{
						pd = true;
						break;
					}
				}
				break;
			}
		}
		return pd;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> q;
	vector<int> num1;
	num1.push_back(1);
	num1.push_back(2);
	num1.push_back(3);
	num1.push_back(4);
	vector<int> num2;
	num2.push_back(5);
	num2.push_back(6);
	num2.push_back(7);
	num2.push_back(8);
	q.push_back(num1);
	q.push_back(num2);
	bool t = s.Find(6, q);

	cout << q[0].size() << endl;
	cout << q.size() << endl;
	return 0;
}