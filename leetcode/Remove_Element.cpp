//����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//ʾ�� 1
//���� nums = [3, 2, 2, 3], val = 3,
//
//����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��
//
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
		{
			if (*iter == val)
			{
				iter = nums.erase(iter) - 1;
			}
		}
		return nums.size();
	}
};