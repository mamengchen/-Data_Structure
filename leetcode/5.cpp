/**
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int x = 0, y = 0, carry = 0, sum = 0;
		ListNode *h = NULL;
		ListNode **t = &h;

		while (l1 != NULL || l2 != NULL)
		{
			x = getValueAndMoveNext(l1);
			y = getValueAndMoveNext(l2);

			sum = carry + x + y;

			ListNode *node = new ListNode(sum % 10);
			*t = node;
			t = (&node->next);

			carry = sum / 10;
		}

		if (carry > 0)
		{
			ListNode *node = new ListNode(carry % 10);
			*t = node;
		}
		return h;
	}
private:
	int getValueAndMoveNext(ListNode* &l)
	{
		int x = 0;
		if (l != NULL)
		{
			x = l->val;
			l = l->next;
		}
		return x;
	}
};