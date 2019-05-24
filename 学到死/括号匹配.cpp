//给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//例如，给出 n = 3，生成结果为：
//[
//	"((()))",
//	"(()())",
//	"(())()",
//	"()(())",
//	"()()()"
//]

class Solution {
public:
	string tmp = "";
	vector<string> vec;
	void dfs(int l, int r)
	{
		if (l == 0 && r == 0)
		{
			vec.push_back(tmp);
		}
		if (l > 0)
		{
			tmp += '(';
			dfs(l - 1, r);
			tmp.pop_back();
		}
		if (r > l)
		{
			tmp += ')';
			dfs(l, r - 1);
			tmp.pop_back();
		}
	}
	vector<string> generateParenthesis(int n) {
		dfs(n, n);
		return vec;
	}
};
