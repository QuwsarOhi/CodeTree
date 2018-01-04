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
    
    node(int val) {
        pf("NODEINIT\n");
        this->key = val;
        this->degree = this->marked = 0;
        this->parent = this->child = NULL;
    }
};


struct FibHeap {
    int nH;             // Number of nodes in Heap              notation : n[H]
    node *H;            // Heap pointer (Points to the minimum key-Node)
    
    
    // Tested, OK
    FibHeap() {           // Heap initializer
        nH = 0;                 // heapSize set to 0
        H = NULL;               // By default the heap is empty, So keep a NULL pointer
    }
    
    // Tested, OK
    void insert(int value) {
        node *newNode = new node(value);                            // New node data type
        newNode->left = newNode->right = newNode;                   // At first, the nodes left and right sibiling is the node itself
        
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
    
    /*
    node* Union(node* H1, node* H2) {
        node* H = H1;
        (H->left)->right = H2;
        (H2->left)->right = H;
        swap(H->left, H2->left);
        return H;
    }*/
    
    void ChildtoRootList(node* HeapPointer, node* childNode) {       // A function to move a child node to the root list
        (HeapPointer->left)->right = childNode;                     // The child node is added to the left of the HeapPointer
        childNode->right = HeapPointer;
        childNode->left = HeapPointer->left;
        HeapPointer->left = childNode;
        if(childNode->key < HeapPointer->key)                       // Also update the HeapPointer to this child node, if this child node has Min value
            HeapPointer = childNode;
        childNode->parent = NULL;                                   // Now this child has no parent
    }
    
    void Fib_Link(node* H1, node* child, node* parent) {
        (child->left)->right = child->right;
        (child->right)->left = child->left;
        
        if(parent->right == parent)
            H1 = parent;
        
        child->left = child->right = child;
        child->parent = parent;
        if(parent->child == NULL)
            parent->child = child;
        
        child->right = parent->child;
        child->left = (parent->child)->left;
        
        ((parent->child)->left)->right = child;
        (parent->child)->left = child;
        
        if(child->key < (parent->child)->key)
            parent->child = child;
        
        parent->degree++;
    }
            
        
    
    void Consolidate(node* H1) {
        int arrSize = (log(nH)/log(2));
        node* arr[arrSize+2];
        
        for(int i = 0; i <= arrSize; ++i)
            arr[i] = NULL;
        node* root1 = H1;
        
        do{
            //root2 = root2->right;
            int degree = root1->degree;
            
            while(arr[degree] != NULL) {
                node* root2 = arr[degree];
                if(root1->key > root2->key)
                    swap(root1, root2);
                if(root2 == H1)
                    H1 = root1;
                Fib_Link(H1, root2, root1);
                
                if(root1->right == root1)   //extra??
                    H1 = root1;
                arr[degree] = NULL;
                degree++;
            }
            
            arr[degree] = root1;
            root1 = root1->right;
        }while(root1 != H);
        
        H = NULL;
        for(int i = 0; i <= arrSize; ++i) {
            if(arr[i] != NULL) {
                arr[i]->left = arr[i]->right = arr[i];
                
                if(H != NULL) {
                    (H->left)->right = arr[i];
                    arr[i]->right = H;
                    arr[i]->left = H->left;
                    H->left = arr[i];
                    if(arr[i]->key < H->key)
                        H = arr[i];
                }
                else
                    H = arr[i];
                
                if(H == NULL)               //extra??
                    H = arr[i];
                else if(arr[i]->key < H->key)       //extra??
                    H = arr[i];
            }
        }
    }
                    
        
    // MOdified, instead of node pointer, int in return type
    // input parameter was node* H1, set to none
    int Extract_Min() {
        node* z = H;        // H1
        node* ChildNode = NULL;
        node* prevHeapPointer = H;     //H1
        
        if(z == NULL)
            return INF;
        
        if(z->child != NULL)
            ChildNode = z->child;                                   // If this Min Key has any immediate child node, get it
        
        if(ChildNode != NULL) {
            node* FinishPoint = ChildNode;                          // This node is the finish point
            do {                                                    // Loop to all immediate child node and move them to rootlist
                node* tmp = ChildNode->right;                       // Save the right sibiling before sending this node to rootlist
                ChildtoRootList(H, ChildNode);                      // Send this node to root list
                ChildNode = tmp;                                    // Go for the right node that was this node's sibiling
            }while(ChildNode != FinishPoint);
        }
        
        (z->left)->right = z->right;                // Z was the HeapPointer, to remove this
        (z->right)->left = z->left;                 // we need to connect the left part of the rootlist with the right part of the rootlist
        H = z->right;                               // the new heapPointer is the right/left (assuming) root
        
        if(z->right == z && z->child == NULL)       // if there is no other nodes/heaps in rootlist
            H = NULL;
        else {
            H = z->right;       //
            Consolidate(H);
        }
        
        nH--;
        return prevHeapPointer->key;
    }
    
    int top() {
        if(H != NULL)
            return H->key;
        return INF;
    }
    
    // BUGGY -------------------------------------
    void deleteNode(node* n) {
        delete n->child;
        delete n->right;
        delete n->left;
        delete n->parent;
        delete n;
    }
    
    void goDown(node* n) {
        if(n != NULL && n->child != NULL) {
            node* r;
            r = NULL;
            if(n->right != NULL && n->right != n)
                r = n->right;
            //goDown(n->child);
            //if(r != NULL)
            //    goDown(r);
        }
        else
            deleteNode(n);
    }
    
    void clear() {
        goDown(H);
    }
    // NEED to add Clear function!!
};


int main() {
    FibHeap heap;
    heap.insert(12);
    heap.insert(14);
    pf("%d\n", heap.top());
    heap.clear();
    pf("ALLOK\n");
    return 0;
}
