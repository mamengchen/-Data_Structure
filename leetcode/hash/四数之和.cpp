
����һ������ n ������������ nums ��һ��Ŀ��ֵ target���ж� nums ���Ƿ�����ĸ�Ԫ�� a��b��c �� d ��ʹ�� a + b + c + d ��ֵ�� target ��ȣ��ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺

���в����԰����ظ�����Ԫ�顣

ʾ����

�������� nums = [1, 0, -1, 0, -2, 2]���� target = 0��

����Ҫ�����Ԫ�鼯��Ϊ��
[
	[-1, 0, 0, 1],
	[-2, -1, 1, 2],
	[-2, 0, 0, 2]
]



class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> my_vec;
		int nums_size = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums_size - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < nums_size - 2; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int left = j + 1; int right = nums_size - 1;
				while (left < right)
				{
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target)
					{
						vector<int> vecint{ nums[i], nums[j], nums[left], nums[right] };
						my_vec.push_back(vecint);
						while (left < right && nums[left] == nums[left + 1]) ++left;
						while (left < right && nums[right] == nums[right - 1]) --right;
						++left;
						--right;
					}
					else if (sum < target)
					{
						++left;
					}
					else
					{
						--right;
					}
				}
			}
		}
		return my_vec;
	}
};