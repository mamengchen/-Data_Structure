//����һ���ַ���(s) ��һ���ַ�ģʽ(p)��ʵ��֧�� '.' �� '*' ��������ʽƥ�䡣
//'.' ƥ�����ⵥ���ַ���
//'*' ƥ���������ǰ���Ԫ�ء�
//ƥ��Ӧ�ø��������ַ���(s) �������ǲ����ַ�����
//˵�� :
//s ����Ϊ�գ���ֻ������ a - z ��Сд��ĸ��
//p ����Ϊ�գ���ֻ������ a - z ��Сд��ĸ���Լ��ַ�.�� *��
//ʾ�� 1 :
//	���� :
//	s = "aa"
//	p = "a"
//	��� : false
//	���� : "a" �޷�ƥ�� "aa" �����ַ�����
//	ʾ�� 2 :
//	���� :
//	s = "aa"
//	p = "a*"
//	��� : true
//	���� : '*' �����ƥ���������ǰ���Ԫ��, ������ƥ�� 'a' �����, �ظ� 'a' һ��, �ַ����ɱ�Ϊ "aa"��
//	ʾ�� 3 :
//	���� :
//	s = "ab"
//	p = ".*"
//	��� : true
//	���� : ".*" ��ʾ��ƥ���������('*')�����ַ�('.')��
//	ʾ�� 4 :
//	���� :
//	s = "aab"
//	p = "c*a*b"
//	��� : true
//	���� : 'c' ���Բ����ظ�, 'a' ���Ա��ظ�һ�Ρ���˿���ƥ���ַ��� "aab"��
//	ʾ�� 5 :
//	���� :
//	s = "mississippi"
//	p = "mis*is*p*."
//	��� : false


ʹ��ѭ����
bool isMatch(string s, string p) {
	vector<vector<int>>results(p.size() + 1, vector<int>(s.size() + 1, 0));
	results[0][0] = 1;
	for (size_t i = 1; i <= p.size(); ++i) {
		results[i][0] = p[i - 1] == '*' ? results[i - 2][0] : 0;
		for (size_t j = 1; j <= s.size(); ++j) {
			if (p[i - 1] == '*') {
				if (s[j - 1] != p[i - 2] && p[i - 2] != '.') {
					results[i][j] = results[i - 2][j]; //�൱��*һ�ζ�����
				}
				else {
					results[i][j] = results[i - 2][j] || results[i - 1][j] || results[i][j - 1]; //*һ�ζ����û�����һ�λ����ö��
				}
			}
			else if (p[i - 1] == '.' || p[i - 1] == s[j - 1]) {
				results[i][j] = results[i - 1][j - 1]; // ����Ƚ�
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

//�Ż���
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