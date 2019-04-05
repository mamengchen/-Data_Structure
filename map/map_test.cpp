//������������洢����<key, value>�ṹ�ļ�ֵ�ԣ�
//�������ݼ���ʱ������ʽ����Ч�ʸ��ߡ�

//SGI-STL�ж��ڼ�ֵ�ԵĶ��壺
/*
template<class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	pair()
		:first(T1())
		,second(T2())
	{}

	pair(const T1& a, const T2& b)
		:first(a)
		,second(b)
	{}
};
*/

//std::map
//template <class Key,
//	class T,
//	class Compare = less<Key>,
//	class Alloc = allocator<pair<const Key, T>>
//>class map;
//key:��ֵ����key������;
//T:��ֵ����value������;
//Compare:�Ƚϵ����ͣ�map�е�Ԫ���ǰ���key���Ƚϵģ�ȱʡ����°���С�����Ƚ�;
//alloc:ͨ���ռ�������������ײ�ռ�;

#include <string>
#include <map>
#include <iostream>
using namespace std;

template<class T>
void Print(T& element)
{
	for (auto& e : element)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	cout << endl;
}

void TestMap()
{
	map<string, string> m1;
	map<string, string> m2{ {"apple", "ƻ��"},
	{"banan", "�㽶"},
	{"peach", "����"} };
	cout << m2["apple"] << endl;
	map<string, string> m3(m2);

	for (auto it = m3.begin(); it != m3.end(); ++it)
	{
		cout << "m3: " << (*it).first << "--->" << (*it).second << endl;
	}
	cout << endl;

	//m2["apple"] = "�Ұ���ƻ��";
	m2["apple"] = "ƻ��";
	cout << m2["apple"] << endl;
	cout << m2.size() << endl;

	cout << "m2::at>> " << m2.at("apple") << endl;
	//cout << "m2::at>> " << m2.at("appled") << endl; //appled����map�У��ú����׳��쳣

	/*map��Ԫ�ص��޸�*/
	m1.insert(pair<string, string>("peach", "����"));

	//��make_pair�����������ֵ��
	m1.insert(make_pair("person", "����"));

	//��operator[]��map�в���Ԫ��
	m1["water"] = "ˮ";
	for (auto it = m1.begin(); it != m1.end(); ++it)
	{
		cout << "m1: " << (*it).first << "--->" << (*it).second << endl;
	}
	cout << endl;

	//���뵽ָ��λ��
	m1.insert(m1.find("water"), make_pair("waterme", "ˮ����"));
	cout << m1.size() << endl;
	cout << "m1-------------" << endl;
	Print(m1);

	//map�еļ�ֵ��keyһ����Ψһ�ģ����key���ڽ�����ʧ�ܣ�����ʧ��
	//����һ����ֵpair<first:������key����second:�ɹ�����true,ʧ�ܷ���false>,
	auto ret = m1.insert(make_pair("water", "��ɫ"));
	if (ret.second)
	{
		cout << "<water, ��ɫ>����map�У��Ѿ�����" << endl;
	}
	else {
		cout << "��ֵΪwater��Ԫ���Ѵ���: " << ret.first->first << "--->" <<
			ret.first->second << " ����ʧ��" << endl;
	}
	cout << "m1-----" << endl;
	Print(m1);

	m1.erase("water");
	cout << "m1::erase(water)-------" << endl;
	Print(m1);

	if (1 == m1.count("person"))
	{
		cout << "person����" << endl;
	}
	else {
		cout << "person����" << endl;
	}
}

int main()
{
	TestMap();
	system("pause");
	return 0;
}

//map�ܽ᣺
//1. map�еĵ�Ԫ���Ǽ�ֵ��
//2. map�е�key��Ψһ�ģ����Ҳ����޸�
//3. Ĭ�ϰ���С�ڵķ�ʽ��key���бȽ�
//4. map�е�Ԫ������õ�����ȥ���������Եõ�һ����������� 
//5. map�ĵײ�Ϊƽ��������(�����)������Ч�ʱȽϸ� 
//6. ֧��[]��������operator[]��ʵ�ʽ��в������