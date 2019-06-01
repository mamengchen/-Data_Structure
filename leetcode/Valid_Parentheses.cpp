/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
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