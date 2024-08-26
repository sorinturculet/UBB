#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

// DECODARE huffman
struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    //Constructor
    Node(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}

    // Constructor
    Node(int freq, Node* l, Node* r) : character('$'), frequency(freq), left(l), right(r) {}
};

struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        if (a->frequency == b->frequency) {
            return a->character > b->character;//lexicografic
        }
        return a->frequency > b->frequency;
    }
};

Node* buildHuffmanTree(const map<char, int>& frec) {
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;
//priority queue pentru noduri, bazat pe functia de comparere
    for (const auto& p : frec) {
        pq.push(new Node(p.first, p.second));

    }
    // Huffman tree
    for(int i=1;i<=frec.size()-1;i++){
        //cout<<pq.top()->character<<" "<<pq.top()->frequency<<endl;
        Node* left = pq.top();
        pq.pop();
        // cout<<pq.top()->character<<" "<<pq.top()->frequency<<endl;
        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node(left->frequency + right->frequency, left, right);
        //cout<<parent->character<<" "<<parent->left->frequency<<" "<<parent->right->frequency<<" "<<parent->frequency<<endl;
        pq.push(parent);
    }

    //In queue o sa ramana doar root-ul
    return pq.top();
}

// genereaza codurile pe baza a arborelui huffman
string degenerateHuffmanCodes(Node* root, const string& s) {
    string code;
    Node* current = root;
    for (char c : s) {
        if (c == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == nullptr && current->right == nullptr) {
            code += current->character;
            current = root;
        }
    }
    return code;
}

string HuffmanCode(const map<char, int>& frec, const string& s) {
    string code;

    // Build the Huffman tree
    Node* root = buildHuffmanTree(frec);

    code=degenerateHuffmanCodes(root, s);

    // Free memory by deleting the Huffman tree
    delete root;

    return code;
}
int main(int argc, char* argv[]) {

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n;
    string s;
    fin>>n;
    map<char,int> frec;
    for(int i=0;i<n;i++){
        char c;
        int nr;
        fin>>c>>nr;
        frec[c]=nr;
    }
    fin>>s;
   // creare cod huffman
    string code;
    code=HuffmanCode(frec,s);
    //afisare code huffman
    fout<<code;
    return 0;
}
