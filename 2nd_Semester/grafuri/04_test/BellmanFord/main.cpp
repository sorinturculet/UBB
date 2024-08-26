#include <iostream>
#include <fstream>
using namespace std;

#define INF 10000
ifstream fin("C:/eu/ubb/2nd_Semester/grafuri/test/BellmanFord/graf.in");
ofstream fout("C:/eu/ubb/2nd_Semester/grafuri/test/BellmanFord/graf.out");
struct Edge {
    int src, dest, weight;
};

void BellmanFord(int n, int edges, Edge Graph[], int src) {


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

int main() {

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
    BellmanFord(n, edges, Graph, src);

    return 0;
}
