//���� n �����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ�����Ч��������ϡ�
//���磬���� n = 3�����ɽ��Ϊ��
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
