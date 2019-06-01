//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻��������������
//
//ʾ����
//
//���룺
//{ "$id":"1","next" : {"$id":"2","next" : null,"random" : {"$ref":"2"},"val" : 2},"random" : {"$ref":"2"},"val" : 1 }
//
//���ͣ�
//�ڵ� 1 ��ֵ�� 1��������һ��ָ������ָ�붼ָ��ڵ� 2 ��
//�ڵ� 2 ��ֵ�� 2��������һ��ָ��ָ�� null�����ָ��ָ�����Լ���

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL)
		{
			return NULL;
		}
		Node* phead;
		Node* pNode_new;
		Node* pNode = head;
		while (pNode != NULL)
		{
			Node* new_node = new Node(pNode->val, pNode->next, NULL);
			pNode->next = new_node;
			pNode = new_node->next;
		}
		phead = head->next;
		pNode = head;
		pNode_new = head->next;
		while (pNode_new->next != NULL)
		{
			if (pNode->random != NULL)
				pNode_new->random = pNode->random->next;
			pNode = pNode_new->next;
			pNode_new = pNode->next;
		}
		if (pNode->random != NULL && pNode_new != NULL)
			pNode_new->random = pNode->random->next;


		pNode = head;
		pNode_new = head->next;
		while (pNode_new->next != NULL)
		{
			pNode->next = pNode_new->next;
			pNode = pNode->next;
			pNode_new->next = pNode->next;
			pNode_new = pNode_new->next;
		}
		pNode->next = NULL;
		return phead;
	}
};