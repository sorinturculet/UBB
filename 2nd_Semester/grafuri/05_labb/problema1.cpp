#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Edge {
    int src, dest, weight;
};
int Ford_Fulkerson(vector<Edge> Graph,int src, int dest) {
    int n = Graph.size();
    vector<vector<int>> adj(n);
    vector<vector<int>> capacity(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {   //adj matrix and capacity matrix
        adj[Graph[i].src].push_back(Graph[i].dest);
        adj[Graph[i].dest].push_back(Graph[i].src);
        capacity[Graph[i].src][Graph[i].dest] = Graph[i].weight;
    }
    vector<vector<int>> flow(n, vector<int>(n, 0));
    int max_flow = 0;
    while (true) {
        vector<int> parent(n, -1);
        stack<int> s;
        s.push(src);
        while (!s.empty()) {//DFS
            int u = s.top();
            s.pop();
            for (int v : adj[u]) {
                if (parent[v] == -1 && capacity[u][v] - flow[u][v] > 0) {
                    parent[v] = u;
                    s.push(v);
                }
            }
        }
        if (parent[dest] == -1)
            break;
        int path_flow = INT_MAX;
        for (int v = dest; v != src; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, capacity[u][v] - flow[u][v]);
        }
        for (int v = dest; v != src; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += path_flow;
            flow[v][u] -= path_flow;
        }
        max_flow += path_flow;
    }
return max_flow;
}
int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int n, m;
    fin >> n >> m;

    vector<Edge> Graph(m);

    for (int i = 0; i < m; i++) {
        int src, dest, weight;
        fin >> src >> dest >> weight;
        Graph[i].src = src;
        Graph[i].dest = dest;
        Graph[i].weight = weight;
    }

    //sursa 0 , destinatia n-1
    int flux=Ford_Fulkerson(Graph,0,n-1);
    fout<<flux<<endl;
    fin.close();

    return 0;
}