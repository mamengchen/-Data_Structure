//����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�
//
//���磬���������Σ�
//
//[
//	[2],
//	[3, 4],
//	[6, 5, 7],
//	[4, 1, 8, 3]
//]
//
//
//�Զ����µ���С·����Ϊ 11������2 + 3 + 5 + 1 = 11����



��Ŀ������������Ҫ������������ǾͿ���ȷ������һ��Ҫ�ӵľ�������������j��j+1λ�õ��������ǾͿ�������ˡ�
ÿ������������˭С�ͼ��ϸı�ԭ���ı������ݣ�

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
