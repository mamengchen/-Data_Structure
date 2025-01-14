#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
// 定义一个节点结构，用于存储图中的边
struct Edge
{
    int to;     // 目标节点
    int weight;  // 边的权重
    Edge(int t, int w) : to(t), weight(w) {}
};


// Dijkstra 算法函数
void dijkstra(int start, const vector<vector<Edge>>& graph) {
    int v = graph.size();          // 获取图的顶点数
    vector<int> dist(v, INT_MAX);  // 存储从起点到每个节点的最短距离
    dist[start] = 0;               // 起点到自己的距离为0

    // 优先队列，按最短距离进行排序
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        // 如果当前距离大于已知的最短距离，则跳过
        if (currentDist > dist[currentNode]) {
            continue;
        }

        // 遍历邻居节点
        for (const Edge& edge : graph[currentNode]) {
            int nextNode = edge.to;
            int newDist = currentDist + edge.weight;

            // 如果找到更短的路径，则更新距离并加入优先队列
            if (newDist < dist[nextNode])
            {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    // 输出结果
    cout << "Node\tDistance from Source\n";
    for(int i = 0; i < v; ++i) {
        if (dist[i] == INT_MAX) {
            cout << i << "\t无穷" << endl;
        } else {
            cout << i << "\t" << dist[i] << endl;
        }
    }
    
}

int main() {
    int v = 5;
    vector<vector<Edge>> graph(v);

    // 添加边，例子中是无向图
    graph[0].push_back(Edge(1, 10));
    graph[0].push_back(Edge(4, 5));
    graph[1].push_back(Edge(2, 1));
    graph[2].push_back(Edge(3, 4));
    graph[4].push_back(Edge(1, 3));
    graph[4].push_back(Edge(2, 9));
    graph[4].push_back(Edge(3, 2));

    int start = 0;
    dijkstra(start, graph);
    
    return 0;
}
