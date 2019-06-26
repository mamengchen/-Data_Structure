�����������е������ڵ㱻����ؽ�����

���ڲ��ı���ṹ������£��ָ��������

ʾ�� 1:

����: [1, 3, null, null, 2]

	1
	/
	3
	\
	2

	���: [3, 1, null, null, 2]

	3
	/
	1
	\
	2


	ʾ�� 2:

����: [3, 1, 4, null, null, 2]

	3
	/ \
	1   4
	/
	2

	���: [2, 1, 4, null, null, 3]

	2
	/ \
	1   4
	/
	3


���������������������һ����������飬���п���O(n)ʱ�临�Ӷȣ����ǿ���һ���ռ������洢
��һ��TreeNode* ���飬Ȼ���������֮�������ӾͿ����ˡ�

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
		void recoverTree(TreeNode* root) {
			vector<TreeNode*> list;
			vector<int> vals;
			inorder(root, list, vals);
			sort(vals.begin(), vals.end());
			for (int i = 0; i < list.size(); ++i)
			{
				list[i]->val = vals[i];
			}
		}
		void inorder(TreeNode* root, vector<TreeNode*> &list, vector<int> &vals)
		{
			if (!root) return;
			inorder(root->left, list, vals);
			list.push_back(root);
			vals.push_back(root->val);
			inorder(root->right, list, vals);
		}
};

	�����������бȽ�
	// Still O(n) space complexity
	class Solution {
	public:
		TreeNode *pre;
		TreeNode *first;
		TreeNode *second;
		void recoverTree(TreeNode *root) {
			pre = NULL;
			first = NULL;
			second = NULL;
			inorder(root);
			if (first && second) swap(first->val, second->val);
		}
		void inorder(TreeNode *root) {
			if (!root) return;
			inorder(root->left);
			if (!pre) pre = root;
			else {
				if (pre->val > root->val) {
					if (!first) first = pre;
					second = root;
				}
				pre = root;
			}
			inorder(root->right);
		}
	};
	// Now O(1) space complexity
	class Solution {
	public:
		void recoverTree(TreeNode *root) {
			TreeNode *first = NULL, *second = NULL, *parent = NULL;
			TreeNode *cur, *pre;
			cur = root;
			while (cur) {
				if (!cur->left) {
					if (parent && parent->val > cur->val) {
						if (!first) first = parent;
						second = cur;
					}
					parent = cur;
					cur = cur->right;
				}
				else {
					pre = cur->left;
					while (pre->right && pre->right != cur) pre = pre->right;
					if (!pre->right) {
						pre->right = cur;
						cur = cur->left;
					}
					else {
						pre->right = NULL;
						if (parent->val > cur->val) {
							if (!first) first = parent;
							second = cur;
						}
						parent = cur;
						cur = cur->right;
					}
				}
			}
			if (first && second) swap(first->val, second->val);
		}
	};
