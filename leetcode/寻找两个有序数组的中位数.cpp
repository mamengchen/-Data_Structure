//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
//请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//你可以假设 nums1 和 nums2 不会同时为空。
//示例 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//则中位数是 2.0
//示例 2 :
//	nums1 = [1, 2]
//	nums2 = [3, 4]
//
//	则中位数是(2 + 3) / 2 = 2.5

一次二分的所需要的时间为logn ，两个同时二分则为log（n + m）

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() && !nums2.empty())
		{
			if (nums2.size() % 2 == 0)
				return (nums2[nums2.size() / 2 - 1] + nums2[nums2.size() / 2])*1.0 / 2;
			return nums2[nums2.size() / 2] * 1.0;
		}
		if (!nums1.empty() && nums2.empty())
		{
			if (nums1.size() % 2 == 0)
				return (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2])*1.0 / 2;
			return nums1[nums1.size() / 2] * 1.0;
		}
		int length1 = nums1.size();
		int length2 = nums2.size();
		int all_length = length1 + length2;
		int l = (all_length + 1) / 2;
		int r = (all_length + 2) / 2;
		return (getMin(nums1, 0, nums2, 0, l) + getMin(nums1, 0, nums2, 0, r))*1.0 / 2;
	}
	int getMin(vector<int> nums1, int nums1_stat, vector<int>nums2, int nums2_stat, int k)
	{
		if (nums1_stat > nums1.size() - 1)
		{
			return nums2[nums2_stat + k - 1];
		}
		if (nums2_stat > nums2.size() - 1)
		{
			return nums1[nums1_stat + k - 1];
		}
		if (k == 1)
		{
			return min(nums1[nums1_stat], nums2[nums2_stat]);
		}
		int Amin = INT_MAX;
		int Bmin = INT_MAX;
		if (nums1_stat + k / 2 - 1 < nums1.size())
		{
			Amin = nums1[nums1_stat + k / 2 - 1];
		}
		if (nums2_stat + k / 2 - 1 < nums2.size())
		{
			Bmin = nums2[nums2_stat + k / 2 - 1];
		}
		return Amin < Bmin ? getMin(nums1, nums1_stat + k / 2, nums2, nums2_stat, k - k / 2) : getMin(nums1, nums1_stat, nums2, nums2_stat + k / 2, k - k / 2);
	}
};