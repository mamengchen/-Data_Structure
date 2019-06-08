#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <assert.h>
#include "Graph.h"
using namespace std;

template <typename Graph>
class Path {
private:
	Graph& G;
	int s;
	bool* visited;
	int* from;

	void dfs(int v)
	{
		visited[v] = true;
		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next())
		{
			if (!visited[i])
			{
				from[i] = v;
				dfs(i);
			}
		}
	}
public:
	Path(Graph& graph, int _s) :G(graph)
	{
		assert(_s >= 0 && _s <= G.n_num());
		visited = new bool[G.n_num()];
		from = new int[G.n_num()];
		for (int i = 0; i < G.n_num(); i++)
		{
			visited[i] = false;
			from[i] = -1;
		}
		this->s = _s;
	}
	
	~Path()
	{
		delete[] visited;
		delete[] from;
	}

	void hasPath(int w)
	{
		assert(w >= 0 && w <= G.n_num());
		return visited[w];
	}

	void path(int w, vector<int>& vec)
	{
		stack<int> mystk;
		int p = w;
		while (p != -1)
		{
			mystk.push(p);
			p = from[p];
		}
		vec.clear();
		while (!mystk.empty())
		{
			vec.push_back(mystk.top());
			mystk.pop();
		}
	}

	void showpath(int w)
	{
		vector<int> my_vec;
		path(w, my_vec);
		for (int i = 0; i < my_vec.size(); i++)
		{
			cout << my_vec[i];
			if (i != my_vec.size())
			{
				cout << "->";
			}
			else
			{
				cout << endl;
			}
		}
	}
};