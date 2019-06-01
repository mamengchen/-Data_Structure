//����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
//ʾ�� :
//����: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
//	��� : 6
//	���� : ����������[4, -1, 2, 1] �ĺ����Ϊ 6��
//	���� :
//	������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int number = nums[0];
		int ret = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			number = max(nums[i], number + nums[i]);
			ret = max(ret, number);
		}
		return ret;
	}
};