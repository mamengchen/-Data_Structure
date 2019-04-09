#include <iostream>
#include <deque>
using namespace std;
template <class Iterator>
void Print(Iterator first, Iterator list)
{
	while (first != list)
	{
		cout << *first;
		++first;
	}
	cout << endl;
}

template <class numtype, class length >
int Calculation(numtype num1, numtype num2, length size)
{
	int number = 0;
	for (length i = 0; i < size; i++)
	{
		number = number + num1[i] * num2[i];
	}
	number = number % 2;
	return number;
}


int main()
{
	deque<int> deq1;
	deque<int> deq_str1;
	deque<int> deq_str2;
	deque<int> all_secret_key;
	int num, num1;
	int d;
	cout << "输入deq1长度：";
	cin >> d;
	while (d--)
	{
		cin >> num;
		deq1.push_back(num);
	}
	int n;
	cout << "输入第一个初始向量：" << endl;
	for (int i = deq1.size(); i > 0; i--)
	{
		cin >> n;
		if (n > 1)
		{
			cout << "<输出有误自动转化>" << endl;
			n = n % 2;
		}
		deq_str1.push_back(n);
	}
	cout << "输入第二个初始向量：" << endl;
	for (int i = deq1.size(); i > 0; i--)
	{
		cin >> n;
		if (n > 1)
		{
			cout << "<输出有误自动转化>" << endl;
			n = n % 2;
		}
		deq_str2.push_back(n);
	}

	cout << "请输入密钥的长度: ";
	cin >> num1;

	while (num1--)
	{
		int keyType1 = Calculation(deq1, deq_str1, deq1.size());
		deq_str1.pop_back();
		deq_str1.push_front(keyType1);
		int keyType2 = Calculation(deq1, deq_str2, deq1.size());
		deq_str2.pop_back();
		deq_str2.push_front(keyType2);
		if (keyType1 == 0 && keyType1 == 0)
		{
			all_secret_key.push_front(all_secret_key[0]);
		}
		else if (keyType1 == 1 && keyType2 == 1)
		{
			all_secret_key.push_front(!all_secret_key[0]);
		}
		else {
			all_secret_key.push_front(keyType1^keyType2);
		}
	}
	Print(all_secret_key.begin(), all_secret_key.end());
	system("pause");
	return 0;
}