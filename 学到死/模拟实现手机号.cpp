//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//示例 :
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


class Solution {
public:
	vector<string> letterCombinations(string digits) {
		unordered_map<char, string> table{
			{'0', " "}, {'1', "*"}, {'2', "abc"},
			{'3', "def"}, {'4',"ghi"}, {'5', "jkl"},
			{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},
			{'9', "wxyz"}
		};
		vector<string> res;
		if (digits == "") return res;
		func(res, "", digits, table, 0);
		return res;
	}

	void func(vector<string> &res, string str, string &digits, unordered_map<char, string> &table, int k)
	{
		if (str.size() == digits.size())
		{
			res.push_back(str);
			return;
		}
		string tmp = table[digits[k]];
		for (char w : tmp)
		{
			str += w;
			func(res, str, digits, table, k + 1);
			str.pop_back();
		}
		return;
	}
};