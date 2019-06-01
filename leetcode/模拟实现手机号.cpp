//����һ������������ 2 - 9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
//
//ʾ�� :
//���룺"23"
//�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


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