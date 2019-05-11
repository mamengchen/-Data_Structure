/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <stdlib.h> 
using namespace std;


class Solution {
public:
	bool isValid(string s) {
		if (s.empty())
		{
			return true;
		}
		map<char, char> my_map;
		my_map.insert(std::pair<char, char>('(', ')'));
		my_map.insert(std::pair<char, char>('{', '}'));
		my_map.insert(std::pair<char, char>('[', ']'));
		stack<char> my_stack;
		for (int i = 0; i < s.size(); i++)
		{
			if (my_stack.empty())
			{
				my_stack.push(s[i]);
				continue;
			}
			if (my_map.find(my_stack.top())->second == s[i])
			{
				my_stack.pop();
			}
			else
			{
				my_stack.push(s[i]);
			}
		}
		if (my_stack.empty())
		{
			return true;
		}
		return false;
	}
};



int main()
{
	Solution s;
	bool tr;
	tr = s.isValid("()[]{}");
	cout << tr;
	system("pause");
	return 0;
}