#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("C:/eu/ubb/2nd_Semester/grafuri/test/bfs_conexe/graf.in");
ofstream fout("C:/eu/ubb/2nd_Semester/grafuri/test/bfs_conexe/graf.out");

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

int main() {
    int n, m;
    fin >> n >> m;
    vector<vector<int>> graf(n);
    for (int i = 0; i < m; i++) { // Corrected indexing starts from 0
        int u, v;
        fin >> u >> v;
        graf[u].push_back(v);
        graf[v].push_back(u);
    }
    vector<bool> v(n, false);
    int nr_componente = 0;
    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            nr_componente++;
            dfs(graf, v, i);
        }
    }
    fout << "Numarul de componente conexe este: " << nr_componente;
    return 0;
}
