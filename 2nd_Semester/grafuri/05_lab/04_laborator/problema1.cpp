#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> PruferCode(const vector<int>& pred) {
    int n = pred.size();
    vector<int> code;

    vector<int> predCount(n, 0);
    for (int i = 0; i < n; ++i) {
        if (pred[i] != -1) {
            predCount[pred[i]]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> leaves;
    for (int i = 0; i < n; ++i) {
        if (predCount[i] == 0) {
            leaves.push(i);
        }
    }
//    for(int i=0;i<predCount.size();i++)
//        cout<<predCount[i]<<" ";
//    cout<<endl;

    while (leaves.size() > 0) {
        int leaf = leaves.top();
        leaves.pop();
        int parent = pred[leaf];
        if(parent!=-1)
            code.push_back(parent);
        predCount[parent]--;
        if (predCount[parent] == 0) {
            leaves.push(parent);
        }

    }

    return code;
}

int main(int argc, char* argv[]) {
    vector<int> listapred;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        listapred.push_back(x);
    }
//    for(int i=0;i<listapred.size();i++)
//        cout<<listapred[i]<<" ";
//    cout<<endl;
    vector<int> prufercode = PruferCode(listapred);
    fout << prufercode.size() << endl;
    for (int i = 0; i < prufercode.size(); i++)
        fout << prufercode[i] << " ";
    return 0;
}
