//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//����Լ������������ظ�Ԫ�ء�
//ʾ�� 1:
//����: [1, 3, 5, 6], 5
//	��� : 2
//	ʾ�� 2 :
//	���� : [1, 3, 5, 6], 2
//	��� : 1
//	ʾ�� 3 :
//	���� : [1, 3, 5, 6], 7
//	��� : 4
//	ʾ�� 4 :
//	���� : [1, 3, 5, 6], 0
//	��� : 0


class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty())
		{
			return 0;
		}
		int count = 0;
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
		{
			if (target <= *iter)
			{
				break;
			}
			count++;
		}
		return count--;
	}
};