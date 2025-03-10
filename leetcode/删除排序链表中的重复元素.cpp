//定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//示例 1:
//输入: 1->1->2
//	输出 : 1->2
//	示例 2 :
//	输入 : 1->1->2->3->3
//	输出 : 1->2->3

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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
		{
			return NULL;
		}
		ListNode* pHead = head;
		ListNode* pCur = head->next;
		while (pCur != NULL)
		{
			if (pHead->val == pCur->val)
			{

				pCur = pCur->next;
				continue;
			}
			pHead->next = pCur;
			pCur = pCur->next;
			pHead = pHead->next;
		}
		pHead->next = pCur;

		return head;
	}
};