//
//����һ�������Ǹ������� m x n �������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
//˵����ÿ��ֻ�����»��������ƶ�һ����
//ʾ�� :
//����:
//[
//	[1, 3, 1],
//	[1, 5, 1],
//	[4, 2, 1]
//]
//��� : 7
//	���� : ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��


class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int col = grid.size();
		int row = grid[0].size();
		for (int i = 1; i < grid.size(); i++)
		{
			grid[i][0] += grid[i - 1][0];
		}
		for (int i = 1; i < row; i++)
		{
			grid[0][i] += grid[0][i - 1];
		}
		for (int i = 1; i < col; i++)
		{
			for (int j = 1; j < row; j++)
			{
				if (grid[i - 1][j] < grid[i][j - 1])
				{
					grid[i][j] += grid[i - 1][j];
					continue;
				}
				grid[i][j] += grid[i][j - 1];
			}
		}
		return grid[col - 1][row - 1];
	}
};