//给定一个字符串(s) 和一个字符模式(p)。实现支持 '.' 和 '*' 的正则表达式匹配。
//'.' 匹配任意单个字符。
//'*' 匹配零个或多个前面的元素。
//匹配应该覆盖整个字符串(s) ，而不是部分字符串。
//说明 :
//s 可能为空，且只包含从 a - z 的小写字母。
//p 可能为空，且只包含从 a - z 的小写字母，以及字符.和 *。
//示例 1 :
//	输入 :
//	s = "aa"
//	p = "a"
//	输出 : false
//	解释 : "a" 无法匹配 "aa" 整个字符串。
//	示例 2 :
//	输入 :
//	s = "aa"
//	p = "a*"
//	输出 : true
//	解释 : '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
//	示例 3 :
//	输入 :
//	s = "ab"
//	p = ".*"
//	输出 : true
//	解释 : ".*" 表示可匹配零个或多个('*')任意字符('.')。
//	示例 4 :
//	输入 :
//	s = "aab"
//	p = "c*a*b"
//	输出 : true
//	解释 : 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
//	示例 5 :
//	输入 :
//	s = "mississippi"
//	p = "mis*is*p*."
//	输出 : false


使用循环：
bool isMatch(string s, string p) {
	vector<vector<int>>results(p.size() + 1, vector<int>(s.size() + 1, 0));
	results[0][0] = 1;
	for (size_t i = 1; i <= p.size(); ++i) {
		results[i][0] = p[i - 1] == '*' ? results[i - 2][0] : 0;
		for (size_t j = 1; j <= s.size(); ++j) {
			if (p[i - 1] == '*') {
				if (s[j - 1] != p[i - 2] && p[i - 2] != '.') {
					results[i][j] = results[i - 2][j]; //相当于*一次都不用
				}
				else {
					results[i][j] = results[i - 2][j] || results[i - 1][j] || results[i][j - 1]; //*一次都不用或者用一次或者用多次
				}
			}
			else if (p[i - 1] == '.' || p[i - 1] == s[j - 1]) {
				results[i][j] = results[i - 1][j - 1]; // 逐个比较
			}
		}
	}
	return results[p.size()][s.size()];
}

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

		if (p.length() >= 2 && p[1] == '*')
		{
			return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
		}
		else
		{
			return first_match && isMatch(s.substr(1), p.substr(1));
		}
	}
};

//优化版
class Solution {
public:
	bool isMatch(string s, string p) {
		return isMatch(s.c_str(), p.c_str());
	}

	bool isMatch(const char* s, const char* p) {
		if (*p == 0) return *s == 0;

		auto first_match = *s && (*s == *p || *p == '.');

		if (*(p + 1) == '*') {
			return isMatch(s, p + 2) || (first_match && isMatch(++s, p));
		}
		else {
			return first_match && isMatch(++s, ++p);
		}
	}
};