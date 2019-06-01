//给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n / 2 ⌋ 的元素。
//你可以假设数组是非空的，并且给定的数组总是存在众数。
//示例 1:
//输入: [3, 2, 3]
//	输出 : 3
//	示例 2 :
//	输入 : [2, 2, 1, 1, 1, 2, 2]
//	输出 : 2


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> my_map;
		std::pair<map<int, int>::iterator, bool> judge;
		for (int i = 0; i < nums.size(); i++)
		{
			judge = my_map.insert(std::pair<int, int>(nums[i], 1));
			if (!judge.second)
			{
				(judge.first->second)++;
			}
		}

		map<int, int>::iterator iter = my_map.begin();
		int data = iter->first;
		int max = iter->second;
		for (; iter != my_map.end(); )
		{

			if (iter->second >= max)
			{
				data = iter->first;
				max = iter->second;
			}
			iter++;
		}
		return data;
	}
};