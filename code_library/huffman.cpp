#include <bits/stdc++.h>
using namespace std;

struct node {
    node* left;
    node* right;
    int Count;
    char Character;

    node(char Character = '$', int Count = 0) {
        this->Count = Count;
        this->Character = Character;
        this->left = NULL;
        this->right = NULL;
    }
};

struct compare{
    bool operator () (node* a, node* b) {
        if(a->Count != b->Count)
            return (a->Count > b->Count);
        else
            return (a->Character > b->Character);
    }
};

string str, chunk;
map<char, int>Counter;              // Stores Frequency for each word
map<char, string>CharToBit;         // Stores Huffman bit representation for each word


node* HuffManCompress(map<char, int>&Counter) {
    node* left;
    node* right;
    node* top;

    priority_queue<node*, vector<node*>, compare> pq;

    for(auto it : Counter)
        pq.push(new node(it.first, it.second));

    while(pq.size() != 1) {
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        top = new node('$', left->Count + right->Count);
        top->left = left;
        top->right = right;

        pq.push(top);
    }
    return top;
}

void CharToBitConverter(node* top, string bits) {
    if(!top)
        return;

    if(top->Character != '$')
        CharToBit[top->Character] = bits;

    CharToBitConverter(top->left, bits + '0');
    CharToBitConverter(top->right, bits + '1');
}

int main() {
    freopen("input.txt", "r", stdin);

    // Input from file
    bool first = 1;
    while(getline(cin, chunk)) {
        if(first) {
            str += chunk;
            first = 0;
        }
        else {
            str += '\n';
            str += chunk;
        }
    }

    // All the words from file
    cout << str << endl;

    // Character frequency counter
    for(int i = 0; i < str.size(); ++i) {
        if(isalpha(str[i]))
            Counter[str[i]]++;
    }

    for(auto it : Counter)
        cout << it.first << " : " << it.second << endl;

    // Makes the Huffman Binary Tree, returns the topmost node
    node* top = HuffManCompress(Counter);

    // Convert the words to associative bits, and save in map
    CharToBitConverter(top, "");
    cout << endl;

    // The appropriate bit size for each word in Huffman Coding
    cout << ceil(log2(Counter.size())) << endl;

    for(auto it: CharToBit)
        cout << it.first << " " << it.second << endl;

    // Equivalent output using Huffman Coding for The file
    for(auto it : str) {
        if(isalpha(it))
            cout << CharToBit[it];
        else
            cout << it;
    }

    return 0;
}
