//����һ��ֻ���� '(' �� ')' ���ַ������ҳ���İ�����Ч���ŵ��Ӵ��ĳ��ȡ�
//ʾ�� 1:
//����: "(()"
//	��� : 2
//	���� : ���Ч�����Ӵ�Ϊ "()"
//	ʾ�� 2 :
//	���� : ")()())"
//	��� : 4
//	���� : ���Ч�����Ӵ�Ϊ "()()"


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