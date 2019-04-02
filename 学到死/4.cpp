/*
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) == m.end())
			{
				m[target - nums[i]] = i;
			}
			else {
				result.push_back(m[nums[i]] + 1);
				result.push_back(i + 1);
				break;
			}
		}
		return result;
	}
};