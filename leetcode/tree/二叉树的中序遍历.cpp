//����һ���������������������� ������
//
//ʾ�� :
//
//����: [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//
//	���: [1, 3, 2]
//
//	���� : �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����

����һ���ݹ�
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

���������������㣨����ջ��
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