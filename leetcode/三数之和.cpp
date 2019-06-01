//����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣
//ע�⣺���в����԰����ظ�����Ԫ�顣
//����, �������� nums = [-1, 0, 1, 2, -1, -4]��
//
//����Ҫ�����Ԫ�鼯��Ϊ��
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