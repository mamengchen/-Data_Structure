//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
//注意：答案中不可以包含重复的三元组。
//例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) return {};
		set<vector<int>> result;
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (int j = 1, i, k; j < nums.size() - 1; ++j)
		{
			i = 0;
			k = nums.size() - 1;
			while (i < j && j < k)
			{
				sum = nums[i] + nums[j] + nums[k];
				if (sum == 0)
				{
					result.insert({ nums[i], nums[j], nums[k] });
					i++;
					if (nums[i] == nums[k]) break;
				}
				else if (sum > 0) k--;
				else if (sum < 0) i++;
			}
		}
		return vector<vector<int>>(result.begin(), result.end());
	}
};