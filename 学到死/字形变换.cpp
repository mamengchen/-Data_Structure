//��һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������С�
//���������ַ���Ϊ "LEETCODEISHIRING" ����Ϊ 3 ʱ���������£�
//L   C   I   R
//E T O E S I I G
//E   D   H   N
//֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"LCIRETOESIIGEDHN"��
//����ʵ��������ַ�������ָ�������任�ĺ�����
//string convert(string s, int numRows);
//ʾ�� 1:
//����: s = "LEETCODEISHIRING", numRows = 3
//	��� : "LCIRETOESIIGEDHN"
//	ʾ�� 2 :
//	���� : s = "LEETCODEISHIRING", numRows = 4
//	��� : "LDREOEIIECIHNTSG"
//	���� :
//
//	L     D     R
//	E   O E   I I
//	E C   I H   N
//	T     S     G


class Solution {
public:
	string convert(string s, int numRows) {
		string ans;
		int n = 0; // �ַ�������λ��
		vector<string> res(numRows); //������������
		if (s.empty()) return ans;
		while (1) {
			int x = 0; //���±���x
			while (x < numRows && n < s.size()) { //��ֱ���±���numRowsλ
				res[x++].push_back(s[n++]);
			}
			x--; // �ָ������һ�е�λ��
			while (x > 1 && n < s.size()) { //���ϱ���numRows-2λ
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

//��һ�ַ�ʽ���ǰ����ֳ�numRows������ÿ���Ǹ������Ǹ������оͿ�����
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