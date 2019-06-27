给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例 :

输入: [1, 1, 2]
	输出 :
	[
		[1, 1, 2],
		[1, 2, 1],
		[2, 1, 1]
	]

	class Solution {
	public:
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			vector<vector<int>> res;
			if (nums.size() == 0)
			{
				return res;
			}
			allsortII(res, 0, nums);
			return res;
		}

		void allsortII(vector<vector<int>> &res, int k, vector<int> &nums)
		{
			if (nums.size() == k)
			{
				res.push_back(nums);
				return;
			}
			else
			{
				std::set<int> rp;
				for (int i = k; i < nums.size(); i++)
				{
					if (rp.find(nums[i]) != rp.end()) continue;
					rp.insert(nums[i]);
					swap(nums[i], nums[k]);
					allsortII(res, k + 1, nums);
					swap(nums[i], nums[k]);
				}
			}
		}
	};