//输入: numbers = [2, 7, 11, 15], target = 9
//	输出 : [1, 2]
//	解释 : 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。


class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> my_vec;
		map<int, vector<int>> my_map;
		std::pair<map<int, vector<int>>::iterator, bool> my_judge;
		for (int i = 0; i < numbers.size(); i++)
		{
			my_judge = my_map.insert(std::pair<int, vector<int>>(numbers[i], 0));
			if (!my_judge.second)
			{
				my_map[numbers[i]].push_back(i + 1);
				continue;
			}
			my_map[numbers[i]].push_back(i + 1);
		}
		for (map<int, vector<int>>::iterator iter = my_map.begin(); iter != my_map.end(); iter++)
		{
			if (!(my_map[target - (iter->first)].empty()))
			{

				my_vec.push_back((iter->second.front()));
				iter->second.erase(iter->second.begin());
				my_vec.push_back(my_map[target - (iter->first)].front());
				break;
			}
		}
		return my_vec;
	}
};