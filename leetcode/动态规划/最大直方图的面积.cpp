

class Solution {
public:
	// 3,2,3
	int largestRectangleArea(vector<int>& heights) {
		if (heights.size() == 0) return 0;
		vector<int> s(heights.size() + 1, 0);
		int top = -1;
		int ret = 0;
		s[++top] = -1;//����һ�� -1 ��Ϊ�˷���ջ����ֻ��һ��Ԫ�ص������
		for (int i = 0; i < heights.size(); ++i) {
			if (top == 0) {
				s[++top] = i;
				continue;
			}
			while (top != 0 && heights[i] < heights[s[top]]) {
				int n = heights[s[top--]];//Ҫ��ջ������
				int res = n * (i - 1 - s[top]);//����õ��ĸ߶�
				ret = max(ret, res);
			}
			s[++top] = i;
		}
		while (top != 0) {//����ջ��ʣ���Ԫ�ء������ﵱǰ�±�Ӧ��Ϊ heights .size()
			int n = heights[s[top--]];
			int res = n * (heights.size() - 1 - s[top]);
			ret = max(ret, res);
		}
		return ret;
	}
};