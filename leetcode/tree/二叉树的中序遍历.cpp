//给定一个二叉树，返回它的中序 遍历。
//
//示例 :
//
//输入: [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//
//	输出: [1, 3, 2]
//
//	进阶 : 递归算法很简单，你可以通过迭代算法完成吗？

方法一：递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
	class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> Nodeval;
			midergodic(root, Nodeval);
			return Nodeval;
		}

		void midergodic(TreeNode* root, vector<int>& val)
		{
			if (root == NULL)
				return;
			midergodic(root->left, val);
			val.push_back(root->val);
			midergodic(root->right, val);
		}
};

方法二：迭代计算（利用栈）
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
	class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> Nodeval;
			stack<TreeNode*> treeNode;
			TreeNode* cur = root;
			while (cur != NULL || !treeNode.empty())
			{
				if (cur != NULL)
				{
					treeNode.push(cur);
					cur = cur->left;
				}
				else
				{
					TreeNode* exchange = treeNode.top();
					Nodeval.push_back(exchange->val);
					treeNode.pop();
					cur = exchange->right;
				}
			}
			return Nodeval;
		}
};