#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

class Data_num1 {
public:
	vector<int> vec;
	int all;
public:

	void man_read()
	{
		char buffer[1024];
		int count = 0;
		ifstream in("data_test1.txt");
		if (!in.is_open())
		{
			cout << "Error opening file";
			exit(1);
		}
		while (!in.eof())
		{
			in.getline(buffer, 1024);
		}
		for (int i = 0; i < sizeof(buffer) / sizeof(buffer[0]); i++)
		{
			if (buffer[i] == ' ')
			{
				vec.push_back(count);
				count = 0;
				continue;
			}
			count = (buffer[i]-'0') + count * 10;
		}
	}

	void man_show()
	{
		vector<int>::iterator iter;
		for (iter = vec.begin(); iter != vec.end(); iter++)
		{
			cout << "num_data1：" << *iter << " | ";
			all += *iter;
		}
		cout << endl;
	}

	void man_all()
	{
		printf("******************************    num_data_all：%d    ********************************\n", all);
	}

	int max()
	{
		int vec_max = vec[0];
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec_max < vec[i])
				vec_max = vec[i];
		}
		return vec_max;
	}

	int min()
	{
		int vec_min = vec[0];
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec_min > vec[i])
				vec_min = vec[i];
		}
		return vec_min;
	}

	void min_max_guifan(vector<double>& x)
	{
		int new_max;
		int new_min;
		int my_min = min();
		int my_max = max();
		printf("\n");
		printf("********************** 请输入new_min: ");
		cin >> new_min;
		printf("********************** 请输入new_max: ");
		cin >> new_max;
		for (int i = 0; i < vec.size(); i++)
		{
			double rx = (vec[i] - my_min) / ((my_max - my_min)*(new_max - new_min)*1.0) + new_min;
			x.push_back(rx);
			printf("v[%d] = %f ", i + 1, x[i]);
		}
	}

	void z_fenshu_guifan(vector<double> &x)
	{	
		double rx = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			rx = vec[i] - all / ((1.0)*vec.size());
			x.push_back(rx);
		}
	}

	void test()
	{
		man_read();
		man_show();
		man_all();
	}
};

class Data_num2 {
public:
	vector<int> vec;
	int all;
public:


	void _read()
	{
		char buffer[1024];
		int count = 0;
		ifstream in("data_test2.txt");
		if (!in.is_open())
		{
			cout << "Error opening file";
			exit(1);
		}
		while (!in.eof())
		{
			in.getline(buffer, 1024);
		}
		for (int i = 0; i < sizeof(buffer) / sizeof(buffer[0]); i++)
		{
			if (buffer[i] == ' ')
			{
				vec.push_back(count);
				count = 0;
				continue;
			}
			count = (buffer[i] - '0') + count * 10;
		}
	}

	void _show()
	{
		vector<int>::iterator iter;
		for (iter = vec.begin(); iter != vec.end(); iter++)
		{
			cout << "num_data2：" << *iter << " | ";
			all += *iter;
		}
		cout << endl;
	}

	void _all()
	{
		printf("******************************    num_data2_all：%d    ********************************\n", all);
	}

	int max()
	{
		int vec_max = vec[0];
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec_max < vec[i])
				vec_max = vec[i];
		}
		return vec_max;
	}

	int min()
	{
		int vec_min = vec[0];
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec_min > vec[i])
				vec_min = vec[i];
		}
		return vec_min;
	}

	void z_fenshu_guifan(vector<double> &x)
	{
		double rx = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			rx = vec[i] - all / ((1.0)*vec.size());
			x.push_back(rx);
		}
	}

	void min_max_guifan(vector<double>& x)
	{
		int new_max;
		int new_min;
		int my_min = min();
		int my_max = max();
		printf("\n");
		printf("********************** 请输入new_min: ");
		cin >> new_min;
		printf("********************** 请输入new_max: ");
		cin >> new_max;
		for (int i = 0; i < vec.size(); i++)
		{
			double rx = (vec[i] - my_min) / ((my_max - my_min)*(new_max - new_min)*1.0) + new_min;
			x.push_back(rx);
			printf("v[%d] = %f ", i + 1, x[i]);
		}
	}

	void test()
	{
		_read();
		_show();
		_all();
	}
};

