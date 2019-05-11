/*���磬 �������� 2 д�� II ����Ϊ�������е� 1��12 д�� XII ����Ϊ X + II �� 27 д��  XXVII, ��Ϊ XX + V + II ��
ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������
I ���Է��� V(5) �� X(10) ����ߣ�����ʾ 4 �� 9��
X ���Է��� L(50) �� C(100) ����ߣ�����ʾ 40 �� 90��
C ���Է��� D(500) �� M(1000) ����ߣ�����ʾ 400 �� 900��
����һ���������֣�����ת��������������ȷ���� 1 �� 3999 �ķ�Χ�ڡ�
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