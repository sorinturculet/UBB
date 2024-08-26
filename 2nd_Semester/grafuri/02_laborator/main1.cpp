#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
#define INF 10000
ifstream fin("C:/eu/ubb/2nd_Semester/grafuri/02_laborator/graf.txt");

void moore(int start, const vector<vector<int>>& graph, vector<int>& length, vector<int>& predecessors) {
    int n = graph.size();
    length.assign(n, INF);
    predecessors.assign(n, -1);
    length[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (length[next] == INF) {
                predecessors[next] = current;
                length[next] = length[current] + 1;
                q.push(next);
            }
        }
    }
}
int Moore_drum(const vector<int>& length, const vector<int>& predecessors, int v) {
    int k = length[v];
    int uk = v;

    while (k != 0) {
        uk = predecessors[uk];
        k--;
    }

    return uk;
}
int main() {
    int n, m;
    fin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
    }

    int start_vertex;
    cout << "Scrieti punctul de inceput: ";
    cin >> start_vertex;

    vector<int> length;
    vector<int> predecessors;
    moore(start_vertex, graph, length, predecessors);

    cout << "Distanta de la varful sursa " << start_vertex << ":" << endl;
    for (int i = 0; i < length.size(); ++i) {
        cout << "Varful " << i << ": " << length[i] << endl;
    }

    cout << "Predecesori:" << endl;
    for (int i = 0; i < predecessors.size(); ++i) {
        cout << "Predecesorul " << i << ": " << predecessors[i] << endl;
    }
    cout<<"Introduceti varful de la care aflam cel mai scurt lant";
    int vertex_to_trace;
    cin>>vertex_to_trace;
    int source_of_vertex = Moore_drum(length, predecessors, vertex_to_trace);
    cout << "Varful " << vertex_to_trace << " este final de lant pentru varful "<< source_of_vertex <<endl;

    return 0;
}