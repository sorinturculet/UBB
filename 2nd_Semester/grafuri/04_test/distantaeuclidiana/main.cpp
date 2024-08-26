#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define INF 10000

ifstream fin("C:/eu/ubb/2nd_Semester/grafuri/test/distantaeuclidiana/graf.txt");

struct Edge {
    int dest;
    float weight;
    Edge(int d, float w) : dest(d), weight(w) {}
};

void Dijkstra(int n, vector<vector<Edge>>& graph, int src,int f) {
    vector<float> dist(n+1, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.dest;
            float w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

//    for (int i = 1; i <= n; ++i) {
//        if (dist[i] == INF)
//            cout << i << " " << "INF" << endl;
//        else
//            cout << i << " " << dist[i] << endl;
//    }
    if (dist[f] == INF)
        cout << "INF" << endl;
    else
        cout << dist[f] << endl;
}

int main() {
    int n, edges;
    fin >> n >> edges;
    vector<pair<int,int>> coordonate(n+1);
    for(int i=1;i<=n;i++){
        int a, b;
        fin >> a >> b;
        coordonate[i].first=a;
        coordonate[i].second=b;
        cout<<coordonate[i].first<<" "<<coordonate[i].second<<endl;
    }

    vector<vector<Edge>> graph(n+1);
    for (int i = 0; i < edges; ++i) {
        int orasA, orasB;
        fin >> orasA >> orasB ;
        float weight=sqrt( (coordonate[orasA].first-coordonate[orasB].first)*(coordonate[orasA].first-coordonate[orasB].first)+(coordonate[orasA].second
                                                                                                                                -coordonate[orasB].second)*(coordonate[orasA].second
                                                                                                                                                            -coordonate[orasB].second));
        graph[orasA].emplace_back(orasB, weight);
    }
    int s,f;
    cout << "Introduceti sursa";
    cin >> s;
    cout << "Introduceti nodul la care vreti sa ajungeti";
    cin >> f;
    Dijkstra(n, graph, s,f);

    return 0;
}