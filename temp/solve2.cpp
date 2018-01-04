#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;



struct node {
    int key;            // Contains the value                   notation : key
    int degree;         // Degree of this node                  notation : degree(x)
    node *parent;        // Parent of this node
    node *left;          // left pointer of this node
    node *right;         // right pointer of this node
    node *child;         // child of this node (every node is connected to ONLY ONE child node)
    bool marked;        // flag to check if this node is marked
    
    node() {
        key = degree = marked = 0;
        parent = child = NULL;
    }
};


struct FibHeap {
    int nH;             // Number of nodes in Heap              notation : n[H]
    node *H;            // Heap pointer (Points to the minimum key-Node)
    
    void InitHeap() {        // Heap initializer
        H = NULL;       // By default the heap is empty, So keep a NULL pointer
    }
    
    
    void insert(int value) {
        node *newNode;                                  // New node data type
        newNode->key = value;                           // Inserting new value in node
        newNode->left = newNode->right = newNode;       // At first, the nodes left and right sibiling is the node itself
        
        if(H == NULL)
            H = newNode;
        else {                                          // The new node is allways added on the left side of the key Pointer (H)
            (H->left)->right = newNode;                 
            newNode->right = H;
            newNode->left = H->left;
            H->left = newNode;
            if(newNode->key < H->key)                   // Change key pointer if the new value is minumum
                H = newNode;
        }
        nH++;                                           // Number of nodes in heap increased by one
    }
    
    
    node* Union(node* H1, node* H2) {
        node* H = H1;
        (H->left)->right = H2;
        (H2->left)->right = H;
        swap(H->left, H2->left);
        return H;
    }
    
    void ChildtoRootList(node* HeapPointer, node* childNode) {       // A function to move a child node to the root list
        (HeapPointer->left)->right = childNode;                     // The child node is added to the left of the HeapPointer
        childNode->right = HeapPointer;
        childNode->left = HeapPointer->left;
        HeapPointer->left = x;
        if(ChildNode->key < HeapPointer->key)                       // Also update the HeapPointer to this child node, if this child node has Min value
            HeapPointer = ChildNode;
        ChildNode->parent = NULL;                                   // Now this child has no parent
    }
    
    node* Extract_Min(node* H1) {
        node* z = H1, ChildNode = NULL;
        
        if(z == NULL)
            return z;
        
        if(z->child != NULL)
            ChildNode = z->child;
        
        if(ChildNode != NULL) {
            node* FinishPoint = ChildNode;
            do {
                node* tmp = ChildNode->right;
                ChildtoRootList(H1, ChildNode);
                ChildNode = tmp;
            }while(ChildNode != FinishPoint);
        }
    
    int top() {
        if(H != NULL)
            return H->key;
        return INF;
    }
    
    
};


int main() {
    return 0;
}
