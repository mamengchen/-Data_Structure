//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
//
//例如，给定三角形：
//
//[
//	[2],
//	[3, 4],
//	[6, 5, 7],
//	[4, 1, 8, 3]
//]
//
//
//自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。



题目分析首先它需要最近的这样我们就可以确定，上一个要加的就是来自于它后j，j+1位置的数，我们就可以填表了。
每次找它下两个谁小就加上改变原来的表中数据；

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int size = triangle.size();
		if (size == 0)
		{
			return 0;
		}
		for (int i = size - 2; i >= 0; --i)
		{
			for (int j = 0; j < triangle[i].size(); j++)
			{
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}
};
