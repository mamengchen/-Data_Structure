/*
����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
     ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
	 ����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
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