//ʵ�� strStr() ������
//����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ��(��0��ʼ)����������ڣ��򷵻� - 1��
//ʾ�� 1:
//����: haystack = "hello", needle = "ll"
//	��� : 2
//	ʾ�� 2 :
//	���� : haystack = "aaaaa", needle = "bba"
//	��� : -1

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
		{
			return 0;
		}
		return haystack.find(needle);
	}
};