#pragma once
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class DenseGraph {
private:
	int n, m; //n:为顶点数，m为边数
	bool directed;  //表示是否为有向图
	vector<vector<bool>> g;

public:
	DenseGraph(int _n, bool _directed)
	{
		this->n = _n;
		this->m = 0;
		this->directed = _directed;
		for (int i = 0; i < n; i++)
		{
			g.push_back(vector<bool>(n, false));
		}
	}

	~DenseGraph()
	{
	}

	int n_num() { return n;}
	int m_num() { return m;}

	void addEdge(int first_data, int second_data)
	{
		assert(first_data >= 0 && first_data <= n);
		assert(second_data >= 0 && second_data <= n);
		if (hasEdge)
			return;
		g[first_data][second_data] = true;
		if (!directed)
			g[second_data][first_data] = true;
		m++;
	}

	bool hasEdge(int first_data, int second_data)
	{
		assert(first_data >= 0 && first_data <= n);
		assert(second_data >= 0 && second_data <= n);
		return g[first_data][second_data];
	}

	class adjIterator {
	private:
		DenseGraph& D;
		int node;
		int index;
	public:
		adjIterator(DenseGraph& d, int _node):D(d)
		{
			this->node = _node;
			this->index = 0;
		}

		int begin()
		{
			index = -1;
			return next();
		}

		int next()
		{
			for (index += 1; index < D.n_num(); index++)
			{
				if (D.g[node][index])
				{
					return index;
				}
			}
			return -1;
		}

		bool end()
		{
			return index >= D.n_num();
		}
	};
};

class SparseGraph {
private:
	int n, m;
	int directed;
	vector<vector<int>> g;

public:
	SparseGraph(int _n, bool _directed)
	{
		this->n = _n;
		this->m = 0;
		this->directed = _directed;
		for (int i = 0; i < n; i++)
		{
			g.push_back(vector<int>());
		}
	}

	int n_num() { return n; }
	int m_num() { return m; }

	void addEdge(int first_data, int second_data)
	{
		assert(first_data >= 0 && first_data < n);
		assert(second_data >= 0 && second_data < n);
		g[first_data].push_back(second_data);
		if (first_data != second_data && directed)
			g[first_data].push_back(second_data);
		m++;
	}

	bool hasEdge(int first_data, int second_data)
	{
		assert(first_data >= 0 && first_data < n);
		assert(second_data >= 0 && second_data < n);
		for (int i = 0; i < g[first_data].size(); i++)
		{
			if (g[first_data][i] == second_data)
				return true;
		}
		return false;
	}

	class adjIterator {
	private:
		SparseGraph& G;
		int node;
		int index;

	public:
		adjIterator(SparseGraph& g, int _node) :G(g)
		{
			this->node = _node;
			this->index = 0;
		}

		int begin()
		{
			index = 0;
			if (G.g[node].size())
				return G.g[node][index];
			return -1;
		}

		int next()
		{
			index++;
			if (index <= G.g[node].size())
				return G.g[node][index];
			return -1;
		}
		
		bool end()
		{
			return index >= G.g[node].size();
		}
	};
};