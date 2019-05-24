//����һ�� N ������������ڵ�ֵ�Ĳ��������(�������ң�������)��
//���磬����һ�� 3���� :
//                    1
//                  / | \
//                3   2  4
//               / \
//              5   6
//������������:
//[
//	[1],
//	[3, 2, 4],
//	[5, 6]
//]
//�������������Ҫÿ�μ�¼ÿ���м�����Ҫ��������
/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/
class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		if (root == NULL) return{};
		vector<vector<int>> my_two_vec;
		vector<int> my_vec;
		queue<Node*> my_que;
		my_que.push(root);
		int count = 1;
		int ret = 0;
		while (!my_que.empty())
		{
			if (!count)
			{
				my_two_vec.push_back(my_vec);
				my_vec.clear();
				count = ret;
				ret = 0;
			}
			for (int i = 0; i < my_que.front()->children.size(); i++)
			{
				my_que.push(my_que.front()->children[i]);
				ret++;
			}
			my_vec.push_back(my_que.front()->val);
			count--;
			my_que.pop();
		}
		my_two_vec.push_back(my_vec);
		return my_two_vec;
	}
};