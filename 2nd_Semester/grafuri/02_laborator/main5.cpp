#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("C:/eu/ubb/2nd_Semester/grafuri/02_laborator/graf5.txt");

void dfs(int node, const vector<vector<int>>& graph,vector<bool> &visited) {
    visited[node] = true;
    cout << "Apel DFS: " << node << endl;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph,visited);
        }
    }
}

int main() {
    int n, m;
    fin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1,false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start_vertex;
    cout << "Introduceti punctul de la care incepem: ";
    cin >> start_vertex;

    dfs(start_vertex, graph,visited);

    return 0;
}