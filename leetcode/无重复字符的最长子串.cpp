//����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
//ʾ�� 1:
//����: "abcabcbb"
//	��� : 3
//	���� : ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
//	ʾ�� 2 :
//	���� : "bbbbb"
//	��� : 1
//	���� : ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
//	ʾ�� 3 :
//	���� : "pwwkew"
//	��� : 3
//	���� : ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
//	��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���

�뷨������map��key����ַ���value��������ַ�������ǰi��λ�á�


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