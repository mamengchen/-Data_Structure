���������������1ʱ����iΪ���Ķ������У�i - 1��*��n - i����nΪ���������������ǿ��Եõ�
һ������ʽ��
f��0�� = 1
f��1�� = 1
f��n�� = ��ͷ���i = 1��n f(i - 1)*f(n - i);
���ǿ���д�����µݹ���룺
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

��������кö��ظ��ļ�����Ҫ��ν����������ǿ���ʹ�ü�����������ߴ���Ч��
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