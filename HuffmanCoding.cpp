#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

class Node {
public:
    string symbol;
    double freq;
    Node* left;
    Node* right;

    Node(string s, double f) : symbol(s), freq(f), left(nullptr), right(nullptr) {}
};

// comparator for heap
struct CompareNode {
    bool operator()(const Node& a, const Node& b) const {
        return a.freq > b.freq;
    }
};

void buildHuffmanCode(Node* root, const string& code, unordered_map<string, string>& codes) {
    if (!root)
        return;

    // if node are leaf add it to codes
    if (!root->left && !root->right) {
        codes[root->symbol] = code;
        return;
    }

    // create code for left and right subtrees
    buildHuffmanCode(root->left, code + "0", codes);
    buildHuffmanCode(root->right, code + "1", codes);
}

vector<pair<string, double>> huffmanCoding(const vector<pair<string, double>>& info) {

    priority_queue<Node, vector<Node>, CompareNode> pq;

    // add symbols to priority queue
    for (auto pair : info) {
        pq.push(Node(pair.first, pair.second));
    }

    // build huffman tree
    while (pq.size() > 1) {
        Node* left = new Node(pq.top());
        pq.pop();
        Node* right = new Node(pq.top());
        pq.pop();

        Node* newNode = new Node("", left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(*newNode);
    }

    Node* root = new Node(pq.top());
    pq.pop();

    // get huffman code for each symbol
    unordered_map<string, string> codes;
    buildHuffmanCode(root, "", codes);

    vector<pair<string, double>> result;
    for (auto pair : info) {
        result.push_back({ pair.first, codes[pair.first].size() });
    }

    return result;
}

int main() {

    vector<pair<string, double>> info = { {"A", 0.4}, {"B", 0.3}, {"C", 0.2}, {"D", 0.1} };
    vector<pair<string, double>> coded = huffmanCoding(info);

    for (auto pair : coded) {
        cout << "Symbol: " << pair.first << ", Code length: " << pair.second << endl;
    }

    return 0;
}