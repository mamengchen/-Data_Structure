////vector������ʧЧ����
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//int main()
//{
//	int a[] = { 1, 2, 3, 4, };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	
//	//ʹ��find����3����λ�õ�iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//
//	//ɾ��posλ�õ����ݣ�����pos������ʧЧ��
//	v.erase(pos);
//	cout << *pos << endl;  //�˴��ᵼ�·Ƿ�����
//
//	//��posλ�ò������ݣ�����pos������ʧЧ��
//	//insert�ᵼ�µ�����ʧЧ������Ϊinsert���ܻᵼ�����ݣ�
//	//���ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��ˡ�
//	pos = find(v.begin(), v.end(), 3);
//	v.insert(pos, 30);
//	cout << *pos << endl; //�˴��ᵼ�·Ƿ�����
//
//	return 0;
//
//
//	system("pause");
//	return 0;
//}

//�����ĵ�����ʧЧ�ĳ���
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
			++it;
		}

		//���ϳ���Ҫ�ĳ�����������erase�᷵��ɾ��λ�õ���һ��λ��
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				v.erase(it);
			}
			++it;
		}

		//���ϳ���Ҫ�ĳ���������erase�᷵��ɾ��λ�õ���һ��λ��
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else {
				++it;
			}
		}
	}
	return 0;
}