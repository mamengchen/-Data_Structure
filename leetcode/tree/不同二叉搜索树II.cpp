给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例 :

输入: 3
	输出 :
	[
		[1, null, 3, 2],
		[3, 2, null, 1],
		[3, 1, null, null, 2],
		[2, 1, 3],
		[1, null, 2, null, 3]
	]
	解释:
	  以上的输出对应以下 5 种不同结构的二叉搜索树：

		  1         3     3      2      1
		  \       /     /      / \      \
		  3     2     1      1   3      2
		  /     /       \                 \
		  2     1         2                 3
解释：
那么剩下的问题，就是求左子树的所有可能的集合，和右子树的所有可能的集合。这两个问题和原问题本质上是一样求法。这样问题就被划分为了两个子问题。
最后再将两边所有可能的组合都合起来，构成一棵树。
每当确定了一个根节点（最外层循环），之后的问题就是一个动态规划的问题。将所有可能的左子树的组合存在lefts中，右子树的可能组合放在rights中。最后再组合。
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