void qiwang_read(vector<int>& vec)
{
	char buffer[1024];
	int count = 0;
	ifstream in("qiwang.txt");
	if (!in.is_open())
	{
		cout << "Error opening file";
		exit(1);
	}
	while (!in.eof())
	{
		in.getline(buffer, 1024);
	}
	for (int i = 0; i < sizeof(buffer) / sizeof(buffer[0]); i++)
	{
		if (buffer[i] == ' ')
		{
			vec.push_back(count);
			count = 0;
			continue;
		}
		count = (buffer[i] - '0') + count * 10;
	}
}

double variance(vector<int>& x, int n)
{
	double s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++)
	{
		s1 += x[i] * x[i];
		s2 += x[i];
	}
	double quare = s1 / n - (s2 / n)*(s2 / n);
	return quare;
}

void function(Data_num1& data1, Data_num2& data2)
{
	int all = data1.all + data2.all;
	vector<int> numdata;
	vector<int> qiwan;
	vector<float> qi;
	vector<vector<int>> o(data1.vec.size(), vector<int>(2, 0));
	vector<vector<float>> e;
	int i, j;
	float num_data;
	for (i = 0; i < data1.vec.size(); i++)
	{
		numdata.push_back(data1.vec[i] + data2.vec[i]);
	}
	for (i = 0; i < numdata.size(); i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				num_data = data1.all * numdata[i] / (all * 1.0);
				qi.push_back(num_data);
			}
			else
			{
				num_data = data2.all * numdata[i] / (all * 1.0);
				qi.push_back(num_data);
			}
			printf("**** e[%d][%d] = %f ***\n" ,j+1, i+1, num_data);
		}
		e.push_back(qi);
		qi.clear();
	}
	qiwang_read(qiwan);

	for (i = 0; i < data1.vec.size(); i++)
	{
		for (j = 0; j < 2; j++)
		{
			o[i][j] = qiwan[i*2 + j];
		}
	}
	
	for (i =  0, num_data = 0; i < numdata.size(); i++)
	{
		for (j = 0; j < 2; j++)
		{
			num_data += (o[i][j] - e[i][j])*(o[i][j] - e[i][j]) / e[i][j];
		}
	}
	printf("**************  pearson x^2 = %f  ***************\n", num_data);

	printf("************** 相关系数 *****************\n");
	double rab = 0;
	int sz = data1.vec.size();
	double Ax = variance(data1.vec, data1.vec.size());
	double Bx = variance(data1.vec, data1.vec.size());
	for (int i = 0; i < data1.vec.size(); i++)
	{
		rab = data1.vec[i] * data1.vec[i] + rab;
	}
	rab = (rab - data1.all*data2.all / (sz*1.0) * (1.0)) / (sz*Ax*Bx);
	printf("数据a与b的相关系数：%f\n", rab);
	printf("*****************************************\n\n");

	printf("**************** 最大-最小规范化 *************\n");
	vector<double> data1_vec;
	data1.min_max_guifan(data1_vec);
	vector<double> data2_vec;
	data2.min_max_guifan(data2_vec);
	printf("\n**********************************************\n\n");

	printf("****************** z分数规范化 *****************\n");
	vector<double> data1_z_vec;
	data1.z_fenshu_guifan(data1_z_vec);
	vector<double> data2_z_vec;
	data2.z_fenshu_guifan(data2_z_vec);
	for (int i = 0; i < data1_z_vec.size(); i++)
	{
		data1_z_vec[i] /= Ax;
		data2_z_vec[i] /= Bx;
	}
	printf("******* z分数规范A数据：*********************\n");
	for (int i = 0; i < data1_z_vec.size(); i++)
	{
		printf("A数据z规范v[%d] ：%f", i + 1, data1_z_vec[i]);
	}
	printf("\n******* z分数规范B数据：*********************\n");
	for (int i = 0; i < data2_z_vec.size(); i++)
	{
		printf("B数据z规范v[%d] ：%f", i + 1, data2_z_vec[i]);
	}
}



int main()
{
	Data_num1 ma;
	ma.test();
	Data_num2 mb;
	mb.test();
	function(ma, mb);
	system("pause");
	return 0;
}