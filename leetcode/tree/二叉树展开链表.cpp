����һ����������ԭ�ؽ���չ��Ϊ����

���磬����������

1
/ \
2   5
/ \   \
3   4   6

����չ��Ϊ��

1
\
2
\
3
\
4
\
5
\
6

�ݹ�
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
		void flatten(TreeNode* root) {
			if (root == nullptr) return;
			flatten(root->left);
			flatten(root->right);
			TreeNode* tmp = root->right;
			root->right = root->left;
			root->left = nullptr;
			while (root->right != nullptr) root = root->right;
			root->right = tmp;
		}
};

�ǵݹ�
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
		void flatten(TreeNode* root) {
			stack<TreeNode*> stree;
			while (root != nullptr || !stree.empty())
			{
				while (root != nullptr)
				{
					stree.push(root);
					root = root->left;
				}
				if (!stree.empty())
				{
					TreeNode* node = stree.top();
					stree.pop();
					TreeNode* tmp = node->right;
					node->right = node->left;
					node->left = 0;
					while (node->right != nullptr) node = node->right;
					node->right = tmp;
					root = tmp;
				}
			}
		}
};