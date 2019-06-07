

class Solution {
public:
	// 3,2,3
	int largestRectangleArea(vector<int>& heights) {
		if (heights.size() == 0) return 0;
		vector<int> s(heights.size() + 1, 0);
		int top = -1;
		int ret = 0;
		s[++top] = -1;//放入一个 -1 是为了方便栈里面只有一个元素的情况。
		for (int i = 0; i < heights.size(); ++i) {
			if (top == 0) {
				s[++top] = i;
				continue;
			}
			while (top != 0 && heights[i] < heights[s[top]]) {
				int n = heights[s[top--]];//要出栈的数字
				int res = n * (i - 1 - s[top]);//计算得到的高度
				ret = max(ret, res);
			}
			s[++top] = i;
		}
		while (top != 0) {//处理栈中剩余的元素。。这里当前下标应该为 heights .size()
			int n = heights[s[top--]];
			int res = n * (heights.size() - 1 - s[top]);
			ret = max(ret, res);
		}
		return ret;
	}
};