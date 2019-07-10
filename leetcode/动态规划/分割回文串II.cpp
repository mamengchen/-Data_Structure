class Solution {
public:
	int minCut(string s) {
		if (s.empty())
			return 0;
		vector<int> cnt(s.size() + 1, 0);
		vector<vector<bool>> my_vec(s.size(), vector<bool>(s.size(), false));
		for (int i = s.size() - 1; i >= 0; i--)
		{
			for (int j = i; j < s.size(); j++)
			{
				if (j == i)
				{
					my_vec[i][j] = true;
				}
				else if (j == i + 1)
				{
					my_vec[i][j] = s[i] == s[j];
				}
				else
				{
					if (my_vec[i + 1][j - 1] && s[i] == s[j])
					{
						my_vec[i][j] = true;
					}
				}
			}
		}
		for (int i = 0; i < cnt.size(); i++)
		{
			cnt[i] = i - 1;
		}

		for (int i = 1; i < cnt.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (my_vec[j][i - 1])
					cnt[i] = min(cnt[i], 1 + cnt[j]);
			}
		}
		return cnt[s.size()];
	}
};