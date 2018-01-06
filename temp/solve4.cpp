#include <bits/stdc++.h>
using namespace std;


struct node {
    int key;
    node* left;
    node* right;
    node* parent;
    node* child;
    
    node(int val) {
        key = val;
        parent = child = NULL;
        this->left = this;
        this->right = this;
    }
};

struct FibHeap {
    int nH, Size;
    node* H;
    
    
    FibHeap(){
        H = NULL;
        nH = Size = 0;
    }
    
    // Full ok?
    void push(int val) {
        
    }
    
    
    // Manual functions ---------------------------
    
};

int main() {
    return 0;
}
