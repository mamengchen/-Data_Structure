//打印所有不超过n（n < 256）的，其平方具有对称性质的数。如11 * 11 = 121。
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	queue<int> q;
	stack<int> v;
	int num = 0;
	int s = 0;
	for (int i = 1; i < 256; ++i)
	{
		bool pa = true;
		num = i * i;
		while (num)
		{
			s = num % 10;
			num = num / 10;
			q.push(s);
			v.push(s);
		}

		while (!q.empty())
		{
			if (q.front() == v.top())
			{
				q.pop();
				v.pop();
			}
			else {
				q = queue<int>();
				v = stack<int>();
				pa = false;
				break;
			}
		}

		if (pa)
		{
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}