给定一个没有重复数字的序列，返回其所有可能的全排列。

示例 :

输入: [1, 2, 3]
	输出 :
	[
		[1, 2, 3],
		[1, 3, 2],
		[2, 1, 3],
		[2, 3, 1],
		[3, 1, 2],
		[3, 2, 1]
	]

	class Solution {
	public:
		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> result;
			allsort(result, 0, nums);
			return result;
		}

		void allsort(vector<vector<int>> &result, int k, vector<int> &nums)
		{
			if (nums.size() == k)
			{
				result.push_back(nums);
				return;
			}

			for (int i = k; i < nums.size(); i++)
			{
				swap(nums[i], nums[k]);
				allsort(result, k + 1, nums);
				swap(nums[i], nums[k]);
			}
		}
	};


	void dfs(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, vector<int> &index) {

		if (temp.size() == nums.size()) {
			ans.push_back(temp);
			return;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			if (index[i] == 0) continue;  //出现过了，直接跳过  
			temp.push_back(nums[i]);
			index[i] = 0;
	    	dfs(ans, temp, nums, index);
			temp.pop_back();  //递归前修改,递归后恢复  
			index[i] = 1;  //递归前修改,递归后恢复  
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> temp;
		vector<int> index(nums.size(), 1);//true表示没有出现过,false表示已经出现过了.  
		dfs(ans, temp, nums, index);
		return ans;
	}


