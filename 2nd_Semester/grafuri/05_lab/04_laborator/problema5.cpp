#include <fstream>
#include <iostream>

using namespace std;
struct Edge {
    int src, dest, weight;
};
int graph_prim(int n,int m,Edge Graph[],Edge Dist[]){
    int weights=0;
    int size=0;
    int visited[100];
    for(int i=0;i<n;i++)
        visited[i]=0;
    visited[0]=1;
    while(size<n-1){
        int min=10000;
        int index=0;
        for(int i=1;i<=m;i++){ //cautam muchia cea mai "mica" care urmeaza sa fie gasita/adaugata
            if(visited[Graph[i].src]==1 && visited[Graph[i].dest]==0 && Graph[i].weight<min){
                min=Graph[i].weight;
                index=i;
            }
            if(visited[Graph[i].dest]==1 && visited[Graph[i].src]==0 && Graph[i].weight<min){
                min=Graph[i].weight;
                index=i;
            }
        }
        if(visited[Graph[index].src]==1 && visited[Graph[index].dest]==0){
            visited[Graph[index].dest]=1;
            Dist[++size]=Graph[index];
            weights+=Graph[index].weight;
        }
        if(visited[Graph[index].dest]==1 && visited[Graph[index].src]==0){
            visited[Graph[index].src]=1;
            Dist[++size]=Graph[index];
            weights+=Graph[index].weight;
        }
    }
    return weights;
}
int main(int argc, char* argv[]) {

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    Edge Graph[100];
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=m;i++){//citim graful
        int src,dest,weight;
        fin>>src>>dest>>weight;
        Graph[i].src=src;
        Graph[i].dest=dest;
        Graph[i].weight=weight;
    }
    int size;
    Edge Dist[100];
    size=graph_prim(n,m,Graph,Dist);
    fout<<size<<endl;
    fout<<n-1<<endl;
    for(int i=1;i<=n-1;i++){
        fout<<Dist[i].src<<" "<<Dist[i].dest<<" "<<Dist[i].weight<<endl;
    }
    return 0;
}