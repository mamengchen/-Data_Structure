//����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
//ʾ�� 1:
//�������� nums = [1, 1, 2],
//
//����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2��
//
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1)
		{
			return nums.size();
		}
		vector<int>::iterator iter;
		vector<int>::iterator num_iter;
		iter = nums.begin();
		num_iter = nums.begin() + 1;
		for (; num_iter != nums.end(); num_iter++)
		{
			if (*iter == *num_iter)
			{
				num_iter = nums.erase(num_iter) - 1;
			}
			else
			{
				iter++;
			}
		}
		return nums.size();
	}
};