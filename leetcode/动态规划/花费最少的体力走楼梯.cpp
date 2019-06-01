//�����ÿ��������Ϊһ�����ݣ��� i�����ݶ�Ӧ��һ���Ǹ�������������ֵ cost[i](������0��ʼ)��
//ÿ��������һ�������㶼Ҫ���Ѷ�Ӧ����������ֵ��Ȼ�������ѡ�������һ�����ݻ������������ݡ�
//����Ҫ�ҵ��ﵽ¥�㶥������ͻ��ѡ��ڿ�ʼʱ�������ѡ�������Ϊ 0 �� 1 ��Ԫ����Ϊ��ʼ���ݡ�
//ʾ�� 1:
//����: cost = [10, 15, 20]
//	��� : 15
//	���� : ��ͻ����Ǵ�cost[1]��ʼ��Ȼ�����������ɵ����ݶ���һ������15��
//	ʾ�� 2 :
//	���� : cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//	��� : 6
//	���� : ��ͻ��ѷ�ʽ�Ǵ�cost[0]��ʼ�����������Щ1������cost[3]��һ������6��
//	ע�⣺
//	cost �ĳ��Ƚ�����[2, 1000]��
//	ÿһ�� cost[i] ������һ��Integer���ͣ���ΧΪ[0, 999]��

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		if (cost.empty())
			return 0;
		if (cost.size() == 1)
			return cost[0];
		int* use_min = new int[cost.size()];
		use_min[0] = cost[0];
		use_min[1] = cost[1];
		for (int i = 2; i < cost.size(); i++)
		{
			use_min[i] = min(use_min[i - 2] + cost[i], use_min[i - 1] + cost[i]);
		}
		return min(use_min[cost.size() - 2], use_min[cost.size() - 1]);
	}
};