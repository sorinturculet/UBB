#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
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
void generateHuffmanCodes(Node* root, const string& prefix, map<char, string>& codes) {
    if (root->left == nullptr && root->right == nullptr) {
        codes[root->character] = prefix;
        //cout<<root->character<<" "<<prefix<<endl;
        return;
    }
    if (root->left != nullptr) {
        generateHuffmanCodes(root->left, prefix + "0", codes);
    }
    if (root->right != nullptr) {
        generateHuffmanCodes(root->right, prefix + "1", codes);
    }
}

string HuffmanCode(const map<char, int>& frec, const string& s) {
    string code;

    // Build the Huffman tree
    Node* root = buildHuffmanTree(frec);

    // Generate Huffman codes for characters
    map<char, string> codes;
    generateHuffmanCodes(root, "", codes);
    for(const auto& elem:codes){
        cout<<elem.first<<" "<<elem.second<<endl;
    }
    // Encode the input string using Huffman codes
    for (char c : s) {
        code += codes[c];
    }

    // Free memory by deleting the Huffman tree
    delete root;

    return code;
}
int main(int argc, char* argv[]) {

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    char s[100];
    fin.getline(s,100);
    map<char,int> frec;
    for(int i=0;i<strlen(s);i++){
       frec[s[i]]++;
    }
    fout<<frec.size()<<endl;
    for(auto elem:frec){
        fout<<elem.first<<" "<<elem.second<<endl;
    }
    //creare cod huffman
    string code;
    code=HuffmanCode(frec,s);
    //afisare code huffman
    fout<<code;
    return 0;
}
