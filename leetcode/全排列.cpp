����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�

ʾ�� :

����: [1, 2, 3]
	��� :
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
			if (index[i] == 0) continue;  //���ֹ��ˣ�ֱ������  
			temp.push_back(nums[i]);
			index[i] = 0;
	    	dfs(ans, temp, nums, index);
			temp.pop_back();  //�ݹ�ǰ�޸�,�ݹ��ָ�  
			index[i] = 1;  //�ݹ�ǰ�޸�,�ݹ��ָ�  
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> temp;
		vector<int> index(nums.size(), 1);//true��ʾû�г��ֹ�,false��ʾ�Ѿ����ֹ���.  
		dfs(ans, temp, nums, index);
		return ans;
	}


