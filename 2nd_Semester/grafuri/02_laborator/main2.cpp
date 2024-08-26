//2. Sa se determine închiderea transitivă a unui graf orientat. (Închiderea tranzitivă poate fi reprezentată ca matricea care descrie, pentru fiecare vârf în parte, care sunt vârfurile accesibile din acest vârf. Matricea inchiderii tranzitive arată unde se poate ajunge din fiecare vârf.) ex. figura inchidere_tranzitiva.png - pentru graful de sus se construieste matricea de jos care arata inchiderea tranzitiva.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define INF 10000
ifstream fin("C:/eu/ubb/2nd_Semester/grafuri/02_laborator/graf2.txt");
void roy_floyd(vector<vector<int>>& D, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (D[i][k] != INF && D[k][j] != INF && D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
            }
        }
    }
}


int main() {
    int n, m;
    int a, b;
    fin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i <= n; i++)
        graph[i][i] = 0;

    for (int i = 0; i <= m; i++) {
        fin >> a >> b;
        graph[a][b] = 1;
    }

    roy_floyd(graph,n);

    for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<n;j++)
            if(graph[i][j]==INF)
                cout<<0<<" ";
            else cout<<1<<" ";

    return 0;
}
