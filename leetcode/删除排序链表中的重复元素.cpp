//��һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
//ʾ�� 1:
//����: 1->1->2
//	��� : 1->2
//	ʾ�� 2 :
//	���� : 1->1->2->3->3
//	��� : 1->2->3

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