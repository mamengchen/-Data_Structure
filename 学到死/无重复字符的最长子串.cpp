//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//示例 1:
//输入: "abcabcbb"
//	输出 : 3
//	解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//	示例 2 :
//	输入 : "bbbbb"
//	输出 : 1
//	解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//	示例 3 :
//	输入 : "pwwkew"
//	输出 : 3
//	解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//	请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

想法：利用map，key存放字符，value存在这个字符的在以前i的位置。


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> my_map;
		std::pair<map<char, int>::iterator, bool> my_judge;
		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			my_judge = my_map.insert(std::pair<char, int>(s[i], i));
			if (my_judge.second == false)
			{
				if (count < my_map.size())
				{
					count = my_map.size();
				}
				i = my_judge.first->second;
				my_map.clear();
			}
		}
		if (count < my_map.size())
		{
			count = my_map.size();
		}
		return count;
	}
};