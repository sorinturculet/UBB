#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

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
    vector<Edge> Graph2;
    int n,m,e;
    fin>>n>>m>>e;
    for(int i=1;i<=e;i++){//citim graful
        int src,dest;
        fin>>src>>dest;
        //Graph2.push_back({src, dest,1});
        Graph2.push_back({src, dest+n,1});
    }
//    int size;
//    Edge Dist[100];
//    size=graph_prim(n,m,Graph,Dist);
//    fout<<size<<endl;
//    fout<<n-1<<endl;
//    for(int i=1;i<=n-1;i++){
//        fout<<Dist[i].src<<" "<<Dist[i].dest<<" "<<Dist[i].weight<<endl;
//    }
    //adaugam nodul sursa si cel destinatie, legat la cele n, respectiv m noduri.
    for(int i=1;i<=n;i++)
        Graph2.push_back({0, i,1});
    for(int i=1;i<=m;i++)
        Graph2.push_back({i+n,n+m+1,1});

    int max_flow = Ford_Fulkerson(Graph2, 0, n + m +1);
    fout << max_flow;

    return 0;
}