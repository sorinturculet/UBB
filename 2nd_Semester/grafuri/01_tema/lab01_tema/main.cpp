#include <iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<list>
using namespace std;
int mat_ad[10][10];
list<int> noduri_izolate;

class Graph{
public:
    map<int,bool>visited;
    map<int,list<int>>adj;

    void addEdge(int v,int w);
    void DFS(int v);
    int isConnected();
};
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}
void Graph::DFS(int v) {
    visited[v]=true;
    list<int>::iterator i;
    for(i= adj[v].begin();i!=adj[v].end();i++)
        if(!visited[*i])
            DFS(*i);
}
int Graph::isConnected() {
    int number_of_nodes=0;
    for(int i=1;i<=visited.size();i++)
        if(visited[i]==1)
            number_of_nodes+=1;
    return number_of_nodes;
}

int main()
{
    ifstream fin("C:/eu/ubb/grafuri/lab01_tema/lab01_tema/in.txt");
    int n=0;
    fin>>n;
    cout<<n<<"\n";

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fin>>mat_ad[i][j];
    fin.close();
    cout<<"Matricea de adiacenta citita este:\n";
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            cout<<mat_ad[i][j];

    //a graf orientat
    for(int i=1;i<=n;i++)
        {int n_muchii=0;
        for(int j=1;j<=n;j++)
            {if(mat_ad[i][j]==1)
                n_muchii++;
            }
        if(n_muchii==0)
            noduri_izolate.push_back(i);
        }
    if(noduri_izolate.empty())
        cout<<"Nu exista noduri izolate\n";
    else
        {cout<<"Nodurile izolate sunt: ";
        for(list<int>::iterator i=noduri_izolate.begin(); i!=noduri_izolate.end(); i++)
            cout<<*i<<" ";
        cout<<endl;
        }

    //b
    bool regulat=true;
    int nr_vecini1=0;
    for(int i=1;i<=n;i++)
        nr_vecini1+=mat_ad[1][i];
    for(int i=1;i<=n;i++)
        {int nr_vecinii=0;
        for(int j=1;j<=n;j++)
            nr_vecinii+=mat_ad[i][j];
        if(nr_vecini1!=nr_vecinii)
            {regulat=false;
            break;}
        }
    if(regulat==1)cout<<"Graful este regulat";
    else cout<<"Graful nu este regulat";
    cout<<"\n";

    //c
    int dist[n][n];
    for(int i=1;i<=n;i++)
        dist[i][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            dist[i][j]=1;
            if (mat_ad[i][j] == 0)
                dist[i][j]=10000;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if (dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
    cout<<"Matricea de distanta este:\n";
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            if(dist[i][j]==10000)
                cout<<"inf"<<" ";
            else cout<<dist[i][j]<<" ";
    cout<<'\n';
    //d
    Graph g;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if (mat_ad[i][j]==1)
                g.addEdge(i,j);
    g.DFS(1);
    cout << "Este graful conex?" << (g.isConnected() ==n ? "Da " : "Nu ") << endl;
    return 0;
}
