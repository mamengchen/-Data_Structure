//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//问总共有多少条不同的路径？
//
//例如，上图是一个7 x 3 的网格。有多少可能的路径？
//说明：m 和 n 的值均不超过 100。
//示例 1:
//输入: m = 3, n = 2
//	输出 : 3
//	解释 :
//	从左上角开始，总共有 3 条路径可以到达右下角。
//	1. 向右->向右->向下
//	2. 向右->向下->向右
//	3. 向下->向右->向右


class Solution {
public:
	int uniquePaths(int m, int n) {
		int map[n][m] = { 0 };
		for (int i = 0; i < m; i++)
			map[0][i] = 1;
		for (int i = 0; i < n; i++)
			map[i][0] = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				map[i][j] = map[i - 1][j] + map[i][j - 1];
			}
		}
		return map[n - 1][m - 1];
	}
};