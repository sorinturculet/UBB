#include <fstream>
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
//DECODARE PRUFER
vector<int> DecodePruferCode(vector<int>& code) {
    int n = code.size() + 1;
    vector<int> pred(n, -1);

    for (int i=0;i<n-1;i++) {
        int smallest = 0;
        while (true) {
            auto it = find(code.begin(), code.end(), smallest);
            if (it == code.end()) { // If the value is not found in the vector
                break;
            }
            ++smallest; // Increment to check the next value
        }

        int parent = code[0];
        code.erase(code.begin());
        pred[smallest] = parent;
        code.push_back(smallest);
    }

    return pred;
}

int main(int argc, char* argv[]) {
    vector<int> prufercode;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        prufercode.push_back(x);
    }

    vector<int> pred = DecodePruferCode(prufercode);
    fout << pred.size() << endl;
    for (auto elem:pred)
        fout << elem<< " ";
    return 0;
}
