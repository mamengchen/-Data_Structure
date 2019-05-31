#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template <typename Graph>
class Component {
private:
	Graph &G;
	bool *visited;
	int ccount;
	int *id;

	void dfs(int v)
	{
		visited[v] = true;
		id = ccount;
		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next())
		{
			if (!visited[i])
				dfs(i);
		}
	}

public:
	Component(Graph &graph) : G(graph)
	{
		visited = new bool[G.n_num()];
		id = new int[G.n_num()];
		ccount = 0;
		for (int i = 0; i < G.n_num(); i++)
		{
			visited[i] = false;
			id[i] = -1;
		}
		for (int i = 0; i < G.n_num(); i++)
		{
			if (!visited[i])
			{
				dfs(i);
				ccount++;
			}
		}
	}

	~Component()
	{
		delete[] visited;
		delete[] id;
	}

	int count() { return ccount; }

	bool isConnected(int v, int w)
	{
		assert(v >= 0 && v < G.n_num());
		assert(w >= 0 && w < G.n_num());
		return id[v] == id[w];
	}
};