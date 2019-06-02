//给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
//示例 1:
//输入: "(()"
//	输出 : 2
//	解释 : 最长有效括号子串为 "()"
//	示例 2 :
//	输入 : ")()())"
//	输出 : 4
//	解释 : 最长有效括号子串为 "()()"


class Solution {
public:
	int longestValidParentheses(string s) {
		std::stack<int> my_stack;
		std::vector<bool> result(s.size(), false);
		int max_number = 0;
		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ')')
			{
				if (!my_stack.empty())
				{
					result[my_stack.top()] = true;
					result[i] = true;
					my_stack.pop();
				}
			}
			else
			{
				my_stack.push(i);
			}
		}
		for (int i = 0; i < result.size(); i++)
		{
			if (result[i])
			{
				count++;
				max_number = max(count, max_number);
			}
			else
			{
				count = 0;
			}
		}
		return max_number;
	}
};