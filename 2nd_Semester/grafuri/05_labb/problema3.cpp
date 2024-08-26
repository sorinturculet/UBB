#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Edge {
    int src, dest;
};

void addEdge(vector<int> adj[], int src, int dest) {
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void removeEdge(vector<int> adj[], int src, int dest) {
    adj[src].erase(remove(adj[src].begin(), adj[src].end(), dest), adj[src].end());
    adj[dest].erase(remove(adj[dest].begin(), adj[dest].end(), src), adj[dest].end());
}

bool isEulerian(vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    int nonZeroDegreeVertex = -1;
    //verificam daca exista noduri cu grad nul
    for (int i = 0; i < n; i++) {
        if (!adj[i].empty()) {
            nonZeroDegreeVertex = i;
            break;
        }
    }

    if (nonZeroDegreeVertex == -1)
        return false;
    //DFS ca sa verificam daca e conex
    stack<int> s;
    s.push(nonZeroDegreeVertex);
    visited[nonZeroDegreeVertex] = true;
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                s.push(u);
            }
        }
    }
    //verificam daca toate nodurile sunt vizitate
    for (int i = 0; i < n; i++) {
        if (!adj[i].empty() && !visited[i])
            return false;
    }
    //verificam daca toate nodurile au grad par
    for (int i = 0; i < n; i++) {
        if (adj[i].size() % 2 != 0)
            return false;
    }

    return true;
}

void findEulerianCycle(vector<int> adj[], int n, vector<int>& eulerianCycle) {
    stack<int> currPath;
    vector<int> circuit;
    int startVertex = 0;

    for (int i = 0; i < n; i++) {
        if (!adj[i].empty()) {
            startVertex = i;
            break;
        }
    }

    currPath.push(startVertex);
    int currVertex = startVertex;

    while (!currPath.empty()) {
        for(auto elem: circuit)
            cout << elem << " ";
        cout << endl;
        if (!adj[currVertex].empty()) {
            currPath.push(currVertex);
            int nextVertex = adj[currVertex].back();
            removeEdge(adj, currVertex, nextVertex);
            currVertex = nextVertex;
        } else {
            circuit.push_back(currVertex);
            currVertex = currPath.top();
            currPath.pop();
        }
    }

    reverse(circuit.begin(), circuit.end());
    eulerianCycle = circuit;
}

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int n, m;
    fin >> n >> m;

    vector<Edge> Graph(m);
    vector<int> adj[n];

    for (int i = 0; i < m; i++) {
        int src, dest;
        fin >> src >> dest;
        Graph[i].src = src;
        Graph[i].dest = dest;
        addEdge(adj, src, dest);
    }

    if (isEulerian(adj, n)) {
        vector<int> eulerianCycle;
        findEulerianCycle(adj, n, eulerianCycle);
        for (int v : eulerianCycle) {
            fout << v << " ";
        }
    } else {
        fout << "No Eulerian Cycle exists";
    }

    return 0;
}
