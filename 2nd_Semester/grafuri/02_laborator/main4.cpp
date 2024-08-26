#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("C:/eu/ubb/grafuri/02_laborator/graf.txt");

void bfs(int n,int mat_adj[][100],int nod,int visited[]){
    queue<int> q;

    visited[nod]=1;
    q.push(nod);

    while(!q.empty()){

        int currentNode=q.front();
        q.pop();
        cout << visited[currentNode]<< " "<<currentNode<<endl;
        for(int i=1;i<=n;i++) {
            if (mat_adj[currentNode][i] == 1)
                if (!visited[i]) {
                    visited[i]=visited[currentNode]+1;
                    q.push(i);
                }
        }
    }
}

int main() {
    int n, m;
    int a, b;
    fin >> n >> m;
    int mat_adj[n + 1][100];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            mat_adj[i][j]=0;

    for (int i = 1; i <= m; i++) {
        fin >> a >> b;
        mat_adj[a][b] = mat_adj[b][a] = 1;
    }


    int nod;
    cout<<"Introduceti nodul pentru care verificam drumurile cu bfs:";
    cin>>nod;
    int visited[n+1];
    for(int i=1;i<=n;i++)
        visited[i]=0;
    bfs(n,mat_adj,nod,visited);

    int grad=1;
    bool visit=true;
    while(visit){
        visit=false;
        for(int i=1;i<=n;i++)
            if(visited[i]==grad) {
                cout << "nivel " << grad-1<< " nod " << i << "\n";
                visit = true;

            }
        grad++;
    }
    return 0;
}