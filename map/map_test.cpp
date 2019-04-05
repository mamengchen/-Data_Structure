//关联容器里面存储的是<key, value>结构的键值对，
//，在数据检索时比序列式容器效率更高。

//SGI-STL中对于键值对的定义：
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
//key:键值对中key的类型;
//T:键值对中value的类型;
//Compare:比较的类型，map中的元素是按照key来比较的，缺省情况下按照小于来比较;
//alloc:通过空间配置器来申请底层空间;

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
	map<string, string> m2{ {"apple", "苹果"},
	{"banan", "香蕉"},
	{"peach", "桃子"} };
	cout << m2["apple"] << endl;
	map<string, string> m3(m2);

	for (auto it = m3.begin(); it != m3.end(); ++it)
	{
		cout << "m3: " << (*it).first << "--->" << (*it).second << endl;
	}
	cout << endl;

	//m2["apple"] = "我爱吃苹果";
	m2["apple"] = "苹果";
	cout << m2["apple"] << endl;
	cout << m2.size() << endl;

	cout << "m2::at>> " << m2.at("apple") << endl;
	//cout << "m2::at>> " << m2.at("appled") << endl; //appled不在map中，该函数抛出异常

	/*map中元素的修改*/
	m1.insert(pair<string, string>("peach", "桃子"));

	//用make_pair函数来构造键值对
	m1.insert(make_pair("person", "人类"));

	//用operator[]向map中插入元素
	m1["water"] = "水";
	for (auto it = m1.begin(); it != m1.end(); ++it)
	{
		cout << "m1: " << (*it).first << "--->" << (*it).second << endl;
	}
	cout << endl;

	//插入到指定位置
	m1.insert(m1.find("water"), make_pair("waterme", "水蜜桃"));
	cout << m1.size() << endl;
	cout << "m1-------------" << endl;
	Print(m1);

	//map中的键值对key一定是唯一的，如果key存在将插入失败，插入失败
	//返回一个键值pair<first:你插入的key名，second:成功返回true,失败返回false>,
	auto ret = m1.insert(make_pair("water", "青色"));
	if (ret.second)
	{
		cout << "<water, 青色>不在map中，已经插入" << endl;
	}
	else {
		cout << "键值为water的元素已存在: " << ret.first->first << "--->" <<
			ret.first->second << " 插入失败" << endl;
	}
	cout << "m1-----" << endl;
	Print(m1);

	m1.erase("water");
	cout << "m1::erase(water)-------" << endl;
	Print(m1);

	if (1 == m1.count("person"))
	{
		cout << "person还在" << endl;
	}
	else {
		cout << "person死了" << endl;
	}
}

int main()
{
	TestMap();
	system("pause");
	return 0;
}

//map总结：
//1. map中的的元素是键值对
//2. map中的key是唯一的，并且不能修改
//3. 默认按照小于的方式对key进行比较
//4. map中的元素如果用迭代器去遍历，可以得到一个有序的序列 
//5. map的底层为平衡搜索树(红黑树)，查找效率比较高 
//6. 支持[]操作符，operator[]中实际进行插入查找