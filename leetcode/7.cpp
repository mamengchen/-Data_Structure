/*例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V(5) 和 X(10) 的左边，来表示 4 和 9。
X 可以放在 L(50) 和 C(100) 的左边，来表示 40 和 90。
C 可以放在 D(500) 和 M(1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <utility>
#include <algorithm>
#include <stdlib.h> 
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		map<char, int> my_map;
		char key;
		int value = 0;
		int old_value = 0;
		int sum = 0;
		my_map.insert(std::pair<char, int>('I', 1));
		my_map.insert(std::pair<char, int>('V', 5));
		my_map.insert(std::pair<char, int>('X', 10));
		my_map.insert(std::pair<char, int>('L', 50));
		my_map.insert(std::pair<char, int>('C', 100));
		my_map.insert(std::pair<char, int>('D', 500));
		my_map.insert(std::pair<char, int>('M', 1000));
		while (s.size())
		{
			key = s.back();
			value = my_map.find(key)->second;
			if (value >= old_value)
			{
				old_value = value;
				sum = sum + value;
			}
			else
			{
				sum = sum - value;
			}
			s.pop_back();
		}
		return sum;
	}
};


int main()
{
	string str = "LVIII";
	int tr;
	Solution s1;
	tr = s1.romanToInt(str);
	cout << tr << endl;
	system("pause");
	return 0;
}