//���ǽ����������� A �ֳ� K �����ڵķǿ������� �����ǵķ�����ÿ���������ڵ�ƽ��ֵ���ܺ͹��ɡ������������ܵõ����������Ƕ��١�
//ע�����Ǳ���ʹ�� A �����е�ÿһ�������з��飬���ҷ�����һ����Ҫ��������
//ʾ�� :
//����:
//A = [9, 1, 2, 3, 9]
//K = 3
//��� : 20
//	���� :
//	A �����ŷ�����[9], [1, 2, 3], [9].�õ��ķ����� 9 + (1 + 2 + 3) / 3 + 9 = 20.
//	����Ҳ���԰� A �ֳ�[9, 1], [2], [3, 9].
//	�����ķ���õ��ķ���Ϊ 5 + 2 + 6 = 13, ���������ֵ.
//	˵�� :
//	1 <= A.length <= 100.
//	1 <= A[i] <= 10000.
//	1 <= K <= A.length.
//	������� 10 ^ -6 �ڱ���Ϊ����ȷ�ġ�



#include<iostream>
#include<vector>
using namespace std;

double max(double x, double y)
{
	if (x < y)
		return y;
	return x;
}
class Solution {
public:
	double largestSumOfAverages(vector<int>& A, int K) {
		int Asize = A.size();
		vector<int> my_vec(Asize + 1, 0);
		for (int i = 1; i <= Asize; i++)
		{
			my_vec[i] = my_vec[i - 1] + A[i - 1];
		}
		vector<vector<double>> my_dp(Asize + 1, (vector<double>(K + 1, 0)));
		for (int i = 1; i <= Asize; i++)
		{
			my_dp[i][1] = my_vec[i] * 1.0 / i;
			for (int k = 2; k <= K && k <= i; k++)
			{
				for (int j = 1; j < i; j++)
				{
					my_dp[i][k] = max(my_dp[i][k], my_dp[j][k - 1] + 1.0*(my_vec[i] - my_vec[j]) / (i - j));
				}
			}
		}
		return my_dp[Asize][K];
	}
};

int main()
{
	Solution ss;
	vector<int> my_vec{ 9,1,2,3,9 };
	ss.largestSumOfAverages(my_vec, 3);
	system("pause");
	return 0;
}