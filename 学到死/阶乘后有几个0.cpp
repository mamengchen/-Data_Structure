//����һ������ n������ n!���β�������������
//ʾ�� 1:
//����: 3
//	��� : 0
//	���� : 3!= 6, β����û���㡣
//	ʾ�� 2 :
//	���� : 5
//	��� : 1
//	���� : 5!= 120, β������ 1 ����.

class Solution {
public:
	int trailingZeroes(int n) {
		int cnt = 0;
		while (n >= 5) {
			if (n % 5 != 0)
				n--;
			else {
				cnt += n / 5;
				n /= 5;
			}
		}
		return cnt;
	}
};