//����������һ���������У��������е�������˳����б������õ���һ��������ǰ�������£�
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 ������  "one 1"  ("һ��һ"), �� 11��
//11 ������ "two 1s" ("����һ"��, �� 21��
//	21 ������ "one 2", "one 1" ��"һ����", "һ��һ"), �� 1211��
//	����һ�������� n��1 �� n �� 30��������������еĵ� n �
//	ע�⣺����˳�򽫱�ʾΪһ���ַ�����
//
//	ʾ�� 1:
//����: 1
//	��� : "1"
//	ʾ�� 2 :
//	���� : 4
//	��� : "1211"

class Solution {
public:

	string MyConverToStr(char obj)
	{
		stringstream ss;
		ss << obj;
		return ss.str();
	}

	string MyConverToStr1(int obj)
	{
		stringstream ss;
		ss << obj;
		return ss.str();
	}

	string countAndSay(int n) {
		if (n == 1)
		{
			return "1";
		}
		if (n == 2)
		{
			return "11";
		}
		string s = "";
		if (n > 1)
		{
			s = countAndSay(n - 1);
		}
		int temp = 1;
		char c = s[(s.size() - 1)];
		string my_str;
		for (int i = s.size() - 2; i >= 0; i--)
		{
			if (c == s.at(i))
			{
				temp++;
			}
			if (c != s.at(i))
			{
				string s1, s2;
				s1 = MyConverToStr(c);
				s2 = MyConverToStr1(temp);
				my_str.insert(0, s1);
				my_str.insert(0, s2);
				temp = 1;
				c = s.at(i);
			}
			if (i == 0)
			{
				string s1, s2;
				s1 = MyConverToStr(c);
				s2 = MyConverToStr1(temp);
				my_str.insert(0, s1);
				my_str.insert(0, s2);
			}
		}
		return my_str;
	}
};