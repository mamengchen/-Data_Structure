����һ������ n������������ 1 ... n Ϊ�ڵ�����ɵĶ�����������

ʾ�� :

����: 3
	��� :
	[
		[1, null, 3, 2],
		[3, 2, null, 1],
		[3, 1, null, null, 2],
		[2, 1, 3],
		[1, null, 2, null, 3]
	]
	����:
	  ���ϵ������Ӧ���� 5 �ֲ�ͬ�ṹ�Ķ�����������

		  1         3     3      2      1
		  \       /     /      / \      \
		  3     2     1      1   3      2
		  /     /       \                 \
		  2     1         2                 3
���ͣ�
��ôʣ�µ����⣬�����������������п��ܵļ��ϣ��������������п��ܵļ��ϡ������������ԭ���Ȿ������һ���󷨡���������ͱ�����Ϊ�����������⡣
����ٽ��������п��ܵ���϶�������������һ������
ÿ��ȷ����һ�����ڵ㣨�����ѭ������֮����������һ����̬�滮�����⡣�����п��ܵ�����������ϴ���lefts�У��������Ŀ�����Ϸ���rights�С��������ϡ�
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
		{
			return vector<TreeNode *> {};
		}
		return helper(1, n);
	}

	vector<TreeNode*> helper(int begin, int end)
	{
		vector<TreeNode*> res;
		if (begin > end)
		{
			res.push_back(NULL);
			return res;
		}
		for (int i = begin; i <= end; i++)
		{
			vector<TreeNode*> left_node = helper(begin, i - 1);
			vector<TreeNode*> right_node = helper(i + 1, end);
			for (auto l : left_node)
			{
				for (auto r : right_node)
				{
					TreeNode* root = new TreeNode(i);
					root->left = l;
					root->right = r;
					res.push_back(root);
				}
			}
		}
		return res;
	}
};