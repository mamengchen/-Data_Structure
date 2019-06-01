//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
//���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����
//
//�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��
//˵����m �� n ��ֵ�������� 100��
//ʾ�� 1:
//����:
//[
//	[0, 0, 0],
//	[0, 1, 0],
//	[0, 0, 0]
//]
//��� : 2
//	���� :
//	3x3 ��������м���һ���ϰ��
//	�����Ͻǵ����½�һ���� 2 ����ͬ��·����
//	1. ����->����->����->����
//	2. ����->����->����->����

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if ((obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1) || obstacleGrid[0][0] == 1) return !obstacleGrid[0][0];
		for (int i = 1; i < obstacleGrid.size(); i++)
		{
			if (obstacleGrid[i][0] == 1)
			{
				while (i < obstacleGrid.size())
					obstacleGrid[i++][0] = 0;
				break;
			}
			obstacleGrid[i][0] = 1;
		}
		for (int i = 1; i < obstacleGrid[0].size(); i++)
		{
			if (obstacleGrid[0][i] == 1)
			{
				while (i < obstacleGrid[0].size())
					obstacleGrid[0][i++] = 0;
				break;
			}
			obstacleGrid[0][i] = 1;
		}
		for (int i = 1; i < obstacleGrid.size(); i++)
		{
			for (int j = 1; j < obstacleGrid[0].size(); j++)
			{
				if (obstacleGrid[i][j] == 1)
				{
					obstacleGrid[i][j] = 0;
					continue;
				}
				obstacleGrid[i][j] = (long long)obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
			}
		}
		return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};