class Solution {
public:
	int mySqrt(int x) {
		long t = (x >> 1) + (x & 1);
		while (t*t > x || (t + 1)*(t + 1) < x)
			t = (x / t + t) >> 1;
		return (int)t;
	}
};