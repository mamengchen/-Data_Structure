//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//
//如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//
//必须原地修改，只允许使用额外常数空间。
//
//以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
//1, 2, 3 → 1, 3, 2
//3, 2, 1 → 1, 2, 3
//1, 1, 5 → 1, 5, 1

第一种解放是一种O（n平方）时间复杂度的方法
输入初始排序的数组{
	   1.如果数组长度为1或者为0
			  直接返回数组
	   2.如果数组长度为2
			  直接交换数组中两个值的位置
			  返回交换后的数组
	   3.从最后一个值开始向前查找（循环1）
				 如果[这个值]比[前一个值]大（判断）
						从最后往前查找截止到[这个值]（循环2）
								   如果出现有值大于[前一个值]（判断）
										   交换这两个值的位置
										   跳出循环2
						遍历这个值的后一个值到末位（循环）
								数字从两边分别交换数值，一直到中间
						返回数组
	   4.排除前面三种情况，说明排序已经是从前往后是最大值
		  遍历从前到中间的位置(循环)
				 数字从两边分别交换数值，一直到中间
		  返回数组
}
class Slotion {
public:
	void mmmm(vector<int>& nums)
	{
		if (nums.size() == 1 || nums.size() == 0)
		{
			return;
		}
		if (nums.size() == 2)
		{
			swap(nums[0], nums[1]);
			return;
		}
		for (int i = nums.size() - 1; i > 0; i--)
		{
			if (nums[i] > nums[i - 1])
			{
				for (int j = nums.size() - 1; j >= i; j--)
				{
					if (nums[j] > nums[i - 1])
					{
						swap(nums[i - 1], nums[j]);
						break;
					}
				}
				for (int j = 0; j < (nums.size() - i) / 2; j++)
				{
					swap(nums[i + j], nums[nums.size() - j - 1]);
				}
				return;
			}
		}
		for (int j = 0; j < nums.size() / 2; j++)
			swap(nums[j], nums[nums.size() - j - 1]);
		return;
	}
};


第二种解法：
1.从后往向前找，找到后数比前数大的情况，记住这个值，结束循环
2.从最后往前找，在第一个出现比这个值大的情况，交换这两个值。
3.将这个值之后的数组倒序排列，
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 2, j = nums.size() - 1;
		while (i >= 0 && nums[i] >= nums[i + 1])
			--i;
		if (i >= 0)
		{
			while (nums[j] <= nums[i])
			{
				j--;
			}
			swap(nums[j], nums[i]);
		}
		reverse(nums.begin() + i + 1, nums.end());
	}
};