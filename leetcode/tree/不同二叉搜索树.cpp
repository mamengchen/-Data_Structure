当给予的整数大于1时，以i为根的二叉树有（i - 1）*（n - i）个n为给的总数这样我们可以得到
一个方程式：
f（0） = 1
f（1） = 1
f（n） = 求和符合i = 1到n f(i - 1)*f(n - i);
我们可以写出以下递归代码：
class Solution {
	int numTrees(n)
	{
		if (n == 0 || n == 1)
			return 1;
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			res += numTrees(i - 1)*numTrees(n - i);
		}
		return res;
	}
};

但是这个有好多重复的计算需要多次进行所有我们可以使用记忆搜索，提高代码效率
class Solution {
public:
	int numTrees(int n) {
		vector<int> my_vec(n + 1, 0);
		my_vec[0] = 1;
		my_vec[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				my_vec[i] += my_vec[j - 1] * my_vec[i - j];
			}
		}
		return my_vec[n];
	}
};