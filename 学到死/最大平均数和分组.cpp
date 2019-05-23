//我们将给定的数组 A 分成 K 个相邻的非空子数组 ，我们的分数由每个子数组内的平均值的总和构成。计算我们所能得到的最大分数是多少。
//注意我们必须使用 A 数组中的每一个数进行分组，并且分数不一定需要是整数。
//示例 :
//输入:
//A = [9, 1, 2, 3, 9]
//K = 3
//输出 : 20
//	解释 :
//	A 的最优分组是[9], [1, 2, 3], [9].得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
//	我们也可以把 A 分成[9, 1], [2], [3, 9].
//	这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
//	说明 :
//	1 <= A.length <= 100.
//	1 <= A[i] <= 10000.
//	1 <= K <= A.length.
//	答案误差在 10 ^ -6 内被视为是正确的。



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