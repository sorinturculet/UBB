#include <iostream>
#include <fstream>
using namespace std;

#define INF 10000

struct Edge {
    int src, dest, weight;
};

void BellmanFord(int n, int edges, Edge Graph[], int src, const char* output_file) {
    ofstream fout(output_file);

    int dist[n + 1];
    for (int i = 1; i <= n; i++)
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

    for (int i = 0; i < n; i++)
        if(dist[i]==INF)
            fout << i << " " << "INF" << endl;
        else fout << i << " " << dist[i] << endl;

    for (int i = 0; i < edges; i++) {
        int u = Graph[i].src;
        int v = Graph[i].dest;
        int weight = Graph[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            fout << "Graful contine cicluri cu ponderi negative" << endl;
            fout.close();
            return;
        }
    }
    fout.close();
}

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    const char* output_file = argv[2];

    Edge Graph[100];

    int n, edges;
    int src;
    fin >> n >> edges >> src;
    for (int i = 0; i < edges; i++) {
        int a, b, weight;
        fin >> a >> b >> weight;
        Graph[i].src = a;
        Graph[i].dest = b;
        Graph[i].weight = weight;
    }
    BellmanFord(n, edges, Graph, src, output_file);

    return 0;
}
