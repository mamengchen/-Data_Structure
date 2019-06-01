//����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
//�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����
//���磬�������¶����� : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
//                             3
//                            / \
//                           5   1
//                          / \  /\
//                         6  2 0  8
//                            /\
//                           7  4
//
//	ʾ�� 1 :
//	���� : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
//	��� : 3
//	���� : �ڵ� 5 �ͽڵ� 1 ��������������ǽڵ� 3��
//	ʾ�� 2 :
//	���� : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 4
//	��� : 5
//	���� : �ڵ� 5 �ͽڵ� 4 ��������������ǽڵ� 5����Ϊ���ݶ�������������Ƚڵ����Ϊ�ڵ㱾��

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return root;
		if (root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left != NULL && right != NULL)
		{
			return root;
		}
		else if (left != NULL) {
			return left;
		}
		else if (right != NULL) {
			return right;
		}
		return NULL;
	}
};