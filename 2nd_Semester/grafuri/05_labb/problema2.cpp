#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
    int dest, revIdx, capacity, flow;
};

void addEdge(vector<vector<Edge>>& adj, int src, int dest, int capacity) {
    Edge forward = {dest, (int)adj[dest].size(), capacity, 0};
    Edge backward = {src, (int)adj[src].size(), 0, 0};
    adj[src].push_back(forward);
    adj[dest].push_back(backward);
}

void preflowPush(vector<vector<Edge>>& adj, int source, int sink) {
    int n = adj.size();
    vector<int> height(n, 0), excess(n, 0);
    queue<int> active;

    height[source] = n;
    for (Edge &e : adj[source]) {
        e.flow = e.capacity;
        adj[e.dest][e.revIdx].flow = -e.capacity;
        excess[e.dest] += e.capacity;
        excess[source] -= e.capacity;
    }

    for (int i = 0; i < n; i++) {
        if (i != source && i != sink && excess[i] > 0) {
            active.push(i);
        }
    }

    while (!active.empty()) {
        int u = active.front();
        active.pop();

        for (Edge &e : adj[u]) {
            if (excess[u] > 0 && e.capacity > e.flow && height[u] == height[e.dest] + 1) {
                int push_flow = min(excess[u], e.capacity - e.flow);
                e.flow += push_flow;
                adj[e.dest][e.revIdx].flow -= push_flow;
                excess[u] -= push_flow;
                excess[e.dest] += push_flow;

                if (excess[e.dest] > 0 && e.dest != source && e.dest != sink) {
                    active.push(e.dest);
                }
            }
        }

        if (excess[u] > 0) {
            height[u]++;
            active.push(u);
        }
    }
}

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int n, m;
    fin >> n >> m;

    vector<vector<Edge>> adj(n);

    for (int i = 0; i < m; i++) {
        int src, dest, capacity;
        fin >> src >> dest >> capacity;
        addEdge(adj, src, dest, capacity);
    }

    preflowPush(adj, 0, n-1);

    int maxFlow = 0;
    for (const Edge &e : adj[0]) {
        maxFlow += e.flow;
    }

    fout << maxFlow << endl;
    fin.close();
    fout.close();
    return 0;
}