#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()

ifstream fin("C:/eu/ubb/2nd_Semester/grafuri/test/dijkstra/graf.in");
ofstream fout("C:/eu/ubb/2nd_Semester/grafuri/test/Dijkstra/graf.out");

struct Edge {
    int dest, weight;
    Edge(int d, int w) : dest(d), weight(w) {}
};

void Dijkstra(int n, vector<vector<Edge>>& graph, int src) {
    vector<int> dist(n, INF); // Adjusted to n instead of n+1
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.dest;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) { // Adjusted to start from 0
        if (dist[i] == INF)
            fout << i << " " << "INF" << endl;
        else
            fout << i << " " << dist[i] << endl;
    }
    fout.close();
}

int main() {
    int n, edges;
    int src;
    fin >> n >> edges >> src;

    vector<vector<Edge>> graph(n); // Adjusted to n instead of n+1
    for (int i = 0; i < edges; ++i) {
        int a, b, weight;
        fin >> a >> b >> weight;
        graph[a].emplace_back(b, weight);
        // If the graph is undirected, uncomment the line below
        // graph[b].emplace_back(a, weight);
    }

    Dijkstra(n, graph, src);

    return 0;
}
