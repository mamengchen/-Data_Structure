//将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
//比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
//L   C   I   R
//E T O E S I I G
//E   D   H   N
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
//请你实现这个将字符串进行指定行数变换的函数：
//string convert(string s, int numRows);
//示例 1:
//输入: s = "LEETCODEISHIRING", numRows = 3
//	输出 : "LCIRETOESIIGEDHN"
//	示例 2 :
//	输入 : s = "LEETCODEISHIRING", numRows = 4
//	输出 : "LDREOEIIECIHNTSG"
//	解释 :
//
//	L     D     R
//	E   O E   I I
//	E C   I H   N
//	T     S     G


class Solution {
public:
	string convert(string s, int numRows) {
		string ans;
		int n = 0; // 字符串遍历位置
		vector<string> res(numRows); //类似于拉链法
		if (s.empty()) return ans;
		while (1) {
			int x = 0; //上下遍历x
			while (x < numRows && n < s.size()) { //垂直向下遍历numRows位
				res[x++].push_back(s[n++]);
			}
			x--; // 恢复到最后一行的位置
			while (x > 1 && n < s.size()) { //向上遍历numRows-2位
				res[--x].push_back(s[n++]);
			}
			if (n == s.size())
				break;
		}
		for (int i = 0; i < numRows; i++) {
			ans += res[i];
		}
		return ans;
	}
};

//第一种方式就是把它分成numRows个数组每到那个放入那个数组中就可以了
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows >= s.size() || numRows == 1) return s;
		vector<vector<char>> my_vec;
		string vec;
		vector<char> vecc;
		int col = 0;
		int i = 0;
		vecc.push_back('0');
		for (int i = 0; i < numRows; i++)
		{
			my_vec.push_back(vecc);
		}
		while (1)
		{
			if (col % 2 == 0)
			{
				i = 0;
				while (i < numRows - 1)
				{
					if (s[i + (col) * (numRows - 1)] != '\0')
						my_vec[i].push_back(s[i + col * (numRows - 1)]);
					i++;
				}
			}
			else
			{
				i = numRows - 1;
				int j = 0;
				while (i > 0)
				{
					if (s[j + (col) * (numRows - 1)] != '\0')
						my_vec[i].push_back(s[j + col * (numRows - 1)]);
					i--;
					j++;
				}
			}
			if ((s.size() - (numRows - 1) * (col + 1)) < numRows)
			{
				break;
			}
			col++;
		}
		if ((col + 1) % 2 == 0)
		{
			for (int i = 0; i < s.size() - (numRows - 1) * (col + 1); i++)
			{
				if (s[i + (col + 1) * (numRows - 1)] != '\0')
					my_vec[i].push_back(s[i + (col + 1) * (numRows - 1)]);
			}
		}
		else
		{
			int j = 0;
			for (int i = numRows - 1; i > (numRows - 1) * (col + 2) - s.size(); i--)
			{
				if (s[j + (col + 1) * (numRows - 1)] != '\0')
					my_vec[i].push_back(s[j + (col + 1) * (numRows - 1)]);
				j++;
			}
		}
		for (int i = 0; i < numRows; i++)
		{
			vec.insert(vec.end(), my_vec[i].begin() + 1, my_vec[i].end());
		}
		return vec;
	}
};