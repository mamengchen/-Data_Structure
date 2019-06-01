//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深拷贝。
//
//示例：
//
//输入：
//{ "$id":"1","next" : {"$id":"2","next" : null,"random" : {"$ref":"2"},"val" : 2},"random" : {"$ref":"2"},"val" : 1 }
//
//解释：
//节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
//节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。

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