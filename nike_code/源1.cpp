
//��������[-2��31�η�, 2��31�η�]�ڵ�3������A��B��C�����ж�A + B�Ƿ����C��
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
//����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�
//
//A1 = �ܱ�5����������������ż���ĺͣ�
//A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1 - n2 + n3 - n4...��
//A3 = ��5������2�����ֵĸ�����
//A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
//A5 = ��5������4��������������֡�

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