#include <iostream>
#include<fstream>
using namespace std;
ifstream f("in.txt");
bool mat_ad[10][10];
int lista_ad[10][10];
bool mat_inc[10][10];
int main()
{
    int n;
    f>>n;
    int a,b;
    int coloana=1;
    while(f>>a>>b)
    {
        mat_ad[a][b]=mat_ad[b][a]=1;//matricea de adicenta;
        mat_inc[a][coloana]=mat_inc[b][coloana]=1;
        coloana++;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(mat_ad[i][j]==1)
                {
                lista_ad[i][0]+=1;
                lista_ad[i][lista_ad[i][0]]=j;
                }
    cout<<"Lista de adiacenta este:\n";
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=lista_ad[i][0];j++)
            cout<<lista_ad[i][j]<<" ";
    cout<<"Matricea de adiacenta este:\n";
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            cout<<mat_ad[i][j]<<" ";
    cout<<"Matricea de incidenta este:\n";
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<coloana;j++)
            cout<<mat_inc[i][j]<<" ";
    return 0;
}
