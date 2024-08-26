#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#define INF 10000
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to perform Bellman-Ford algorithm
// Returns true if no negative cycle is found
// Function to perform Bellman-Ford algorithm
// Returns true if no negative cycle is found

    bool BellmanFord(int n, int edges, Edge Graph[], int src,int dist[]) {

        for (int i = 0; i <= n; i++)
            dist[i] = INF;
        dist[src] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < edges; j++) {
                int u = Graph[j].src;
                int v = Graph[j].dest;
                int weight = Graph[j].weight;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

//        for (int i = 0; i < n; i++)
//            if (dist[i] == INF)
//                fout << i << " " << "INF" << endl;
//            else fout << i << " " << dist[i] << endl;

        for (int i = 0; i < edges; i++) {
            int u = Graph[i].src;
            int v = Graph[i].dest;
            int weight = Graph[i].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {

                return false;
            }
        }
        return true;
    }
// Function to perform Dijkstra's algorithm
// starting from a given vertex
vector<int> dijkstra(vector<vector<int>>& graph, int start) {
    int V = graph.size();
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != INF) {
                int w = graph[u][v];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    return dist;
}

// Function to perform Johnson's algorithm
vector<vector<int>> johnsonsAlgorithm(int n, int edges,Edge graph[], const char* output_file) {

    ofstream fout(output_file);
    vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, INF));
    for (int i = 0; i < edges; i++) {
        int src = graph[i].src;
        int dest = graph[i].dest;
        int weight = graph[i].weight;
        adjMatrix[src][dest] = weight;
    }

    for(int i=0;i<n;i++) {
        graph[edges + i].src = n;
        graph[edges + i].dest = i;
        graph[edges + i].weight = 0;
    }
    n++;
    edges+=n-1;
    int dist[n+1];
    // Step 1: Bellman-Ford
    if (!BellmanFord(n, edges, graph,n-1,dist )) {
        fout<<-1;
        return {};
    }
//   x
    // Step 2: Adjust edge weights

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (adjMatrix[u][v] != INF) {
                adjMatrix[u][v] += dist[u] - dist[v];
                fout<<u<<" "<<v<<" "<<adjMatrix[u][v]<<endl;
            }
        }
    }
    fout<<endl;
    vector<vector<int>> shortestPaths(n, vector<int>(n));
    for (int u = 0; u < n; ++u) {
        vector<int> dist2 = dijkstra(adjMatrix, u);
        for (int v = 0; v < n; ++v) {
            shortestPaths[u][v] = dist2[v] - dist[u] + dist[v]; // Adjust the distances back
        }
    }
    n--;
    for (int i = 0; i < n; ++i , fout << endl) {
        for (int j = 0; j < n; ++j) {
            if(shortestPaths[i][j]>=INF)
                fout<<"INF ";
            else fout << shortestPaths[i][j] << " ";
        }
    }


    return shortestPaths;

}

int main(int argc, char* argv[]) {
    cout << argv[1]<<endl;
    cout << argv[2] << endl;
    Edge Graph[100];
    int n, edges;
    ifstream fin(argv[1]);
    fin >> n >> edges;

    // Populate the Graph array with edges
    for (int i = 0; i < edges; i++) {
        int a, b, weight;
        fin >> a >> b >> weight;
        Graph[i].src = a;
        Graph[i].dest = b;
        Graph[i].weight = weight;
    }

    vector<vector<int>> distance = johnsonsAlgorithm(n,edges,Graph, argv[2]);

    // Output shortest paths

    return 0;
}
