
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

(���磬����[0, 1, 2, 4, 5, 6, 7] ���ܱ�Ϊ[4, 5, 6, 7, 0, 1, 2])��

����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� - 1 ��

����Լ��������в������ظ���Ԫ�ء�

����㷨ʱ�临�Ӷȱ����� O(log n) ����

ʾ�� 1:

����: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
	��� : 4


	ʾ�� 2 :

	���� : nums = [4, 5, 6, 7, 0, 1, 2], target = 3
	��� : -1


class Solution {
	public:
		int search(vector<int>& nums, int target) {
			if (nums.size() == 0) return -1;
			int left = 0; int right = nums.size() - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (nums[mid] == target) return mid;
				else if (nums[mid] < nums[right])
				{
					if (nums[mid] < target && nums[right] >= target)
					{
						left = mid + 1;
					}
					else
					{
						right = mid - 1;
					}
				}
				else
				{
					if (nums[left] <= target && nums[mid] > target)
					{
						right = mid - 1;
					}
					else
					{
						left = mid + 1;
					}
				}
			}
			return -1;
		}
};

