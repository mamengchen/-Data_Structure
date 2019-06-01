合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例 :
输入:
[
	1->4->5,
	1->3->4,
	2->6
]
输出 : 1->1->2->3->4->4->5->6



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		while (lists.size() > 1)
		{
			int n = lists.size();
			for (int i = 0; i < n >> 1; i++)
				lists[i] = merge(lists[i], lists[n - 1 - i]);
			lists.resize((n + 1) / 2);
		}
		return lists.size() == 0 ? nullptr : lists[0];
	}

	ListNode* merge(ListNode* l1, ListNode* l2)
	{
		ListNode *head = new ListNode(0);
		ListNode *p = head;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if (l1)
		{
			p->next = l1;
		}
		if (l2)
			p->next = l2;
		return head->next;
	}
};