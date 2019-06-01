/*编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1:
输入: ["flower", "flow", "flight"]
	输出 : "fl"
	示例 2 :
	输入 : ["dog", "racecar", "car"]
	输出 : ""
	解释 : 输入不存在公共前缀。
	说明 :
	所有输入只包含小写字母 a - z 。
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
		{
			return "";
		}
		if (strs.size() == 1)
		{
			return strs[0];
		}
		string my_str;
		int minlength = strs[0].size();
		for (int i = 1; i < strs.size(); i++)
		{
			if (strs[i].size() < minlength)
			{
				minlength = strs[i].size();
			}
		}
		for (int i = 0; i < minlength; i++)
		{
			int judge = 1;
			int j = 1;
			for (; j < strs.size(); j++)
			{
				if (strs[j][i] == strs[0][i])
				{
					judge++;
				}
			}
			if (judge != j || i + 1 == minlength)
			{
				if (i + 1 == minlength && judge == j)
				{
					i = i + 1;
				}
				string ss(strs[0].begin(), strs[0].begin() + i);
				my_str.insert(0, ss);
				break;
			}
		}
		return my_str;
	}
};