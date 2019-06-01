/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef struct ListNode ListNode;
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
		{
			return l2;
		}
		if (l2 == nullptr)
		{
			return l1;
		}
		ListNode* pNode = new ListNode(0);
		ListNode* pHead = nullptr;
		bool biaoshi = true;
		while (l1 != nullptr && l2 != nullptr)
		{

			if (l1->val <= l2->val)
			{
				pNode->next = l1;
				l1 = l1->next;
			}
			else
			{
				pNode->next = l2;
				l2 = l2->next;
			}
			pNode = pNode->next;
			if (biaoshi)
			{
				pHead = pNode;
				biaoshi = false;
			}
		}
		if (l1 == nullptr)
		{
			pNode->next = l2;
		}
		else
		{
			pNode->next = l1;
		}
		return pHead;
	}
};