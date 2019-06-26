二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1, 3, null, null, 2]

	1
	/
	3
	\
	2

	输出: [3, 1, null, null, 2]

	3
	/
	1
	\
	2


	示例 2:

输入: [3, 1, 4, null, null, 2]

	3
	/ \
	1   4
	/
	2

	输出: [2, 1, 4, null, null, 3]

	2
	/ \
	1   4
	/
	3


二叉搜索树的中序遍历是一个有序的数组，所有开辟O(n)时间复杂度，就是开辟一个空间用来存储
这一个TreeNode* 数组，然后把他排序之后在连接就可以了。

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

	两个两个进行比较
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
