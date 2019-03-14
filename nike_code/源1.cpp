
//给定区间[-2的31次方, 2的31次方]内的3个整数A、B和C，请判断A + B是否大于C。
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int time;
	long long A, B, C;
	cin >> time;
	for (int i = 1; i <= time; i++) {
		cin >> A >> B >> C;
		if (A + B > C) {
			cout << "Case #" << i << ": true" << endl;
		}
		else {
			cout << "Case #" << i << ": false" << endl;
		}
	}
}

//
//给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
//
//A1 = 能被5整除的数字中所有偶数的和；
//A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1 - n2 + n3 - n4...；
//A3 = 被5除后余2的数字的个数；
//A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
//A5 = 被5除后余4的数字中最大数字。

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n, i, a, num[5] = { 0,0,0,0,0 }, chu = 0;
	float c = 0.0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a;
		if (a % 10 == 0)
		{
			num[0] += a;
		}
		if (a % 5 == 1)
		{
			num[1] += pow(-1, chu)*a;
			chu++;
		}
		if (a % 5 == 2)
		{
			num[2]++;
		}
		if (a % 5 == 3)
		{
			num[3] += a;
			c = c + 1.0;
		}
		if (a % 5 == 4 && a > num[4])
		{
			num[4] = a;
		}
	}
	if (num[0] == 0) cout << "N ";
	else cout << num[0] << ' ';
	if (num[1] == 0) cout << "N ";
	else cout << num[1] << ' ';
	if (num[2] == 0) cout << "N ";
	else cout << num[2] << ' ';
	if (num[3] == 0) cout << "N ";
	else cout << setiosflags(ios::fixed) << setprecision(1) << num[3] / c << ' ';
	if (num[1] == 0) cout << "N";
	else cout << num[4];
	return 0;
}