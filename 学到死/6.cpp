/*
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
	 输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int>m;
		int maxLen = 0;
		int lastRepeatPos = -1;
		for (int i = 0; i < s.size(); i++)
		{
			if (m.find(s[i]) != m.end() && lastRepeatPos < m[s[i]])
			{
				lastRepeatPos = m[s[i]];
			}
			if (i - lastRepeatPos > maxLen)
			{
				maxLen = i - lastRepeatPos;
			}

			m[s[i]] = i;
		}
		return maxLen;
	}
};