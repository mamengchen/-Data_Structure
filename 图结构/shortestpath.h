#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <assert.h>
#include <queue>
#include "Graph.h"
using namespace std;

template<typename Graph>
class shortestpath {

private:
	Graph& G;
	int s;
	bool* visited;
	int* from;
	int* ord;
public:
	shortestpath(Graph& graph, int _s) :G(graph)
	{
		assert(_s >= 0 && s < G.n_num());
		visited = new bool[graph.n_num()];
		from = new int[graph.n_num()];
		ord = new int[G.n_num()];
		for (int i = 0; i < G.n_num(); i++)
		{
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}
		this->s = _s;
		queue<int> q;

		q.push(s);
		visited[s] = true;
		ord[s] = 0;
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			typename Graph::adjIterator adj(G, v);
			for (int i = adj.begin(); !adj.end(); i++)
			{
				if (!visited[i])
				{
					q.push(i);
					visited[i] = true;
					from[i] = v;
					ord[i] = ord[v] + 1;
				}
			}
		}
	}

	~shortestpath()
	{
		delete[] visited;
		delete[] from;
		delete[] ord;
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

	int length(int w)
	{
		assert(w >= 0 && w < G.n_num());
		return ord[w];
	}
};