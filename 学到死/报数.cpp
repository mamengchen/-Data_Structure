//报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 被读作  "one 1"  ("一个一"), 即 11。
//11 被读作 "two 1s" ("两个一"）, 即 21。
//	21 被读作 "one 2", "one 1" （"一个二", "一个一"), 即 1211。
//	给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
//	注意：整数顺序将表示为一个字符串。
//
//	示例 1:
//输入: 1
//	输出 : "1"
//	示例 2 :
//	输入 : 4
//	输出 : "1211"

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